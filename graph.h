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
extern bool asserted;
class Graph
{
	std::map<std::string,Node*> nodes;
	std::map<std::string,Node*> nodesamename[50];
	std::map<int,float> outvalue;
	int size,cnt;
	// void pushNode(std::string str,Node* newnode);
	public:
		Graph();
		Node* operator[] (const string& str);//获取节点
		void pushNode(std::string str,Node* newnode);
		// void push(const std::string &newNodeName,const string& OpNodetype ); //OneParentNode push
		// void push(const std::string &newNodeName,const string& OpNodetype, const string& parentNodeName );
		// void push(const std::string &newNodeName,const string& OpNodetype, const string& parentNodeName1, const string& parentNodeName2 );
		// void push(const std::string &newNodeName,const string& OpNodetype, const string& parentNodeName1,const string& parentNodeName2,const string& parentNodeName3 ); 
		void reset(string nodename);
		float eval(string nodename, const map<string,float> &phMap);
		void setvariable(string vname,float value);
		float lookupanswer(int t);
};
