#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include "node.h"
class sum:public TwoParentsNode
{
	public:
		using TwoParentsNode::TwoParentsNode;
		float func(float x,float y);
};
class subtraction:public TwoParentsNode
{
	public:
		using TwoParentsNode::TwoParentsNode;
		float func(float x,float y);
};
class multiply:public TwoParentsNode
{
	public:
		using TwoParentsNode::TwoParentsNode;
		float func(float x,float y);
};
class division:public TwoParentsNode
{
	public:
		using TwoParentsNode::TwoParentsNode;
		float func(float x,float y);
};
class EQU:public TwoParentsNode
{
	public:
		using TwoParentsNode::TwoParentsNode;
		float func(float x,float y);
};
class GTR:public TwoParentsNode
{
	public:
		using TwoParentsNode::TwoParentsNode;
		float func(float x,float y);
};
class GEQ:public TwoParentsNode
{
	public:
		using TwoParentsNode::TwoParentsNode;
		float func(float x,float y);
};
class LSS:public TwoParentsNode
{
	public:
		using TwoParentsNode::TwoParentsNode;
		float func(float x,float y);
};
class LEQ:public TwoParentsNode
{
	public:
		using TwoParentsNode::TwoParentsNode;	
		float func(float x,float y);
};
