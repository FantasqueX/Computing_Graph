#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include "node.h"
extern bool asserted;
class Print:public OneParentNode
{
	std::string nm;
	public:
		Print(std::string str, Node* parent);
		float func(float x);
};
class Sin:public OneParentNode
{
	public:
		using OneParentNode::OneParentNode;
		float func(float x);
};
class Exp:public OneParentNode
{
	public:
		using OneParentNode::OneParentNode;
		float func(float x);
};
class Log:public OneParentNode
{
	public:
		using OneParentNode::OneParentNode;
		float func(float x);
};
class Tanh:public OneParentNode
{
	public:
		using OneParentNode::OneParentNode;
		float func(float x);
};
class Sigmoid:public OneParentNode
{
	public:
		using OneParentNode::OneParentNode;
		float func(float x);
};
