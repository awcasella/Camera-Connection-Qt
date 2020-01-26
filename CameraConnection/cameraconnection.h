#ifndef CAMERACONNECTION_H
#define CAMERACONNECTION_H

#include <QWidget>
#include <QCamera>
#include <QCameraViewfinder>
#include <QMainWindow>
#include <QCameraImageCapture>
#include <QGraphicsScene>

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
    void SetCbListCam(QList<QCameraInfo> &cams);

public slots:
    void on_bt_exit_clicked();
    void on_bt_connect_clicked();
    void on_bt_disconnect_clicked();
    void on_bt_capture_clicked();

    void imageCaptured(int id, const QImage image);

private:
    Ui::CameraConnection *ui;

    QCameraViewfinder *viewFinder;
    QCamera *camera;
    QCameraImageCapture *imageCapture;
    QStringList camNames;

    bool checkCameras(void);
    bool isPlaying = false;

protected:
    QList<QCameraInfo> devCameras;
private slots:
    void on_bt_play_clicked();
    void on_bt_stop_clicked();
    void on_rb_photo_clicked();
    void on_rb_video_clicked();
    void on_bt_return_clicked();
};

#endif // CAMERACONNECTION_H
