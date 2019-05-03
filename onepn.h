#pragma once
#include <iostream>
#include "node.h"

extern bool asserted;

class Print:public OneParentNode
{
	std::string nm; //保存被print变量名
	public:
		Print(std::string str, Node* parent);
		float func();
};

class Sin:public OneParentNode
{
	public:
		using OneParentNode::OneParentNode;
		float func();
};

class Exp:public OneParentNode
{
	public:
		using OneParentNode::OneParentNode;
		float func();
};

class Log:public OneParentNode
{
	public:
		using OneParentNode::OneParentNode;
		float func();
};

class Tanh:public OneParentNode
{
	public:
		using OneParentNode::OneParentNode;
		float func();
};

class Sigmoid:public OneParentNode
{
	public:
		using OneParentNode::OneParentNode;
		float func();
};
