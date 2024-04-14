#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Functions.h"
#include <QFileDialog>
#include <QPixmap>
#include <QInputDialog>
Image image1;
Image image2;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->MergeC1->setVisible(false);
    ui->MergeC2->setVisible(false);
    ui->FlipH->setVisible(false);
    ui->FlipV->setVisible(false);
    ui->BrightSl->setVisible(false);
    ui->RotateL->setVisible(false);
    ui->RotateR->setVisible(false);
    ui->FrameR->setVisible(false);
    ui->FrameB->setVisible(false);
    ui->FrameG->setVisible(false);
    ui->FrameBW->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_LoadImage_clicked()
{
    name1 = QFileDialog::getOpenFileName(this, "Open File", "C://");
    if(name1 != ""){
        image1.loadNewImage(name1.toStdString());
    }
    QPixmap pix(name1);
    ui->Picture->setPixmap(pix.scaled(400,200,Qt::KeepAspectRatio));
}


void MainWindow::on_SaveImage_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "C://", tr("Images (*.jpg *.png)"));
    if(fileName != ""){
        image1.saveImage(fileName.toStdString());
    }
}


void MainWindow::on_ResetEffects_clicked()
{
    if(name1 != ""){
        QPixmap pix(name1);
        image1.loadNewImage(name1.toStdString());
        image1.saveImage("temp.jpg");
        image1.saveImage("temp1.jpg");
        ui->Picture->setPixmap(pix.scaled(400,200,Qt::KeepAspectRatio));
    }
}

void MainWindow::on_Grey_f1_clicked()
{
    ui->MergeC1->setVisible(false);
    ui->MergeC2->setVisible(false);
    ui->FlipH->setVisible(false);
    ui->FlipV->setVisible(false);
    ui->BrightSl->setVisible(false);
    ui->RotateL->setVisible(false);
    ui->RotateR->setVisible(false);
    ui->FrameR->setVisible(false);
    ui->FrameB->setVisible(false);
    ui->FrameG->setVisible(false);
    ui->FrameBW->setVisible(false);
    if(name1 != ""){
        to_grey_f1(image1);
        image1.saveImage("temp.jpg");
        QString absolutePath = QDir::currentPath() + "/temp.jpg";
        QPixmap pix(absolutePath);
        ui->Picture->setPixmap(pix.scaled(400,200,Qt::KeepAspectRatio));
    }
}


void MainWindow::on_Black_White_f2_clicked()
{
    ui->MergeC1->setVisible(false);
    ui->MergeC2->setVisible(false);
    ui->FlipH->setVisible(false);
    ui->FlipV->setVisible(false);
    ui->BrightSl->setVisible(false);
    ui->RotateL->setVisible(false);
    ui->RotateR->setVisible(false);
    ui->FrameR->setVisible(false);
    ui->FrameB->setVisible(false);
    ui->FrameG->setVisible(false);
    ui->FrameBW->setVisible(false);
    if(name1 != ""){
        to_black_and_white_f2(image1);
        image1.saveImage("temp.jpg");
        QString absolutePath = QDir::currentPath() + "/temp.jpg";
        QPixmap pix(absolutePath);
        ui->Picture->setPixmap(pix.scaled(400,200,Qt::KeepAspectRatio));
    }
}



void MainWindow::on_Invert_f3_clicked()
{
    ui->MergeC1->setVisible(false);
    ui->MergeC2->setVisible(false);
    ui->FlipH->setVisible(false);
    ui->FlipV->setVisible(false);
    ui->BrightSl->setVisible(false);
    ui->RotateL->setVisible(false);
    ui->RotateR->setVisible(false);
    ui->FrameR->setVisible(false);
    ui->FrameB->setVisible(false);
    ui->FrameG->setVisible(false);
    ui->FrameBW->setVisible(false);
    if(name1 != ""){
        invert_colors_f3(image1);
        image1.saveImage("temp.jpg");
        QString absolutePath = QDir::currentPath() + "/temp.jpg";
        QPixmap pix(absolutePath);
        ui->Picture->setPixmap(pix.scaled(400,200,Qt::KeepAspectRatio));
    }
}


