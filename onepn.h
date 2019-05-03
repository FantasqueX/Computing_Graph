#pragma once
#include <iostream>
#include "node.h"

extern bool asserted;

class Print:public OneParentNode
{
	std::string nm; //保存被print变量名
	public:
		Print(std::string str, Node* parent);
		float func() override;
};

class Sin:public OneParentNode
{
	public:
		using OneParentNode::OneParentNode;
		float func() override;
};

class Exp:public OneParentNode
{
	public:
		using OneParentNode::OneParentNode;
		float func() override;
};

class Log:public OneParentNode
{
	public:
		using OneParentNode::OneParentNode;
		float func() override;
};

class Tanh:public OneParentNode
{
	public:
		using OneParentNode::OneParentNode;
		float func() override;
};

class Sigmoid:public OneParentNode
{
	public:
		using OneParentNode::OneParentNode;
		float func() override;
};
