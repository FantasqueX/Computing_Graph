#include "twopn.h"
#include <cmath>
float sum::func(float x,float y)
{
	return x+y;
}
float subtraction::func(float x,float y)
{
	return x-y;
}
float multiply::func(float x,float y)
{
	return x*y;
}
float division::func(float x,float y)
{
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
float EQU::func(float x,float y)
{
	if(isnan(x)||isnan(y))return NAN;
	return float(x==y);
}
float GTR::func(float x,float y)
{
	if(isnan(x)||isnan(y))return NAN;
	return float(x>y);
}
float GEQ::func(float x,float y)
{
	if(isnan(x)||isnan(y))return NAN;
	return float(x>=y);
}
float LSS::func(float x,float y)
{
	if(isnan(x)||isnan(y))return NAN;
	return float(x<y);
}
float LEQ::func(float x,float y)
{
	if(isnan(x)||isnan(y))return NAN;
	return float(x<=y);
}
/*
创建新的双变量函数的方法:
例:方法1:
class Pow:public TwoParentsNode
{
	public:
		using TwoParentsNode::TwoParentsNode;
		float func(float x,float y)
		{
			return std::pow(x,y);
		}
};
gra.push(节点名,new Pow(gra[父节点名1],gra[父节点名2]));(gra为Graph类的实例) 

方法2:
gra.push(节点名,new Tpn<std::pow>(gra[父节点名1],gra[父节点名2]));
*/
