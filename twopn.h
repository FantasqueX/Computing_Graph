#pragma once
#include "node.h"
extern bool asserted;

class Sum:public TwoParentsNode
{
	public:
		using TwoParentsNode::TwoParentsNode;
		float func();
};
class Subtraction:public TwoParentsNode
{
	public:
		using TwoParentsNode::TwoParentsNode;
		float func();
};
class Multiply:public TwoParentsNode
{
	public:
		using TwoParentsNode::TwoParentsNode;
		float func();
};
class Division:public TwoParentsNode
{
	public:
		using TwoParentsNode::TwoParentsNode;
		float func();
};
class EQU:public TwoParentsNode
{
	public:
		using TwoParentsNode::TwoParentsNode;
		float func();
};
class GTR:public TwoParentsNode
{
	public:
		using TwoParentsNode::TwoParentsNode;
		float func();
};
class GEQ:public TwoParentsNode
{
	public:
		using TwoParentsNode::TwoParentsNode;
		float func();
};
class LSS:public TwoParentsNode
{
	public:
		using TwoParentsNode::TwoParentsNode;
		float func();
};
class LEQ:public TwoParentsNode
{
	public:
		using TwoParentsNode::TwoParentsNode;	
		float func();
};
