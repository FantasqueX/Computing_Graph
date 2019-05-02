#pragma once
#include <iostream>
#include <string>
#include <cmath>
class Node
{
	protected:
		float tempeval;//临时计算数值(避免重复计算)
		bool calculated = 0;//是否已计算 (避免重复计算)
	public:
		virtual float geteval() = 0;//获取节点数值
		virtual void setvalue(float a);//对variable赋值 
		virtual void reset() ;//设为"未计算"状态
};

class ZeroParentNode:public Node//没有父节点的节点,constant,variable,placeholder
{
	public:
		float geteval();
};

class OneParentNode:public Node//1个父节点的节点,print和单变量函数
{
	public:
		Node *p1;//parents
		OneParentNode(Node* parent);
		virtual float func(float x) = 0;//这个节点对应的函数 	
		float geteval();
		void reset();
};

class TwoParentsNode:public Node//2个父节点的节点,四则运算与比较
{
	public:
		Node *p1,*p2;//parents
		virtual float func(float x,float y) = 0;	
		float geteval();
		void reset();
		TwoParentsNode(Node* parent1,Node* parent2);
};

class ThreeParentsNode:public Node//3个父节点的节点,只有cond
{
	public:
		Node *p1,*p2,*p3;//parents
		virtual float func(float x,float y,float z) = 0;		
		float geteval();
		void reset();
		ThreeParentsNode(Node* parent1,Node* parent2,Node* parent3);
};