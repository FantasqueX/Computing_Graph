#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include "node.h"
class Print:public OneParentNode
{
	public:
		using OneParentNode::OneParentNode;
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
