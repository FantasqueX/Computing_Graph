#pragma once
#include "node.h"

extern bool asserted;
class Placeholder:public Operand
{
	public:
		void setvalue(float a);
		float geteval() override;
		Placeholder();
};

class Constant:public Operand
{
	public:
		float geteval() override;
		void reset() override;
		Constant(float b);
};

class Variable:public Operand
{
	public:
		void setvalue(float a);
		float geteval() override;
		void reset() override;
		Variable(float b);
};
