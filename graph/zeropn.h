#pragma once
#include "node.h"

extern bool asserted;
class Placeholder:public ZeroParentNode
{
	public:
		void setvalue(float a);
		float geteval() override;
		Placeholder();
};

class Constant:public ZeroParentNode
{
	public:
		float geteval() override;
		void reset() override;
		Constant(float b);
};

class Variable:public ZeroParentNode
{
	public:
		void setvalue(float a);
		float geteval() override;
		void reset() override;
		Variable(float b);
};
