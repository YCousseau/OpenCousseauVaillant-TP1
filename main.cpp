#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char **argv)
{
    Mat img_gray = imread("../imagesDeTest/monarch.png", IMREAD_GRAYSCALE);
    std::cout << "Forme (gris) : " << img_gray.shape() << ", Type : " << img_gray.type() << std::endl;

    Mat img_color = imread("../imagesDeTest/monarch.png", IMREAD_COLOR);
    std::cout << "Forme (gris) : " << img_color.shape() << ", Type : " << img_color.type() << std::endl;

    Mat img_rgba = imread("../imagesDeTest/po.png", IMREAD_UNCHANGED);
    std::cout << "Forme (gris) : " << img_rgba.shape() << ", Type : " << img_rgba.type() << std::endl;

    Vec4b &color = img_rgba.at<Vec4b>(0, 0);
    std::cout << "B: " << (int)color[0] << ", G: " << (int)color[1] << ", R: " << (int)color[2] << ", A: " << (int)color[3] << std::endl;

    return 0;
}