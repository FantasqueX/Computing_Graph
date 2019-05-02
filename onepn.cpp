#include "onepn.h"
#include <string>
Print::Print(std::string str,Node* parent): OneParentNode(parent)
{
	nm = str;
}
float Print::func(float x)
{
	std::cout<<"PRINT operator: "<<nm<<" = "<<x<<std::endl;
	return x;
}
float Sin::func(float x)
{
	return sin(x);
}
float Exp::func(float x)
{
	return exp(x);
}
float Log::func(float x)
{
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
float Tanh::func(float x)
{
	return tanh(x);
}
float Sigmoid::func(float x)
{
	return (tanh(x/2)+1)/2;
}
/*
创建新的单变量函数的方法:
例:方法1:
class Sqr:public OneParentNode
{
	public:
		using OneParentNode::OneParentNode;
		float func(float x)
		{
			return x*x;
		}
};
gra.push(节点名,new Sqr(gra[父节点名]));(gra为Graph类的实例)

方法2:
float Sqr(float x)
{
	return x*x;
}
gra.push(节点名,new Opn<Sqr>(gra[父节点名]));
*/ 