void MainWindow::on_Merge_f4_clicked()
{
    ui->MergeC1->setVisible(false);
    ui->MergeC2->setVisible(false);
    ui->FlipH->setVisible(false);
    ui->FlipV->setVisible(false);
    ui->BrightSl->setVisible(false);
    ui->RotateL->setVisible(false);
    ui->RotateR->setVisible(false);
    ui->FrameR->setVisible(false);
    ui->FrameB->setVisible(false);
    ui->FrameG->setVisible(false);
    ui->FrameBW->setVisible(false);
    name2 = QFileDialog::getOpenFileName(this, "Open File", "C://");
    if(name2 != ""){
        image2.loadNewImage(name2.toStdString());
        ui->MergeC1->setVisible(true);
        ui->MergeC2->setVisible(true);
    }

}

void MainWindow::on_MergeC1_clicked()
{
    mergeImages_f4(image1,image2,1);
    image1.saveImage("temp.jpg");
    QString absolutePath = QDir::currentPath() + "/temp.jpg";
    QPixmap pix(absolutePath);
    ui->Picture->setPixmap(pix.scaled(400,200,Qt::KeepAspectRatio));
}


void MainWindow::on_MergeC2_clicked()
{
    mergeImages_f4(image1,image2,2);
    image1.saveImage("temp.jpg");
    QString absolutePath = QDir::currentPath() + "/temp.jpg";
    QPixmap pix(absolutePath);
    ui->Picture->setPixmap(pix.scaled(400,200,Qt::KeepAspectRatio));
}

void MainWindow::on_Flip_f5_clicked()
{
    ui->MergeC1->setVisible(false);
    ui->MergeC2->setVisible(false);
    ui->FlipH->setVisible(false);
    ui->FlipV->setVisible(false);
    ui->BrightSl->setVisible(false);
    ui->RotateL->setVisible(false);
    ui->RotateR->setVisible(false);
    ui->FrameR->setVisible(false);
    ui->FrameB->setVisible(false);
    ui->FrameG->setVisible(false);
    ui->FrameBW->setVisible(false);
    if(name1 != ""){
        ui->FlipH->setVisible(true);
        ui->FlipV->setVisible(true);
    }
}

void MainWindow::on_FlipH_clicked()
{
    flip_horizontally_f5(image1);
    image1.saveImage("temp.jpg");
    QString absolutePath = QDir::currentPath() + "/temp.jpg";
    QPixmap pix(absolutePath);
    ui->Picture->setPixmap(pix.scaled(400,200,Qt::KeepAspectRatio));
}


void MainWindow::on_FlipV_clicked()
{
    flip_vertically_f5(image1);
    image1.saveImage("temp.jpg");
    QString absolutePath = QDir::currentPath() + "/temp.jpg";
    QPixmap pix(absolutePath);
    ui->Picture->setPixmap(pix.scaled(400,200,Qt::KeepAspectRatio));
}

void MainWindow::on_Rotate_f6_clicked()
{
    ui->MergeC1->setVisible(false);
    ui->MergeC2->setVisible(false);
    ui->FlipH->setVisible(false);
    ui->FlipV->setVisible(false);
    ui->BrightSl->setVisible(false);
    ui->RotateL->setVisible(false);
    ui->RotateR->setVisible(false);
    ui->FrameR->setVisible(false);
    ui->FrameB->setVisible(false);
    ui->FrameG->setVisible(false);
    ui->FrameBW->setVisible(false);
    if(name1 != ""){
        ui->RotateL->setVisible(true);
        ui->RotateR->setVisible(true);
    }
}

