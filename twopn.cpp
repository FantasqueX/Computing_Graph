#include "twopn.h"
#include <cmath>
float sum::func(float x,float y)
{
	return x+y;
}
float subtraction::func(float x,float y)
{
	return x-y;
}
float multiply::func(float x,float y)
{
	return x*y;
}
float division::func(float x,float y)
{
<<<<<<< HEAD
    if(y==0)
    {
        std::cout<<"ERROR: Division by zero" << std::endl;
        return NAN;
    }
    else
        return x/y;
=======
	if(y==0)
	{
		if(!asserted)
		{
			std::cout<<"ERROR: Division by zero"<<std::endl;
			asserted=1;
		}
		return NAN;
	}
	else
		return x/y;
>>>>>>> 895d1d48c25cb7d0887bd6021983ed67e7d726dc
}
float EQU::func(float x,float y)
{
	if(isnan(x)||isnan(y))return NAN;
	return float(x==y);
}
float GTR::func(float x,float y)
{
	if(isnan(x)||isnan(y))return NAN;
	return float(x>y);
}
float GEQ::func(float x,float y)
{
	if(isnan(x)||isnan(y))return NAN;
	return float(x>=y);
}
float LSS::func(float x,float y)
{
	if(isnan(x)||isnan(y))return NAN;
	return float(x<y);
}
float LEQ::func(float x,float y)
{
	if(isnan(x)||isnan(y))return NAN;
	return float(x<=y);
}
