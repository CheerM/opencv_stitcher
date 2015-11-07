#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/nonfree/nonfree.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/stitching/stitcher.hpp>
#include <iostream>
#include <vector>

using namespace cv;
using namespace std;

void stitchLeftRight(Mat& leftImage, Mat& rightImage, Mat&rightImageWarped, Mat& panorama);

int main(int argc, char* argv[])
{
	int size_ = argc - 1;
   	Mat img;
   	vector<Mat> imgs;  
   	for (int i = 1; i <= size_; i ++) {
   		img = imread(argv[i], 1);
   		imgs.push_back(img);
   	} 

    	//拼接  
  	Mat pano;  
  	Stitcher stitcher = Stitcher::createDefault(false);  
  	Stitcher::Status status = stitcher.estimateTransform(imgs);
  	if (status != Stitcher::OK) {
               cout << "Can't match images" << int(status) << endl;
               system("pause"); 
               return -1;
        }
   	//stitcher.composePanorama(pano); //使用之前的图片集imgs
   	status = stitcher.composePanorama(pano);//可以加入新的图片集imgs(保证与之前的大小数量一致)
  	if (status != Stitcher::OK) {
               cout << "Can't stitch images" << int(status) << endl;
               system("pause"); 
               return -1;
        }
  	imwrite("result.png", pano);  
  	imshow("result",pano);  
	waitKey(0);
	return 0;
}

