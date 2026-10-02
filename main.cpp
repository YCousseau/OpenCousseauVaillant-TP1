#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

void printHist(Mat img);
void sous_echantillonner(Mat &img, int factor);

int main(int argc, char **argv)
{
    /**************************************************************************
     *             Présentation de la structure de données Image              *
     **************************************************************************/

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

    /**************************************************************************
     *                         Sous-échantillonnage                           *
     **************************************************************************/
    Mat img_256 = imread("../imagesDeTest/peppers-256.png", IMREAD_GRAYSCALE);
    sous_echantillonner(img_256, 4);
    while (waitKey(0) != 'q')
        ;

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

void sous_echantillonner(Mat &img, int factor)
{
    Mat outImg(img.rows / factor, img.cols / factor, img.type());

    int r, g, b;
    for (int i = 0; i < img.rows; i += factor)
    {
        for (int j = 0; j < img.cols; j += factor)
        {
            b = 0;
            g = 0;
            r = 0;
            for (int x = 0; x < factor; x++)
            {
                for (int y = 0; y < factor; y++)
                {
                    auto pixel = img.at<Vec3b>(i + x, j + y);
                    b += pixel[0];
                    g += pixel[1];
                    r += pixel[2];
                }
            }
            b /= factor * factor;
            g /= factor * factor;
            r /= factor * factor;
            int new_x = i / factor;
            int new_y = j / factor;
            outImg.at<Vec3b>(new_x, new_y) = Vec3b(b, g, r);
        }
    }
    imshow("Image d'origine", img);
    imshow("Image redimentionnée", outImg);
}