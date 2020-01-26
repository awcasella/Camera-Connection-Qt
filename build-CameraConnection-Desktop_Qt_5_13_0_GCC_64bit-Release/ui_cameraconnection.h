/********************************************************************************
** Form generated from reading UI file 'cameraconnection.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERACONNECTION_H
#define UI_CAMERACONNECTION_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CameraConnection
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QRadioButton *rb_video;
    QSplitter *splitter;
    QPushButton *bt_play;
    QPushButton *bt_stop;
    QLCDNumber *lcdNumber;
    QGroupBox *groupBox_2;
    QPushButton *bt_capture;
    QRadioButton *rb_photo;
    QPushButton *bt_return;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *bt_connect;
    QPushButton *bt_disconnect;
    QPushButton *bt_exit;
    QComboBox *combo_selectDevice;
    QLabel *lb_screen;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CameraConnection)
    {
        if (CameraConnection->objectName().isEmpty())
            CameraConnection->setObjectName(QString::fromUtf8("CameraConnection"));
        CameraConnection->resize(900, 650);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CameraConnection->sizePolicy().hasHeightForWidth());
        CameraConnection->setSizePolicy(sizePolicy);
        CameraConnection->setMinimumSize(QSize(900, 650));
        CameraConnection->setMaximumSize(QSize(900, 650));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imgs/spider.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        CameraConnection->setWindowIcon(icon);
        centralWidget = new QWidget(CameraConnection);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setStyleSheet(QString::fromUtf8(""));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(700, 360, 181, 181));
        rb_video = new QRadioButton(groupBox);
        rb_video->setObjectName(QString::fromUtf8("rb_video"));
        rb_video->setEnabled(false);
        rb_video->setGeometry(QRect(9, 30, 161, 21));
        splitter = new QSplitter(groupBox);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(10, 70, 150, 98));
        splitter->setOrientation(Qt::Vertical);
        bt_play = new QPushButton(splitter);
        bt_play->setObjectName(QString::fromUtf8("bt_play"));
        bt_play->setEnabled(false);
        bt_play->setMinimumSize(QSize(150, 30));
        bt_play->setMaximumSize(QSize(150, 30));
        bt_play->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: rgb(136, 138, 133);\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/imgs/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        bt_play->setIcon(icon1);
        splitter->addWidget(bt_play);
        bt_stop = new QPushButton(splitter);
        bt_stop->setObjectName(QString::fromUtf8("bt_stop"));
        bt_stop->setEnabled(false);
        bt_stop->setMaximumSize(QSize(160, 30));
        bt_stop->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: rgb(136, 138, 133);\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/imgs/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        bt_stop->setIcon(icon2);
        splitter->addWidget(bt_stop);
        lcdNumber = new QLCDNumber(splitter);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setMaximumSize(QSize(160, 30));
        lcdNumber->setDigitCount(8);
        splitter->addWidget(lcdNumber);
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(700, 170, 181, 131));
        bt_capture = new QPushButton(groupBox_2);
        bt_capture->setObjectName(QString::fromUtf8("bt_capture"));
        bt_capture->setEnabled(false);
        bt_capture->setGeometry(QRect(10, 80, 150, 30));
        bt_capture->setMinimumSize(QSize(0, 30));
        bt_capture->setMaximumSize(QSize(16777215, 30));
        bt_capture->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: rgb(136, 138, 133);\n"
"}"));
        rb_photo = new QRadioButton(groupBox_2);
        rb_photo->setObjectName(QString::fromUtf8("rb_photo"));
        rb_photo->setEnabled(false);
        rb_photo->setGeometry(QRect(10, 30, 161, 21));
        rb_photo->setChecked(true);
        bt_return = new QPushButton(centralWidget);
        bt_return->setObjectName(QString::fromUtf8("bt_return"));
        bt_return->setEnabled(false);
        bt_return->setGeometry(QRect(710, 90, 150, 30));
        bt_return->setMinimumSize(QSize(0, 30));
        bt_return->setMaximumSize(QSize(16777215, 30));
        bt_return->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: rgb(136, 138, 133);\n"
"}"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 10, 646, 574));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(15);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        bt_connect = new QPushButton(widget);
        bt_connect->setObjectName(QString::fromUtf8("bt_connect"));
        bt_connect->setMinimumSize(QSize(210, 30));
        bt_connect->setMaximumSize(QSize(210, 30));
        bt_connect->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: rgb(136, 138, 133);\n"
"}"));

        horizontalLayout->addWidget(bt_connect);

        bt_disconnect = new QPushButton(widget);
        bt_disconnect->setObjectName(QString::fromUtf8("bt_disconnect"));
        bt_disconnect->setMinimumSize(QSize(210, 30));
        bt_disconnect->setMaximumSize(QSize(210, 30));
        bt_disconnect->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: rgb(136, 138, 133);\n"
"}"));

        horizontalLayout->addWidget(bt_disconnect);

        bt_exit = new QPushButton(widget);
        bt_exit->setObjectName(QString::fromUtf8("bt_exit"));
        bt_exit->setMinimumSize(QSize(210, 30));
        bt_exit->setMaximumSize(QSize(210, 30));
        bt_exit->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: rgb(136, 138, 133);\n"
"}"));
        QIcon icon3;
        QString iconThemeName = QString::fromUtf8("exit");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon3 = QIcon::fromTheme(iconThemeName);
        } else {
            icon3.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        bt_exit->setIcon(icon3);
        bt_exit->setCheckable(false);

        horizontalLayout->addWidget(bt_exit);


        verticalLayout->addLayout(horizontalLayout);

        combo_selectDevice = new QComboBox(widget);
        combo_selectDevice->addItem(QString());
        combo_selectDevice->setObjectName(QString::fromUtf8("combo_selectDevice"));
        combo_selectDevice->setMinimumSize(QSize(640, 30));
        combo_selectDevice->setMaximumSize(QSize(640, 30));
        combo_selectDevice->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"	color: rgb(0, 0, 0);\n"
"	background-color: rgb(255,255,255);\n"
"}"));

        verticalLayout->addWidget(combo_selectDevice);

        lb_screen = new QLabel(widget);
        lb_screen->setObjectName(QString::fromUtf8("lb_screen"));
        lb_screen->setMinimumSize(QSize(640, 480));
        lb_screen->setMaximumSize(QSize(640, 480));
        lb_screen->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	background-color: rgb(0,0,0);\n"
"}"));

        verticalLayout->addWidget(lb_screen);

        CameraConnection->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CameraConnection);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 900, 22));
        CameraConnection->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CameraConnection);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        CameraConnection->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CameraConnection);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        CameraConnection->setStatusBar(statusBar);

        retranslateUi(CameraConnection);

        QMetaObject::connectSlotsByName(CameraConnection);
    } // setupUi

    void retranslateUi(QMainWindow *CameraConnection)
    {
        CameraConnection->setWindowTitle(QCoreApplication::translate("CameraConnection", "Parker - A Camera Connection Software", nullptr));
        groupBox->setTitle(QCoreApplication::translate("CameraConnection", "Video", nullptr));
        rb_video->setText(QCoreApplication::translate("CameraConnection", "Enable video mode", nullptr));
        bt_play->setText(QCoreApplication::translate("CameraConnection", "Play", nullptr));
        bt_stop->setText(QCoreApplication::translate("CameraConnection", "Stop", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("CameraConnection", "Photo", nullptr));
        bt_capture->setText(QCoreApplication::translate("CameraConnection", "Capture", nullptr));
        rb_photo->setText(QCoreApplication::translate("CameraConnection", "Enable photo mode", nullptr));
        bt_return->setText(QCoreApplication::translate("CameraConnection", "Return", nullptr));
        bt_connect->setText(QCoreApplication::translate("CameraConnection", "Connect", nullptr));
        bt_disconnect->setText(QCoreApplication::translate("CameraConnection", "Disconnect", nullptr));
        bt_exit->setText(QCoreApplication::translate("CameraConnection", " Exit", nullptr));
#if QT_CONFIG(shortcut)
        bt_exit->setShortcut(QCoreApplication::translate("CameraConnection", "Ctrl+W", nullptr));
#endif // QT_CONFIG(shortcut)
        combo_selectDevice->setItemText(0, QCoreApplication::translate("CameraConnection", "Select device", nullptr));

        lb_screen->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CameraConnection: public Ui_CameraConnection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERACONNECTION_H
