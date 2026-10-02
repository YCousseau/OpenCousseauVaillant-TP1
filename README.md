# VPO - TP1
``Yanis COUSSEAU, Louis VAILLANT``

# Partie 1 - Présentation de la structure de données Image

Après portage du programme python vers du C++, nous obtenons le code suivant:

```c++
Mat img_gray = imread("../imagesDeTest/monarch.png", IMREAD_GRAYSCALE);
std::cout << "Taille (gris) : " << img_gray.shape() << ", Cannaux: " << img_gray.channels() << ", Type : " << img_gray.type() << std::endl;

Mat img_color = imread("../imagesDeTest/monarch.png", IMREAD_COLOR);
std::cout << "Taille (couleur) : " << img_color.shape() << ", Cannaux: " << img_color.channels() << ", Type : " << img_color.type() << std::endl;

Mat img_rgba = imread("../imagesDeTest/po.png", IMREAD_UNCHANGED);
std::cout << "Taille (RGBA) : " << img_rgba.shape() << ", Cannaux: " << img_rgba.channels() << ", Type : " << img_rgba.type() << std::endl;

//Lire la valeur d'un pixel
Vec4b &color = img_rgba.at<Vec4b>(0, 0);
std::cout << "B: " << (int)color[0] << ", G: " << (int)color[1] << ", R: " << (int)color[2] << ", A: " << (int)color[3] << std::endl;
```

En C++, la fonction shape ne renvoie pas le nombre de cannaux.
L'affichage a donc été adapté afin de rajouter cette information manquante.

Similairement, la fonction `dtype` est nommée `type` en C++ et retourne un entier. 
Du code existe pour reconvertir ces entiers en chaines de caractères (voir [ce lien](https://gist.github.com/rummanwaqar/cdaddd5a175f617c0b107d353fd33695))

# Partie 2 - Histogramme

## Utilisation de l'IA

matplotlib n'étant pas disponible, l'IA a été utilisée afin de générer le code permettant de tracer l'histogramme.

## Calcul et affichage de l'histogramme

Nous obtenons le résultat suivant:

| Image | Histogramme |
|-------|-------------|
| ![](images_rapport/og.png ) | ![](images_rapport/og_hist.png ) |

On peut constater un manque de valeur les plus élevées dans l'histogramme (abscence de blanc).

## Egalisation de l'histogramme

Après égalisation de l'histogramme nous obtenons les résultats suivant:

| Image | Histogramme |
|-------|-------------|
| ![](images_rapport/egal.png ) | ![](images_rapport/egal_hist.png ) |

On peut constater que le contraste est amélioré, toutes les parties de l'histogramme sont maintenant utilisées.

## Modification de la luminosité et du contraste

| Image originale | Alpha = 1 Beta = 40 | Alpha = 1,5 Beta = 0 |
|-----------------|---------------------|----------------------|
| ![](images_rapport/mon_og.png) | ![](images_rapport/a1b40.png) | ![](images_rapport/a15b0.png) |

Visuellement, nous pouvons constater que l'augmentation du beta permet d'augmenter la luminosité et que l'augmentation de beta permet d'améliorer le contraste. 

Si on regarde les histogrammes :
| Image originale | Alpha = 1 Beta = 40 | Alpha = 1,5 Beta = 0 |
|-----------------|---------------------|----------------------|
| ![](images_rapport/mon_og_hist.png) | ![](images_rapport/a1b40_hist.png) | ![](images_rapport/a15b0_hist.png) |

On constate que l'augementation de beta décale l'histogramme vers la droite, augmentant ainsi la quantité de blanc dans l'image.