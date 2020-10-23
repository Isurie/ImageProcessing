/*Generating Histogram*/

//#include <opencv2/core/core.hpp>
//
//#include <opencv2/highgui/highgui.hpp>
//
//#include <opencv2/imgproc/imgproc.hpp>
//
//#include <iostream>
//
//using namespace cv;
//
//using namespace std;
//
//int main(int argc, char** argv)
//
//{
//
//	if (argc != 2)
//
//	{
//
//		cout << " Usage: display_image ImageToLoadAndDisplay" << endl;
//
//		return -1;
//
//	}
//
//	Mat image;
//
//	image = imread(argv[1], IMREAD_COLOR); // Read the file
//
//	if (!image.data) // Check for invalid input
//
//	{
//
//		cout << "Could not open or find the image" << std::endl;
//
//		return -1;
//
//	}
//
//	Mat gr;
//
//	int his[256];
//
//	for (int i = 0; i < 256; i++) {
//
//		his[i] = 0;
//
//	}
//
//	cvtColor(image, gr, COLOR_BGR2GRAY, 0);	//(input img, destination, code)
//
//	int h = gr.rows;
//
//	int w = gr.cols;
//
//	int val = 0;
//
//	cout << "Width: " << w << endl;
//
//	cout << "Height: " << h << endl;
//
//	for (int i = 0; i < h; i++) {
//
//		for (int j = 0; j < w; j++) {
//
//			val = gr.at<uchar>(i, j);	//Getting grey value of pixel
//
//			his[val] = his[val] + 1;
//
//		}
//
//	}
//
//	int max = 0;
//
//	for (int i = 0; i < 256; i++) {
//
//		cout << "Gray level " << i << ": " << his[i] << endl;
//
//		if (max < his[i])
//
//			max = his[i];
//
//	}
//
//	cout << max << endl;
//
//	Mat him(301, 260, CV_8UC1, Scalar(255));
//
//	int hist[256];
//
//	double maxd = max;
//
//	for (int i = 0; i <= 255; i++) {
//
//		hist[i] = cvRound(double(his[i] / maxd) * 300);
//
//		Point pt1 = Point(i, 300 - hist[i]);
//
//		Point pt2 = Point(i, 300);
//
//		line(him, pt1, pt2, Scalar(0), 1, 8, 0);
//
//	}
//
//	namedWindow("Display window", WINDOW_AUTOSIZE); // Create a window for display.
//
//	imshow("Display window", image); // Show our image inside it.
//
//	namedWindow("Display Gray", WINDOW_AUTOSIZE); // Create a window for display.
//
//	imshow("Display Gray", gr); // Show our image inside it.
//
//	namedWindow("Display Histogram", WINDOW_AUTOSIZE); // Create a window for display.
//
//	imshow("Display Histogram", him); // Show our image inside it.
//
//	waitKey(0); // Wait for a keystroke in the window
//
//	image.release();
//
//	gr.release();
//
//	him.release();
//
//	return 0;
//
//}




/*Contrast Stretching*/
#include <opencv2/core/core.hpp>

#include <opencv2/highgui/highgui.hpp>

#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>



using namespace cv;

using namespace std;

int main(int argc, char** argv)

{

	if (argc != 2)

	{

		cout << " Usage: display_image ImageToLoadAndDisplay" << endl;

		return -1;

	}

	Mat image;

	image = imread(argv[1], IMREAD_COLOR); // Read the file



	if (!image.data) // Check for invalid input

	{

		cout << "Could not open or find the image" << std::endl;

		return -1;

	}

	Mat gr;



	cvtColor(image, gr, COLOR_BGR2GRAY, 0);	//Color Conversion to gray

	int h = gr.rows;

	int w = gr.cols;

	int x = 0;

	double y = 0.0;

	cout << "Width: " << w << endl;
	cout << "Height: " << h << endl;

	Mat CSt = gr.clone();	//Get clone image

	for (int i = 0; i < h; i++) {	//each row

		for (int j = 0; j < w; j++) {	//in a row left to right(colum by colum)

			x = (int)gr.at<uchar>(i, j);	//take current pixel value

			y = 0.0;

			if (x < 150) {

				y = (double)(20 / 150) * (double)(x);

			}

			else {

				if (x < 210) {

					y = (double)(230 / 60) * (double)(x - 150) + 20;

				}

				else {

					y = (double)(5 / 45) * (double)(x - 210) + 250;

				}

			}

			CSt.at<uchar>(i, j) = (uchar)(cvRound(y));	//round

		}

	}

	namedWindow("Display Gray", WINDOW_AUTOSIZE); // Create a window for display.

	imshow("Display Gray", gr); // Show our image inside it.

	namedWindow("Display window", WINDOW_AUTOSIZE); // Create a window for display.

	imshow("Display window", CSt); // Show our image inside it.

	waitKey(0); // Wait for a keystroke in the window

	gr.release();

	CSt.release();

	return 0;

}
