#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "node.h"
#include "zeropn.h"
#include "onepn.h"
#include "twopn.h"
#include "threepn.h"

class Graph
{
	Node** nodes;
	int maxsize;
	int used = 0;
	int getid(std::string str);
	public:
		Graph(int sz);
		~Graph();
		Node* getNamePointer(string str);
		Node* operator[](const string str);
		int push(Node* newnode);
		void reset();
		float eval(string nodename,int placeholdernum,std::vector<string> placeholdernames,std::vector<float> placeholdervalue);
		void setvariable(string vname,float value);
};
