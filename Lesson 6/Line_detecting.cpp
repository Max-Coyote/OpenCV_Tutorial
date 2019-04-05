#include<iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

int main(int argc, char *argv[])
{
    Mat src = imread("test_image.jpg");
    Mat gray;
    cvtColor(src, gray, COLOR_RGB2GRAY);
    Mat blur;
    GaussianBlur(gray, blur,Size(5,5), 0);
    Mat can;
    Canny(blur, can, 50, 150);
    int height = can.rows;
    vector<Point> polygons;
    polygons.push_back(Point(200, height));
    polygons.push_back(Point(1100, height));
    polygons.push_back(Point(550, 250));
    Mat mask = Mat::zeros(src.rows, src.cols, CV_8UC1);
    fillConvexPoly(mask, polygons, Scalar(255,255,255));
    Mat masked_image;
    bitwise_and(can, mask, masked_image);

    vector<Vec4i> lines;
        HoughLinesP(masked_image, lines, 0.5, CV_PI/180, 100, 40, 5);
        for (int i = 0; i < lines.size(); i++)
        {
            Vec4i l = lines[i];
            line( src, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0,0,255), 3, CV_AA);
        }
    imshow("imsg", src);
    waitKey(0);

}
