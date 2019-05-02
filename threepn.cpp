#include "threepn.h"
#include<string>
float Cond::func(float x,float y,float z)
{
	if(isnan(x)||isnan(y)||isnan(z))return NAN;
    if(x>0)
        return y;
    else
        return z;
}
