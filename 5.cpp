#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    Mat image = imread("input_image.jpg");

    if (image.empty()) {
        cout << "Could not open or find the image" << endl;
        return -1;
    }

    imshow("Original Image", image);
    waitKey(0);

    Mat grayImage;
    cvtColor(image, grayImage, COLOR_BGR2GRAY);
    imshow("Grayscale Image", grayImage);
    waitKey(0);

    Mat blurredImage;
    GaussianBlur(image, blurredImage, Size(5, 5), 0);
    imshow("Blurred Image", blurredImage);
    waitKey(0);

    Mat sharpenedImage;
    Mat kernel = (Mat_<char>(3,3) <<  0, -1,  0,
                                      -1,  5, -1,
                                       0, -1,  0);
    filter2D(image, sharpenedImage, image.depth(), kernel);
    imshow("Sharpened Image", sharpenedImage);
    waitKey(0);

    Rect roi(100, 100, 300, 300);
    Mat croppedImage = image(roi);
    imshow("Cropped Image", croppedImage);
    waitKey(0);

    Mat resizedImage;
    resize(image, resizedImage, Size(200, 200));
    imshow("Resized Image", resizedImage);
    waitKey(0);

    imwrite("processed_image.jpg", resizedImage);

    return 0;
}

