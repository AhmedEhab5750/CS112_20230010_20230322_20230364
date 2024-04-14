#include <QApplication>
#include "mainwindow.h"
#include "Image_Class.h"
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow window;
    window.setWindowTitle("BabyPhotoshop");
    window.show();
    return app.exec();
}
