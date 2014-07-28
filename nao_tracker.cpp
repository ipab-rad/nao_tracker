#include <iostream>
#include <aruco/aruco.h>
#include <aruco/cvdrawingutils.h>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace aruco;

int main(int, char**){
  VideoCapture cap(0); // open the default camera
  if(!cap.isOpened())  // check if we succeeded
    return -1;
    
  
  namedWindow("Nao Tracker",1);
  for(;;)
  {
    Mat frame;
    cap >> frame; // get a new frame from camera
    // cvtColor(frame, edges, CV_BGR2GRAY);
    // GaussianBlur(edges, edges, Size(7,7), 1.5, 1.5);
    // Canny(edges, edges, 0, 30, 3);
    MarkerDetector MDetector;
    vector<Marker> Markers;
    MDetector.detect(frame, Markers);
    for (unsigned int i=0;i<Markers.size();i++) {
            cout<<Markers[i]<<endl;
            Markers[i].draw(frame, Scalar(0,0,255),2);
        }
    imshow("edges", frame);
    if(waitKey(30) >= 0) break;
  }
  // the camera will be deinitialized automatically in VideoCapture destructor
  return 0;
}
