#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include "node.h"
using namespace std;
class Placeholder:public ZeroParentNode
{
	public:
		static float valuelist;
		float value;//应该统一进tempvalue？
		void setvalue(float a);
		float geteval();
		Placeholder(string a);
};
class Constant:public ZeroParentNode
{
		float value;
	public:
		float geteval();
		virtual void reset();
		Constant(string a,float b);
};
class Variable:public ZeroParentNode
{
	public:
		float value;
		void setvalue(float a);
		float geteval();
		virtual void reset();
		Variable(std::string a,float b);
};
