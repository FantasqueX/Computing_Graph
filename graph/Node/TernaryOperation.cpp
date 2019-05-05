#include "TernaryOperation.h"

float Cond::func()
{
    float x = parents[0]->getValue(),y = parents[1] ->getValue(), z = parents[2]->getValue();
	if(std::isnan(x)||std::isnan(y)||std::isnan(z))return NAN;
    if(x>0)
        return y;
    return z;
}
