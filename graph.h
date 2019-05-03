#pragma once
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
	std::map<int,float> outvalue;//eval结果历史纪录，key储存eval是第几次操作，value储存eval结果
	int cnt;//总操作次数
	public:
		Graph();
		Node* operator[] (const std::string& str);//获取节点
		void pushNode(std::string str,Node* newnode);//加入新节点
		void reset(std::string nodename);//清除上一次计算的结果(内部递归清除所有计算过程)
		float eval(std::string nodename, const std::map<std::string,float> &phMap);//传入placeholder列表进行计算
		void setvariable(std::string vname,float value);//设置variable的值
		float lookupanswer(int t);//获取第t次操作的结果
};
