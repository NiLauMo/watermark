#pragma once
#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

/*From unsigned char (decimal) to string (binary)*/
string uchar2bin(unsigned char value);
/*From string (binary) to unsigned char (decimal)*/
unsigned char bin2uchar(string bin);

/*Embed the second chapter picture into the first picture*/
Mat makeWatermark(Mat image1, Mat image2);
/*Extract embedded image*/
Mat recoveryImage(Mat image);