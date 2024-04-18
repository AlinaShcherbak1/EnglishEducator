#include "mainmenu.h"
#include <QApplication>
#include <QStyle>
#include <QRect>
#include <QGuiApplication>
#include <QScreen>
#include <QDebug>

int my_x;
int my_y;


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainMenu mainWindow;
    mainWindow.setWindowState(Qt::WindowMaximized);
    mainWindow.show();
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
        my_x = (screenGeometry.width() - mainWindow.width()) / 2;
        my_y = (screenGeometry.height() - mainWindow.height()) / 2;
        screenWidth = screenGeometry.width();
        screenHeight = screenGeometry.height();
    return app.exec();
}
