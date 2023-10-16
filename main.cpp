/*
FCAI – OOP Programming – 2023 - Assignment 1
Program Name:				CS213-2023-20220293-20220361-20220186-A1-Part1.cpp
Last Modification Date:	09/10/2023
Author1 and ID and Group:	Mohamed Atef Mouad       20220293 mo7amed3atf24@gmail.com
Author2 and ID and Group:	Nour Shaaban             20220361 nourshaaban59@gmail.com
Author3 and ID and Group:	Abdelrahman Ahmed Elsayd 20220186 toti2017abdo@gmail.com
Doctor :		Mohamed El Ramly

This code provides a set of image processing functions for both grayscale (GS) and RGB images. It organizes these functions using function pointers to enhance code readability and maintainability.
typedef void (*ImageProcessingFunction)(bool);: This line defines a typedef for a function pointer type named ImageProcessingFunction.
It specifies that this function pointer type can point to functions that take a single bool parameter and return void this bool determine witch to use RGB algoritiam or GS.

ImageProcessingFunction arr[16]={nullptr,Black_white,Neg_Image,Merge_image,Flip_image,Rotate_image,Darken_Lighten,Detect_Edges,Enlarge_Image,Shrink_image,mirror_image,Shuffle_image,BlurImage,CropImage,skewHorizontal,skewVertical};: \
This line declares an array arr of type ImageProcessingFunction. It initializes this array with pointers to various image processing functions. Each element of the array corresponds to a specific image processing function, such as "Black_white," "Neg_Image," "Merge_image," and so on.

string s;: This line declares a string variable named s to store user input for specifying whether the image is in RGB or grayscale format.

start:: This is a label in the code. It's used for creating a loop to allow the user to perform multiple image processing operations in sequence.

short in = input();: This line calls the input() function to get the user's choice of image processing operation and stores it in the variable in. The input() function returns a number between 1 and 15 corresponding to the selected operation.
Code Structure

Image Loading:

The loadImage function prompts the user to enter the source image file name and appends ".bmp" to it.
Similarly, loadRGBImage performs the same task but for RGB images.


Image Saving:

The saveImage and saveRGBImage functions prompt the user to specify the target image file name and save the processed image as a BMP file.
Image Processing Functions:

The code defines several image processing functions, each accessible via a function pointer. These functions operate on both GS and RGB images.
User Interaction

The main function begins by:

Accepting user input to choose an image processing filter.
Verifying the input's validity, ensuring it falls within the range of available filters (1 to 15).
Asking the user whether their image is in RGB or GS format.
Loading the image accordingly using the appropriate loading function (loadRGBImage or loadImage).
Filters and Their Descriptions

The code implements 15 different filters:

1 - Black and White:

For GS images, it calculates the average grayscale value and sets pixels above the average to white and below to black.
For RGB images, it calculates the average for each color channel and applies a similar thresholding.

2 - Invert Image:

Inverts each pixel value by subtracting it from 255.

3 - Merge Images:

For GS images, it loads a second image, averages corresponding pixels, and stores the result in the first image.
For RGB images, it calculates channel-wise averages and combines the two images.

4 - Flip Image:

This filter offers two options: horizontal (H) and vertical (V) flipping.
For horizontal flipping (H), it swaps pixels from the left half of the image with pixels from the right half along the vertical axis.
For vertical flipping (V), it swaps pixels from the top half of the image with pixels from the bottom half along the horizontal axis.
This revised description clarifies that horizontal flipping swaps left and right, while vertical flipping swaps top and bottom.

5 - Rotate Image:

Rotates the image by user-defined degrees (90, 180, or 270) by applying multiple 90-degree rotations.
For a 90-degree rotation, the code performs a single rotation operation, swapping pixels to rotate the image clockwise.
For a 180-degree rotation, it executes two consecutive 90-degree rotations.
For a 270-degree rotation, it applies three 90-degree rotations.
During a 90-degree rotation:
An empty image is created as a copy of the original.
Pixels in the original image are swapped to the new image such that the first row becomes the last column, the second row becomes the second-to-last column, and so on.
This rotation algorithm is applied to both grayscale (GS) and RGB images, ensuring consistent results.

6 - Darken and Lighten Image:

This filter allows the user to choose between two options: Darken (D) or Lighten (L).
When choosing to Darken (D), the code applies a factor of 0.5 to pixel values, reducing their intensity by half.
When choosing to Lighten (L), the code applies a factor of 1.5 to pixel values, increasing their intensity by one and a half times.
This operation affects both grayscale (GS) and RGB images uniformly, making them darker or lighter based on the chosen option

7 - Detect Edges:
This function takes a boolean parameter 'n' to determine whether to apply the edge detection algorithm to grayscale (GS) or RGB images.
In the case of GS images, it calculates the average pixel intensity in the image and identifies edges by comparing adjacent pixel intensities.
For RGB images, it calculates the average intensity for each color channel (red, green, and blue) and detects edges independently in each channel.
Edges are identified by significant changes in pixel intensity compared to the calculated averages.

8 - Enlarge Image:
This function allows the user to enlarge a quarter of the image (quarters numbered 1 to 4).
The user chooses which quarter to enlarge.
For grayscale (GS) images, it enlarges the selected quarter by replicating pixel values.
For RGB images, it enlarges the selected quarter by replicating color information in the three color channels (red, green, and blue).

9 - Shrink Image:
The 'Shrink Image' function lets the user shrink an image by a factor of 1/2, 1/3, or 1/4.
The user specifies the desired shrinking factor.
For RGB images, it reduces the image size by averaging pixel values in non-overlapping blocks of pixels.
For grayscale (GS) images, it similarly reduces the image size by averaging pixel intensities in non-overlapping blocks.
The result is a smaller version of the original image.

10 - Shuffle_image:
This function shuffles or reorders portions of the image based on user input.
It asks the user to input the order in which they want the four quadrants of the image to be arranged.
It divides the image into four quadrants and rearranges them according to the user's input.

11 - mirror_image:
This function mirrors the image horizontally, vertically, or in both directions based on user input.
It asks the user to choose which half of the image they want to mirror (Left, Right, Up, or Down) and then performs the mirroring accordingly.

12 - BlurImage:
This function applies a blur effect to the image.
It calculates a blurred version of the image by taking the average of pixel values from neighboring pixels.
The degree of blur depends on the user's choice of the function (grayscale or RGB).

13 - CropImage:
This function allows the user to crop a rectangular region from the image.
It asks the user to input the starting point (X, Y) and the dimensions (length L and width W) of the region to be cropped.
It then sets the pixel values outside this region to white (255) for grayscale images or initializes the color channels to white (255, 255, 255) for RGB images.

14 - skewHorizontal:
This function skews the image horizontally based on the user's input angle.
It calculates the new position of each pixel after applying horizontal skewing and assigns the average value from neighboring pixels to the skewed positions.
The degree of skewing depends on the user's input angle.

15 - skewVertical:
This function skews the image vertically based on the user's input angle.
Similar to skewHorizontal, it calculates the new position of each pixel after applying vertical skewing and assigns the average value from neighboring pixels to the skewed positions.
The degree of skewing depends on the user's input angle.

These functions provide various image processing and transformation capabilities, allowing users to manipulate images in different ways. Users can choose between grayscale (n = 1) and RGB (n = 0) modes for most of these functions to apply the transformations to either grayscale or color images.

*/
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include "bmplib.h"
using namespace std;
unsigned char imageGS[SIZE][SIZE];
unsigned char imageRGB[SIZE][SIZE][RGB];
char imageFileName[100];
void loadImage();
void saveImage();
void saveImageRGB();
void Black_white(bool n);
void Neg_Image(bool n);
void Merge_image(bool n);
void Flip_image(bool n);
void Rotate_image(bool n);
void Darken_Lighten(bool n);
void Detect_Edges(bool n);
void Enlarge_Image(bool n);
void Shrink_image(bool n);
void Shuffle_image(bool n);
void mirror_image(bool n);
void BlurImage(bool n);
void CropImage(bool n);
void skewHorizontal(bool n);
void skewVertical(bool n);
short input();
typedef void (*ImageProcessingFunction)(bool);

