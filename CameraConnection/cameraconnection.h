#ifndef CAMERACONNECTION_H
#define CAMERACONNECTION_H

#include <QWidget>
#include <QCamera>
#include <QCameraViewfinder>
#include <QMainWindow>
#include <QCameraImageCapture>
#include <QGraphicsScene>
#include <QMediaRecorder>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

namespace Ui {
    class CameraConnection;
}

class CameraConnection : public QMainWindow
{
    Q_OBJECT

public:
    explicit CameraConnection(QWidget *parent = nullptr);
    ~CameraConnection();

private:
    Ui::CameraConnection *ui;

    QCameraViewfinder *viewFinder;
    QCamera *camera;
    QCameraImageCapture *imageCapture;
    QMediaRecorder *mediaRecorder;
    QStringList camNames;

    // Look for all the cameras available and display them to the user
    bool checkCameras(void);
    bool isPlaying = false;

protected:
    QList<QCameraInfo> devCameras;

private slots:

    // Radiobutton to enable take a picture
    void on_rb_photo_clicked();

    // Button to take a picture from camera
    void on_bt_capture_clicked();

    // Button to stop displaying the picture it was taken
    void on_bt_return_clicked();

    // Radiobutton to enable record a video
    void on_rb_video_clicked();

    // Button to start/pause recording video
    void on_bt_record_clicked();

    // Button to stop recording video
    void on_bt_stop_clicked();

    // Button to exit the application
    void on_bt_exit_clicked();

    // Button to  connect to cammera that was selected
    void on_bt_connect_clicked();

    // Button to connect from cammera that was selected
    void on_bt_disconnect_clicked();

    // Display image captured in the main window of the app
    void imageCaptured(int id, const QImage image);

    void SetCbListCam(QList<QCameraInfo> &cams);
};

#endif // CAMERACONNECTION_H
