#pragma once
#include <vector>
#include <map>
#include <iostream>
#include <string>
#include "node.h"
#include "zeropn.h"
#include "onepn.h"
#include "twopn.h"
#include "threepn.h"

class Graph
{
	map<string,Node*> nodes;
	vector<float> OutputList;
	int size;
	Node* operator[] (const string str);//获取节点
	void pushNode(string newNodeName,Node* newnode);//创建并加入新节点
	public:
		Graph(){};//默认直接创建
		~Graph(){};//析构
		void push(string newNodeName,string nodeTypName, ...);
		void reset();
		float eval(string nodename,int placeholdernum,string* placeholdernames,float* placeholdervalue);//计算,传入参数有数组？
		void setvariable(string vname,float value);
};