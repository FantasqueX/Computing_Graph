#include <iostream>
#include <string>
#include "zeropn.h"
void Placeholder::setvalue(float a)
{
	value=a;
	calculated=1;//未赋值为0,已赋值为1 
}
float Placeholder::geteval()
{
	if(calculated)
		return value;//若已赋值则返回对应数值 
	else//否则输出error并返回nan 
	{
		if(!asserted) 
		{
			std::cout<<"ERROR: Placeholder missing"<<std::endl;
			asserted=1;
		}
		return NAN;
	}
}
float Constant::geteval()
{
	return value;
}
void Constant::reset(){}//constant的calculated恒为1,所以reset不需要进行任何操作

Constant::Constant(float b)
{
	value=b;
}
void Variable::setvalue(float a)//修改variable的值 
{
	value=a;
}
float Variable::geteval()
{
	return value;
}
void Variable::reset() {}//variable的calculated恒为1,所以reset不需要进行任何操作
Variable::Variable(float b)
{
	value=b;
}
