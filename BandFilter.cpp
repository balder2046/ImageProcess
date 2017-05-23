//
// Created by 赵磊 on 2017/5/23.
//

#include <cmath>
#include "BandFilter.h"

CBandFilter::CBandFilter(int nWidth) {
    m_nWidth = nWidth;
}

double CBandFilter::GetWeight(int distance) {
    double fdist = double(distance) / m_nWidth;
    fdist = fabs(fdist);
    if (fdist < 1.0) return 1.0;
    if (fdist < 1.5) return -1.0;
    return .0;
}