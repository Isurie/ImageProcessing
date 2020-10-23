#include <iostream>

#include <opencv2/core/core.hpp>

#include <opencv2/opencv.hpp>

#include<opencv2/imgproc/imgproc.hpp>

 

using namespace cv;

using namespace std;

 

 

int main(int argc, char *argv[])

{

    if (argc != 3) {

        printf("Enter exeFileName imageFileName\n");

    }



	Mat image = imread(argv[1], IMREAD_COLOR);



    if (image.empty()) {

        cout << "Error: No Image to load" << endl;

    }



	Mat gr(image.rows,image.cols,CV_8UC1,Scalar(0));

	cvtColor(image,gr,COLOR_BGR2GRAY);



    Mat dest = gr.clone();



    int T = atoi(argv[2]);

   

    int gx = 0;

    int gy = 0;

    int G = 0;

    for (int i = 0; i < gr.rows - 1; i++) {

        for (int j = 0; j < gr.cols - 1; j++) {

            gx = (int)gr.at<uchar>(i, j) - (int)gr.at<uchar>(i, j + 1);

            gy = (int)gr.at<uchar>(i, j) - (int)gr.at<uchar>(i+1, j);

            G = abs(gx) + abs(gy);



            if (G >= T) {

                dest.at<uchar>(i, j) = 255;

            }

            else {

                dest.at<uchar>(i, j) = 0;

            }

        }

    }

	

	// display histogram



 

    namedWindow("Gray Image", 1);

    imshow("Gray Image", gr);



    namedWindow("Edge Detected Image", 1);

    imshow("Edge Detected Image", dest);

 

    waitKey();

    gr.release();

    return 0;

}

