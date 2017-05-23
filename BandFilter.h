//
// Created by 赵磊 on 2017/5/23.
//

#ifndef IMAGEPROCESS_BANDFILTER_H
#define IMAGEPROCESS_BANDFILTER_H

class CBandFilter {
public:
    CBandFilter(int nWidth);

public:
    double GetWeight(int distance);

private:
    int m_nWidth;
};

#endif //IMAGEPROCESS_BANDFILTER_H
