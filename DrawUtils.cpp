//
// Created by 赵磊 on 2017/2/9.
//
#include "DrawUtils.h"
using namespace cv;
void DrawArrow(cv::Mat &matTarget, const cv::Point &start, const cv::Point &end,const cv::Scalar &color,int thickness)
{
    arrowedLine(matTarget,start,end,color,thickness);
}
