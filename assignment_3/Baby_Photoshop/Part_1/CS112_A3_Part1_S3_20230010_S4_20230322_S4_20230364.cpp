// FCAI – Structured Programming – 2024 - Assignment 3 - Part 1
// Program Name: CS112_A3_Part1_S3_20230010_S4_20230322_S4_20230364.cpp
// Author1 and ID and Group: Ahmed Ehab Sayed Ibrahim                   ID(20230010) Group A Section 3
// Author2 and ID and Group: Mohamed Akram Abbas Mohamed                ID(20230322) Group A Section 4
// Author3 and ID and Group: Mohammed Yaser Abo El-Maaty Abd El-Sattar  ID(20230364) Group A Section 4
// Emails:
//          Ahmed Ehab Sayed Ibrahim                    Personal_email: ahmedehab5750@gmail.com
//          Mohammed Yaser Abo El-Maaty Abd El-Sattar   Personal_email: m0hammady4ser@gmail.com
//          Mohamed Akram Abbas Mohamed                 Personal_email: mohamed.akram09382020@gmail.com
// Teaching Assistant: Ahmed Lotfy
// Who did what:
//               ID1: 20230010 Did the main function, filter 1 grey, filter 7 brightness, helped in other functions.
//               ID2: 20230322 Did save and load functions and filter 2 black and white, filter 5 flip horizontal and vertical.
//               ID3: 20230364 Did filter 3 invert colors, filter 12 box blur.
#include <bits/stdc++.h>
#include "Image_Class.h"
using namespace std;
void to_grey_f1(Image &image){
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            int average = (image(i, j, 0) + image(i, j, 1) + image(i, j, 2)) / 3;
            for (int k = 0; k < image.channels; k++) {
                image(i, j, k) = average;
            }
        }
    }
    cout << "Image converted to Grey scale successfully." << endl;
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
    cout << "Image converted to Black and White scale successfully." << endl;
}
void invert_colors_f3(Image &image1){
    for (int i = 0; i < image1.width; i++) {
        for (int j = 0; j < image1.height; j++) {
            for (int k = 0; k < image1.channels; k++) {
                image1(i, j, k) *= -1;
            }
        }
    }
    cout << "Image colors inverted successfully." << endl;
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
    image1 = new_image;
    cout << "Image flipped Horizontally successfully." << endl;
}
Image flip_vertically_f5(Image image1){
    Image new_image(image1.width, image1.height); // Create a new image with the same dimensions
    for (int i = 0; i < image1.height; i++) {      // Iterate over rows
        for (int j = 0; j < image1.width; j++) {   // Iterate over columns
            for (int k = 0; k < image1.channels; k++) {  // Iterate over color channels
                new_image(j, image1.height - i - 1, k) = image1(j, i, k); // Adjusted indexing for vertical flipping
            }
        }
    }
    cout << "Image flipped Vertically successfully." << endl;
    return new_image;
}
void brightness_f7(Image &image) {
    string choice;
    cout
            << "Please choose one of the following\n1) Higher The Brightness by 50%.\n2) Lower The Brightness by 50%.\n3) I choose the percentage manually.\n";
    cin >> choice;
    while (choice != "1" && choice != "2" && choice != "Higher" && choice != "Lower" && choice != "3" &&
           choice != "manual") {
        cout << "Invalid choice please enter 1 or 2\n";
        cin >> choice;
    }
    if (choice == "1" || choice == "Higher") {
        for (int i = 0; i < image.width; i++) {
            for (int j = 0; j < image.height; j++) {
                for (int k = 0; k < image.channels; k++) {
                    int new_value = image(i, j, k) * 1.5;
                    image(i, j, k) = (new_value > 255) ? 255 : new_value; // Cap the value at 255
                }
            }
        }
    }
    else if (choice == "2" || choice == "Lower") {
        for (int i = 0; i < image.width; i++) {
            for (int j = 0; j < image.height; j++) {
                for (int k = 0; k < image.channels; k++) {
                    int new_value = image(i, j, k) * 0.5;
                    image(i, j, k) = (new_value < 0) ? 0: new_value; // Ensure the value is non-negative
                }
            }
        }
    }
    else {
        string brightness;
        float number = 0;
        bool isWrong = false;
        cout << "Please enter bright percentage you want like 120% for 20% more and 80% for 20% less\n";
        cin >> brightness;
        for (char &k: brightness) {
            if (isdigit(k)) {
                number *= 10;
                number += int(k - '0');
            } else if (k == '%') {
                break;
            } else {
                isWrong = true;
                break;
            }
        }
        while (isWrong) {
            isWrong = false;
            cout << "\"" << brightness << "\" is a wrong input please enter valid numbers (e.g. 90%, 90, 120%, 120, ...etc)\n";
            cin >> brightness;
            number = 0;
            for (char &k: brightness) {
                if (isdigit(k)) {
                    number *= 10;
                    number += int(k - '0');
                } else if (k == '%') {
                    break;
                } else {
                    isWrong = true;
                    break;
                }
            }
        }
        number /= 100;
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
    cout << "Changed Image Brightness successfully." << endl;
}
void boxBlur_f12(Image& image) {
    string number;
    cout << "Please Enter the radius to compute the kernel size\n";
    cout << "Make sure to choose numbers from 1 to 10.\nYou can choose higher values but it would go so slow\n";
    cin >> number;
    int blurRadius = 0;
    bool isWrong = false;
    for (char &k: number) {
        if (isdigit(k)) {
            blurRadius *= 10;
            blurRadius += int(k - '0');
        }
        else{
            isWrong = true;
            break;
        }
    }
    while (isWrong) {
        isWrong = false;
        cout << "\"" << number << "\" is a wrong input please enter valid numbers (e.g. 2, 4, 1, 5, ...etc)\n";
        cin >> number;
        blurRadius = 0;
        for (char &k: number) {
            if (isdigit(k)) {
                blurRadius *= 10;
                blurRadius += int(k - '0');
            }
            else {
                isWrong = true;
                break;
            }
        }
    }
    int width = image.width;
    int height = image.height;
    int channels = image.channels;
    // Create a temporary image to store the blurred result
    Image blurredImage(width, height);
    // Precompute the kernel size
    int kernelSize = 2 * blurRadius + 1;
    cout << "Processing...\n";
    // Blur horizontally
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            for (int c = 0; c < channels; c++) {
                int sum = 0;
                for (int dx = -blurRadius; dx <= blurRadius; ++dx) {
                    int nx = max(0, min(width - 1, x + dx));
                    sum += image(nx, y, c);
                }
                blurredImage(x, y, c) = sum / kernelSize;
            }
        }
    }
    cout << "Finishing...\n";
    // Blur vertically (on the horizontally blurred image)
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            for (int c = 0; c < channels; c++) {
                int sum = 0;
                for (int dy = -blurRadius; dy <= blurRadius; ++dy) {
                    int ny = max(0, min(height - 1, y + dy));
                    sum += blurredImage(x, ny, c);
                }
                image(x, y, c) = sum / kernelSize;
            }
        }
    }
    cout << "Done Blurring the image using \"" << blurRadius << "\" as the blur radius\n";
}
void save_image(Image &Savedimg){
    // Initializing a string to hold the name of the initial image and the edited one.
    string saveName;
    bool isvalid =true;
    while(isvalid){
        cout << "Enter the name of the edited image\nOnly Supported Extensions are{.jpg, .bmp, .png, .tga}\nTo save:";
        cin >> saveName;
        try{
            Savedimg.saveImage(saveName);
            isvalid = false;
        }
        catch(...) {
            cout << endl;
        }
    }

}
string load_image(){
    Image img;
    // Initializing a string to hold the name of the initial image and the edited one.
    string imgName;
    bool isvalid =true;
    while(isvalid){
        cout << "Enter the name of the image you want to edit\nOnly Supported Extensions are{.jpg, .bmp, .png, .tga}\nLoad:";
        cin >> imgName;
        try{
            img.loadNewImage(imgName);
            isvalid = false;
            string jpgName = imgName.substr(0, imgName.find_last_of(".")) + ".jpg";
            img.saveImage(jpgName);
            // Load the newly saved JPG image
        }
        catch(...) {
            cout << endl;
        }
    }
    return imgName;
}
int main() {
    Image image1, image2;
    bool isLoaded = false;
    while(true){
        cout << "Welcome in baby photoshop\n";
        cout << "Choose an operation to apply on the Image\n";
        cout << "1) Load an Image.\n2) Save an Image.\n3) Grey filter.\n4) Black&White filter.\n5) Invert colors filter.\n";
        cout << "6) Flip Image.\n7) Blur Image.\n8) Brightness Editor\n9) Exit.\n";
        string choice;
        cin >> choice;

        if(choice == "1" || choice == "load"){
            image1.loadNewImage(load_image());
            isLoaded = true;
        }
        else if((choice == "2" || choice == "save") && isLoaded){
            save_image(image1);
        }
        else if(choice == "3" && isLoaded){
            to_grey_f1(image1);
        }
        else if(choice == "4" && isLoaded){
            to_black_and_white_f2(image1);
        }
        else if(choice == "5" && isLoaded){
            invert_colors_f3(image1);
        }
        else if(choice == "6" && isLoaded){
            string HorV;
            do {
                cout << "Please enter a valid choice 1 or 2.\n1) Flip Horizontally.\n2) Flip Vertically.\n";
                cin >> HorV;
            } while(HorV != "1" && HorV != "2" && HorV != "Horizontal" && HorV != "Vertical");
            if(HorV == "1" || HorV == "Horizontal"){
                flip_horizontally_f5(image1);
            }
            else{
                image1 = flip_vertically_f5(image1);
            }
        }
        else if(choice == "7" && isLoaded){
            boxBlur_f12(image1);
        }
        else if(choice == "8" && isLoaded){
            brightness_f7(image1);
        }
        else if(choice == "9" || choice == "exit"){
            break;
        }
        else{
            cout << "Load an image first please\n";
        }
    }
    return 0;
}
