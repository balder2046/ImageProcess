//
// Created by 赵磊 on 2017/2/9.
//

#ifndef IMAGEPROCESS_GRADIENTSHOW_H
#define IMAGEPROCESS_GRADIENTSHOW_H
#include "opencv2/opencv.hpp"
#include <string>
class GradientShow {
public:
    GradientShow(const std::string &winName);

    void Init();
    void Run();

protected:
    void processFrame();
protected:
    void showDebug();
protected:
    void cbMouse(int event,int x,int y,int flags);
    static void cbMouseAdapter(int event,int x,int y,int flags,void *pData);

protected:
    void drawGradient(int dx,int dy);
    int arrowLength;

private:
    std::string winName;
    cv::Mat matFrame;
    cv::Mat matGradX; // the gradient in Axis X
    cv::Mat matGradY; // the gradient in Axis Y

};


#endif //IMAGEPROCESS_GRADIENTSHOW_H
