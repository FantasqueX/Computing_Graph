#pragma once
#include <iostream>
#include <string>
#include <cmath>
const float NaN=0.0/0.0;
class Node
{
	public:
		std::string name;
		virtual float geteval();
		virtual void setvalue(float a);
		float tempeval;
		bool calculated=0;
		bool printable=0;
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
		OneParentsNode(std::string a,Node* parent1);
		virtual float func(float x);
		float geteval();
		int getParentsNum();
};
template<float func(float f)>
class Opn:public Node
{
	public:
		Node *p1;//parents
		Opn(std::string a,Node* parent1)
		{
			name=a;
			p1=parent1;
		}
		float geteval()
		{
			if(calculated)return tempeval;
			else
			{
				calculated=1;
				tempeval=func(p1->geteval());
				return tempeval;
			}
		}
		int getParentsNum()
		{
			return 1;
		}
};
template<float func(float f1,float f2)>
class Tpn:public Node
{
	public:
		Node *p1,*p2;//parents
		Tpn(std::string a,Node* parent1,Node* parent2)
		{
			name=a;
			p1=parent1;
			p2=parent2;
		}
		float geteval()
		{
			if(calculated)return tempeval;
			else
			{
				calculated=1;
				tempeval=func(p1->geteval(),p2->geteval());
				return tempeval;
			}
		}
		int getParentsNum()
		{
			return 2;
		}
		TwoParentsNode(std::string a,Node* parent1,Node* parent2);
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
