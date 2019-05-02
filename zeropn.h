#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include "node.h"
using namespace std;

extern bool asserted;
class Placeholder:public ZeroParentNode
{
	public:
		static float valuelist;
		float value;//placeholderµÄÖµ 
		void setvalue(float a);//¸³Öµ 
		float geteval();
};

class Constant:public ZeroParentNode
{
		float value;
	public:
		float geteval();
		virtual void reset();
		Constant(float b);
};

class Variable:public ZeroParentNode
{
	public:
		float value;
		void setvalue(float a);
		float geteval();
		virtual void reset();
		Variable(float b);
};
