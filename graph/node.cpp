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

float Node::geteval()
{
    if(calculated)
        return tempeval;//如果已计算就直接返回计算数值
    calculated=1;
    return tempeval=func();
}

float Operand::func()
{
    return NAN;
}

UnaryOperation::UnaryOperation(Node* p1)
{
    parents.push_back(p1);
}


BinaryOperation::BinaryOperation(Node* p1,Node* p2)
{
    parents.push_back(p1);
    parents.push_back(p2);
}



TernaryOperation::TernaryOperation(Node* p1,Node* p2,Node* p3)
{
    parents.push_back(p1);
    parents.push_back(p2);
    parents.push_back(p3);
}