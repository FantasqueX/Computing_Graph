#pragma once
#include <iostream>
#include <string>
#include <cmath>
class Node
{
	public:
		virtual float geteval();
		virtual void setvalue(float a);
		float tempeval;
		bool calculated=0;
		virtual void reset();
};
class ZeroParentsNode:public Node
{
	public:
		float geteval();
		int getParentsNum();
};

class OneParentsNode:public Node
{
	public:
		Node *p1;//parents
		OneParentsNode(Node* parent);
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
		TwoParentsNode(Node* parent1,Node* parent2);
};
class ThreeParentsNode:public Node
{
	public:
		Node *p1,*p2,*p3;//parents
		virtual float func(float x,float y,float z);		
		float geteval();
		int getParentsNum();
		ThreeParentsNode(Node* parent1,Node* parent2,Node* parent3);
};