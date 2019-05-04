#include "UnaryOperation.h"

Print::Print(std::string nm,std::string str,Node* parent): UnaryOperation(nm,parent)
{
	pnm = str;
}

float Print::func()
{
	float x = parents[0]->geteval();
	std::cout<<"PRINT operator: "<<pnm<<" = "<<x<<std::endl;
	return x;
}

float Sin::func()
{
	float x = parents[0]->geteval();
	return sin(x);
}

float Sin::derivative()
{
	float x = parents[0]->geteval();
	return cos(x);
}

float Exp::func()
{
	float x = parents[0]->geteval();
	return exp(x);
}

float Exp::derivative()
{
	return func();
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

float Log::derivative()
{
	float x = parents[0]->geteval();
	return 1/x;
}

float Tanh::func()
{
	float x = parents[0]->geteval();
	return tanh(x);
}

float Tanh::derivative()
{
	float x = parents[0]->geteval();
	return 1/pow(cosh(x),2);
}

float Sigmoid::func()
{
	float x = parents[0]->geteval();
	return (tanh(x/2)+1)/2;
}

float Sigmoid::derivative()
{
	return func()*(1-func());
}