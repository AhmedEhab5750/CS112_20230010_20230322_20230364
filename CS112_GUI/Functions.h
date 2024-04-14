#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#endif // FUNCTIONS_H
#include "Image_Class.h"
#include <bits/stdc++.h>
void to_grey_f1(Image &image){
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            int average = (image(i, j, 0) + image(i, j, 1) + image(i, j, 2)) / 3;
            for (int k = 0; k < image.channels; k++) {
                image(i, j, k) = average;
            }
        }
    }
}
void to_black_and_white_f2(Image &image1){
    for (int i = 0; i < image1.width; i++) {
        for (int j = 0; j < image1.height; j++) {
            int average = (image1(i, j, 0) + image1(i, j, 1) + image1(i, j, 2)) / 3;
            for (int k = 0; k < image1.channels; k++) {
                if(average > 127){
                    image1(i, j, k) = 255;
                }
                else{
                    image1(i, j, k) = 0;
                }
            }
        }
    }
}
void invert_colors_f3(Image &image1){
    for (int i = 0; i < image1.width; i++) {
        for (int j = 0; j < image1.height; j++) {
            for (int k = 0; k < image1.channels; k++) {
                image1(i, j, k) *= -1;
            }
        }
    }
}
void mergeImages_f4(Image& image1, Image& image2, int choice) {
    int new_width;
    int new_height;
    if(choice == 1){
        new_width = std::max(image1.width, image2.width);
        new_height = std::max(image1.height, image2.height);
    }
    else{
        new_width = std::min(image1.width, image2.width);
        new_height = std::min(image1.height, image2.height);
    }
    Image resized_image(new_width, new_height);
    for (int y = 0; y < new_height; y++) {
        for (int x = 0; x < new_width; x++) {
            for (int c = 0; c < image1.channels; c++) {
                int original_x = x * image1.width / new_width;
                int original_y = y * image1.height / new_height;
                resized_image(x, y, c) = image1(original_x, original_y, c);
            }
        }
    }
    resized_image.saveImage("temp.jpg");
    image1.loadNewImage("temp.jpg");
    Image resized1_image(new_width, new_height);
    for (int y = 0; y < new_height; y++) {
        for (int x = 0; x < new_width; x++) {
            for (int c = 0; c < image2.channels; c++) {
                int original_x = x * image2.width / new_width;
                int original_y = y * image2.height / new_height;
                resized1_image(x, y, c) = image2(original_x, original_y, c);
            }
        }
    }
    resized1_image.saveImage("temp.jpg");
    image2.loadNewImage("temp.jpg");
    int mergedImageWidth=std::min(image1.width,image2.width);
    int mergedImageHeight=std::min(image1.height,image2.height);
    Image mergedImage(mergedImageWidth, mergedImageHeight);
    for (int y = 0; y < mergedImageHeight ; y++) {
        for (int x = 0; x < mergedImageWidth; x++) {
            // Get the pixel values of the two images
            unsigned char r1 = image1.getPixel(x, y, 0);
            unsigned char g1 = image1.getPixel(x, y, 1);
            unsigned char b1 = image1.getPixel(x, y, 2);
            unsigned char r2 = image2.getPixel(x, y, 0);
            unsigned char g2 = image2.getPixel(x, y, 1);
            unsigned char b2 = image2.getPixel(x, y, 2);
            unsigned char r = (r1 + r2) / 2;
            unsigned char g = (g1 + g2) / 2;
            unsigned char b = (b1 + b2) / 2;
            mergedImage.setPixel(x, y, 0, r);
            mergedImage.setPixel(x, y, 1, g);
            mergedImage.setPixel(x, y, 2, b);
        }
    }
    mergedImage.saveImage("temp.jpg");
    image1.loadNewImage("temp.jpg");
}
void flip_horizontally_f5(Image &image1){
    Image new_image(image1.width, image1.height); // Flipping width and height
    for (int i = 0; i < image1.width; i++) {
        for (int j = 0; j < image1.height; j++) {
            for (int k = 0; k < image1.channels; k++) {
                new_image(image1.width - i - 1, j, k) = image1(i, j, k); // Adjusted indexing for temp
            }
        }
    }
    new_image.saveImage("temp.jpg");
    image1.loadNewImage("temp.jpg");
}
void flip_vertically_f5(Image &image1){
    Image new_image(image1.width, image1.height); // Create a new image with the same dimensions
    for (int i = 0; i < image1.height; i++) {      // Iterate over rows
        for (int j = 0; j < image1.width; j++) {   // Iterate over columns
            for (int k = 0; k < image1.channels; k++) {  // Iterate over color channels
                new_image(j, image1.height - i - 1, k) = image1(j, i, k); // Adjusted indexing for vertical flipping
            }
        }
    }
    new_image.saveImage("temp.jpg");
    image1.loadNewImage("temp.jpg");
}
void rotate_right_f6(Image &image1){
    Image new_image(image1.height, image1.width); // Flipping width and height
    for (int i = 0; i < image1.width; i++) {
        for (int j = 0; j < image1.height; j++) {
            for (int k = 0; k < image1.channels; k++) {
                new_image(image1.height - j - 1, i, k) = image1(i, j, k); // Adjusted indexing for rotation
            }
        }
    }
    new_image.saveImage("temp.jpg");
    image1.loadNewImage("temp.jpg");
}

