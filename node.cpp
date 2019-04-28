#include "node.h"
float Node::geteval()
{
}
void Node::setvalue(float a)
{
}
void Node::reset()
{
    calculated=0;
}
float ZeroParentsNode::geteval()
{
    return 1;
}
int ZeroParentsNode::getParentsNum()
{
    return 0;
}
float OneParentsNode::geteval()
{
    if(calculated)return tempeval;
    else
    {
        calculated=1;
        tempeval=func(p1->geteval());
        return tempeval;
    }
}
int OneParentsNode::getParentsNum()
{
    return 1;
}
float OneParentsNode::func(float x){}
OneParentsNode::OneParentsNode(std::string a,Node* parent1)
{
    name=a;
    p1=parent1;
}
float TwoParentsNode::func(float x,float y)
{
}
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
TwoParentsNode::TwoParentsNode(std::string a,Node* parent1,Node* parent2)
{
    name=a;
    p1=parent1;
    p2=parent2;
}
float ThreeParentsNode::func(float x,float y,float z){}
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
ThreeParentsNode::ThreeParentsNode(std::string a,Node* parent1,Node* parent2,Node* parent3)
{
    name=a;
    p1=parent1;
    p2=parent2;
    p3=parent3;
}