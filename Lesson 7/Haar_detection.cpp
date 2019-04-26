#include<iostream>
#include<opencv2/objdetect/objdetect.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

int main(int argc, char *argv[])
{
	CascadeClassifier plate_cascade;
	plate_cascade.load("C:/git/OpenCV_Tutorial/Lesson 7/haarcascade_russian_plate_number.xml");
	if (!plate_cascade.load("C:/git/OpenCV_Tutorial/Lesson 7/haarcascade_russian_plate_number.xml"))
	{
		cerr << "Error Loading XML file" << endl;
		return 0;
	}

	VideoCapture capture(0);
	if (!capture.isOpened())
		throw "Error when reading file";
	namedWindow("window", 1);
	for (;;)
	{
		Mat image;
		capture >> image;
		if (image.empty())
			break;

		// Detect plates
		std::vector<Rect> plates;
		plate_cascade.detectMultiScale(image, plates, 1.1, 1, CASCADE_SCALE_IMAGE, Size(30, 30));

		// Draw rects on the detected faces
		for (int i = 0; i < plates.size(); i++)
		{
			rectangle(image, plates[i], Scalar(255, 0, 255), 4, 8, 0);
		}

		imshow("Detection plates", image);
		waitKey(1);
	}

	return 0;
}
