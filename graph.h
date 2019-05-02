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
	std::map<std::string,Node*> nodes;//节点指针列表,由于有重名覆盖现象,所以不一定包括所有节点 
	std::map<int,float> outvalue;//计算结果历史纪录 
	int cnt=0;//eval的次数 
	public:		
		Node* operator[] (const string str);//已知节点名,获取节点指针 
		void push(std::string str,Node* newnode);//加入新节点 
		void reset(string nodename);//把某次eval的结果清除以便进行下一次计算 
		float eval(string nodename, const map<string,float> &phMap/*placeholder列表*/);//计算某节点数值,如果没有placeholder则phMap为空 
		void setvariable(string vname,float value);//设置某个variable的值 
		float lookupanswer(int t);//获取第t次eval的结果 
};
