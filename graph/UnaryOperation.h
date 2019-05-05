#pragma once
#include "node.h"

extern bool asserted;

class Print:public UnaryOperation
{
	std::string pnm; //保存被print变量名
	public:
		Print(std::string str, Node* parent);
		float func() override;
};		float derivative();

class Sin:public UnaryOperation
{
	public:
		using UnaryOperation::UnaryOperation;
		float func() override;
		float derivative();
};

class Exp:public UnaryOperation
{
	public:
		using UnaryOperation::UnaryOperation;
		float func() override;
		float derivative();
};

class Log:public UnaryOperation
{
	public:
		using UnaryOperation::UnaryOperation;
		float func() override;
		float derivative();
};

class Tanh:public UnaryOperation
{
	public:
		using UnaryOperation::UnaryOperation;
		float func() override;
		float derivative();
};

class Sigmoid:public UnaryOperation
{
	public:
		using UnaryOperation::UnaryOperation;
		float func() override;
		float derivative();
};
