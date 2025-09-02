#include "login.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    // 设置应用程序的属性，确保主窗口关闭后应用程序不会退出
    //a.setQuitOnLastWindowClosed(false);
    
    login s;
    s.show();
    
    return a.exec();
}
