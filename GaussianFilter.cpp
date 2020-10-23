#include <iostream>

#include <opencv2/core/core.hpp>

#include <opencv2/opencv.hpp>

#include<opencv2/imgproc/imgproc.hpp>

 

using namespace cv;

using namespace std;

 

 

int main(int argc, char *argv[])

{

    if (argc != 2) {

        printf("Enter exeFileName imageFileName\n");

    }





	Mat image = imread(argv[1], IMREAD_COLOR);



    if (image.empty()) {

        cout << "Error: No Image to load" << endl;

    }



	Mat gr(image.rows,image.cols,CV_8UC1,Scalar(0));

	cvtColor(image,gr,COLOR_BGR2GRAY);

    Mat dest = gr.clone();



    Mat imgk1 = gr.clone();

    Mat imgk2 = gr.clone();

    Mat imgdiff = gr.clone();



    double k1[5][5] = { {1,4,7,4,1},{4,16,26,16,4},{7,26,41,26,7},{4,16,26,16,4},{1,4,7,4,1} };

    double k2[5][5] = { {196,199,200,199,196},{199,202,203,202,199},{200,203,204,203,200},{199,202,203,202,199},{196,199,200,199,196} };

   

    double val1 = 0.0;

    double val2 = 0.0; 

    double diff = 0.0;



    for (int i = 2; i < gr.rows - 2; i++) {

        for (int j = 2; j < gr.cols - 2; j++) {

            val1 = 0.0;

            val2 = 0.0;

            for (int m = -2; m <= 2; m++) {

                for (int n = -2; n <= 2; n++) {

                    val1= val1 + k1[m+2][n+2] * double(gr.at<uchar>(i + m, j + n)) / 273;

                    val2 = val2 + k2[m+2][n+2] * double(gr.at<uchar>(i + m, j + n)) / 5000;

                    diff = val2 - val1;

                }

            }

            imgk1.at<uchar>(i, j) = cvRound(val1);

            imgk2.at<uchar>(i, j) = cvRound(val2);

            imgdiff.at<uchar>(i, j) = cvRound(diff);

        }

    }

	

	// display histogram

   

 

    namedWindow("Gray Image", 1);

    imshow("Gray Image", gr);



    namedWindow("Kernel 1", 1);

    imshow("Kernel 1", imgk1);



    namedWindow("Kernel 2", 1);

    imshow("Kernel 2", imgk2);



    namedWindow("Difference", 1);

    imshow("Difference", imgdiff);

 

    waitKey();



    gr.release();

    imgk1.release();

    imgk2.release();

    imgdiff.release();

    return 0;

}