#include "UnaryOperation.h"
#include <string>
Print::Print(std::string str,Node* parent): UnaryOperation(parent)
{
	nm = str;
}
float Print::func()
{
	float x = parents[0]->geteval();
	std::cout<<"PRINT operator: "<<nm<<" = "<<x<<std::endl;
	return x;
}
float Sin::func()
{
	float x = parents[0]->geteval();
	return sin(x);
}
float Exp::func()
{
	float x = parents[0]->geteval();
	return exp(x);
}
float Log::func()
{
	float x = parents[0]->geteval();
	if(x<=0)
	{
		if(!asserted)
		{
			std::cout<<"ERROR: LOG operator's input must be positive"<<std::endl;
			asserted=1;
		}
		return NAN;
	}
	return log(x);
}
float Tanh::func()
{
	float x = parents[0]->geteval();
	return tanh(x);
}
float Sigmoid::func()
{
	float x = parents[0]->geteval();
	return (tanh(x/2)+1)/2;
}
