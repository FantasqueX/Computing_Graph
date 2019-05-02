#pragma once
#include <iostream>
#include <string>
#include <cmath>
class Node
{
	protected:
		// friend class Graph;
		float tempeval;
		bool calculated = 0;
	public:
		virtual float geteval() = 0;
		virtual void setvalue(float a);
		// float tempeval;
		// bool calculated = 0;
		virtual void reset();
};

class ZeroParentNode:public Node
{
	public:
		float geteval();
		int getParentsNum();
};

class OneParentNode:public Node
{
	public:
		Node *p1;//parents
		OneParentNode(Node* parent);
		virtual float func(float x) = 0;	
		float geteval();
		int getParentsNum();
};

class TwoParentsNode:public Node
{
	public:
		Node *p1,*p2;//parents
		virtual float func(float x,float y) = 0;	
		float geteval();
		int getParentsNum();
		TwoParentsNode(Node* parent1,Node* parent2);
};

class ThreeParentsNode:public Node
{
	public:
		Node *p1,*p2,*p3;//parents
		virtual float func(float x,float y,float z) = 0;		
		float geteval();
		int getParentsNum();
		ThreeParentsNode(Node* parent1,Node* parent2,Node* parent3);
};

template<float f(float x,)>
class Opn:public OneParentNode
{
	using OneParentNode::OneParentNode;
	float func(float x){return f(x);}
};

template<float f(float x)>
class Opn:public OneParentNode
{
	using OneParentNode::OneParentNode;
	float func(float x){return f(x);}
};

template<float f(float x,float y)>
class Tpn:public TwoParentNode
{
	using TwoParentNode::TwoParentNode;
	float func(float x,float y){return f(x,y);}
};
