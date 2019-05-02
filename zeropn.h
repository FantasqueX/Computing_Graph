#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include "node.h"
using namespace std;
class Placeholder:public ZeroParentsNode
{
	public:
		static float valuelist;
		float value;
		void setvalue(float a);
		float geteval();
		Placeholder();
};
class Constant:public ZeroParentsNode
{
		float value;
	public:
		float geteval();
		virtual void reset();
		Constant(float b);
};
class Variable:public ZeroParentsNode
{
	public:
		float value;
		void setvalue(float a);
		float geteval();
		virtual void reset();
		Variable(float b);
};