void MainWindow::on_RotateL_clicked()
{
    image1.loadNewImage("temp.jpg");
    rotate_left_f6(image1);
    image1.saveImage("temp.jpg");
    QString absolutePath = QDir::currentPath() + "/temp.jpg";
    QPixmap pix(absolutePath);
    ui->Picture->setPixmap(pix.scaled(400,200,Qt::KeepAspectRatio));
}


void MainWindow::on_RotateR_clicked()
{
    image1.loadNewImage("temp.jpg");
    rotate_right_f6(image1);
    image1.saveImage("temp.jpg");
    QString absolutePath = QDir::currentPath() + "/temp.jpg";
    QPixmap pix(absolutePath);
    ui->Picture->setPixmap(pix.scaled(400,200,Qt::KeepAspectRatio));
}

void MainWindow::on_Brightness_f7_clicked()
{
    ui->MergeC1->setVisible(false);
    ui->MergeC2->setVisible(false);
    ui->FlipH->setVisible(false);
    ui->FlipV->setVisible(false);
    ui->BrightSl->setVisible(false);
    ui->RotateL->setVisible(false);
    ui->RotateR->setVisible(false);
    ui->FrameR->setVisible(false);
    ui->FrameB->setVisible(false);
    ui->FrameG->setVisible(false);
    ui->FrameBW->setVisible(false);
    if(name1 != ""){
        ui->BrightSl->setVisible(true);
        image1.saveImage("temp.jpg");
    }
}

void MainWindow::on_BrightSl_sliderReleased()
{
    int sliderValue = ui->BrightSl->value();
    float brightness = float(sliderValue) / 100.0;
    image1.loadNewImage("temp.jpg");
    brightness_f7(image1, brightness);
    image1.saveImage("temp1.jpg");
    QString absolutePath = QDir::currentPath() + "/temp1.jpg";
    QPixmap pix(absolutePath);
    ui->Picture->setPixmap(pix.scaled(400,200,Qt::KeepAspectRatio));
}


void MainWindow::on_Crop_f8_clicked()
{
    ui->MergeC1->setVisible(false);
    ui->MergeC2->setVisible(false);
    ui->FlipH->setVisible(false);
    ui->FlipV->setVisible(false);
    ui->BrightSl->setVisible(false);
    ui->RotateL->setVisible(false);
    ui->RotateR->setVisible(false);
    ui->FrameR->setVisible(false);
    ui->FrameB->setVisible(false);
    ui->FrameG->setVisible(false);
    ui->FrameBW->setVisible(false);
    int X1 = QInputDialog::getInt(this, "Title", "Enter X1:", 0);
    int Y1 = QInputDialog::getInt(this, "Title", "Enter Y1:", 0);
    int wdth = QInputDialog::getInt(this, "Title", "Enter New Width:", 0);
    int hght = QInputDialog::getInt(this, "Title", "Enter New Height:", 0);
    if(X1 < image1.width && Y1 < image1.height && wdth <= image1.width && hght <= image1.height){
        crop_f8(image1, X1, Y1, wdth, hght);
        image1.saveImage("temp.jpg");
        QString absolutePath = QDir::currentPath() + "/temp.jpg";
        QPixmap pix(absolutePath);
        ui->Picture->setPixmap(pix.scaled(400,200,Qt::KeepAspectRatio));
    }
}


void MainWindow::on_Frame_f9_clicked()
{
    ui->MergeC1->setVisible(false);
    ui->MergeC2->setVisible(false);
    ui->FlipH->setVisible(false);
    ui->FlipV->setVisible(false);
    ui->BrightSl->setVisible(false);
    ui->RotateL->setVisible(false);
    ui->RotateR->setVisible(false);
    ui->FrameR->setVisible(false);
    ui->FrameB->setVisible(false);
    ui->FrameG->setVisible(false);
    ui->FrameBW->setVisible(false);
    if(name1 != ""){
        ui->FrameR->setVisible(true);
        ui->FrameB->setVisible(true);
        ui->FrameG->setVisible(true);
        ui->FrameBW->setVisible(true);
    }

}

