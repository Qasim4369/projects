#include <iostream>
#include <opencv2/opencv.hpp>
#include <fstream>
//#include "List.h"
using namespace cv;
using namespace std;
int Q1() {
    system("CLS");
    int rows = 0;
    int cols = 0;
    int black = 0;
    int white = 0;
    int mean = 0;
    int avgblk = 0;
    ofstream MyFile("Q1.txt");
    Mat image = imread("image001.pgm", 0);
    // Error Handling
    if (image.empty()) {
        cout << "Image File "
            << "Not Found" << endl;
        cin.get();
        return -1;
    }
    for (int i = 0; i < image.rows; i++)
        rows = rows + 1;
    for (int j = 0; j < image.cols; j++)
        cols = cols + 1;

    for (int i = 0; i < image.rows; i++)
    {
        for (int j = 0; j < image.cols; j++)
        {
            if (image.at<uchar>(i, j) == 0)
            {
                black += 1;
                avgblk += 1;
            }
            if (image.at<uchar>(i, j) == 255)
            {
                white += 1;
            }
            mean = mean + image.at<uchar>(i, j);
        }
        cout << "Row " << i << "Number of blacks : " << avgblk << endl;
        MyFile << "Row " << i << "Number of blacks : " << avgblk << endl;
        avgblk = 0;
    }
    int total = (cols * rows);
    mean = mean / total;

    cout << "Columns :" << cols << endl << "Rows :" << rows << endl << "Mean :" << mean << endl;
    cout << "Whites :" << white << endl << "Blacks :" << black << endl;
    //cout << "M = " << endl << " " << image << endl << endl;
    Mat img_neg = 255 - image;
    imshow("Image", img_neg);
    waitKey(0);
    MyFile << "Mean : " << mean << endl;
    MyFile << "Whites :" << white << endl << "Blacks :" << black << endl;
    return 0;
}
void Q2() {
    int row = 0;
    int col = 0;
    cout << "Enter Pixel Co-ordinates" << endl;
    cout << "Row number ";
    cin >> row ;
    cout << "Column number ";
    cin >> col;
    system("CLS");
    Mat image = imread("image002.pgm", IMREAD_GRAYSCALE);
    // Error Handling
    if (image.empty()) {
        cout << "Image File "
            << "Not Found" << endl;
        cin.get();
        
    }
    Mat labels;
    int comp = connectedComponents(image, labels, 8);
    vector<Vec3b> colour(comp);
    colour[0] = Vec3b(0, 0, 0);
    for (int i = 0; i < comp; i++) {
        colour[i] = Vec3b(rand() & 255, rand() & 255, rand() & 255);
    }
    Mat out = Mat::zeros(image.size(), CV_8UC3);

    for (int i = 0; i < image.rows; ++i) {
        
        for (int j = 0; j < image.cols; ++j) {
            {
                   int label = labels.at<int>(i, j);
                   Vec3b& pixel = out.at<Vec3b>(i, j);
                   pixel = colour[label];
            }
        }
    }
    imshow("in", image);
    imshow("out", out);
    waitKey(0);
    cout <<"Number of Components: "<< comp;
    ofstream MyFile("Q2.txt");
    MyFile << "Row : " << row<< endl;
    MyFile << "Col : " << col << endl;
    MyFile << "Number of Components : " << comp << endl;

}
void Q3() {
    int row = 0;
    int col = 0;
    cout << "Enter Pixel Co-ordinates" << endl;
    cout << "Row number ";
    cin >> row;
    cout << "Column number ";
    cin >> col;
    system("CLS");
    Mat image = imread("cattle-9.pgm", IMREAD_GRAYSCALE);
    // Error Handling
    if (image.empty()) {
        cout << "Image File "
            << "Not Found" << endl;
        cin.get();
    }
    Mat labels;
    int comp = connectedComponents(image, labels, 8);
    vector<Vec3b> colour(comp);
    colour[0] = Vec3b(0, 0, 0);
    for (int i = 0; i < comp; i++) {
        colour[i] = Vec3b(rand() & 1, rand() & 255, rand() & 255);
    }
    Mat out = Mat::zeros(image.size(), CV_8UC3);

    for (int i = 0; i < image.rows; ++i) {

        for (int j = 0; j < image.cols; ++j) {
            {
                int label = labels.at<int>(i, j);
                Vec3b& pixel = out.at<Vec3b>(i, j);
                pixel = colour[label];
            }
        }
    }
    imshow("in", image);
    imshow("out", out);
    waitKey(0);
    cout << "Number of Components: " << comp;
    ofstream MyFile("Q3.txt");
    MyFile << "Row : " << row << endl;
    MyFile << "Col : " << col << endl;
    MyFile << "Number of Components : " << comp << endl;

}


int Q4() {
    int key = -1;
    int black = 0;
    //List* list = new List();
    Mat img = imread("C:\\Users\\hp\\Desktop\\Uni\\Datastructures\\DSA_N_Qasim_20i1783_Module_2\\Project1\\image001.pgm", IMREAD_GRAYSCALE);
    if (img.empty()) {
        cout << "Image File "
            << "Not Found" << endl;
        cin.get();
        return -1;
    }
    ofstream MyFile("Q4.txt");
    MyFile << img.rows<< " " << img.cols;
    MyFile << endl ;
    MyFile << key;
    for (int i = 0; i < img.rows; i++)
    {
        for (int j = 0; j < img.cols; j++)
        {
            if (img.at<uchar>(i, j) == 0)
            {
                //list->add(j);
                MyFile << j << " ";
                black++;
            }
        }
        MyFile << key << endl;
    }
    Mat out = Mat::zeros(img.size(), CV_8UC3);
    MyFile << key;
    for (int i = 0; i < img.rows; i++)
    {
        for (int j = 0; j < img.cols; j++)
        {
            if (img.at<uchar>(i, j) == 0)
            {
                //list->add(j);
                MyFile << j << " ";
                black++;
            }
        }
        MyFile << key << endl;
    }
    cout << "Total Number of Black Pixels : " << black;
    Mat img_neg = 255 - img;
    imshow("Image", img_neg);
    waitKey(0);
}

//int main()
//{
//    char choice;
//    cout << "Which Question (1,2,3,4)" << endl;
//    cin >> choice;
//    switch (choice)
//    {
//    case '1': Q1();
//        break;
//    case '2': Q2();
//        break;
//    case '3': Q3();
//        break;
//    case '4': Q4();
//        break;
//    default: cout << "You've chosen neither";
//    }
//    return 0;
//}