int main()
{
    ImageProcessingFunction arr[16]={nullptr,Black_white,Neg_Image,Merge_image,Flip_image,Rotate_image,Darken_Lighten,Detect_Edges,Enlarge_Image,Shrink_image,mirror_image,Shuffle_image,BlurImage,CropImage,skewHorizontal,skewVertical};
    start:;
    short in=input();
    if (in >= 1 && in <= 15) {
        bool par=1;
        loadImage();
        readGSBMP(imageFileName, imageGS);
        if (arr[in] != nullptr) {
            arr[in](par);
            saveImage();
            cout<<"\ndo you wanna do another filter?(Y OR F): ";
            char cho;cin>>cho;
            if(cho=='Y'||cho=='y') goto start;
            else if(cho=='F'||cho=='f') cout<<"OK BYE!";
            else cout<<"INVALID INPUT!";
        } else {
            cout << "Invalid function selection!\n";
            return 1;
        }
    } else {
        cout << "Invalid input!\n";
        return 1;
    }
    return 0;
}

void loadImage () {
   cout << "Enter the source image file name: ";
   cin >> imageFileName;
   strcat (imageFileName, ".bmp");
}
void saveImage () {
   cout << "Enter the target image file name: ";
   cin >> imageFileName;
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName,imageGS);
}
void saveImageRGB () {
   cout << "Enter the target image file name: ";
   cin >> imageFileName;
   strcat (imageFileName, ".bmp");
   writeRGBBMP(imageFileName,imageRGB);
}
void Black_white(bool n)
{
	/*
 	* Convert the loaded image to black and white.
 	* This function converts the loaded image to black and white (grayscale). For color
 	* images, it calculates the average intensity of the red, green, and blue channels for
 	* each pixel and sets the resulting grayscale value based on the average intensity.
 	* For grayscale images, it compares each pixel's intensity to the average intensity and
 	* assigns either white or black based on the comparison.
 	* param n - A boolean indicating whether the current image is grayscale (true) or color (false).
 	*/
    int Total = 0;
     if (!n) {
        // Process color image
        int r = 0, g = 0, b = 0;

        // Calculate the sum of intensities for each color channel
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                r += imageRGB[i][j][0];
                g += imageRGB[i][j][1];
                b += imageRGB[i][j][2];
            }
        }

        // Calculate average intensities
        int avgr = r / (SIZE * SIZE);
        int avgg = g / (SIZE * SIZE);
        int avgb = b / (SIZE * SIZE);

        // Convert to black and white based on average intensities
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (imageRGB[i][j][0] > avgr||imageRGB[i][j][1] > avgg||imageRGB[i][j][2] > avgb){
                    imageRGB[i][j][0] = 255;
                    imageRGB[i][j][1] = 255;
                    imageRGB[i][j][2] = 255;
                }
                else
                {
                    imageRGB[i][j][0] = 0;
                    imageRGB[i][j][1] = 0;
                    imageRGB[i][j][2] = 0;
                }
            }
        }
    } else {
        // Process grayscale image
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                Total += imageGS[i][j];
            }
        }

        // Calculate average intensity
        int avg = Total / (SIZE * SIZE);

        // Convert to black and white based on average intensity
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                int Sum = imageGS[i][j];
                if (Sum > avg) {
                    imageGS[i][j] = 255;
                } else if (Sum < avg) {
                    imageGS[i][j] = 0;
                }
            }
        }
    }

}
void Neg_Image(bool n)
{
	/*
 	* Create the negative of the loaded image.
 	* This function creates the negative image of the loaded image. For grayscale images,
 	* it inverts the intensity of each pixel. For color images, it inverts the intensity
 	* of each color channel (red, green, and blue) separately.
 	* param n - A boolean indicating whether the current image is grayscale (true) or color (false).
 	*/
    if (!n) {
        // Process color image
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                imageRGB[i][j][0] = 255 - imageRGB[i][j][0];
                imageRGB[i][j][1] = 255 - imageRGB[i][j][1];
                imageRGB[i][j][2] = 255 - imageRGB[i][j][2];
            }
        }
    } else {
        // Process grayscale image
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                imageGS[i][j] = 255 - imageGS[i][j];
            }
        }
    }

}
void Merge_image(bool n)
{
	/*
 	* Merge the loaded image with another image.
 	* This function loads another image and merges it with the currently loaded image.
 	* The merging process involves taking the average of corresponding pixel values
 	* between the two images for each channel (red, green, and blue in color images, or
 	* grayscale intensity in grayscale images).
 	* param n - A boolean indicating whether the current image is grayscale (true) or color (false).
 	*/
    cout << "You Should ";
    loadImage();

    if (n) {
        // Process grayscale image
        unsigned char imageGS2[SIZE][SIZE];
        readGSBMP(imageFileName, imageGS2);

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                imageGS[i][j] = (imageGS[i][j] + imageGS2[i][j]) / 2;
            }
        }
    } else {
        // Process color image
        unsigned char imageRGB2[SIZE][SIZE][RGB];
        readRGBBMP(imageFileName, imageRGB2);

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                imageRGB[i][j][0] = (imageRGB2[i][j][0] + imageRGB[i][j][0]) / 2;
                imageRGB[i][j][1] = (imageRGB2[i][j][1] + imageRGB[i][j][1]) / 2;
                imageRGB[i][j][2] = (imageRGB2[i][j][2] + imageRGB[i][j][2]) / 2;
            }
        }
    }

}
void Flip_image(bool n)
{
	/*
 	* Flip the loaded image horizontally or vertically.
 	* This function allows you to flip the loaded image either horizontally (left-to-right)
 	* or vertically (top-to-bottom).
 	* param n - A boolean indicating whether the image is grayscale (true) or color (false).
 	*/
 	fl:;
    cout << "\nPlease Enter your Choice: Horizontal Flip (H) or Vertical Flip (V): ";
    char s;
    cin >> s;

    if (s == 'H' || s == 'V') {
        if (s == 'H') {
            // Horizontal flip
            if (!n) {
                // Process color image
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0, y = SIZE - 1; j < SIZE / 2; j++, y--) {
                        swap(imageRGB[i][j][0], imageRGB[i][y][0]);
                        swap(imageRGB[i][j][1], imageRGB[i][y][1]);
                        swap(imageRGB[i][j][2], imageRGB[i][y][2]);
                    }
                }
            } else {
                // Process grayscale image
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0, y = SIZE - 1; j < SIZE / 2; j++, y--) {
                        swap(imageGS[i][j], imageGS[i][y]);
                    }
                }
            }
        } else if (s == 'V') {
            // Vertical flip
            if (!n) {
                // Process color image
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0, y = SIZE - 1; j < SIZE / 2; j++, y--) {
                        swap(imageRGB[j][i][0], imageRGB[y][i][0]);
                        swap(imageRGB[j][i][1], imageRGB[y][i][1]);
                        swap(imageRGB[j][i][2], imageRGB[y][i][2]);
                    }
                }
            } else {
                // Process grayscale image
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0, y = SIZE - 1; j < SIZE / 2; j++, y--) {
                        swap(imageGS[j][i], imageGS[y][i]);
                    }
                }
            }
        }
    } else {
        cout << "Invalid Input! Please enter 'H' for Horizontal Flip or 'V' for Vertical Flip." << endl;
        goto fl;
    }
}
void Rotate_image(bool n)
{
	/*
	* Rotate the loaded image by a specified degree (90, 180, 270).
 	* This function allows you to rotate the loaded image by 90, 180, or 270 degrees in a clockwise direction.
	* param n - A boolean indicating whether the image is grayscale (true) or color (false).
	*/
	rot:;
    cout << "Enter the degree of rotation (90, 180, 270): ";
    short deg;
    cin >> deg;

    if (deg == 90 || deg == 180 || deg == 270) {
        int rotations = deg / 90;

        if (!n) {
            // Process color image
            unsigned char tempRGB[SIZE][SIZE][RGB];

            for (int k = 0; k < rotations; k++) {
                // Copy the image data to a temporary array
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j < SIZE; j++) {
                        tempRGB[i][j][0] = imageRGB[i][j][0];
                        tempRGB[i][j][1] = imageRGB[i][j][1];
                        tempRGB[i][j][2] = imageRGB[i][j][2];
                    }
                }

                // Rotate the image clockwise
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j < SIZE; j++) {
                        imageRGB[i][j][0] = tempRGB[SIZE - 1 - j][i][0];
                        imageRGB[i][j][1] = tempRGB[SIZE - 1 - j][i][1];
                        imageRGB[i][j][2] = tempRGB[SIZE - 1 - j][i][2];
                    }
                }
            }
        } else {
            // Process grayscale image
            unsigned char tempGS[SIZE][SIZE];

            for (int k = 0; k < rotations; k++) {
                // Copy the image data to a temporary array
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j < SIZE; j++) {
                        tempGS[i][j] = imageGS[i][j];
                    }
                }

                // Rotate the image clockwise
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j < SIZE; j++) {
                        imageGS[i][j] = tempGS[SIZE - 1 - j][i];
                    }
                }
            }
        }
    } else {
        cout << "Invalid Input! Please enter 90, 180, or 270 for rotation." << endl;
        goto rot;
    }
}
void Darken_Lighten(bool n)
{
	/*
 	* Darken or lighten the loaded image.
 	* This function allows you to darken or lighten the loaded image. You can specify the desired effect using 'D' to darken or 'L' to lighten.
 	* param n - A boolean indicating whether the image is grayscale (true) or color (false).
 	*/
    cout<<"\n you want it Darken or Lighten( D or L ): ";
    char s;cin>>s;
    double factor=0.0;
    // Check if the user wants to darken or lighten the image
    if (s == 'D') {
        factor = 0.5; // Darken by reducing pixel values to half
    } else if (s == 'L') {
        factor = 1.5; // Lighten by increasing pixel values by 1.5 times
    } else {
        cout << "Invalid Input!" << endl;
        return;
    }

    if (!n) {
        // Process color image
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                // Adjust each RGB channel based on the chosen factor
                if (s == 'D') {
                    imageRGB[i][j][0] = max(0, (int)(imageRGB[i][j][0] * factor));
                    imageRGB[i][j][1] = max(0, (int)(imageRGB[i][j][1] * factor));
                    imageRGB[i][j][2] = max(0, (int)(imageRGB[i][j][2] * factor));
                } else {
                    imageRGB[i][j][0] = min(255, (int)(imageRGB[i][j][0] * factor));
                    imageRGB[i][j][1] = min(255, (int)(imageRGB[i][j][1] * factor));
                    imageRGB[i][j][2] = min(255, (int)(imageRGB[i][j][2] * factor));
                }
            }
        }
    } else {
        // Process grayscale image
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                // Adjust pixel values based on the chosen factor
                if (s == 'D') {
                    imageGS[i][j] = max(0, (int)(imageGS[i][j] * factor));
                } else {
                    imageGS[i][j] = min(255, (int)(imageGS[i][j] * factor));
                }
            }
        }
    }
}
void Detect_Edges(bool n)
{
	/*
 	* Detect edges in the loaded image.
 	* This function detects edges in the loaded image, highlighting areas of significant color intensity change.
 	* For grayscale images, it identifies intensity changes. For color images, it considers intensity changes in each RGB channel.
 	* param n - A boolean indicating whether the image is grayscale (true) or color (false).
 	*/
    int total =0;
    if(!n)
    {
        unsigned char tempRGB[SIZE][SIZE][RGB];
        int tr=0,tg=0,tb=0;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                tr+=imageRGB[i][j][0];
                tg+=imageRGB[i][j][1];
                tb+=imageRGB[i][j][2];
                tempRGB[i][j][0]=255;
                tempRGB[i][j][1]=255;
                tempRGB[i][j][2]=255;
            }
        }
        tr/=(SIZE*SIZE);
        tg/=(SIZE*SIZE);
        tb/=(SIZE*SIZE);
        for(int i=0;i<SIZE;i++)
        {
            for(int j=0;j+1<SIZE;j++)
            {
                if((imageRGB[i][j][0]>tr&&imageRGB[i][j+1][0]<tr)||(imageRGB[i][j][0]<tr&&imageRGB[i][j+1][0]>tr))
                {
                    tempRGB[i][j][0]=0;
                }if((imageRGB[i][j][1]>tg&&imageRGB[i][j+1][1]<tg)||(imageRGB[i][j][1]<tg&&imageRGB[i][j+1][1]>tg))
                {
                    tempRGB[i][j][1]=0;
                }if((imageRGB[i][j][2]>tb&&imageRGB[i][j+1][2]<tb)||(imageRGB[i][j][2]<tb&&imageRGB[i][j+1][2]>tb))
                {
                    tempRGB[i][j][2]=0;
                }
            }
        }for(int i=0;i+1<SIZE;i++)
        {
            for(int j=0;j<SIZE;j++)
            {
                if((imageRGB[i][j][0]>tr&&imageRGB[i+1][j][0]<tr)||(imageRGB[i][j][0]<tr&&imageRGB[i+1][j][0]>tr))
                {
                    tempRGB[i][j][0]=0;
                }if((imageRGB[i][j][1]>tg&&imageRGB[i+1][j][1]<tg)||(imageRGB[i][j][1]<tg&&imageRGB[i+1][j][1]>tg))
                {
                    tempRGB[i][j][1]=0;
                }if((imageRGB[i][j][2]>tb&&imageRGB[i+1][j][2]<tb)||(imageRGB[i][j][2]<tb&&imageRGB[i+1][j][2]>tb))
                {
                    tempRGB[i][j][2]=0;
                }
            }
        }for(int i=SIZE-1;i>0;i--)
        {
            for(int j=SIZE;j>=0;j--)
            {
                if((imageRGB[i][j][0]>tr&&imageRGB[i-1][j][0]<tr)||(imageRGB[i][j][0]<tr&&imageRGB[i-1][j][0]>tr))
                {
                    tempRGB[i][j][0]=0;
                }if((imageRGB[i][j][1]>tg&&imageRGB[i-1][j][1]<tg)||(imageRGB[i][j][1]<tg&&imageRGB[i-1][j][1]>tg))
                {
                    tempRGB[i][j][1]=0;
                }if((imageRGB[i][j][2]>tb&&imageRGB[i-1][j][2]<tb)||(imageRGB[i][j][2]<tb&&imageRGB[i-1][j][2]>tb))
                {
                    tempRGB[i][j][2]=0;
                }
            }
        }for(int i=SIZE-1;i>=0;i--)
        {
            for(int j=SIZE;j>0;j--)
            {
                if((imageRGB[i][j][0]>tr&&imageRGB[i][j-1][0]<tr)||(imageRGB[i][j][0]<tr&&imageRGB[i][j-1][0]>tr))
                {
                    tempRGB[i][j][0]=0;
                }if((imageRGB[i][j][1]>tg&&imageRGB[i][j-1][1]<tg)||(imageRGB[i][j][1]<tg&&imageRGB[i][j-1][1]>tg))
                {
                    tempRGB[i][j][1]=0;
                }if((imageRGB[i][j][2]>tb&&imageRGB[i][j-1][2]<tb)||(imageRGB[i][j][2]<tb&&imageRGB[i][j-1][2]>tb))
                {
                    tempRGB[i][j][2]=0;
                }
            }
        }
        for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for(int k=0;k<3;k++)
            {
                imageRGB[i][j][k]=tempRGB[i][j][k];
            }
        }
    }
    }
    else
    {
        unsigned char tempRGB[SIZE][SIZE];
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                total+=imageGS[i][j];
                tempRGB[i][j]=255;
            }
        }
        int avg=total/(SIZE*SIZE);
        for(int i=0;i<SIZE;i++)
        {
            for(int j=0;j+1<SIZE;j++)
            {
                if((imageGS[i][j]>avg&&imageGS[i][j+1]<avg)||(imageGS[i][j]<avg&&imageGS[i][j+1]>avg))
                {
                    tempRGB[i][j]=0;
                }
            }
        }for(int i=0;i+1<SIZE;i++)
        {
            for(int j=0;j<SIZE;j++)
            {
                if((imageGS[i][j]>avg&&imageGS[i+1][j]<avg)||(imageGS[i][j]<avg&&imageGS[i+1][j]>avg))
                {
                    tempRGB[i][j]=0;
                }
            }
        }
        for(int i=SIZE-1;i>=0;i--)
        {
            for(int j=SIZE;j>0;j--)
            {
                if((imageGS[i][j]>avg&&imageGS[i][j-1]<avg)||(imageGS[i][j]<avg&&imageGS[i][j-1]>avg))
                {
                    tempRGB[i][j]=0;
                }
            }
        }
        for(int i=SIZE-1;i>0;i--)
        {
            for(int j=SIZE;j>=0;j--)
            {
                if((imageGS[i][j]>avg&&imageGS[i-1][j]<avg)||(imageGS[i][j]<avg&&imageGS[i-1][j]>avg))
                {
                    tempRGB[i][j]=0;
                }
            }
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                imageGS[i][j]=tempRGB[i][j];
            }
        }

        }

}
void Enlarge_Image(bool n)
{
	/*
	* Enlarge a quarter of the loaded image.
	* The function allows the user to select and enlarge one of the four quarters
 	* (1, 2, 3, or 4) of the image in both grayscale and RGB modes.
 	* param n - A boolean indicating whether the image is grayscale (true) or RGB (false).
 	*/
    cout<<"Which quarter you want to enlarge(1 , 2 , 3 , 4): ";
    short ch;cin>>ch;
    unsigned char temp[SIZE][SIZE];
    unsigned char tempRGB[SIZE][SIZE][RGB];
    if (ch == 1) {
        if (n) {
            // Enlarge the selected grayscale quarter
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    temp[i][j] = imageGS[i / 2][j / 2];
                }
            }

            // Copy the enlarged grayscale quarter back to the image
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    imageGS[i][j] = temp[i][j];
                }
            }
        } else {
            // Enlarge the selected RGB quarter
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    tempRGB[i][j][0] = imageRGB[i / 2][j / 2][0];
                    tempRGB[i][j][1] = imageRGB[i / 2][j / 2][1];
                    tempRGB[i][j][2] = imageRGB[i / 2][j / 2][2];
                }
            }

            // Copy the enlarged RGB quarter back to the image
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    imageRGB[i][j][0] = tempRGB[i][j][0];
                    imageRGB[i][j][1] = tempRGB[i][j][1];
                    imageRGB[i][j][2] = tempRGB[i][j][2];
                }
            }
        }
    }
    else if(ch==2)
    {
        if(n)
        {
            for(int i=0;i<SIZE;i++)
            {
                for(int j=0;j<SIZE;j++)
                {
                    temp[i][j]=imageGS[i/2][j/2+SIZE/2];
                }
            }
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    imageGS[i][j]=temp[i][j];
                }
            }
        }
        else
        {
            for(int i=0;i<SIZE;i++)
            {
                for(int j=0;j<SIZE;j++)
                {
                    tempRGB[i][j][0]=imageRGB[i/2][j/2+SIZE/2][0];
                    tempRGB[i][j][1]=imageRGB[i/2][j/2+SIZE/2][1];
                    tempRGB[i][j][2]=imageRGB[i/2][j/2+SIZE/2][2];
                }
            }
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    imageRGB[i][j][0]=tempRGB[i][j][0];
                    imageRGB[i][j][1]=tempRGB[i][j][1];
                    imageRGB[i][j][2]=tempRGB[i][j][2];
                }
            }
        }
    }
    else if(ch==4)
    {
        if(n)
        {
            for(int i=0;i<SIZE;i++)
            {
                for(int j=0;j<SIZE;j++)
                {
                    temp[i][j]=imageGS[i/2+SIZE/2][j/2+SIZE/2];
                }
            }
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    imageGS[i][j]=temp[i][j];
                }
            }
        }
        else
        {
            for(int i=0;i<SIZE;i++)
            {
                for(int j=0;j<SIZE;j++)
                {
                    tempRGB[i][j][0]=imageRGB[i/2+SIZE/2][j/2+SIZE/2][0];
                    tempRGB[i][j][1]=imageRGB[i/2+SIZE/2][j/2+SIZE/2][1];
                    tempRGB[i][j][2]=imageRGB[i/2+SIZE/2][j/2+SIZE/2][2];
                }
            }
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    imageRGB[i][j][0]=tempRGB[i][j][0];
                    imageRGB[i][j][1]=tempRGB[i][j][1];
                    imageRGB[i][j][2]=tempRGB[i][j][2];
                }
            }
        }
    }

}
void Shrink_image(bool n) {
	/**
 	* Shrink the loaded image by a specified factor.
	* The function allows the user to shrink the image by a factor of 1/2, 1/3, or 1/4
	* in both grayscale and RGB modes. It resizes the image while maintaining aspect ratio.
 	* param n - A boolean indicating whether the image is grayscale (true) or RGB (false).
 	*/
    cout << "Enter the factor to shrink the image (1/2, 1/3, 1/4): ";
    string factor1;
    cin >> factor1;
    float factor = 0.0;

    // Convert the user-input factor string to a floating-point number
    if (factor1 == "1/2") {
        factor = 1.0 / 2;
    } else if (factor1 == "1/3") {
        factor = 1.0 / 3;
    } else if (factor1 == "1/4") {
        factor = 1.0 / 4;
    } else {
        cout << "Invalid factor choice." << endl;
        return;
    }

    // Calculate the new width based on the chosen factor
    int new_width = SIZE * factor;

    // Resize the image while maintaining aspect ratio
    if (!n) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (i <= new_width && j <= new_width) {
                    // Copy pixel values from the original image to the resized image
                    imageRGB[i][j][0] = imageRGB[(int)(i / factor)][(int)(j / factor)][0];
                    imageRGB[i][j][1] = imageRGB[(int)(i / factor)][(int)(j / factor)][1];
                    imageRGB[i][j][2] = imageRGB[(int)(i / factor)][(int)(j / factor)][2];
                } else {
                    // Set pixels outside the resized area to white (255, 255, 255)
                    imageRGB[i][j][0] = 255;
                    imageRGB[i][j][1] = 255;
                    imageRGB[i][j][2] = 255;
                }
            }
        }
    } else {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (i <= new_width && j <= new_width) {
                    // Copy pixel values from the original image to the resized image
                    imageGS[i][j] = imageGS[(int)(i / factor)][(int)(j / factor)];
                } else {
                    // Set pixels outside the resized area to white (255)
                    imageGS[i][j] = 255;
                }
            }
        }
    }
}
void Shuffle_image(bool n)
{
	/*
 	* Shuffle the loaded image based on user-defined order.
 	* The function shuffles the image into four quadrants based on the provided order,
 	* combining them into a single image. The user specifies the order as an array of
 	* four integers (1, 2, 3, 4), where each number represents a quadrant. The function
 	* supports both grayscale and RGB images.
 	* param n - A boolean indicating whether the image is grayscale (true) or RGB (false).
 	*/

    int arr[4], cnt{1}, r = 0, c = 0, j = 0, k = 0, newc = 0, newr = 0;

    // Prompt the user to enter the order of the image quadrants
    cout << "Enter the order of the image you want: ";

    // Read the user-defined order into an array
    for (int i = 0; i < 4; i++) {
        cin >> arr[i];
    }

    // Create an array to track whether each quadrant number has been found
    bool found[4] = { false };

    // Check if each quadrant number is found and mark it as found
    for (int i = 0; i < 4; i++) {
        if (arr[i] == 1) found[0] = true;
        if (arr[i] == 2) found[1] = true;
        if (arr[i] == 3) found[2] = true;
        if (arr[i] == 4) found[3] = true;
    }

    // Check if any quadrant number is missing
    for (int i = 0; i < 4; i++) {
        if (!found[i]) {
            cout << "Invalid input! ";
            return;
        }
    }

    unsigned image[SIZE][SIZE], imager[SIZE][SIZE][RGB];

    // Loop through the user-defined order and shuffle the image quadrants
    for (int i = 0; i < 4; i++) {
        if (arr[i] == 1 && n) {
            // Shuffle grayscale image quadrant 1
            for (r = newr, j = 0; j < SIZE / 2; r++, j++) {
                for (c = newc, k = 0; k < SIZE / 2; c++, k++) {
                    image[r][c] = imageGS[j][k];
                }
            }
        } else if (arr[i] == 1 && !n) {
            // Shuffle RGB image quadrant 1
            for (r = newr, j = 0; j < SIZE / 2; r++, j++) {
                for (c = newc, k = 0; k < SIZE / 2; c++, k++) {
                    imager[r][c][0] = imageRGB[j][k][0];
                    imager[r][c][1] = imageRGB[j][k][1];
                    imager[r][c][2] = imageRGB[j][k][2];
                }
            }
        } else if (arr[i] == 2 && n) {
            // Shuffle grayscale image quadrant 2
            for (r = newr, j = 0; j < SIZE / 2; r++, j++) {
                for (c = newc, k = SIZE / 2; k < SIZE; c++, k++) {
                    image[r][c] = imageGS[j][k];
                }
            }
        } else if (arr[i] == 2 && !n) {
            // Shuffle RGB image quadrant 2
            for (r = newr, j = 0; j < SIZE / 2; r++, j++) {
                for (c = newc, k = SIZE / 2; k < SIZE; c++, k++) {
                    imager[r][c][0] = imageRGB[j][k][0];
                    imager[r][c][1] = imageRGB[j][k][1];
                    imager[r][c][2] = imageRGB[j][k][2];
                }
            }
        } else if (arr[i] == 3 && n) {
            // Shuffle grayscale image quadrant 3
            for (r = newr, j = SIZE / 2; j < SIZE; r++, j++) {
                for (c = newc, k = 0; k < SIZE / 2; c++, k++) {
                    image[r][c] = imageGS[j][k];
                }
            }
        } else if (arr[i] == 3 && !n) {
            // Shuffle RGB image quadrant 3
            for (r = newr, j = SIZE / 2; j < SIZE; r++, j++) {
                for (c = newc, k = 0; k < SIZE / 2; c++, k++) {
                    imager[r][c][0] = imageRGB[j][k][0];
                    imager[r][c][1] = imageRGB[j][k][1];
                    imager[r][c][2] = imageRGB[j][k][2];
                }
            }
        } else if (arr[i] == 4 && n) {
            // Shuffle grayscale image quadrant 4
            for (r = newr, j = SIZE / 2; j < SIZE; r++, j++) {
                for (c = newc, k = SIZE / 2; k < SIZE; c++, k++) {
                    image[r][c] = imageGS[j][k];
                }
            }
        } else {
            // Shuffle RGB image quadrant 4
            for (r = newr, j = SIZE / 2; j < SIZE; r++, j++) {
                for (c = newc, k = SIZE / 2; k < SIZE; c++, k++) {
                    imager[r][c][0] = imageRGB[j][k][0];
                    imager[r][c][1] = imageRGB[j][k][1];
                    imager[r][c][2] = imageRGB[j][k][2];
                }
            }
        }

        ++cnt;

        // Update the new row and column offsets based on the quadrant count
        if (cnt == 2) newr = 0, newc = SIZE / 2;
        else if (cnt == 3) newr = SIZE / 2, newc = 0;
        else if (cnt == 4) newr = SIZE / 2, newc = SIZE / 2;
    }

    // Copy the shuffled image back to the original image array
    if (n) {
        for (int i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                imageGS[i][j] = image[i][j];
            }
        }
    } else {
        for (int i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                imageRGB[i][j][0] = imager[i][j][0];
                imageRGB[i][j][1] = imager[i][j][1];
                imageRGB[i][j][2] = imager[i][j][2];
            }
        }
    }
}
void mirror_image(bool n)
{
	/*
 	* Function: mirror_image
 	* ----------------------
 	* Mirror the loaded image in the specified direction.
	 * The function can mirror the image horizontally (left-to-right),
 	* vertically (up-to-down), or both, depending on the user's choice.
 	*
 	* Parameters:
 	*   - bool n: A flag indicating whether the image is grayscale (true) or RGB (false).
 	*
 	* Mirror Directions:
	 *   - 'L' (Left): Mirror the image horizontally (left-to-right).
 	*   - 'R' (Right): Mirror the image horizontally (right-to-left).
 	*   - 'U' (Up): Mirror the image vertically (up-to-down).
 	*   - 'D' (Down): Mirror the image vertically (down-to-up).
 	* note When n is true (grayscale), the function works on the imageGS array. When n is false (RGB), it works on the imageRGB array.
	 */
    cout<<"Enter the half you want(L , R , U , D): ";
    char co;cin>>co;
    if(co!='L'&&co!='R'&&co!='U'&&co!='D')
    {
        cout<<"INVALID INPUT!";
        return;
    }
    if (co == 'L') {
        // Mirror the image horizontally (left-to-right)
        if (!n) {
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0, y = SIZE - 1; j < y; j++, y--) {
                    for (int k = 0; k < SIZE; k++) {
                        imageRGB[i][y][0] = imageRGB[i][j][0];
                        imageRGB[i][y][1] = imageRGB[i][j][1];
                        imageRGB[i][y][2] = imageRGB[i][j][2];
                    }
                }
            }
        } else {
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0, y = SIZE - 1; j < y; j++, y--) {
                    imageGS[i][y] = imageGS[i][j];
                }
            }
        }
    } else if (co == 'R') {
        // Mirror the image horizontally (right-to-left)
        if (!n) {
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0, y = SIZE - 1; j < y; j++, y--) {
                    for (int k = 0; k < SIZE; k++) {
                        imageRGB[i][j][0] = imageRGB[i][y][0];
                        imageRGB[i][j][1] = imageRGB[i][y][1];
                        imageRGB[i][j][2] = imageRGB[i][y][2];
                    }
                }
            }
        } else {
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0, y = SIZE - 1; j < y; j++, y--) {
                    imageGS[i][j] = imageGS[i][y];
                }
            }
        }
    } else if (co == 'D') {
        // Mirror the image vertically (down-to-up)
        if (!n) {
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0, y = SIZE - 1; j < y; j++, y--) {
                    for (int k = 0; k < SIZE; k++) {
                        imageRGB[j][i][0] = imageRGB[y][i][0];
                        imageRGB[j][i][1] = imageRGB[j][i][1];
                        imageRGB[j][i][2] = imageRGB[y][i][2];
                    }
                }
            }
        } else {
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0, y = SIZE - 1; j < y; j++, y--) {
                    imageGS[j][i] = imageGS[y][i];
                }
            }
        }
    } else {
        // Mirror the image vertically (up-to-down)
        if (!n) {
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0, y = SIZE - 1; j < y; j++, y--) {
                    for (int k = 0; k < SIZE; k++) {
                        imageRGB[y][i][0] = imageRGB[j][i][0];
                        imageRGB[y][i][1] = imageRGB[j][i][1];
                        imageRGB[y][i][2] = imageRGB[j][i][2];
                    }
                }
            }
        } else {
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0, y = SIZE - 1; j < y; j++, y--) {
                    imageGS[y][i] = imageGS[j][i];
                }
            }
        }
    }
}
void BlurImage(bool n){
	/*
 	* Apply a blurring effect to the loaded image.
 	* The function can blur either a grayscale or an RGB image.
 	* The blurring process calculates the average value of the surrounding pixels for each pixel
 	* to create a smoothing effect.
 	* note When n is true (grayscale), the function works on the imageGS array. When n is false (RGB), it works on the imageRGB array.
 	*/

    if (n) {
        // Apply blurring to a grayscale image
        for (int i = 1; i < SIZE - 1; i++) {
            for (int j = 1; j < SIZE - 1; j++) {
                // Calculate the average of the surrounding pixels
                imageGS[i][j] = (imageGS[i + 1][j] + imageGS[i - 1][j] + imageGS[i][j + 1] + imageGS[i][j - 1] +
                                imageGS[i + 2][j] + imageGS[i - 2][j] + imageGS[i][j + 2] + imageGS[i][j - 2]) /
                               8;
            }
        }
    } else {
        // Apply blurring to an RGB image
        for (int i = 0; i < SIZE - 1; i++) {
            for (int j = 0; j < SIZE - 1; j++) {
                for (int k = 0; k < 3; k++) {
                    // Calculate the average of the surrounding pixels for each color channel
                    imageRGB[i][j][k] =
                        (imageRGB[i + 1][j][k] + imageRGB[i - 1][j][k] + imageRGB[i][j + 1][k] + imageRGB[i][j - 1][k] +
                         imageRGB[i + 2][j][k] + imageRGB[i - 2][j][k] + imageRGB[i][j + 2][k] + imageRGB[i][j - 2][k]) /
                        8;
                }
            }
        }
    }
}
void CropImage(bool n){
	/*
 	* Crop the loaded image to a specified region.
 	* The function allows you to crop a rectangular region from the loaded image,
 	* either in grayscale or RGB. The user is prompted to input the starting point (X, Y)
 	* and the dimensions (length L and width W) of the desired cropping region.
 	* note When n is true (grayscale), the function works on the imageGS array. When n is false (RGB), it works on the imageRGB array.
 	*/
    int x, y, l, w;

    // Prompt the user to input the cropping parameters
    cout << "Enter Starting Point X and Y\n       X: ";
    cin >> x;
    cout << "\n       Y: ";
    cin >> y;
    cout << "\nEnter The length   L and width W \n       L: ";
    cin >> l;
    cout << "\n       W: ";
    cin >> w;

    if (!n) {
        // Crop an RGB image
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < 3; k++) {
                    if (i >= x && i <= x + l && j >= y && j <= y + w) {
                        continue;
                    } else {
                        // Set pixel values outside the cropping region to 255 (white)
                        imageRGB[i][j][k] = 255;
                    }
                }
            }
        }
    } else {
        // Crop a grayscale image
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (i >= x && i <= x + l && j >= y && j <= y + w) {
                    continue;
                } else {
                    // Set pixel values outside the cropping region to 255 (white)
                    imageGS[i][j] = 255;
                }
            }
        }
    }

}
void skewHorizontal(bool n) {
    /*
 	* Skew the loaded image horizontally based on the specified degree of skewness.
 	* The function allows you to apply a horizontal skew transformation to the image.
 	* It calculates the new positions of pixels after skewing and applies the
 	* transformation to either a grayscale or RGB image.
 	* note When n is true (grayscale), the function works on the imageGS array. When n is false (RGB), it works on the imageRGB array.
 	*/

    // Prompt the user to enter the degree of skewness
    cout << "Enter The Degree you want: ";
    double skewAngle;
    cin >> skewAngle;

    // Initialize temporary arrays to store the skewed image
    unsigned char tmpImg[SIZE][SIZE]{};
    unsigned char tmpImgRGB[SIZE][SIZE][RGB]{};
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            tmpImg[i][j]=255;
            for(int k=0;k<3;k++) tmpImgRGB[i][j][k]=255;
        }
    }

    // Calculate parameters for the skew transformation
    double toLeave = tan(skewAngle * M_PI / 180.0) * SIZE;
    double compress = (double)SIZE / (SIZE - toLeave);
    double step = toLeave / 256, cur = 0, taken = 0;

    if (!n) {
        // Skew an RGB image
        for (int row = 0; row < SIZE; row++) {
            cur = 0;
            for (int col = toLeave - taken; col < SIZE - taken; col++) {
                int avgr = 0, avgb = 0, avgg = 0, pix = 0;

                // Calculate the average color values of neighboring pixels
                for (int i = max(0, (int)ceil(cur - compress)); i < min(SIZE, (int)ceil(cur + compress)); i++, ++pix) {
                    avgr += imageRGB[row][i][0];
                    avgg += imageRGB[row][i][1];
                    avgb += imageRGB[row][i][2];
                }
                avgr /= max(1, pix);
                avgb /= max(1, pix);
                avgg /= max(1, pix);

                // Store the average color values in the temporary RGB image
                tmpImgRGB[row][col][0] = avgr;
                tmpImgRGB[row][col][1] = avgg;
                tmpImgRGB[row][col][2] = avgb;
                cur += compress;
            }
            taken += step;
        }

        // Copy the skewed RGB image back to the original imageRGB array
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                imageRGB[i][j][0] = tmpImgRGB[i][j][0];
                imageRGB[i][j][1] = tmpImgRGB[i][j][1];
                imageRGB[i][j][2] = tmpImgRGB[i][j][2];
            }
        }
    } else {
        // Skew a grayscale image
        for (int row = 0; row < SIZE; row++) {
            cur = 0;
            for (int col = toLeave - taken; col < SIZE - taken; col++) {
                int avg = 0, pix = 0;

                // Calculate the average pixel value of neighboring pixels
                for (int i = max(0, (int)ceil(cur - compress)); i < min(SIZE, (int)ceil(cur + compress)); i++, ++pix) {
                    avg += imageGS[row][i];
                }
                avg /= max(1, pix);

                // Store the average pixel value in the temporary grayscale image
                tmpImg[row][col] = avg;
                cur += compress;
            }
            taken += step;
        }

        // Copy the skewed grayscale image back to the original imageGS array
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                imageGS[i][j] = tmpImg[i][j];
            }
        }
    }
}

