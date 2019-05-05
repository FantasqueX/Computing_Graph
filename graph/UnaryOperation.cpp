#include "UnaryOperation.h"

Print::Print(std::string nm,std::string str,Node* parent): UnaryOperation(nm,parent)
{
	pnm = str;
}

float Print::func()
{
	float x = parents[0]->getValue();
	std::cout<<"PRINT operator: "<<pnm<<" = "<<x<<std::endl;
	return x;
}

float Sin::func()
{
	float x = parents[0]->getValue();
	return sin(x);
}

float Sin::derivative()
{
	float x = parents[0]->getValue();
	return cos(x);
}

float Exp::func()
{
	float x = parents[0]->getValue();
	return exp(x);
}

float Exp::derivative()
{
	return func();
}

float Log::func()
{
	float x = parents[0]->getValue();
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

float Log::derivative()
{
	float x = parents[0]->getValue();
	return 1/x;
}

float Tanh::func()
{
	float x = parents[0]->getValue();
	return tanh(x);
}

float Tanh::derivative()
{
	float x = parents[0]->getValue();
	return 1/pow(cosh(x),2);
}

float Sigmoid::func()
{
	float x = parents[0]->getValue();
	return (tanh(x/2)+1)/2;
}

float Sigmoid::derivative()
{
	return func()*(1-func());
}