#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main() {

  std::cout << cv::getBuildInformation();
  // Create a VideoCapture object and open the input file
  // If the input is the web camera, pass 0 instead of the video file name
  VideoCapture cap(-1);

  // Check if camera opened successfully
  if (!cap.isOpened()) {
    cout << "Error opening video stream or file" << endl;
    return -1;
  }

  while (1) {

    Mat frame;
    cap >> frame;
    if (frame.empty())
      break;
    imshow("Frame", frame);
    char c = static_cast<char>(waitKey(25));
    
    if (c == 27)
      break;
  }
  cap.release();
  destroyAllWindows();

  return 0;
}
