#include <bits/stdc++.h>
#include <opencv2/opencv.hpp> 

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
    // VideoCapture vid("video/ball.mp4");
    VideoCapture vid(0);

    Mat frame, frame_resized, frame_thresh, frame_hsv;

    int L_H = 0;
    int U_H = 179;
    int L_S = 0;
    int U_S = 255;
    int L_V = 0;
    int U_V = 255;

    namedWindow("threshold", WINDOW_AUTOSIZE);

    createTrackbar("L_H", "threshold", &L_H, 179);
    createTrackbar("U_H", "threshold", &U_H, 179);
    createTrackbar("L_S", "threshold", &L_S, 255);
    createTrackbar("U_S", "threshold", &U_S, 255);
    createTrackbar("L_V", "threshold", &L_V, 255);
    createTrackbar("U_V", "threshold", &U_V, 255);
    

        
    while (true) {
        vid.read(frame);

        resize(frame, frame_resized, Size(), 0.5, 0.5);
        cvtColor(frame_resized, frame_hsv, COLOR_BGR2HSV);

        
        inRange(frame_hsv, Scalar(L_H, L_S, L_V), Scalar(U_H, U_S, U_V), frame_thresh);

        vector<vector<Point>> counturs;
        findContours(frame_thresh, counturs, RETR_TREE, CHAIN_APPROX_NONE);

        for (int i = 0; i < counturs.size(); i++) {
            vector<Point>counturs_new;
            Point2f center;
            float radius;
            counturs_new = counturs[i];
            minEnclosingCircle(counturs_new, center, radius);
            if (radius> 20 && radius < 78){
                circle(frame_resized , center, radius, Scalar(255, 0, 0), 3 );
                printf("x: %2f y: %2f radius: %2f\n", center.x, center.y, radius);
            }
        }

        

        
        imshow("video", frame_resized);
        imshow("halo", frame_thresh);

        if ((char)27 == (char) waitKey(20)) 
        break; 
    }
    return 0;
}