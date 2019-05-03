#pragma once
#include<cmath>
#include<iostream>
#include<vector>

class Node
{
	protected:
		float tempeval;//临时计算数值(避免重复计算)
		bool calculated = 0;//是否已计算 (避免重复计算)
		std::vector<Node*>parents;
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
		OneParentNode(Node* p1);
		virtual float func() = 0;//这个节点对应的函数 	
		float geteval();
};

class TwoParentsNode:public Node//2个父节点的节点,四则运算与比较
{
	public:
		virtual float func() = 0;	
		float geteval();
		TwoParentsNode(Node* p1,Node* p2);
};

class ThreeParentsNode:public Node//3个父节点的节点,只有cond
{
	public:
		virtual float func() = 0;		
		float geteval();
		ThreeParentsNode(Node* p1,Node* p2,Node* p3);
};