#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/geometry/2d.hpp>

using namespace cv;

void printHist(Mat img,
               std::string orgTitle = "Image d'origine",
               std::string histTitle = "Histogramme Niveaux de Gris");
void sous_echantillonner(Mat &img, int factor);
void quantification(Mat &img, int N);

int main(int argc, char **argv)
{
    // /**************************************************************************
    //  *             Présentation de la structure de données Image              *
    //  **************************************************************************/
    // Mat img_gray = imread("../imagesDeTest/monarch.png", IMREAD_GRAYSCALE);
    // std::cout << "Taille (gris) : " << img_gray.shape() << ", Cannaux: " << img_gray.channels() << ", Type : " << img_gray.type() << std::endl;

    // Mat img_color = imread("../imagesDeTest/monarch.png", IMREAD_COLOR);
    // std::cout << "Taille (couleur) : " << img_color.shape() << ", Cannaux: " << img_color.channels() << ", Type : " << img_color.type() << std::endl;

    // Mat img_rgba = imread("../imagesDeTest/po.png", IMREAD_UNCHANGED);
    // std::cout << "Taille (RGBA) : " << img_rgba.shape() << ", Cannaux: " << img_rgba.channels() << ", Type : " << img_rgba.type() << std::endl;

    // Vec4b &color = img_rgba.at<Vec4b>(0, 0);
    // std::cout << "B: " << (int)color[0] << ", G: " << (int)color[1] << ", R: " << (int)color[2] << ", A: " << (int)color[3] << std::endl;

    // /**************************************************************************
    //  *                    Histogramme de l’image originale                    *
    //  **************************************************************************/
    // Mat img_peppers = imread("../imagesDeTest/peppers-512.png", IMREAD_GRAYSCALE);

    // printHist(img_peppers);
    // while (waitKey(0) != 'q')
    //     ;

    // equalizeHist(img_peppers, img_peppers);
    // while (waitKey(0) != 'q')
    //     ;

    // /**************************************************************************
    //  *             Modification de la luminosité et du contraste              *
    //  **************************************************************************/
    // Mat imgLumCont;
    // convertScaleAbs(img_color, imgLumCont, 1, 40);
    // imshow("alpha=1, beta=40", imgLumCont);
    // while (waitKey(0) != 'q')
    //     ;

    // convertScaleAbs(img_color, imgLumCont, 1.5, 0);
    // imshow("alpha=1.5, beta=0", imgLumCont);
    // while (waitKey(0) != 'q')
    //     ;

    // /**************************************************************************
    //  *                         Sous-échantillonnage                           *
    //  **************************************************************************/
    // Mat img_256 = imread("../imagesDeTest/peppers-256.png", IMREAD_GRAYSCALE);
    // sous_echantillonner(img_256, 4);
    // Mat img_256_nearest;
    // resize(img_256, img_256_nearest, Size(), 0.25, 0.25, INTER_NEAREST);
    // namedWindow("Image redimentionnée INTER_NEAREST", WINDOW_NORMAL);
    // imshow("Image redimentionnée INTER_NEAREST", img_256_nearest);
    // Mat img_256_area;
    // resize(img_256, img_256_area, Size(), 0.25, 0.25, INTER_AREA);
    // namedWindow("Image redimentionnée INTER_AREA", WINDOW_NORMAL);
    // imshow("Image redimentionnée INTER_AREA", img_256_area);
    // while (waitKey(0) != 'q')
    //     ;

    // /**************************************************************************
    //  *                    Quantification de niveaux de gris                   *
    //  **************************************************************************/
    // Mat img_512_gray = imread("../imagesDeTest/peppers-512.png", IMREAD_GRAYSCALE);
    // namedWindow("Image d'origine", WINDOW_NORMAL);
    // imshow("Image d'origine", img_512_gray);
    // quantification(img_512_gray, 64);
    // quantification(img_512_gray, 16);
    // quantification(img_512_gray, 4);
    // quantification(img_512_gray, 2);
    // while (waitKey(0) != 'q')
    //     ;

    /**************************************************************************
     *                       Application de LUT colorées                      *
     **************************************************************************/
    Mat img_512_gray2 = imread("../imagesDeTest/peppers-512.png", IMREAD_GRAYSCALE);
    namedWindow("Image d'origine", WINDOW_NORMAL);
    imshow("Image d'origine", img_512_gray2);
    Mat coloredImg;
    applyColorMap(img_512_gray2, coloredImg, COLORMAP_JET);
    namedWindow("LUT - JET", WINDOW_NORMAL);
    imshow("LUT - JET", coloredImg);
    applyColorMap(img_512_gray2, coloredImg, COLORMAP_HOT);
    namedWindow("LUT - HOT", WINDOW_NORMAL);
    imshow("LUT - HOT", coloredImg);
    applyColorMap(img_512_gray2, coloredImg, COLORMAP_OCEAN);
    namedWindow("LUT - OCEAN", WINDOW_NORMAL);
    imshow("LUT - OCEAN", coloredImg);
    applyColorMap(img_512_gray2, coloredImg, COLORMAP_PINK);
    namedWindow("LUT - PINK", WINDOW_NORMAL);
    imshow("LUT - PINK", coloredImg);
    while (waitKey(0) != 'q')
        ;

    // /**************************************************************************
    //  *                               Rotation                                 *
    //  **************************************************************************/
    // Mat squares = imread("../imagesDeTest/squares.tif");
    // int height = squares.rows;
    // int width = squares.cols;

    // Point2f center(width / 2.0f, height / 2.0f);

    // Mat rotation_90 = getRotationMatrix2D(center, -90, 1.0);
    // Mat rotation_45 = getRotationMatrix2D(center, -45, 1.0);
    // Mat rotation_15 = getRotationMatrix2D(center, -15, 1.0);

    // Mat rotated_90_image;
    // warpAffine(squares, rotated_90_image, rotation_90, cv::Size(width, height), INTER_LINEAR);
    // Mat rotated_45_image;
    // warpAffine(squares, rotated_45_image, rotation_45, cv::Size(width, height), INTER_LINEAR);
    // warpAffine(rotated_45_image, rotated_45_image, rotation_45, cv::Size(width, height), INTER_LINEAR);

    // Mat rotated_15_image;
    // warpAffine(squares, rotated_15_image, rotation_15, cv::Size(width, height), INTER_LINEAR);
    // warpAffine(rotated_15_image, rotated_15_image, rotation_15, cv::Size(width, height), INTER_LINEAR);
    // warpAffine(rotated_15_image, rotated_15_image, rotation_15, cv::Size(width, height), INTER_LINEAR);
    // warpAffine(rotated_15_image, rotated_15_image, rotation_15, cv::Size(width, height), INTER_LINEAR);
    // warpAffine(rotated_15_image, rotated_15_image, rotation_15, cv::Size(width, height), INTER_LINEAR);
    // warpAffine(rotated_15_image, rotated_15_image, rotation_15, cv::Size(width, height), INTER_LINEAR);

    // // Display the result
    // imshow("Original Image", squares);
    // imshow("Rotated 90 Image", rotated_90_image);
    // imshow("Rotated 2x45 Image", rotated_45_image);
    // imshow("Rotated 6x15 Image", rotated_15_image);
    // while (waitKey(0) != 'q')
    //     ;

    return 0;
}

