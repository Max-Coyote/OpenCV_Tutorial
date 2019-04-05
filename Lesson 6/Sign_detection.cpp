#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <cmath>
#include <iostream>
#include "opencv/cv.h"
#include "opencv/highgui.h"
#include <stdio.h>
#include <math.h>

Mat FindFigures(Mat src)
{
	// Convert to grayscale
	cv::Mat gray;
	cv::cvtColor(src, gray, CV_BGR2GRAY);

	// Use Canny instead of threshold to catch squares with gradient shading
	cv::Mat bw;
	cv::cvtColor(src, bw, CV_BGR2GRAY);
	cv::adaptiveThreshold(bw, gray, 125, CV_ADAPTIVE_THRESH_GAUSSIAN_C, CV_THRESH_BINARY, 7, 6);
	
	std::vector<Vec3f> circles;
	int morph_size = 20;

	HoughCircles(bw, circles, CV_HOUGH_GRADIENT, 1, 10, m, n, 10, 32);
	int k = 0;

	for (size_t i = 0; i < circles.size(); i++)
	{


		if (k < 3)
		{
			Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
			int radius = cvRound(circles[i][2]);

			//circle(src, center, 3, Scalar(0, 255, 0), -1, 8, 0);
			// circle outline
			circle(src, center, radius, Scalar(255, 0, 0), 3, 8, 0);


			Mat cirsave;
			Rect r(abs(center.x - radius), abs(center.y - radius), radius * 2, radius * 2);
			cirsave = src.clone();
			cirsave.rows = radius * 2;
			cirsave.cols = radius * 2;
			Rect rpaste(0, 0, radius * 2, radius * 2);


			src(r).copyTo(cirsave(rpaste));

			int max_similarity = 0;
			int max_similarity_pos = 0;
			string max_similarity_name = "";
			for (int i = 0; i < 8; i++)
			{
				Mat base_part = imread(base[i]);
				
				//int similarity = Find_Black_Percent_Similarity_Cir(base_part, cirsave);
				int similarity = Find_Percent_Similarity_Cir(base_part, cirsave);
				if ((similarity > 75)  && (similarity > max_similarity))
				{
					max_similarity = similarity;
					max_similarity_name = base[i + 8];
					max_similarity_pos = i;
					putText(src, max_similarity_name, cvPoint(r.x, r.y), FONT_HERSHEY_SIMPLEX, 0.5, cvScalar(1,1,1), 2, 8);
				//Save_To_Path(base_part, cirsave, similarity);
				}
				if ((i == 6) && (max_similarity >= 80))
				{
					cout << max_similarity << endl;
					circle(src, center, radius, 130, 4, 10);
					//rectangle(src, r, 5, 2, 10);
					Save_To_Path(imread(base[max_similarity_pos]), cirsave, max_similarity);
					Save_To_Path(src, cirsave, max_similarity);
				}
				
			}


			
			
			
			
			waitKey(10);
		}
		else
			break;

	}

	/*rect*/
	return src;
	
}
int main()
{
	VideoCapture cap("C://Users/KorzhukovMV/Desktop// /Moscow Streets Kutuzovsky Prospect Kremlin SUMMER in 4K.mp4"); // open the default camera
	//VideoCapture cap("C://Users/KorzhukovMV/Desktop// /3.1   ' ',  .mp4"); // open the default camera
 //VideoCapture cap(0);
	//VideoCapture cap("C://Users/KorzhukovMV/Desktop// /1.mp4");
	//VideoCapture cap("C://Users/KorzhukovMV/Desktop/VIDEO0171.mp4"); // open the default camera
	if (!cap.isOpened())  // check if we succeeded
		return -1;

	Mat edges;
	namedWindow("edges", 1);
	for (;;)
	{


		Mat src, src_gray;
		cap >> src;
		try {
			imshow("src", FindFigures(src));
			}
		catch (Exception)
		{
			cout << 'err' << endl;
		}

		waitKey(10);

	}

	// the camera will be deinitialized automatically in VideoCapture destructor
	system("pause");
	return 0;


}

