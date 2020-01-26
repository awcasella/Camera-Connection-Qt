#include "cameraconnection.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //a.setWindowIcon(QIcon("../imgs/shield.png"));
    CameraConnection w;
    w.show();

    return a.exec();
}
