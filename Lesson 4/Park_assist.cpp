#include<iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

#define PI 3.14159265
int main(int argc, char *argv[])
{
    Mat src = imread("Prius_Top.png");
    Mat Prius;
    resize(src, Prius, Size(454, 176));
    int a = 40;
    Mat drawing = Mat::zeros(Prius.rows * 3, Prius.cols * 3, CV_8UC3);
    namedWindow("winda", WINDOW_AUTOSIZE);
    //rectangle(drawing, Rect(Prius.cols, Prius.rows, Prius.cols, Prius.rows), Scalar(255, 0 , 0), 3, LINE_AA, 0);
    createTrackbar("Steering angle", "winda", &a, 81);
    while (true)
    {
        drawing = Mat::zeros(Prius.rows * 3, Prius.cols * 3, CV_8UC3);
        rectangle(drawing, Rect(Point(0, 0), Point(drawing.cols, drawing.rows)), Scalar(255,255,255), -1, 8, 0);
        Prius.copyTo(drawing(Rect(Prius.cols, Prius.rows, Prius.cols, Prius.rows)));

        int angle = a - 40;
        line(drawing, Point(Prius.cols + 92 - 15, Prius.rows), Point(Prius.cols + 92 + 15, Prius.rows), Scalar(0,0,255), 6, LINE_AA, 0);
        line(drawing, Point(Prius.cols + 92 - 15, Prius.rows + 176), Point(Prius.cols + 92 + 15, Prius.rows + 176), Scalar(0,0,255), 6, LINE_AA, 0);
        line(drawing, Point(Prius.cols + 92 + 270 - 15 * cos(angle * PI / 180.0), Prius.rows + 15 * sin(angle * PI / 180.0)), Point(Prius.cols + 92 + 270 + 15 * cos(angle * PI / 180.0), Prius.rows - 15 * sin(angle * PI / 180.0)), Scalar(0,0,255), 6, LINE_AA, 0);
        line(drawing, Point(Prius.cols + 92 + 270 - 15 * cos(angle * PI / 180.0), Prius.rows + 15 * sin(angle * PI / 180.0) + 176), Point(Prius.cols + 92 + 270 + 15 * cos(angle * PI / 180.0), Prius.rows - 15 * sin(angle * PI / 180.0) + 176), Scalar(0,0,255), 6, LINE_AA, 0);
        if (angle > 0)
            circle(drawing, Point(Prius.cols + 92, Prius.rows + 88 - 270/tan(angle * PI / 180.0)), 270/sin(angle * PI / 180.0), Scalar(0, 255, 0), 15, LINE_AA, 0);
            else if (angle < 0) circle(drawing, Point(Prius.cols + 92, Prius.rows + 88 - 270/tan((180 + angle) * PI / 180.0)), 270/sin((180 + angle) * PI / 180.0), Scalar(0, 255, 0), 15, LINE_AA, 0);
        else
            line(drawing, Point(Prius.cols + 92, Prius.rows + 88), Point(Prius.cols + 1000, Prius.rows + 88), Scalar(0, 255, 0), 15, LINE_AA, 0);
        imshow("winda", drawing);
        //imshow("second_window", Prius);
        waitKey(1);
        if (a == 81) break;
    }

}

