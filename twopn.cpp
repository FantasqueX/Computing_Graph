#include "twopn.h"
float sum(float x,float y)
{
    return x+y;
}
float subtraction(float x,float y)
{
    return x-y;
}
float multiply(float x,float y)
{
    return x*y;
}
float division(float x,float y)
{
    if(y==0)
    {
        std::cout<<"ERROR: Division by zero";
        return NaN;
    }
    else
        return x/y;
}
float EQU(float x,float y)
{
    return float(x==y);
}
float GTR(float x,float y)
{
    return float(x>y);
}
float GEQ(float x,float y)
{
    return float(x>=y);
}
float LSS(float x,float y)
{
    return float(x<y);
}
float LEQ(float x,float y)
{
    return float(x<=y);
}
