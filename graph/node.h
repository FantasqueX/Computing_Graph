#pragma once
#include<cmath>
#include<iostream>
#include<vector>
#include<string>

class Node
{
	protected:
		float tempeval;//临时计算数值(避免重复计算)
		float tempderivative;//临时计算导数值
		bool calculated = 0;//是否已计算 (避免重复计算)
		bool calculatedderivative = 0;//是否已计算
		std::string name;
		std::vector<Node*> parents;
		std::vector<Node*> sons;
	public:
		virtual float getValue() = 0;//获取节点数值
		virtual void setValue(float a);//对variable赋值 
		virtual void reset() ;//设为"未计算"状态
		virtual float getderivative(Node*);
		virtual float lookupderivative(Node*) = 0;
		void pushback(Node*);
};

class Operand:public Node//没有父节点的节点,constant,variable,placeholder
{
	protected:
		float value;
	public:
		float lookupderivative(Node*);
};

class Operation:public Node
{
	virtual float func() = 0;
	float lookupderivative(Node*) = 0;
	virtual float getValue();//获取节点数值
};

class UnaryOperation:public Operation//1个父节点的节点,print和单变量函数
{
	public:
		UnaryOperation(std::string,Node* p1);
		virtual float derivative() ;
		float lookupderivative(Node*);
};

class BinaryOperation:public Operation//2个父节点的节点,四则运算与比较
{
	public:
		BinaryOperation(std::string,Node* p1,Node* p2);
		virtual float derivative1() ;
		virtual float derivative2() ;
		float lookupderivative(Node*);
};

class TernaryOperation:public Operation//3个父节点的节点,只有cond
{
	public:
		TernaryOperation(std::string,Node* p1,Node* p2,Node* p3);
		float lookupderivative(Node*);
};