void MainWindow::on_FrameR_clicked()
{
    if(name1 != ""){
        addFrame_f9(image1, 'A');
        image1.saveImage("temp1.jpg");
        QString absolutePath = QDir::currentPath() + "/temp1.jpg";
        QPixmap pix(absolutePath);
        ui->Picture->setPixmap(pix.scaled(400,200,Qt::KeepAspectRatio));
    }
}

void MainWindow::on_FrameB_clicked()
{
    if(name1 != ""){
        addFrame_f9(image1, 'C');
        image1.saveImage("temp1.jpg");
        QString absolutePath = QDir::currentPath() + "/temp1.jpg";
        QPixmap pix(absolutePath);
        ui->Picture->setPixmap(pix.scaled(400,200,Qt::KeepAspectRatio));
    }
}


void MainWindow::on_FrameG_clicked()
{
    if(name1 != ""){
        addFrame_f9(image1, 'B');
        image1.saveImage("temp1.jpg");
        QString absolutePath = QDir::currentPath() + "/temp1.jpg";
        QPixmap pix(absolutePath);
        ui->Picture->setPixmap(pix.scaled(400,200,Qt::KeepAspectRatio));
    }
}


void MainWindow::on_FrameBW_clicked()
{
    if(name1 != ""){
        int Thick = QInputDialog::getInt(this, "Title", "Enter Frame Thickness:", 0);
        W_and_B_Frame_f9(image1,Thick ,20);
        image1.saveImage("temp1.jpg");
        QString absolutePath = QDir::currentPath() + "/temp1.jpg";
        QPixmap pix(absolutePath);
        ui->Picture->setPixmap(pix.scaled(400,200,Qt::KeepAspectRatio));
    }
}



void MainWindow::on_Edges_f10_clicked()
{
    ui->MergeC1->setVisible(false);
    ui->MergeC2->setVisible(false);
    ui->FlipH->setVisible(false);
    ui->FlipV->setVisible(false);
    ui->BrightSl->setVisible(false);
    ui->RotateL->setVisible(false);
    ui->RotateR->setVisible(false);
    ui->FrameR->setVisible(false);
    ui->FrameB->setVisible(false);
    ui->FrameG->setVisible(false);
    ui->FrameBW->setVisible(false);
    if(name1 != ""){
        detectEdges_f10(image1);
        image1.saveImage("temp.jpg");
        QString absolutePath = QDir::currentPath() + "/temp.jpg";
        QPixmap pix(absolutePath);
        ui->Picture->setPixmap(pix.scaled(400,200,Qt::KeepAspectRatio));
    }
}


void MainWindow::on_Resize_f11_clicked()
{
    ui->MergeC1->setVisible(false);
    ui->MergeC2->setVisible(false);
    ui->FlipH->setVisible(false);
    ui->FlipV->setVisible(false);
    ui->BrightSl->setVisible(false);
    ui->RotateL->setVisible(false);
    ui->RotateR->setVisible(false);
    ui->FrameR->setVisible(false);
    ui->FrameB->setVisible(false);
    ui->FrameG->setVisible(false);
    ui->FrameBW->setVisible(false);
}


void MainWindow::on_Blur_f12_clicked()
{
    ui->MergeC1->setVisible(false);
    ui->MergeC2->setVisible(false);
    ui->FlipH->setVisible(false);
    ui->FlipV->setVisible(false);
    ui->BrightSl->setVisible(false);
    ui->RotateL->setVisible(false);
    ui->RotateR->setVisible(false);
    ui->FrameR->setVisible(false);
    ui->FrameB->setVisible(false);
    ui->FrameG->setVisible(false);
    ui->FrameBW->setVisible(false);
}


