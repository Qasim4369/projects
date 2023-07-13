#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "Header.h"
using namespace std;
using namespace cv;
Image::Image(const char* filename)
{
	Mat img = imread(filename);
}
Image::~Image()
{
	delete[] data;
}
int Image::Getsize()
{
	return 0;
}
bool Image::read(const char* filename)
{
	Mat img = imread(filename);
	return false;
}
bool Image::write(const char* filename, int img)
{
	imwrite(filename, img);
	return false;
}
int Image::GetPixel()
{
}
void Image::SetPixel(int col, int row, int n)
{
}
int Image::Getsize()
{
}
void Image::ConvertToNegative()
{
	Mat img = imread("image.jpg");
	Mat grey;
	cvtColor(img, grey, COLOR_BGR2GRAY);
}