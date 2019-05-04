#include "node.h"

void Node::setvalue(float a)//除了variable以外这个函数不起作用
{
}

void Node::reset()
{
    for (auto it = parents.begin(); it != parents.end(); ++it)
        (*it)->reset();
    calculated=0;
    calculatedderivative = 0;
}

float Node::geteval()
{
    if(calculated)
        return tempeval;//如果已计算就直接返回计算数值
    calculated=1;
    return tempeval=func();
}

float Node::getderivative(Node* f)//求得导f/导x
{
    if(calculatedderivative)
        return tempderivative;
    calculatedderivative = 1;
    tempderivative = 0;
    if(!sons.size())
    {
        if(f->name == name)
            tempderivative = 1;
    }
    else
    {
        for(auto it  = sons.begin(); it != sons.end() ; ++it)
            tempderivative += (*it)->getderivative(f)*(*it)->lookupderivative(this);
    }
    return tempderivative;
}

float Operand::func()
{
    return NAN;
}

float Operand::lookupderivative(Node* p)
{
    return 0;
}

float UnaryOperation::derivative()
{
    return NAN;
}

float UnaryOperation::lookupderivative(Node* p)
{
    return derivative();
}

float BinaryOperation::derivative1()
{
    return NAN;
}

float BinaryOperation::derivative2()
{
    return NAN;
}

float BinaryOperation::lookupderivative(Node* p)
{
    int tmp = 0;
    for(auto it = parents.begin(); it != parents.end(); ++it)
    {
        ++tmp;
        if((*it) == p)
        {
            if(tmp == 1)
                return derivative1();
            return derivative2();
        }
    }
}

float TernaryOperation::lookupderivative(Node*)
{
    return NAN;
}

UnaryOperation::UnaryOperation(std::string nm,Node* p1)
{
    name = nm;
    parents.push_back(p1);
    p1->sons.push_back(this);
}

BinaryOperation::BinaryOperation(std::string nm,Node* p1,Node* p2)
{
    name = nm;
    parents.push_back(p1);
    parents.push_back(p2);
    p1->sons.push_back(this);
    p2->sons.push_back(this);
}

TernaryOperation::TernaryOperation(std::string nm,Node* p1,Node* p2,Node* p3)
{
    name = nm;
    parents.push_back(p1);
    parents.push_back(p2);
    parents.push_back(p3);
    p1->sons.push_back(this);
    p2->sons.push_back(this);
    p3->sons.push_back(this);
}