void MainWindow::on_Sun_f13_clicked()
{
    ui->MergeC1->setVisible(false);
    ui->MergeC2->setVisible(false);
    ui->FlipH->setVisible(false);
    ui->FlipV->setVisible(false);
    ui->BrightSl->setVisible(false);
    ui->RotateL->setVisible(false);
    ui->RotateR->setVisible(false);
    ui->FrameR->setVisible(false);
    ui->FrameB->setVisible(false);
    ui->FrameG->setVisible(false);
    ui->FrameBW->setVisible(false);
    if(name1 != ""){
        wano_Sunlight_f13(image1);
        image1.saveImage("temp.jpg");
        QString absolutePath = QDir::currentPath() + "/temp.jpg";
        QPixmap pix(absolutePath);
        ui->Picture->setPixmap(pix.scaled(400,200,Qt::KeepAspectRatio));
    }
}


void MainWindow::on_OilPainting_f14_clicked()
{
    ui->MergeC1->setVisible(false);
    ui->MergeC2->setVisible(false);
    ui->FlipH->setVisible(false);
    ui->FlipV->setVisible(false);
    ui->BrightSl->setVisible(false);
    ui->RotateL->setVisible(false);
    ui->RotateR->setVisible(false);
    ui->FrameR->setVisible(false);
    ui->FrameB->setVisible(false);
    ui->FrameG->setVisible(false);
    ui->FrameBW->setVisible(false);
}


void MainWindow::on_TV_f15_clicked()
{
    ui->MergeC1->setVisible(false);
    ui->MergeC2->setVisible(false);
    ui->FlipH->setVisible(false);
    ui->FlipV->setVisible(false);
    ui->BrightSl->setVisible(false);
    ui->RotateL->setVisible(false);
    ui->RotateR->setVisible(false);
    ui->FrameR->setVisible(false);
    ui->FrameB->setVisible(false);
    ui->FrameG->setVisible(false);
    ui->FrameBW->setVisible(false);
    if(name1 != ""){
        applyTVNoiseFilter_f15(image1);
        image1.saveImage("temp.jpg");
        QString absolutePath = QDir::currentPath() + "/temp.jpg";
        QPixmap pix(absolutePath);
        ui->Picture->setPixmap(pix.scaled(400,200,Qt::KeepAspectRatio));
    }
}


void MainWindow::on_Purple_f16_clicked()
{
    ui->MergeC1->setVisible(false);
    ui->MergeC2->setVisible(false);
    ui->FlipH->setVisible(false);
    ui->FlipV->setVisible(false);
    ui->BrightSl->setVisible(false);
    ui->RotateL->setVisible(false);
    ui->RotateR->setVisible(false);
    ui->FrameR->setVisible(false);
    ui->FrameB->setVisible(false);
    ui->FrameG->setVisible(false);
    ui->FrameBW->setVisible(false);
    if(name1 != ""){
        wano_purple_f16(image1);
        image1.saveImage("temp.jpg");
        QString absolutePath = QDir::currentPath() + "/temp.jpg";
        QPixmap pix(absolutePath);
        ui->Picture->setPixmap(pix.scaled(400,200,Qt::KeepAspectRatio));
    }
}


void MainWindow::on_InfraRed_f17_clicked()
{
    ui->MergeC1->setVisible(false);
    ui->MergeC2->setVisible(false);
    ui->FlipH->setVisible(false);
    ui->FlipV->setVisible(false);
    ui->BrightSl->setVisible(false);
    ui->RotateL->setVisible(false);
    ui->RotateR->setVisible(false);
    ui->FrameR->setVisible(false);
    ui->FrameB->setVisible(false);
    ui->FrameG->setVisible(false);
    ui->FrameBW->setVisible(false);
    if(name1 != ""){
        to_InfraRed_f17(image1);
        image1.saveImage("temp.jpg");
        QString absolutePath = QDir::currentPath() + "/temp.jpg";
        QPixmap pix(absolutePath);
        ui->Picture->setPixmap(pix.scaled(400,200,Qt::KeepAspectRatio));
    }
}


