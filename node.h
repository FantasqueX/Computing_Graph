#pragma once
#include <iostream>
#include <string>
#include <cmath>
const float NaN=0.0/0.0;
class Node //抽象类Node
{
	protected:
	string TypName;//记录类型
	public:
		std::string name;
		virtual float geteval() = 0;
		virtual void setvalue(float a);
		virtual int getParentsNum() = 0; 
		float tempeval;
		bool calculated=0;//记录是否在一次计算中是否已经计算过
		bool printable=0;//?
		virtual void reset() = 0;
};

class ZeroParentNode:public Node //
{
	public:
		float geteval();
		int getParentsNum();
};

class OneParentNode:public Node
{
	public:
		Node *p1;//parents
		OneParentNode(std::string a,Node* parent1);
		virtual float func(float x);	
		float geteval();
		int getParentsNum();
};

class TwoParentsNode:public Node
{
	public:
		Node *p1,*p2;//parents
		virtual float func(float x,float y);	
		float geteval();
		int getParentsNum();
		TwoParentsNode(std::string a,Node* parent1,Node* parent2);
};

class ThreeParentsNode:public Node
{
	public:
		Node *p1,*p2,*p3;//parents
		virtual float func(float x,float y,float z);		
		float geteval();
		int getParentsNum();
		ThreeParentsNode(std::string a,Node* parent1,Node* parent2,Node* parent3);
};