#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <functional>
#include "Image_Class.h"
class MainWindow : public QWidget {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    QLabel *imageLabel;
    QVBoxLayout *buttonsLayout;

    void addButton(const QString &text, std::function<void()> onClick);
    void to_grey_f1(Image &image);
    void to_black_and_white_f2(Image &image1);
    void invert_colors_f3(Image &image1);
    void mergeImages_f4(Image& image1, Image& image2, int choice);
    void flip_horizontally_f5(Image &image1);
    void flip_vertically_f5(Image &image1);
    void rotate_right_f6(Image &image1);
    void rotate_left_f6(Image &image1);
    void brightness_f7(Image &image, int choice, float number = 90);
    void crop_f8(Image &image,  int x, int y, int W, int H);
    void addFrame_f9(Image& image, char choice);
    void W_and_B_Frame_f9(Image& image, int frameWidth = 10, int checkerSize = 20);
    void detectEdges_f10(Image& image);
    void resize_image_f11(Image &image, int new_width, int new_height);
    void boxBlur_f12(Image& image,int blurRadius);
    void wano_Sunlight_f13(Image& img);
    void applyOilPaintingFilter_f14(Image& image);
    void oilPaintingFilter_faster_f14(Image& image, int radius = 10, int intensity = 100);
    void applyTVNoiseFilter_f15(Image& image);
    void wano_purple_f16(Image& img);
    void to_InfraRed_f17(Image &image);
    void skewImagealmostright_f18(Image& inputImage, double skewDegree);
    void to_whiteRed_filter_extra1(Image &image);
    void to_Blood_filter_extra2(Image &image);
    void to_redGreen_extra3(Image &image);
    void to_Xray_filter_extra4(Image &image);
    void save_image();
    void load_image(int imageNumber);
};

#endif // MAINWINDOW_H
