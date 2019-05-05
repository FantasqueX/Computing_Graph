#include "Operand.h"

void Placeholder::setValue(float a)
{
	value=a;
	calculated=1;
}

float Placeholder::getValue()
{
	if(calculated)
		return value;
	if(!asserted)
	{
		std::cout<<"ERROR: Placeholder missing"<<std::endl;
		asserted=1;
	}
	return NAN;
}

Placeholder::Placeholder(std::string nm)
{
	name = nm;
}

float Constant::getValue()
{
	return value;
}

void Constant::reset() {}

Constant::Constant(std::string nm,float b)
{
	name = nm;
	value=b;
}

void Variable::setValue(float a)
{
	value=a;
}
float Variable::getValue()
{
	return value;
}

void Variable::reset() {}

Variable::Variable(std::string nm,float b)
{
	name = nm;
	value=b;
}
