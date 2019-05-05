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

Placeholder::Placeholder(const std::string& nm)
{
	name = nm;
}

float Constant::getValue()
{
	return value;
}

void Constant::reset() {}

Constant::Constant(const std::string& nm,float b)
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

Variable::Variable(const std::string& nm,float b)
{
	name = nm;
	value=b;
}
