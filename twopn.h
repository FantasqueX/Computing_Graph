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
		float func() override;
};
class EQU:public TwoParentsNode
{
	public:
		using TwoParentsNode::TwoParentsNode;
		float func() override;
};
class GTR:public TwoParentsNode
{
	public:
		using TwoParentsNode::TwoParentsNode;
		float func() override;
};
class GEQ:public TwoParentsNode
{
	public:
		using TwoParentsNode::TwoParentsNode;
		float func() override;
};
class LSS:public TwoParentsNode
{
	public:
		using TwoParentsNode::TwoParentsNode;
		float func() override;
};
class LEQ:public TwoParentsNode
{
	public:
		using TwoParentsNode::TwoParentsNode;	
		float func() override;
};
