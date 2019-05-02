#include <iostream>
#include <string>
#include "zeropn.h"
void Placeholder::setvalue(float a)
{
    value=a;
    calculated=1;
}
float Placeholder::geteval()
{
    if(calculated)
        return value;
    else
    {
        std::cout<<"ERROR: Placeholder missing"<<std::endl;
        return NAN;
    }
}
Placeholder::Placeholder()
{
}
float Constant::geteval()
{
    return value;
}
void Constant::reset()
{
}
Constant::Constant(float b)
{
    value=b;
}
void Variable::setvalue(float a)
{
    value=a;
}
float Variable::geteval()
{
    return value;
}
void Variable::reset() {}
Variable::Variable(float b)
{
    value=b;
}