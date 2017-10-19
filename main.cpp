//Author: Carter Fitzsimons
#include <iostream>
#include "bitmap.h"
#include <string>
#include <vector>

using namespace std;

int main()
{
    //holds the currently selected pixel from within the loaded bitmap
    Pixel currentPixel;
    //holds the inputted name of the file
    string fileName;
    //holds the actual pixel matrix
    Bitmap picture;
    
    //gets file name and stores it as fileName
    do
    {
        cout << "Enter the image's file name" << endl;
        cin >> fileName;  //fileName stores the inputted file name
        picture.open(fileName); //opens the .bmp as a Bitmap class/data type so we can interact with the data it contains.
        if(picture.isImage() != true)
        {
            cout << "The image must be a 24 bit depth .bmp file. Please try again." << endl;
        }
    }
    //checks to see if a real image is imported
    while(picture.isImage() != true);
    //define a vector of a vector of Pixels
    vector<vector <Pixel> > pixelMap;
    //puts the contents of  picture into pixelMap
    pixelMap = picture.toPixelMatrix();
    //nested for loops iterate through the matrix, average the R, G, and B value of each pixel individually, and replace the pixel with a new greyscale one
    for(int i = 0; i < pixelMap.size(); i++)
    {
	    for(int j = 0; j < pixelMap[i].size(); j++)
	    {
		    currentPixel = pixelMap[i][j];
		    //adds the R, G, and B values together and stores in sum
		    int sum = currentPixel.red + currentPixel.blue + currentPixel.green;
		    //divides the sum by 3 to get an average value of the 3 pixels
		    int avg = sum / 3;
		    //sets the currentPixel equal to the average
		    currentPixel.red = avg;
		    currentPixel.blue = avg;
		    currentPixel.green = avg;
		    //replaces the old pixel with the new greyscale one before repeating the process throughout every pixel in the imported image
		    pixelMap[i][j] = currentPixel;
	    }
    }
	
    //puts the changed pixels back into the actual pixel matrix before saving 
    picture.fromPixelMatrix(pixelMap);
    //saves the new image as oldtimey.bmp
    picture.save("oldtimey.bmp");
    cout << "Your image has been converted to greyscale and saved as oldtimey.bmp!";
}


