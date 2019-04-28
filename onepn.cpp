#include "onepn.h"
float Print::func(float x)
{
    std::cout<<"Print Operator: "<<p1->name<<"="<<x<<std::endl;
    return x;
}
float Sin(float x)
{
    return sin(x);
}
float Exp(float x)
{
    return exp(x);
}
float Log(float x)
{
    if(x<=0)
        std::cout<<"LOG operator's input must be positive"<<std::endl;
    return log(x);
}
float Tanh(float x)
{
    return tanh(x);
}
float Sigmoid(float x)
{
    return (tanh(x/2)+1)/2;
}
