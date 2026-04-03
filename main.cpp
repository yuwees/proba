#include "mainwindow.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    
    // Загрузка стилей
    QFile styleFile(":/styles.qss");
    styleFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(styleFile.readAll());
    qApp->setStyleSheet(styleSheet);
    
    MainWindow w;
    w.show();
    return a.exec();
}