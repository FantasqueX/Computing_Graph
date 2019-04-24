#include "twopn.h"
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
    if(y==0)
    {
        std::cout<<"ERROR: Division by zero";
        return NaN;
    }
    else
        return x/y;
}
float EQU::func(float x,float y)
{
    return float(x==y);
}
float GTR::func(float x,float y)
{
    return float(x>y);
}
float GEQ::func(float x,float y)
{
    return float(x>=y);
}
float LSS::func(float x,float y)
{
    return float(x<y);
}
float LEQ::func(float x,float y)
{
    return float(x<=y);
}