/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *Grey_f1;
    QPushButton *Black_White_f2;
    QPushButton *Invert_f3;
    QPushButton *Merge_f4;
    QPushButton *Flip_f5;
    QPushButton *Rotate_f6;
    QPushButton *Brightness_f7;
    QPushButton *Crop_f8;
    QPushButton *Frame_f9;
    QPushButton *Edges_f10;
    QPushButton *Resize_f11;
    QPushButton *Blur_f12;
    QPushButton *Sun_f13;
    QPushButton *OilPainting_f14;
    QPushButton *TV_f15;
    QPushButton *Purple_f16;
    QPushButton *InfraRed_f17;
    QPushButton *Skew_f18;
    QPushButton *WhiteRed_e1;
    QPushButton *Blood_e2;
    QPushButton *RedGreen_e3;
    QPushButton *XRay_e4;
    QPushButton *LoadImage;
    QPushButton *SaveImage;
    QPushButton *ResetEffects;
    QLabel *Picture;
    QPushButton *MergeC1;
    QPushButton *MergeC2;
    QPushButton *FlipH;
    QPushButton *FlipV;
    QSlider *BrightSl;
    QPushButton *RotateL;
    QPushButton *RotateR;
    QPushButton *FrameB;
    QPushButton *FrameR;
    QPushButton *FrameBW;
    QPushButton *FrameG;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        Grey_f1 = new QPushButton(centralwidget);
        Grey_f1->setObjectName("Grey_f1");
        Grey_f1->setGeometry(QRect(650, 0, 101, 31));
        Black_White_f2 = new QPushButton(centralwidget);
        Black_White_f2->setObjectName("Black_White_f2");
        Black_White_f2->setGeometry(QRect(650, 40, 101, 31));
        Invert_f3 = new QPushButton(centralwidget);
        Invert_f3->setObjectName("Invert_f3");
        Invert_f3->setGeometry(QRect(650, 80, 101, 31));
        Merge_f4 = new QPushButton(centralwidget);
        Merge_f4->setObjectName("Merge_f4");
        Merge_f4->setGeometry(QRect(650, 120, 101, 31));
        Flip_f5 = new QPushButton(centralwidget);
        Flip_f5->setObjectName("Flip_f5");
        Flip_f5->setGeometry(QRect(650, 160, 101, 31));
        Rotate_f6 = new QPushButton(centralwidget);
        Rotate_f6->setObjectName("Rotate_f6");
        Rotate_f6->setGeometry(QRect(650, 200, 101, 31));
        Brightness_f7 = new QPushButton(centralwidget);
        Brightness_f7->setObjectName("Brightness_f7");
        Brightness_f7->setGeometry(QRect(650, 240, 101, 31));
        Crop_f8 = new QPushButton(centralwidget);
        Crop_f8->setObjectName("Crop_f8");
        Crop_f8->setGeometry(QRect(650, 280, 101, 31));
        Frame_f9 = new QPushButton(centralwidget);
        Frame_f9->setObjectName("Frame_f9");
        Frame_f9->setGeometry(QRect(650, 320, 101, 31));
        Edges_f10 = new QPushButton(centralwidget);
        Edges_f10->setObjectName("Edges_f10");
        Edges_f10->setGeometry(QRect(540, 0, 101, 31));
        Resize_f11 = new QPushButton(centralwidget);
        Resize_f11->setObjectName("Resize_f11");
        Resize_f11->setGeometry(QRect(540, 40, 101, 31));
        Blur_f12 = new QPushButton(centralwidget);
        Blur_f12->setObjectName("Blur_f12");
        Blur_f12->setGeometry(QRect(540, 80, 101, 31));
        Sun_f13 = new QPushButton(centralwidget);
        Sun_f13->setObjectName("Sun_f13");
        Sun_f13->setGeometry(QRect(540, 120, 101, 31));
        OilPainting_f14 = new QPushButton(centralwidget);
        OilPainting_f14->setObjectName("OilPainting_f14");
        OilPainting_f14->setGeometry(QRect(540, 160, 101, 31));
        TV_f15 = new QPushButton(centralwidget);
        TV_f15->setObjectName("TV_f15");
        TV_f15->setGeometry(QRect(540, 200, 101, 31));
        Purple_f16 = new QPushButton(centralwidget);
        Purple_f16->setObjectName("Purple_f16");
        Purple_f16->setGeometry(QRect(540, 240, 101, 31));
        InfraRed_f17 = new QPushButton(centralwidget);
        InfraRed_f17->setObjectName("InfraRed_f17");
        InfraRed_f17->setGeometry(QRect(540, 280, 101, 31));
        Skew_f18 = new QPushButton(centralwidget);
        Skew_f18->setObjectName("Skew_f18");
        Skew_f18->setGeometry(QRect(540, 320, 101, 31));
        WhiteRed_e1 = new QPushButton(centralwidget);
        WhiteRed_e1->setObjectName("WhiteRed_e1");
        WhiteRed_e1->setGeometry(QRect(430, 0, 101, 31));
        Blood_e2 = new QPushButton(centralwidget);
        Blood_e2->setObjectName("Blood_e2");
        Blood_e2->setGeometry(QRect(430, 40, 101, 31));
        RedGreen_e3 = new QPushButton(centralwidget);
        RedGreen_e3->setObjectName("RedGreen_e3");
        RedGreen_e3->setGeometry(QRect(430, 80, 101, 31));
        XRay_e4 = new QPushButton(centralwidget);
        XRay_e4->setObjectName("XRay_e4");
        XRay_e4->setGeometry(QRect(430, 120, 101, 31));
        LoadImage = new QPushButton(centralwidget);
        LoadImage->setObjectName("LoadImage");
        LoadImage->setGeometry(QRect(0, 0, 80, 24));
        SaveImage = new QPushButton(centralwidget);
        SaveImage->setObjectName("SaveImage");
        SaveImage->setGeometry(QRect(80, 0, 80, 24));
        ResetEffects = new QPushButton(centralwidget);
        ResetEffects->setObjectName("ResetEffects");
        ResetEffects->setGeometry(QRect(160, 0, 80, 24));
        Picture = new QLabel(centralwidget);
        Picture->setObjectName("Picture");
        Picture->setGeometry(QRect(8, 35, 400, 200));
        MergeC1 = new QPushButton(centralwidget);
        MergeC1->setObjectName("MergeC1");
        MergeC1->setGeometry(QRect(20, 270, 80, 24));
        MergeC2 = new QPushButton(centralwidget);
        MergeC2->setObjectName("MergeC2");
        MergeC2->setGeometry(QRect(110, 270, 80, 24));
        FlipH = new QPushButton(centralwidget);
        FlipH->setObjectName("FlipH");
        FlipH->setGeometry(QRect(20, 270, 80, 24));
        FlipV = new QPushButton(centralwidget);
        FlipV->setObjectName("FlipV");
        FlipV->setGeometry(QRect(110, 270, 80, 24));
        BrightSl = new QSlider(centralwidget);
        BrightSl->setObjectName("BrightSl");
        BrightSl->setGeometry(QRect(20, 300, 160, 16));
        BrightSl->setMaximum(500);
        BrightSl->setSingleStep(10);
        BrightSl->setValue(100);
        BrightSl->setOrientation(Qt::Horizontal);
        RotateL = new QPushButton(centralwidget);
        RotateL->setObjectName("RotateL");
        RotateL->setGeometry(QRect(20, 270, 80, 24));
        RotateR = new QPushButton(centralwidget);
        RotateR->setObjectName("RotateR");
        RotateR->setGeometry(QRect(110, 270, 80, 24));
        FrameB = new QPushButton(centralwidget);
        FrameB->setObjectName("FrameB");
        FrameB->setGeometry(QRect(110, 270, 80, 24));
        FrameR = new QPushButton(centralwidget);
        FrameR->setObjectName("FrameR");
        FrameR->setGeometry(QRect(20, 270, 80, 24));
        FrameBW = new QPushButton(centralwidget);
        FrameBW->setObjectName("FrameBW");
        FrameBW->setGeometry(QRect(110, 300, 80, 24));
        FrameG = new QPushButton(centralwidget);
        FrameG->setObjectName("FrameG");
        FrameG->setGeometry(QRect(20, 300, 80, 24));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Grey_f1->setText(QCoreApplication::translate("MainWindow", "Grey Filter", nullptr));
        Black_White_f2->setText(QCoreApplication::translate("MainWindow", "Black & White Filter", nullptr));
        Invert_f3->setText(QCoreApplication::translate("MainWindow", "Invert Filter", nullptr));
        Merge_f4->setText(QCoreApplication::translate("MainWindow", "Merge 2 Photos", nullptr));
        Flip_f5->setText(QCoreApplication::translate("MainWindow", "Flip Photo", nullptr));
        Rotate_f6->setText(QCoreApplication::translate("MainWindow", "Rotate Photo", nullptr));
        Brightness_f7->setText(QCoreApplication::translate("MainWindow", "Brightness Editor", nullptr));
        Crop_f8->setText(QCoreApplication::translate("MainWindow", "Crop Photo", nullptr));
        Frame_f9->setText(QCoreApplication::translate("MainWindow", "Add Frame", nullptr));
        Edges_f10->setText(QCoreApplication::translate("MainWindow", "Detect Edges", nullptr));
        Resize_f11->setText(QCoreApplication::translate("MainWindow", "Resize Image", nullptr));
        Blur_f12->setText(QCoreApplication::translate("MainWindow", "Blur Image", nullptr));
        Sun_f13->setText(QCoreApplication::translate("MainWindow", "SunLight Filter", nullptr));
        OilPainting_f14->setText(QCoreApplication::translate("MainWindow", "OilPainting Filter", nullptr));
        TV_f15->setText(QCoreApplication::translate("MainWindow", "TV Noise Filter", nullptr));
        Purple_f16->setText(QCoreApplication::translate("MainWindow", "Purple Filter", nullptr));
        InfraRed_f17->setText(QCoreApplication::translate("MainWindow", "Infra-Red Filter", nullptr));
        Skew_f18->setText(QCoreApplication::translate("MainWindow", "Skew Image", nullptr));
        WhiteRed_e1->setText(QCoreApplication::translate("MainWindow", "White Red Filter", nullptr));
        Blood_e2->setText(QCoreApplication::translate("MainWindow", "Blood Filter", nullptr));
        RedGreen_e3->setText(QCoreApplication::translate("MainWindow", "Red Green Filter", nullptr));
        XRay_e4->setText(QCoreApplication::translate("MainWindow", "X-Ray Filter", nullptr));
        LoadImage->setText(QCoreApplication::translate("MainWindow", "Load Image", nullptr));
        SaveImage->setText(QCoreApplication::translate("MainWindow", "Save Image", nullptr));
        ResetEffects->setText(QCoreApplication::translate("MainWindow", "Reset Effects", nullptr));
        Picture->setText(QString());
        MergeC1->setText(QCoreApplication::translate("MainWindow", "Choice 1", nullptr));
        MergeC2->setText(QCoreApplication::translate("MainWindow", "Choice 2", nullptr));
        FlipH->setText(QCoreApplication::translate("MainWindow", "Horizontal", nullptr));
        FlipV->setText(QCoreApplication::translate("MainWindow", "Vertical", nullptr));
        RotateL->setText(QCoreApplication::translate("MainWindow", "Left", nullptr));
        RotateR->setText(QCoreApplication::translate("MainWindow", "Right", nullptr));
        FrameB->setText(QCoreApplication::translate("MainWindow", "Blue Frame", nullptr));
        FrameR->setText(QCoreApplication::translate("MainWindow", "Red Frame", nullptr));
        FrameBW->setText(QCoreApplication::translate("MainWindow", "Blue & White", nullptr));
        FrameG->setText(QCoreApplication::translate("MainWindow", "Green Frame", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