void rotate_left_f6(Image &image1){
    Image new_image(image1.height, image1.width); // Flipping width and height
    for (int i = 0; i < image1.width; i++) {
        for (int j = 0; j < image1.height; j++) {
            for (int k = 0; k < image1.channels; k++) {
                new_image(j, image1.width - i - 1, k) = image1(i, j, k); // Adjusted indexing for temp
            }
        }
    }
    new_image.saveImage("temp.jpg");
    image1.loadNewImage("temp.jpg");
}
void brightness_f7(Image &image, float number) {
    if (number >= 1) {
        for (int i = 0; i < image.width; i++) {
            for (int j = 0; j < image.height; j++) {
                for (int k = 0; k < image.channels; k++) {
                    int new_value = image(i, j, k) * number;
                    image(i, j, k) = (new_value > 255) ? 255 : new_value; // Cap the value at 255
                }
            }
        }
    }
    else if (number < 1) {
         for (int i = 0; i < image.width; i++) {
             for (int j = 0; j < image.height; j++) {
                 for (int k = 0; k < image.channels; k++) {
                     int new_value = image(i, j, k) * number;
                     image(i, j, k) = (new_value < 0) ? 0 : new_value; // Ensure the value is non-negative
                 }
             }
         }
    }
}
void crop_f8(Image &image, int x, int y, int W, int H){
    Image cropped(W,H);
    for(int i=x,counter=0; i<W+x; i++,counter++){
        for(int j=y,counter_2=0; j<H+y;j++,counter_2++){
            for(int r=0;r<image.channels;r++){
                cropped(counter,counter_2,r)=image(i,j,r);
            }
        }
    }
    cropped.saveImage("temp.jpg");
    image.loadNewImage("temp.jpg");

}
void addFrame_f9(Image& image, char choice) {
    for (int y = 0; y < image.height; y++) {
        for (int x = 0; x < image.width; x++) {
            if (y < 10 || y >= image.height - 10 || x < 10 || x >= image.width - 10) {
                if(toupper(choice)=='A'){
                    image(x, y, 0) = 255;
                    image(x, y, 1) = 0;
                    image(x, y, 2) = 0;
                }
                else if(toupper(choice)=='B'){
                    image(x, y, 0) = 0;
                    image(x, y, 1) = 255;
                    image(x, y, 2) = 0;
                }
                else if(toupper(choice)=='C'){
                    image(x, y, 0) = 0;
                    image(x, y, 1) = 0;
                    image(x, y, 2) = 255;
                }
            }
        }
    }
}
void W_and_B_Frame_f9(Image& image, int frameWidth, int checkerSize) {
    for (int y = 0; y < image.height; ++y) {
        for (int x = 0; x < image.width; ++x) {
            if (y < frameWidth || y >= image.height - frameWidth ||
                x < frameWidth || x >= image.width - frameWidth) {
                if ((x / checkerSize) % 2 == 0 && (y / checkerSize) % 2 == 0) {
                    image(x, y, 0) = 0;    // Red
                    image(x, y, 1) = 0;    // Green
                    image(x, y, 2) = 255;  // Blue
                } else {
                    image(x, y, 0) = 255;  // Red
                    image(x, y, 1) = 255;  // Green
                    image(x, y, 2) = 255;  // Blue
                }
            }
        }
    }
}
void detectEdges_f10(Image& image) {
    Image newimage(image.width, image.height);
    for (int y = 1; y < image.height - 1; ++y) {
        for (int x = 1; x < image.width - 1; ++x) {
            for(int c = 0;c < image.channels;c++){
                int gx = image(x + 1, y - 1, c) + 2 * image(x + 1, y, c)
                         + image(x + 1, y + 1, c) - image(x - 1, y - 1, c) - 2 * image(x - 1, y, c) - image(x - 1, y + 1, c);
                int gy = image(x - 1, y + 1, c) + 2 * image(x, y + 1, c) + image(x + 1, y + 1, c)
                         - image(x - 1, y - 1, c) - 2 * image(x, y - 1, c) - image(x + 1, y - 1, c);
                int gradientMagnitude = abs(gx) + abs(gy);
                int threshold = 250;
                int edgePixel = (gradientMagnitude > threshold) ? 0 : 255;
                newimage(x, y, c) = edgePixel;
            }
        }
    }
    newimage.saveImage("temp.jpg");
    image.loadNewImage("temp.jpg");
}
void resize_image_f11(Image &image, int new_width,int new_height) {
    if (new_width < 0 || new_height < 0) {
        new_height = abs(new_height);
        new_width = abs(new_width);
    }
    Image resized_image(new_width, new_height);
    for (int y = 0; y < new_height; y++) {
        for (int x = 0; x < new_width; x++) {
            for (int c = 0; c < image.channels; c++) {
                int original_x = x * image.width / new_width;
                int original_y = y * image.height / new_height;
                resized_image(x, y, c) = image(original_x, original_y, c);
            }
        }
    }
    resized_image.saveImage("temp.jpg");
    image.loadNewImage("temp.jpg");
}
void boxBlur_f12(Image& image,int blurRadius) {
    int width = image.width;
    int height = image.height;
    int channels = image.channels;
    Image blurredImage(width, height);
    int kernelSize = 2 * blurRadius + 1;
    // Blur horizontally
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            for (int c = 0; c < channels; c++) {
                int sum = 0;
                for (int dx = -blurRadius; dx <= blurRadius; ++dx) {
                    int nx = std::max(0, std::min(width - 1, x + dx));
                    sum += image(nx, y, c);
                }
                blurredImage(x, y, c) = sum / kernelSize;
            }
        }
    }
    // Blur vertically (on the horizontally blurred image)
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            for (int c = 0; c < channels; c++) {
                int sum = 0;
                for (int dy = -blurRadius; dy <= blurRadius; ++dy) {
                    int ny = std::max(0, std::min(height - 1, y + dy));
                    sum += blurredImage(x, ny, c);
                }
                image(x, y, c) = sum / kernelSize;
            }
        }
    }
}
void wano_Sunlight_f13(Image& img){
    for (int i = 0; i < img.width; ++i) {
        for (int j = 0; j < img.height; ++j) {
            img(i, j, 2) *= 0.5;
        }
    }
    img.saveImage("temp.jpg");
    img.loadNewImage("temp.jpg");
}
void applyOilPaintingFilter_f14(Image& image) {
    Image resultImage(image.width, image.height);
    int radius = 5;
    int intensity = 100;
    for (int y = 0; y < image.height; y++) {
        for (int x = 0; x < image.width; x++) {
            int maxCount = 0;
            int maxR = 0, maxG = 0, maxB = 0;
            for (int dy = -radius; dy <= radius; dy++) {
                for (int dx = -radius; dx <= radius; dx++) {
                    int nx = x + dx;
                    int ny = y + dy;
                    if (nx >= 0 && nx < image.width && ny >= 0 && ny < image.height) {
                        unsigned char r = image(nx, ny, 0);
                        unsigned char g = image(nx, ny, 1);
                        unsigned char b = image(nx, ny, 2);
                        int dist = abs(r - image(x, y, 0)) + abs(g - image(x, y, 1)) + abs(b - image(x, y, 2));
                        if (dist < intensity) {
                            int count = 1;
                            for (int ndy = -radius; ndy <= radius; ndy++) {
                                for (int ndx = -radius; ndx <= radius; ndx++) {
                                    int nnx = x + ndx;
                                    int nny = y + ndy;
                                    if (nnx >= 0 && nnx < image.width && nny >= 0 && nny < image.height) {
                                        unsigned char nr = image(nnx, nny, 0);
                                        unsigned char ng = image(nnx, nny, 1);
                                        unsigned char nb = image(nnx, nny, 2);
                                        if (nr == r && ng == g && nb == b) {
                                            count++;
                                        }
                                    }
                                }
                            }
                            if (count > maxCount) {
                                maxCount = count;
                                maxR = r;
                                maxG = g;
                                maxB = b;
                            }
                        }
                    }
                }
            }
            resultImage(x, y, 0) = maxR;
            resultImage(x, y, 1) = maxG;
            resultImage(x, y, 2) = maxB;
        }
    }
    resultImage.saveImage("temp.jpg");
    image.loadNewImage("temp.jpg");
}
void oilPaintingFilter_faster_f14(Image& image, int radius, int intensity) {
    Image tempImage(image.width, image.height);
    for (int y = 0; y < image.height; ++y) {
        for (int x = 0; x < image.width; ++x) {
            std::vector<std::vector<int>> frequency(image.channels, std::vector<int>(256, 0));
            int startX = std::max(0, x - radius);
            int endX = std::min(image.width - 1, x + radius);
            int startY = std::max(0, y - radius);
            int endY = std::min(image.height - 1, y + radius);
            for (int j = startY; j <= endY; ++j) {
                for (int i = startX; i <= endX; ++i) {
                    for (int c = 0; c < image.channels; ++c) {
                        frequency[c][image(i, j, c)]++;
                    }
                }
            }
            std::vector<int> dominantColor(image.channels, 0);
            for (int c = 0; c < image.channels; ++c) {
                int maxFrequency = 0;
                for (int k = 0; k < 256; ++k) {
                    if (frequency[c][k] > maxFrequency) {
                        maxFrequency = frequency[c][k];
                        dominantColor[c] = k;
                    }
                }
            }
            for (int c = 0; c < image.channels; ++c) {
                tempImage(x, y, c) = dominantColor[c];
            }
        }
    }
    for (int y = 0; y < image.height; ++y) {
        for (int x = 0; x < image.width; ++x) {
            for (int c = 0; c < image.channels; ++c) {
                int oilPaintingValue = tempImage(x, y, c);
                int originalValue = image(x, y, c);
                int newValue = originalValue + (oilPaintingValue - originalValue) * intensity / 255;
                newValue = std::max(0, std::min(newValue, 255));
                image(x, y, c) = newValue;
            }
        }
    }
}
void applyTVNoiseFilter_f15(Image& image) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(-100, 100); // Noise range
    int centerX = image.width / 2;
    int centerY = image.height / 2;
    double maxDist = sqrt(centerX * centerX + centerY * centerY); // Maximum distance from center
    for (int y = 0; y < image.height; ++y) {
        for (int x = 0; x < image.width; ++x) {
            for (int c = 0; c < image.channels; ++c) {
                // Apply noise
                int noise = dis(gen);
                int value = image.getPixel(x, y, c) + noise;
                value = std::max(0, std::min(255, value));
                image.setPixel(x, y, c, value);
                // Apply vignette effect
                double dist = sqrt((centerX - x) * (centerX - x) + (centerY - y) * (centerY - y));
                double factor = 1.0 - pow(dist / maxDist, 4); // Increase the power for a larger dark area
                int pixelValue = image.getPixel(x, y, c);
                int newValue = static_cast<int>(pixelValue * factor);
                newValue = std::max(0, std::min(255, newValue));
                image.setPixel(x, y, c, newValue);
            }
        }
        // Add horizontal lines
        if (y % 10 == 0) { // Change 10 to adjust the frequency of lines
            for (int x = 0; x < image.width; ++x) {
                for (int c = 0; c < image.channels; ++c) {
                    image.setPixel(x, y, c, 0); // Set pixel to black
                }
            }
        }
    }
}
void wano_purple_f16(Image& img){
    for (int i = 0; i < img.width; ++i) {
        for (int j = 0; j < img.height; ++j) {
            img(i, j, 1) *= 0.7;
        }
    }
    img.saveImage("temp.jpg");
    img.loadNewImage("temp.jpg");
}
void to_InfraRed_f17(Image &image){
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            int red = image(i, j, 0);
            image(i, j, 0) = 255;   // Red (white)
            image(i, j, 1) = -1 * red;   // Green (red)
            image(i, j, 2) = -1 * red;   // Blue (red)
        }
    }
}
void skewImagealmostright_f18(Image& inputImage, double skewDegree) {
    int width = inputImage.width;
    int height = inputImage.height;
    // Convert skew degree to radians
    double skewRadians = skewDegree * M_PI / 180.0;
    // Calculate the new width of the image after skewing
    int newWidth = static_cast<int>(width + tan(skewRadians) * height);
    // Create a new image with the same height and adjusted width
    Image outputImage(newWidth, height);
    // Iterate over the pixels of the output image
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < newWidth; ++x) {
            // Calculate the corresponding source coordinates in the input image
            double xSrc = x - tan(skewRadians) * (height - y);
            // Check if the source coordinates are within the bounds of the input image
            if (xSrc >= 0 && xSrc < width) {
                // Perform linear interpolation
                int x0 = static_cast<int>(xSrc);
                int x1 = x0 + 1;
                // Calculate interpolation weights
                double weight1 = xSrc - x0;
                double weight0 = 1.0 - weight1;

                // Interpolate pixel values from the input image
                for (int c = 0; c < inputImage.channels; ++c) {
                    double interpolatedValue = weight0 * inputImage(x0, y, c) + weight1 * inputImage(x1, y, c);
                    outputImage(x, y, c) = interpolatedValue;
                }
            }
        }
    }
    outputImage.saveImage("temp.jpg");
    inputImage.loadNewImage("temp.jpg");
}
void to_whiteRed_filter_extra1(Image &image){ // BETA
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            int red = image(i, j, 0);
            if(red >= 250){
                image(i, j, 0) = red;   // Red
                image(i, j, 1) = 255;   // Green (white)
                image(i, j, 2) = 255;   // Blue (white)
            } else {
                image(i, j, 0) = 255;   // Red (white)
                image(i, j, 1) = red;   // Green (red)
                image(i, j, 2) = red;   // Blue (red)
            }
        }
    }
}
void to_Blood_filter_extra2(Image &image){ // BETA
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            int intensity = (image(i, j, 0) + image(i, j, 1) + image(i, j, 2)) / 3;
            int red = intensity;  // Red component
            int green = 255 - intensity;
            int blue = 255 - intensity;
            image(i, j, 0) = red;
            image(i, j, 1) = 0;
            image(i, j, 2) = 0;
        }
    }
}
void to_redGreen_extra3(Image &image){ // BETA still not working as intended.
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            int intensity = (image(i, j, 0) + image(i, j, 1) + image(i, j, 2)) / 3;
            int red = intensity;  // Red component
            int green = 125 + intensity;  // Green component
            int blue = 125 + intensity;  // Blue component
            image(i, j, 0) = red;
            image(i, j, 1) = green;
            image(i, j, 2) = blue;
        }
    }
}
void to_Xray_filter_extra4(Image &image){ // BETA
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            int red = image(i, j, 0);
            if(red >= 250){ // Adjust threshold as needed
                image(i, j, 0) = -1* red;
                image(i, j, 1) = 0;
                image(i, j, 2) = 0;
            } else {
                image(i, j, 0) = 0;
                image(i, j, 1) = -1 * red;
                image(i, j, 2) = -1 * red;
            }
        }
    }
}
