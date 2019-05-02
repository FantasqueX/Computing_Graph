#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "node.h"
#include "zeropn.h"
#include "onepn.h"
#include "twopn.h"
#include "threepn.h"

class Graph
{
	std::map<std::string,Node*> nodes;
	std::map<int,float> outvalue;
	int size,cnt;
	public:
		Graph();
		Node* operator[] (const string str);//获取节点
		void push(std::string str,Node* newnode);
		void reset();
		float eval(string nodename, const map<string,float> &phMap);
		void setvariable(string vname,float value);
		float lookupanswer(int t);
};