void skewVertical(bool n) {
	/*
 	* Skew the loaded image vertically based on the specified degree of skewness.
 	* The function allows you to apply a vertical skew transformation to the image.
	 * It calculates the new positions of pixels after skewing and applies the
 	* transformation to either a grayscale or RGB image.
 	* note When n is true (grayscale), the function works on the imageGS array. When n is false (RGB), it works on the imageRGB array.
 	*/

    // Prompt the user to enter the degree of skewness
    cout << "Enter The Degree you want: ";
    double skewAngle;
    cin >> skewAngle;

    // Initialize temporary arrays to store the skewed image
    unsigned char tmpImg[SIZE][SIZE]{};
    unsigned char tmpImgRGB[SIZE][SIZE][RGB]{};
     for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            tmpImg[i][j]=255;
            for(int k=0;k<3;k++) tmpImgRGB[i][j][k]=255;
        }
    }

    // Calculate parameters for the skew transformation
    double toLeave = tan(skewAngle * M_PI / 180.0) * SIZE;
    double compress = (double)SIZE / (SIZE - toLeave);
    double step = toLeave / 256, cur = 0, taken = 0;

    if (!n) {
        // Skew an RGB image
        for (int col = 0; col < SIZE; col++) {
            cur = 0;
            for (int row = toLeave - taken; row < SIZE - taken; row++) {
                int avgr = 0, avgb = 0, avgg = 0, pix = 0;

                // Calculate the average color values of neighboring pixels
                for (int i = max(0, (int)ceil(cur - compress)); i < min(SIZE, (int)ceil(cur + compress)); i++, ++pix) {
                    avgr += imageRGB[i][col][0];
                    avgg += imageRGB[i][col][1];
                    avgb += imageRGB[i][col][2];
                }
                avgr /= max(1, pix);
                avgb /= max(1, pix);
                avgg /= max(1, pix);

                // Store the average color values in the temporary RGB image
                tmpImgRGB[row][col][0] = avgr;
                tmpImgRGB[row][col][1] = avgg;
                tmpImgRGB[row][col][2] = avgb;
                cur += compress;
            }
            taken += step;
        }

        // Copy the skewed RGB image back to the original imageRGB array
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                imageRGB[i][j][0] = tmpImgRGB[i][j][0];
                imageRGB[i][j][1] = tmpImgRGB[i][j][1];
                imageRGB[i][j][2] = tmpImgRGB[i][j][2];
            }
        }
    } else {
        // Skew a grayscale image
        for (int col = 0; col < SIZE; col++) {
            cur = 0;
            for (int row = toLeave - taken; row < SIZE - taken; row++) {
                int avg = 0, pix = 0;

                // Calculate the average pixel value of neighboring pixels
                for (int i = max(0, (int)ceil(cur - compress)); i < min(SIZE, (int)ceil(cur + compress)); i++, ++pix) {
                    avg += imageGS[i][col];
                }
                avg /= max(1, pix);

                // Store the average pixel value in the temporary grayscale image
                tmpImg[row][col] = avg;
                cur += compress;
            }
            taken += step;
        }

        // Copy the skewed grayscale image back to the original imageGS array
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                imageGS[i][j] = tmpImg[i][j];
            }
        }
    }
}

short input()
{
	/*
	The input() function is a utility function used to get user input for selecting a specific image processing or transformation operation. Here's how it works:
	It displays a menu of available image processing operations, numbered from 1 to 15, each with a brief description.
	It prompts the user to enter their choice by typing the corresponding number between 1 and 15.
	The function reads the user's input, validates it, and returns the chosen option as a short integer
	*/
    cout<<"Enter the Filter you want :\n       1) Black and White\n       2) Invert Image\n       3) Merge Image\n       4) Flip Image\n       5) Rotate Image\n       6) Darken and Lighten Image\n       7) Detect Image Edges\n       8) Enlarge Image\n       9) Shrink Image\n       10) Mirror Image\n       11) Shuffle Image\n       12) Blur Image\n       13) Crop Image\n       14) Skew Horizontally\n       15) Skew Vertically\n       Enter Your choice between(1 and 15): ";
    short choice;cin>>choice;
    return choice;
}

