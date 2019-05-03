#include "node.h"

void Node::setvalue(float a)//除了variable以外这个函数不起作用
{
}

void Node::reset()
{
    for (auto it = parents.begin(); it != parents.end(); ++it)
        (*it)->reset();
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

OneParentNode::OneParentNode(Node* p1)
{
    parents.push_back(p1);
}

float TwoParentsNode::geteval()
{
    if(calculated)
        return tempeval;
    calculated=1;
    return tempeval=func();
}

TwoParentsNode::TwoParentsNode(Node* p1,Node* p2)
{
    parents.push_back(p1);
    parents.push_back(p2);
}

float ThreeParentsNode::geteval()
{
    if(calculated)
        return tempeval;
    calculated=1;
    return tempeval=func();
}


ThreeParentsNode::ThreeParentsNode(Node* p1,Node* p2,Node* p3)
{
    parents.push_back(p1);
    parents.push_back(p2);
    parents.push_back(p3);
}