#include "onepn.h"
float Print::func(float x)
{
    std::cout<<"Print Operator: "<<p1->name<<"="<<x<<std::endl;
    return x;
}
float Sin::func(float x)
{
    return sin(x);
}
float Exp::func(float x)
{
    return exp(x);
}
float Log::func(float x)
{
    if(x<=0)
        std::cout<<"LOG operator's input must be positive"<<std::endl;
    return log(x);
}
float Tanh::func(float x)
{
    return tanh(x);
}
float Sigmoid::func(float x)
{
    return (tanh(x/2)+1)/2;
}