//
// Created by 赵磊 on 2017/2/9.
//

#ifndef IMAGEPROCESS_DRAWUTILS_H
#define IMAGEPROCESS_DRAWUTILS_H
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#define WHITE cv::Scalar(255,255,255)
void DrawArrow(cv::Mat &matTarget, const cv::Point &start, const cv::Point &end,const cv::Scalar &color,int thickness);
#endif //IMAGEPROCESS_DRAWUTILS_H
