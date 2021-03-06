//
// Created by 赵磊 on 2017/2/9.
//

#include "GradientShow.h"
#include "DrawUtils.h"
using namespace cv;

void GradientShow::Init() {
    namedWindow(winName);
    setMouseCallback(winName,cbMouseAdapter,this);
    matFrame = Mat(512,512,CV_8UC4,Scalar(255,255,255));
    // circle(matFrame,Point(256,256),100,Scalar(0,255,0),5);
    //rectangle(matFrame,Point(156,156),Point(356,356),Scalar(0,255,0),CV_FILLED);
    matFrame = imread(inputImagePath);
}

void GradientShow::Run() {
    processFrame();
    showDebug();
    imshow(winName,matFrame);
    waitKey(0);
}

GradientShow::GradientShow(const std::string &winName, const std::string &inputfilename) : winName(winName) {
    inputImagePath = inputfilename;
    arrowLength = 50;
}

void GradientShow::processFrame() {
    Mat frameGray;
    cvtColor(matFrame,frameGray,COLOR_BGR2GRAY);
    GaussianBlur(frameGray,frameGray,Size(5,5),1.5);
    Sobel(frameGray,matGradX,CV_16S,1,0);
    Sobel(frameGray,matGradY,CV_16S,0,1);


}

void GradientShow::showDebug() {
    Mat tempFrameX;
    convertScaleAbs(matGradX,tempFrameX,0.5,128);
    imshow(winName + "_gradX",tempFrameX);
    Mat tempFrameY;
    convertScaleAbs(matGradY,tempFrameY,0.5,128);
    imshow(winName + "_gradY",tempFrameY);
}

void GradientShow::cbMouse(int event, int x, int y, int flags) {
    if (event == CV_EVENT_LBUTTONDOWN)
    {
        Point pt(x,y);
        short xGrad = matGradX.at<short>(y,x);
        short yGrad = matGradY.at<short>(y,x);
        printf("You clicked at (%d,%d), gradient is (%d,%d)\n",x,y,xGrad,yGrad);
        drawGradient(xGrad,yGrad);
    }
}

void GradientShow::cbMouseAdapter(int event, int x, int y, int flags, void *pData) {
    GradientShow *ptr = (GradientShow *)pData;
    ptr->cbMouse(event,x,y,flags);
}

void GradientShow::drawGradient(int dx, int dy) {
    int height = matFrame.rows;
    int width = matFrame.cols;
    Point center(width / 2, height / 2);
    if (abs(dx) > 30 || abs(dy) > 30)
    {
        double x,y;
        x = dx;
        y = dy;
        double length = sqrt(dx * dx + dy * dy);
        x = dx / length;
        y = dy / length;
        int arrowlength = height / 4;
        Mat temp = matFrame.clone();
        Point end(center.x + arrowlength * x,center.y + arrowlength*y);
        DrawArrow(temp,center,end,Scalar(255,0,0),5);
        imshow(winName,temp);

    }
    else
    {
        imshow(winName,matFrame);
    }



}
