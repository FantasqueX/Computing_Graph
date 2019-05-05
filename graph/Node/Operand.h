#pragma once
#include "node.h"

extern bool asserted;
class Placeholder:public Operand
{
	public:
		void setValue(float a);
		float getValue() override;
		Placeholder(const std::string&);
};

class Constant:public Operand
{
	public:
		float getValue() override;
		void reset() override;
		Constant(const std::string& nm,float b);
};

class Variable:public Operand
{
	public:
		void setValue(float a);
		float getValue() override;
		void reset() override;
		Variable(const std::string& nm,float b);
};
