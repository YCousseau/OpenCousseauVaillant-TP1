#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

void printHist(Mat img);

int main(int argc, char **argv)
{
    /**************************************************************************
     *             Présentation de la structure de données Image              *
     **************************************************************************/
    Mat img_gray = imread("../imagesDeTest/monarch.png", IMREAD_GRAYSCALE);
    std::cout << "Forme (gris) : " << img_gray.shape() << ", Type : " << img_gray.type() << std::endl;

    Mat img_color = imread("../imagesDeTest/monarch.png", IMREAD_COLOR);
    std::cout << "Forme (gris) : " << img_color.shape() << ", Type : " << img_color.type() << std::endl;

    Mat img_rgba = imread("../imagesDeTest/po.png", IMREAD_UNCHANGED);
    std::cout << "Forme (gris) : " << img_rgba.shape() << ", Type : " << img_rgba.type() << std::endl;

    Vec4b &color = img_rgba.at<Vec4b>(0, 0);
    std::cout << "B: " << (int)color[0] << ", G: " << (int)color[1] << ", R: " << (int)color[2] << ", A: " << (int)color[3] << std::endl;

    /**************************************************************************
     *                    Histogramme de l’image originale                    *
     **************************************************************************/
    Mat img_peppers = imread("../imagesDeTest/peppers-512.png", IMREAD_GRAYSCALE);

    printHist(img_peppers);
    waitKey(0);

    return 0;
}

void printHist(Mat img)
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
    imshow("Image d'origine", img);
    imshow("Histogramme Niveaux de Gris", histImage);
}