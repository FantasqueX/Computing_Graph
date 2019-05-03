#include "twopn.h"

float Sum::func()
{
	float x = p1->geteval(),y = p2->geteval();
	return x+y;
}

float Subtraction::func()
{
	float x = p1->geteval(),y = p2->geteval();
	return x-y;
}

float Multiply::func()
{
	float x = p1->geteval(),y = p2->geteval();
	return x*y;
}

float Division::func()
{
	float x = p1->geteval(),y = p2->geteval();
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

float EQU::func()
{
	float x = p1->geteval(),y = p2->geteval();
	if(std::isnan(x)||std::isnan(y))return NAN;
	return float(x==y);
}

float GTR::func()
{
	float x = p1->geteval(),y = p2->geteval();
	if(std::isnan(x)||std::isnan(y))return NAN;
	return float(x>y);
}

float GEQ::func()
{
	float x = p1->geteval(),y = p2->geteval();
	if(std::isnan(x)||std::isnan(y))return NAN;
	return float(x>=y);
}

float LSS::func()
{
	float x = p1->geteval(),y = p2->geteval();
	if(std::isnan(x)||std::isnan(y))return NAN;
	return float(x<y);
}

float LEQ::func()
{
	float x = p1->geteval(),y = p2->geteval();
	if(std::isnan(x)||std::isnan(y))return NAN;
	return float(x<=y);
}
