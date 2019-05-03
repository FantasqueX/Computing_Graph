#pragma once
#include "node.h"

extern bool asserted;
class Placeholder:public ZeroParentNode
{
	public:
		static float valuelist;
		float value;
		void setvalue(float a);
		float geteval();
		Placeholder();
};

class Constant:public ZeroParentNode
{
		float value;
	public:
		float geteval();
		void reset();
		Constant(float b);
};

class Variable:public ZeroParentNode
{
	public:
		float value;
		void setvalue(float a);
		float geteval();
		void reset();
		Variable(float b);
};
