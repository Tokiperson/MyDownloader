#include "deepseek_client.h"
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QTimer>
#include <QEventLoop>

DeepSeekClient::DeepSeekClient(QObject *parent)
    : QObject(parent)
    , networkManager(new QNetworkAccessManager(this))
    , apiEndpoint("https://api.deepseek.com/chat/completions")
{
    // 设置SSL配置
    QSslConfiguration sslConfig = QSslConfiguration::defaultConfiguration();
    sslConfig.setPeerVerifyMode(QSslSocket::VerifyNone);
    QSslConfiguration::setDefaultConfiguration(sslConfig);
}

DeepSeekClient::~DeepSeekClient()
{
    cancelAllRequests();
    delete networkManager;
}

void DeepSeekClient::setApiKey(const QString &apiKey)
{
    this->apiKey = apiKey;
}

void DeepSeekClient::sendMessage(const QString &message)
{
    if (apiKey.isEmpty()) {
        emit errorOccurred("API key not set");
        return;
    }

    // 防止过多并发请求
    if (activeReplies.size() >= 3) {
        emit errorOccurred("Too many requests, please wait a moment");
        return;
    }

    QNetworkRequest request(apiEndpoint);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", QString("Bearer %1").arg(apiKey).toUtf8());

    QJsonObject jsonObj;
    jsonObj["model"] = "deepseek-chat";

    QJsonArray messagesArray;
    QJsonObject systemMessage;
    systemMessage["role"] = "system";
    systemMessage["content"] = "你是一个友好的AI助手，会用简洁有趣专业的语言回答问题。对话默认使用英文";
    messagesArray.append(systemMessage);

    QJsonObject userMessage;
    userMessage["role"] = "user";
    userMessage["content"] = message;
    messagesArray.append(userMessage);

    jsonObj["messages"] = messagesArray;
    jsonObj["temperature"] = 0.7;
    jsonObj["max_tokens"] = 1000;

    QJsonDocument doc(jsonObj);
    QByteArray data = doc.toJson();

    qDebug() << "Sending request to OpenRouter:" << apiEndpoint;
    qDebug() << "Request data size:" << data.size();

    QNetworkReply *reply = networkManager->post(request, data);
    activeReplies.append(reply); // 添加到活跃请求列表

    // 使用弱引用来避免悬挂指针问题
    connect(reply, &QNetworkReply::finished, this, [this, reply]() {
        // 从活跃列表中移除
        QMutexLocker locker(&mutex);
        activeReplies.removeOne(reply);
        locker.unlock();

        if (reply->error() == QNetworkReply::NoError) {
            QByteArray responseData = reply->readAll();
            qDebug() << "Response received, size:" << responseData.size();

            // 安全解析JSON响应
            QJsonParseError parseError;
            QJsonDocument responseDoc = QJsonDocument::fromJson(responseData, &parseError);
            
            if (parseError.error != QJsonParseError::NoError) {
                QString errorMsg = "JSON parse error: " + parseError.errorString();
                qDebug() << errorMsg;
                emit errorOccurred(errorMsg);
            } else {
                QJsonObject responseObj = responseDoc.object();
                
                if (responseObj.contains("choices") && responseObj["choices"].isArray()) {
                    QJsonArray choices = responseObj["choices"].toArray();
                    if (!choices.isEmpty()) {
                        QJsonObject choice = choices[0].toObject();
                        if (choice.contains("message")) {
                            QJsonObject messageObj = choice["message"].toObject();
                            QString content = messageObj["content"].toString();
                            emit responseReceived(content);
                        } else {
                            emit errorOccurred("No message in response");
                        }
                    } else {
                        emit errorOccurred("Empty choices array");
                    }
                } else {
                    QString errorMsg = "Invalid response format";
                    qDebug() << errorMsg;
                    emit errorOccurred(errorMsg);
                }
            }
        } else {
            QString errorMsg = QString("Network error: %1\nStatus code: %2")
                .arg(reply->errorString())
                .arg(reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt());
            qDebug() << errorMsg;
            emit errorOccurred(errorMsg);
        }
        
        // 安全清理reply对象
        if(reply->isFinished())
        {
            delete reply;
        }
    });

    // 添加超时处理
    /*
    QTimer::singleShot(30000, this, [this, reply]() {
        if (reply && reply->isRunning()) {
            qDebug() << "Request timed out, aborting...";
            reply->abort();
            emit errorOccurred("Request timed out after 30 seconds");
        }
    });
    */
}

void DeepSeekClient::cancelAllRequests()
{
    // 取消所有活跃的请求
    for (QNetworkReply *reply : activeReplies) {
        if (reply && reply->isRunning()) {
            reply->abort();
        }
        reply->deleteLater();
    }
    activeReplies.clear();
}
