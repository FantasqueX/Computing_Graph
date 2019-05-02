#include "node.h"
// float Node::geteval()
// {
// }

void Node::setvalue(float a)
{
}

void Node::reset()
{
    calculated=0;
}

float ZeroParentNode::geteval()
{
    return 1;
}

int ZeroParentNode::getParentsNum()
{
    return 0;
}

float OneParentNode::geteval()
{
    if(calculated)return tempeval;
    else
    {
        calculated=1;
        tempeval=func(p1->geteval());
        return tempeval;
    }
}

int OneParentNode::getParentsNum()
{
    return 1;
}

// float OneParentNode::func(float x){}

OneParentNode::OneParentNode(Node* parent1)
{
    p1=parent1;
}

// float TwoParentsNode::func(float x,float y)
// {
// }

float TwoParentsNode::geteval()
{
    if(calculated)return tempeval;
    else
    {
        calculated=1;
        tempeval=func(p1->geteval(),p2->geteval());
        return tempeval;
    }
}

int TwoParentsNode::getParentsNum()
{
    return 2;
}

TwoParentsNode::TwoParentsNode(Node* parent1,Node* parent2)
{
    p1=parent1;
    p2=parent2;
}

// float ThreeParentsNode::func(float x,float y,float z){}

float ThreeParentsNode::geteval()
{
    if(calculated)return tempeval;
    else
    {
        calculated=1;
        tempeval=func(p1->geteval(),p2->geteval(),p3->geteval());
        return tempeval;
    }
}

int ThreeParentsNode::getParentsNum()
{
    return 3;
}

ThreeParentsNode::ThreeParentsNode(Node* parent1,Node* parent2,Node* parent3)
{
    p1=parent1;
    p2=parent2;
    p3=parent3;
}