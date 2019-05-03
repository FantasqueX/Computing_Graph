#include "node.h"

void Node::setvalue(float a)//除了variable以外这个函数不起作用
{
}

void Node::reset()
{
    calculated=0;
}

void OneParentNode::reset()
{
	p1->reset();//递归清零 
    calculated=0;
}
void TwoParentsNode::reset()
{
	p1->reset();//递归清零
	p2->reset();
    calculated=0;
}
void ThreeParentsNode::reset()
{
	p1->reset();//递归清零
	p2->reset();
	p3->reset();
    calculated=0;
}

float ZeroParentNode::geteval()
{
    return NAN;
}

float OneParentNode::geteval()
{
    if(calculated)
        return tempeval;//如果已计算就直接返回计算数值
    calculated=1;
    return tempeval=func();
}

OneParentNode::OneParentNode(Node* parent1)
{
    p1=parent1;
}

float TwoParentsNode::geteval()
{
    if(calculated)
        return tempeval;
    calculated=1;
    return tempeval=func();
}


TwoParentsNode::TwoParentsNode(Node* parent1,Node* parent2)
{
    p1=parent1;
    p2=parent2;
}


float ThreeParentsNode::geteval()
{
    if(calculated)
        return tempeval;
    calculated=1;
    return tempeval=func();
}


ThreeParentsNode::ThreeParentsNode(Node* parent1,Node* parent2,Node* parent3)
{
    p1=parent1;
    p2=parent2;
    p3=parent3;
}
