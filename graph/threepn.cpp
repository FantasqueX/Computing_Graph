#include "threepn.h"

float Cond::func()
{
    float x = parents[0]->geteval(),y = parents[1] ->geteval(), z = parents[2]->geteval();
	if(std::isnan(x)||std::isnan(y)||std::isnan(z))return NAN;
    if(x>0)
        return y;
    return z;
}
