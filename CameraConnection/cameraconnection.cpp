#include "cameraconnection.h"
#include "ui_cameraconnection.h"

#include <QMessageBox>
#include <QCameraInfo>
#include <QCameraImageCapture>
#include <QDebug>
#include <QApplication>
#include <QWindow>
#include <QPixmap>

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>

CameraConnection::CameraConnection(QWidget *parent) : QMainWindow(parent), ui(new Ui::CameraConnection) {
    ui->setupUi(this);

    if(checkCameras()){
        QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
        foreach (const QCameraInfo &cameraInfo, cameras) {
            qDebug() << "Name: " << cameraInfo.deviceName();
            qDebug() << "Description: " << cameraInfo.description();
            qDebug() << "Orientation: " << cameraInfo.orientation();
            qDebug() << "Position: " << cameraInfo.position();
            qDebug() << "Cam default: " << cameraInfo.defaultCamera() << endl;
        }
        this->SetCbListCam(cameras);
    }



    ui->bt_capture->setEnabled(false);
    ui->bt_disconnect->setEnabled(false);

    ui->lcdNumber->display("00:00:00");
}

CameraConnection::~CameraConnection() {
    delete camera;
    delete viewFinder;
    delete imageCapture;
    delete ui;
}

void CameraConnection::SetCbListCam(QList<QCameraInfo> &cams){
    QStringList camDescription;
    foreach (const QCameraInfo oneCam, cams) {
        this->camNames.append(oneCam.deviceName());
        camDescription.append(oneCam.description());
    }
    ui->combo_selectDevice->addItems(camDescription);
}

bool CameraConnection::checkCameras(){

    int numCameras = QCameraInfo::availableCameras().count();
    if(numCameras > 0){
        qDebug() << numCameras << "cameras detected." << endl;
        return true;
    } else {
        qDebug() << "No cameras were detected." << endl;
        return false;
    }
}

void CameraConnection::on_bt_connect_clicked(){
    QByteArray myCamera;

    if(ui->combo_selectDevice->currentIndex() > 0){
        //myCamera = ui->combo_selectDevice->itemText(ui->combo_selectDevice->currentIndex()).toUtf8();
        myCamera = this->camNames[ui->combo_selectDevice->currentIndex() - 1].toUtf8();

        camera = new QCamera(myCamera);

        viewFinder = new QCameraViewfinder(ui->lb_screen);

        /* Call function OpenCam() */
        viewFinder->setFixedWidth(ui->lb_screen->width());
        viewFinder->setFixedHeight(ui->lb_screen->height());

        /* Set my ViewFinder Widget in ViewFinder object QCamera */
        camera->setViewfinder(viewFinder);

        /* Show ViewFinder */
        viewFinder->show();

         /* Start capture video */
        camera->start();

        ui->bt_connect->setEnabled(false);
        ui->combo_selectDevice->setEnabled(false);

        ui->rb_photo->setEnabled(true);
        ui->rb_photo->setChecked(true);
        ui->bt_capture->setEnabled(true);

        ui->rb_video->setEnabled(true);
        ui->rb_video->setChecked(false);
        ui->bt_record->setEnabled(false);
        ui->bt_stop->setEnabled(false);

        ui->bt_disconnect->setEnabled(true);
    }else{
        //QMessageBox::warning(this, "Error", "Select a device", QMessageBox::Ok);
        ui->statusBar->showMessage("Select a device", 3000);
    }
}

void CameraConnection::on_bt_disconnect_clicked(){
    camera->stop();

    delete camera;
    delete viewFinder;

    ui->bt_connect->setEnabled(true);
    ui->bt_disconnect->setEnabled(false);
    ui->combo_selectDevice->setEnabled(true);

    ui->bt_capture->setEnabled(false);
    ui->rb_photo->setEnabled(false);
    ui->rb_photo->setChecked(true);

    ui->rb_video->setEnabled(false);
    ui->rb_video->setChecked(false);
    ui->bt_record->setEnabled(false);
    ui->bt_stop->setEnabled(false);

    ui->bt_return->setEnabled(false);

    ui->lb_screen->clear();
    ui->lb_screen->setStyleSheet("QLabel{background-color:black}");
}

void CameraConnection::on_bt_exit_clicked(){
    QMessageBox::StandardButton resposta = QMessageBox::question(this, "Camera Connection", "Do you really want to close the application?", QMessageBox::Yes | QMessageBox::No);
    if (resposta == QMessageBox::Yes){
        QApplication::quit();
        //close();
    }
}

void CameraConnection::on_bt_capture_clicked(){
    // Defining QImageCapture object
    imageCapture = new QCameraImageCapture(camera);

    connect(imageCapture, SIGNAL(imageCaptured(int, const QImage)), this, SLOT(imageCaptured(int, const QImage)));

    imageCapture->setCaptureDestination(QCameraImageCapture::CaptureToBuffer);

    camera->setCaptureMode(QCamera::CaptureStillImage);
    camera->start();
    //on half pressed shutter button
    camera->searchAndLock();

    //on shutter button pressed
    int id = imageCapture->capture();

    //on shutter button released
    camera->unlock();

    ui->bt_return->setEnabled(true);
}

void CameraConnection::imageCaptured(int id, const QImage image){
    //imageCapture->cancelCapture();
    /*
    image.save("/home/ayrton/Pictures/salvadao.jpg");

    cv::Mat I = cv::imread("/home/ayrton/Pictures/salvadao.jpg", 0);

    cv::namedWindow( "Display window: " + QString::number(id).toStdString(), cv::WINDOW_AUTOSIZE );
    cv::imshow("Display window: " + QString::number(id).toStdString(), I);
    cv::waitKey(0);
    */
    //image.scaled(ui->lb_screen->width(), ui->lb_screen->height(), Qt::KeepAspectRatio);
    viewFinder->close();
    ui->lb_screen->setPixmap(QPixmap::fromImage(image));
}

void CameraConnection::on_bt_record_clicked(){
    //ui->bt_return->setEnabled(true);
    if(!this->isPlaying){
        ui->bt_play->setText("Pause");
        ui->bt_play->setIcon(QIcon(":/imgs/pause.png"));
        this->isPlaying = true;
    }else{
        ui->bt_play->setText("Play");
        ui->bt_play->setIcon(QIcon(":/imgs/play.png"));
        this->isPlaying = false;
    }

    ui->statusBar->showMessage("Not implemented yet.");
}

void CameraConnection::on_bt_stop_clicked(){
    //ui->bt_return->setEnabled(false);
    ui->statusBar->showMessage("Not implemented yet.");
}

void CameraConnection::on_rb_photo_clicked(){
    ui->bt_return->setEnabled(false);

    ui->bt_capture->setEnabled(true);

    ui->rb_video->setChecked(false);
    ui->bt_play->setEnabled(false);
    ui->bt_stop->setEnabled(false);
}

void CameraConnection::on_rb_video_clicked(){
    ui->bt_return->setEnabled(false);

    ui->bt_play->setEnabled(true);
    ui->bt_stop->setEnabled(false);

    ui->rb_photo->setChecked(false);
    ui->bt_capture->setEnabled(false);
}

void CameraConnection::on_bt_return_clicked(){
    viewFinder->show();
}
