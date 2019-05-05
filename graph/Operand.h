#pragma once
#include "node.h"

extern bool asserted;
class Placeholder:public Operand
{
	public:
		std::string name;
		void setValue(float a);
		float getValue() override;
		Placeholder(std::string);
};

class Constant:public Operand
{
	public:
		float getValue() override;
		void reset() override;
		Constant(std::string,float b);
};

class Variable:public Operand
{
	public:
		void setValue(float a);
		float getValue() override;
		void reset() override;
		Variable(std::string,float b);
};