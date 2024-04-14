#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString name1, name2;
private slots:

    void on_Grey_f1_clicked();

    void on_Black_White_f2_clicked();

    void on_Invert_f3_clicked();

    void on_Merge_f4_clicked();

    void on_Flip_f5_clicked();

    void on_Rotate_f6_clicked();

    void on_Brightness_f7_clicked();

    void on_Crop_f8_clicked();

    void on_Frame_f9_clicked();

    void on_Edges_f10_clicked();

    void on_Resize_f11_clicked();

    void on_Blur_f12_clicked();

    void on_Sun_f13_clicked();

    void on_OilPainting_f14_clicked();

    void on_TV_f15_clicked();

    void on_Purple_f16_clicked();

    void on_InfraRed_f17_clicked();

    void on_Skew_f18_clicked();

    void on_WhiteRed_e1_clicked();

    void on_Blood_e2_clicked();

    void on_RedGreen_e3_clicked();

    void on_XRay_e4_clicked();

    void on_LoadImage_clicked();

    void on_SaveImage_clicked();

    void on_ResetEffects_clicked();

    void on_MergeC1_clicked();

    void on_MergeC2_clicked();

    void on_FlipH_clicked();

    void on_FlipV_clicked();

    void on_BrightSl_sliderReleased();

    void on_RotateL_clicked();

    void on_RotateR_clicked();

    void on_FrameR_clicked();

    void on_FrameB_clicked();

    void on_FrameG_clicked();

    void on_FrameBW_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
