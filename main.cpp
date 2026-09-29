#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char** argv )
{
    Mat img = imread("monarch.png", IMREAD_GRAYSCALE);


    return 0;
}