#include<opencv2/opencv.hpp> //OpenCV header to use VideoCapture class//
#include <opencv2/core/core.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <chrono>
#include<iostream>

using namespace std;
using namespace cv;

int main() {

   Mat myImage;                    //Declaring a matrix to load the frames//
   namedWindow("Video Player");    //Declaring the video to show the video//
   VideoCapture cap(0);            //Declaring an object to capture stream of frames from default camera//
   if (!cap.isOpened()){           //This section prompt an error message if no video stream is found//
      cout << "No video stream detected" << endl;
      system("pause");
      return-1;
   }

    std::vector<KeyPoint> keypoints_1, keypoints_2;
  Mat descriptors_1, descriptors_2;
  Ptr<FeatureDetector> detector = ORB::create();
  Ptr<DescriptorExtractor> descriptor = ORB::create();
  Ptr<DescriptorMatcher> matcher = DescriptorMatcher::create("BruteForce-Hamming");

   while (true){ //Taking an everlasting loop to show the video//
      cap >> myImage;
      if (myImage.empty()){ //Breaking the loop if no video frame is detected//
         break;
      }
    chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
      detector->detect(myImage, keypoints_1);
      Mat outimg1;
      drawKeypoints(myImage, keypoints_1, outimg1, Scalar::all(-1), DrawMatchesFlags::DEFAULT);

      imshow("Video Player", outimg1);//Showing the video//
      char c = (char)waitKey(25);//Allowing 25 milliseconds frame processing time and initiating break condition//
      if (c == 27){ //If 'Esc' is entered break the loop//
         break;
      }
   }
   cap.release();//Releasing the buffer memory//
   return 0;
}