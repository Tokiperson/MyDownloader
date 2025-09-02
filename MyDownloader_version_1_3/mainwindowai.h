#ifndef MAINWINDOWAI_H
#define MAINWINDOWAI_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QScrollArea>
#include "deepseek_client.h"


namespace Ui {
class MainWindowAI;
}

class MainWindowAI : public QMainWindow
{
    Q_OBJECT

public:
    MainWindowAI(QWidget *parent = nullptr);
    ~MainWindowAI();

private slots:
    void handleSendMessage();
    void handleClearChat();
    void handleAIResponse(const QString &response);
    void handleAIError(const QString &error);
    void handleResetApiKey();

private:
    void appendMessage(const QString &message, bool isUser);
    void setupDeepSeek();
    void resetApiKey();

    QWidget *centralWidget;
    QVBoxLayout *mainLayout;
    QTextEdit *chatDisplay;
    QLineEdit *inputField;
    QPushButton *sendButton;
    QPushButton *resetApiKeyButton;
    QPushButton *clearButton;
    QScrollArea *scrollArea;
    DeepSeekClient *deepseekClient;
};

#endif // MAINWINDOWAI_H
