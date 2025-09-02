#include "mainwindowai.h"
#include <QVBoxLayout>
#include <QWidget>
#include <QDateTime>
#include <QScrollBar>
#include <QMessageBox>
#include <QSettings>
#include <QInputDialog>
#include <QIcon>
#include <QDebug>

MainWindowAI::MainWindowAI(QWidget *parent)
    : QMainWindow(parent)
{
    // 设置窗口图标
    setWindowIcon(QIcon(":/icon.png"));

    // 创建中心部件
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // 创建主布局
    mainLayout = new QVBoxLayout(centralWidget);

    // 创建聊天显示区域
    chatDisplay = new QTextEdit(this);
    chatDisplay->setReadOnly(true);
    chatDisplay->setStyleSheet("QTextEdit { background-color: #000000; }");
    mainLayout->addWidget(chatDisplay);

    // 创建输入区域
    QHBoxLayout *inputLayout = new QHBoxLayout();

    inputField = new QLineEdit(this);
    inputField->setPlaceholderText("Input your question...");
    inputLayout->addWidget(inputField);

    sendButton = new QPushButton("Send", this);
    inputLayout->addWidget(sendButton);

    clearButton = new QPushButton("Clear", this);
    inputLayout->addWidget(clearButton);

    resetApiKeyButton = new QPushButton("Reset API", this);
    inputLayout->addWidget(resetApiKeyButton);

    mainLayout->addLayout(inputLayout);

    // 连接信号和槽
    connect(sendButton, &QPushButton::clicked, this, &MainWindowAI::handleSendMessage);
    connect(clearButton, &QPushButton::clicked, this, &MainWindowAI::handleClearChat);
    connect(resetApiKeyButton, &QPushButton::clicked, this, &MainWindowAI::handleResetApiKey);
    connect(inputField, &QLineEdit::returnPressed, this, &MainWindowAI::handleSendMessage);

    // 设置窗口标题和大小
    setWindowTitle("MyDownloader AI Assistant(DeepSeek V3.1)");
    resize(600, 400);

    // 初始化DeepSeek客户端
    setupDeepSeek();

    // 添加欢迎消息
    appendMessage("Hello！I'm DeepSeek AI Assistant，what can I help you？", false);
}

MainWindowAI::~MainWindowAI()
{
    delete deepseekClient;
}

void MainWindowAI::setupDeepSeek()
{
    deepseekClient = new DeepSeekClient(this);

    // 从设置中读取API密钥
    QSettings settings("YourCompany", "DeepSeekChat");
    QString apiKey = settings.value("apiKey").toString();

    if (apiKey.isEmpty()) {
        // 如果没有保存的API密钥，弹出对话框请求输入
        bool ok;
        apiKey = QInputDialog::getText(this, "DeepSeek API",
                                       "Please input DeepSeek API KEY:", QLineEdit::Password,
                                       "", &ok);

        if (ok && !apiKey.isEmpty()) {
            settings.setValue("apiKey", apiKey);
        }
    }

    deepseekClient->setApiKey(apiKey);

    // 连接信号
    connect(deepseekClient, &DeepSeekClient::responseReceived,
            this, &MainWindowAI::handleAIResponse);
    connect(deepseekClient, &DeepSeekClient::errorOccurred,
            this, &MainWindowAI::handleAIError);
}
void MainWindowAI::resetApiKey()
{
    QSettings settings("YourCompany", "DeepSeekChat");
    settings.remove("apiKey"); // 删除旧的API密钥

    bool ok;
    QString apiKey = QInputDialog::getText(this, "DeepSeek API",
                                           "Please input DeepSeek API KEY:", QLineEdit::Password,
                                           "", &ok);

    if (ok && !apiKey.isEmpty()) {
        settings.setValue("apiKey", apiKey);
        deepseekClient->setApiKey(apiKey);
        appendMessage("API KEY refreshed!", false);
    } else {
        appendMessage("API KEY didn't change，please try later", false);
    }
}

void MainWindowAI::handleResetApiKey()
{
    resetApiKey();
}
void MainWindowAI::handleSendMessage()
{
    QString userInput = inputField->text().trimmed();
    if (userInput.isEmpty()) {
        return;
    }

    // 显示用户消息
    appendMessage(userInput, true);
    inputField->clear();

    // 发送消息到DeepSeek
    deepseekClient->sendMessage(userInput);
}

void MainWindowAI::handleClearChat()
{
    chatDisplay->clear();
    appendMessage("Hello！I'm DeepSeek AI Assistant，what can I help you？", false);
}

void MainWindowAI::handleAIResponse(const QString &response)
{
    appendMessage(response, false);
}

void MainWindowAI::handleAIError(const QString &error)
{
    // 显示错误信息，但不会导致程序崩溃
    qDebug() << "AI Error:" << error;
    QMessageBox::warning(this, "Error", "AI Response Error: " + error);
}

void MainWindowAI::appendMessage(const QString &message, bool isUser)
{
    QString timestamp = QDateTime::currentDateTime().toString("hh:mm:ss");
    QString formattedMessage = QString("[%1] %2: %3\n")
                                   .arg(timestamp)
                                   .arg(isUser ? "You" : "AI")
                                   .arg(message);

    chatDisplay->append(formattedMessage);

    // 滚动到底部
    QScrollBar *scrollbar = chatDisplay->verticalScrollBar();
    scrollbar->setValue(scrollbar->maximum());
}