void printHist(Mat img, std::string orgTitle, std::string histTitle)
{
    // Calculer l'histogramme
    Mat hist;
    int histSize = 256;       // Nombre de "bins" (colonnes de l'histogramme)
    float range[] = {0, 256}; // Plage des valeurs de pixels (256 est exclus)
    const float *histRange = {range};
    bool uniform = true, accumulate = false;
    calcHist(&img, 1, 0, Mat(), hist, 1, &histSize, &histRange, uniform, accumulate);

    // Créer une image pour dessiner l'histogramme
    int hist_w = 512, hist_h = 400;
    int bin_w = cvRound((double)hist_w / histSize);
    Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(0, 0, 0)); // Fond noir

    // Normaliser le résultat pour qu'il s'adapte à la hauteur de l'image du graphique
    normalize(hist, hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());

    // Tracer l'histogramme (dessin ligne par ligne)
    for (int i = 1; i < histSize; i++)
    {
        line(histImage,
             Point(bin_w * (i - 1), hist_h - cvRound(hist.at<float>(i - 1))),
             Point(bin_w * (i), hist_h - cvRound(hist.at<float>(i))),
             Scalar(255, 255, 255), 2, 8, 0); // Ligne blanche
    }

    // Affichage
    namedWindow(orgTitle, WINDOW_NORMAL);
    imshow(orgTitle, img);
    namedWindow(histTitle, WINDOW_NORMAL);
    imshow(histTitle, histImage);
}

void sous_echantillonner(Mat &img, int factor)
{
    Mat outImg(img.rows / factor, img.cols / factor, img.type());

    int r, g, colorMean;
    for (int i = 0; i < img.rows; i += factor)
    {
        for (int j = 0; j < img.cols; j += factor)
        {
            colorMean = 0;
            for (int x = 0; x < factor; x++)
            {
                for (int y = 0; y < factor; y++)
                {
                    colorMean += img.at<uchar>(i + x, j + y);
                }
            }
            colorMean /= factor * factor;
            outImg.at<uchar>(i / factor, j / factor) = colorMean;
        }
    }
    imshow("Image d'origine", img);
    namedWindow("Image redimentionnée", WINDOW_NORMAL);
    imshow("Image redimentionnée", outImg);
}

void quantification(Mat &img, int N)
{
    Mat outImg(img);
    int step = 256 / N;
    for (int i = 0; i < outImg.rows; i++)
    {
        for (int j = 0; j < outImg.cols; j++)
        {
            uchar originalVal = outImg.at<uchar>(i, j);
            uchar newVal = std::floor(originalVal / step) * step;
            outImg.at<uchar>(i, j) = newVal;
        }
    }
    printHist(outImg,
              "Image quantifiée par " + std::to_string(N),
              "Histograme quantifiée par " + std::to_string(N));
}