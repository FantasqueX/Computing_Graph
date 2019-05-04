#include "BinaryOperation.h"

float Sum::func()
{
	float x = parents[0]->geteval(),y = parents[1]->geteval();
	return x+y;
}

float Sum::derivative1()
{
	return 1;
}

float Sum::derivative2()
{
	return 1;
}

float Subtraction::func()
{
	float x = parents[0]->geteval(),y = parents[1]->geteval();
	return x-y;
}

float Subtraction::derivative1()
{
	return 1;
}

float Subtraction::derivative2()
{
	return -1;
}

float Multiply::func()
{
	float x = parents[0]->geteval(),y = parents[1]->geteval();
	return x*y;
}

float Multiply::derivative1()
{
	return parents[1]->geteval();
}

float Multiply::derivative2()
{
	return parents[0]->geteval();
}

float Division::func()
{
	float x = parents[0]->geteval(),y = parents[1]->geteval();
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
}

float Division::derivative1()
{
	return 1/parents[1]->geteval();
}

float Division::derivative2()
{
	float x = parents[0]->geteval(),y = parents[1]->geteval();
	return -x/(y*y);
}

float EQU::func()
{
	float x = parents[0]->geteval(),y = parents[1]->geteval();
	if(std::isnan(x)||std::isnan(y))return NAN;
	return float(x==y);
}

float GTR::func()
{
	float x = parents[0]->geteval(),y = parents[1]->geteval();
	if(std::isnan(x)||std::isnan(y))return NAN;
	return float(x>y);
}

float GEQ::func()
{
	float x = parents[0]->geteval(),y = parents[1]->geteval();
	if(std::isnan(x)||std::isnan(y))return NAN;
	return float(x>=y);
}

float LSS::func()
{
	float x = parents[0]->geteval(),y = parents[1]->geteval();
	if(std::isnan(x)||std::isnan(y))return NAN;
	return float(x<y);
}

float LEQ::func()
{
	float x = parents[0]->geteval(),y = parents[1]->geteval();
	if(std::isnan(x)||std::isnan(y))return NAN;
	return float(x<=y);
}
