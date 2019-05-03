#include "threepn.h"

float Cond::func()
{
    float x = p1->geteval(),y = p2->geteval(), z = p3->geteval();
	if(std::isnan(x)||std::isnan(y)||std::isnan(z))return NAN;
    if(x>0)
        return y;
    return z;
}
