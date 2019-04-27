#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include "node.h"
class Print:public OneParentsNode
{
	public:
		using OneParentsNode::OneParentsNode;
		float func(float x);
};
class Sin:public OneParentsNode
{
	public:
		using OneParentsNode::OneParentsNode;
		float func(float x);
};
class Exp:public OneParentsNode
{
	public:
		using OneParentsNode::OneParentsNode;
		float func(float x);
};
class Log:public OneParentsNode
{
	public:
		using OneParentsNode::OneParentsNode;
		float func(float x);
};
class Tanh:public OneParentsNode
{
	public:
		using OneParentsNode::OneParentsNode;
		float func(float x);
};
class Sigmoid:public OneParentsNode
{
	public:
		using OneParentsNode::OneParentsNode;
		float func(float x);
};
