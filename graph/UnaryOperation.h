#pragma once
#include <iostream>
#include "node.h"

extern bool asserted;

class Print:public UnaryOperation
{
	std::string nm; //保存被print变量名
	public:
		Print(std::string str, Node* parent);
		float func() override;
};

class Sin:public UnaryOperation
{
	public:
		using UnaryOperation::UnaryOperation;
		float func() override;
};

class Exp:public UnaryOperation
{
	public:
		using UnaryOperation::UnaryOperation;
		float func() override;
};

class Log:public UnaryOperation
{
	public:
		using UnaryOperation::UnaryOperation;
		float func() override;
};

class Tanh:public UnaryOperation
{
	public:
		using UnaryOperation::UnaryOperation;
		float func() override;
};

class Sigmoid:public UnaryOperation
{
	public:
		using UnaryOperation::UnaryOperation;
		float func() override;
};
