#include "Operand.h"

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
		if(!asserted)
		{
			std::cout<<"ERROR: Placeholder missing"<<std::endl;
			asserted=1;
		}
		return NAN;
	}
}
Placeholder::Placeholder(std::string nm)
{
	name = nm;
}

float Constant::geteval()
{
	return value;
}

void Constant::reset() {}

Constant::Constant(std::string nm,float b)
{
	name = nm;
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

Variable::Variable(std::string nm,float b)
{
	name = nm;
	value=b;
}
