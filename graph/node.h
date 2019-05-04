#pragma once
#include<cmath>
#include<iostream>
#include<vector>
#include<string>

class Node
{
	protected:
		float tempeval;//临时计算数值(避免重复计算)
		float tempderivative;
		bool calculated = 0;//是否已计算 (避免重复计算)
		bool calculatedderivative = 0;
		std::vector<Node*> parents;
	public:
		std::string name;
		std::vector<Node*> sons;
		virtual float geteval();//获取节点数值
		virtual void setvalue(float a);//对variable赋值 
		virtual void reset() ;//设为"未计算"状态
		virtual float func() = 0;
		virtual float getderivative(Node*);
		virtual float lookupderivative(Node*) = 0;
};

class Operand:public Node//没有父节点的节点,constant,variable,placeholder
{
	protected:
		float value;
	public:
		float func() override;
		float lookupderivative(Node*);
};

class UnaryOperation:public Node//1个父节点的节点,print和单变量函数
{
	public:
		UnaryOperation(std::string,Node* p1);
		virtual float derivative() ;
		float lookupderivative(Node*);
};

class BinaryOperation:public Node//2个父节点的节点,四则运算与比较
{
	public:
		BinaryOperation(std::string,Node* p1,Node* p2);
		virtual float derivative1() ;
		virtual float derivative2() ;
		float lookupderivative(Node*);
};

class TernaryOperation:public Node//3个父节点的节点,只有cond
{
	public:
		TernaryOperation(std::string,Node* p1,Node* p2,Node* p3);
		float lookupderivative(Node*);
};