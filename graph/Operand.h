#pragma once
#include "node.h"

extern bool asserted;
class Placeholder:public Operand
{
	public:
		std::string name;
		void setvalue(float a);
		float geteval() override;
		Placeholder(std::string);
};

class Constant:public Operand
{
	public:
		float geteval() override;
		void reset() override;
		Constant(std::string,float b);
};

class Variable:public Operand
{
	public:
		void setvalue(float a);
		float geteval() override;
		void reset() override;
		Variable(std::string,float b);
};