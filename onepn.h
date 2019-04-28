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
float Sin(float x);
float Exp(float x);
float Log(float x);
float Tanh(float x);
float Sigmoid(float x);