void MainWindow::on_Skew_f18_clicked()
{
    ui->MergeC1->setVisible(false);
    ui->MergeC2->setVisible(false);
    ui->FlipH->setVisible(false);
    ui->FlipV->setVisible(false);
    ui->BrightSl->setVisible(false);
    ui->RotateL->setVisible(false);
    ui->RotateR->setVisible(false);
    ui->FrameR->setVisible(false);
    ui->FrameB->setVisible(false);
    ui->FrameG->setVisible(false);
    ui->FrameBW->setVisible(false);

}


void MainWindow::on_WhiteRed_e1_clicked()
{
    ui->MergeC1->setVisible(false);
    ui->MergeC2->setVisible(false);
    ui->FlipH->setVisible(false);
    ui->FlipV->setVisible(false);
    ui->BrightSl->setVisible(false);
    ui->RotateL->setVisible(false);
    ui->RotateR->setVisible(false);
    ui->FrameR->setVisible(false);
    ui->FrameB->setVisible(false);
    ui->FrameG->setVisible(false);
    ui->FrameBW->setVisible(false);
    if(name1 != ""){
        to_whiteRed_filter_extra1(image1);
        image1.saveImage("temp.jpg");
        QString absolutePath = QDir::currentPath() + "/temp.jpg";
        QPixmap pix(absolutePath);
        ui->Picture->setPixmap(pix.scaled(400,200,Qt::KeepAspectRatio));
    }
}


void MainWindow::on_Blood_e2_clicked()
{
    ui->MergeC1->setVisible(false);
    ui->MergeC2->setVisible(false);
    ui->FlipH->setVisible(false);
    ui->FlipV->setVisible(false);
    ui->BrightSl->setVisible(false);
    ui->RotateL->setVisible(false);
    ui->RotateR->setVisible(false);
    ui->FrameR->setVisible(false);
    ui->FrameB->setVisible(false);
    ui->FrameG->setVisible(false);
    ui->FrameBW->setVisible(false);
    if(name1 != ""){
        to_Blood_filter_extra2(image1);
        image1.saveImage("temp.jpg");
        QString absolutePath = QDir::currentPath() + "/temp.jpg";
        QPixmap pix(absolutePath);
        ui->Picture->setPixmap(pix.scaled(400,200,Qt::KeepAspectRatio));
    }
}


void MainWindow::on_RedGreen_e3_clicked()
{
    ui->MergeC1->setVisible(false);
    ui->MergeC2->setVisible(false);
    ui->FlipH->setVisible(false);
    ui->FlipV->setVisible(false);
    ui->BrightSl->setVisible(false);
    ui->RotateL->setVisible(false);
    ui->RotateR->setVisible(false);
    ui->FrameR->setVisible(false);
    ui->FrameB->setVisible(false);
    ui->FrameG->setVisible(false);
    ui->FrameBW->setVisible(false);
    to_redGreen_extra3(image1);
    if(name1 != ""){
        image1.saveImage("temp.jpg");
        QString absolutePath = QDir::currentPath() + "/temp.jpg";
        QPixmap pix(absolutePath);
        ui->Picture->setPixmap(pix.scaled(400,200,Qt::KeepAspectRatio));
    }
}


void MainWindow::on_XRay_e4_clicked()
{
    ui->MergeC1->setVisible(false);
    ui->MergeC2->setVisible(false);
    ui->FlipH->setVisible(false);
    ui->FlipV->setVisible(false);
    ui->BrightSl->setVisible(false);
    ui->RotateL->setVisible(false);
    ui->RotateR->setVisible(false);
    ui->FrameR->setVisible(false);
    ui->FrameB->setVisible(false);
    ui->FrameG->setVisible(false);
    ui->FrameBW->setVisible(false);
    if(name1 != ""){
        to_Xray_filter_extra4(image1);
        image1.saveImage("temp.jpg");
        QString absolutePath = QDir::currentPath() + "/temp.jpg";
        QPixmap pix(absolutePath);
        ui->Picture->setPixmap(pix.scaled(400,200,Qt::KeepAspectRatio));
    }
}
