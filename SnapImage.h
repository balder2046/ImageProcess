//
// Created by 赵磊 on 2017/2/9.
//

#ifndef IMAGEPROCESS_SNAPIMAGE_H
#define IMAGEPROCESS_SNAPIMAGE_H

#include "opencv2/opencv.hpp"
#include <string>
class SnapImage {
public:
    SnapImage(const std::string &inputFile,const std::string &outFileBase);
public:
    void Init();
    void Run();
protected:
    std::string outFileNameBase;
    std::string inputVideoFilePath;
    cv::Mat matFrame;
    std::string winName;
protected:
    std::string genOutFileName();
private:
    int writeFileNo;
// Player Settings
private:
    int fpsVideo;
    int framecountVideo;
    int widthVideo;
    int heightVideo;
private:
    cv::VideoCapture captureVideo;
};


#endif //IMAGEPROCESS_SNAPIMAGE_H
