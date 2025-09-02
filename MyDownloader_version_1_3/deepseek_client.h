#ifndef DEEPSEEK_CLIENT_H
#define DEEPSEEK_CLIENT_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QList>
#include <QMutex>

class DeepSeekClient : public QObject
{
    Q_OBJECT

public:
    explicit DeepSeekClient(QObject *parent = nullptr);
    ~DeepSeekClient();
    void setApiKey(const QString &apiKey);
    void sendMessage(const QString &message);
    void cancelAllRequests(); // 取消所有未完成的请求

signals:
    void responseReceived(const QString &response);
    void errorOccurred(const QString &error);

private:
    QNetworkAccessManager *networkManager;
    QString apiKey;
    QString apiEndpoint;
    QList<QNetworkReply*> activeReplies; // 存储所有活跃的请求
    QMutex mutex; // 保护活跃请求列表的互斥锁
};

#endif // DEEPSEEK_CLIENT_H
