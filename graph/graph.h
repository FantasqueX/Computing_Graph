#pragma once
#include <string>
#include <map>
#include "node.h"
#include "Operand.h"
#include "UnaryOperation.h"
#include "BinaryOperation.h"
#include "TernaryOperation.h"

extern bool asserted;
using std::string;
class Graph
{
	std::map<string,Node*> nodes;
	std::map<int,float> outvalue;//eval结果历史纪录，key储存eval是第几次操作，value储存eval结果
	int cnt;//总操作次数
	public:
		Graph();
		Node* operator[] (const string& str);//获取节点
		void pushNode(string str,Node* newnode);//加入新节点
		void reset(string nodename);//清除上一次计算的结果(内部递归清除所有计算过程)
		float eval(string nodename, const std::map<std::string,float> &phMap);//传入placeholder列表进行计算
		void setVariable(string vname,float value);//设置variable的值
		float lookupanswer(int t);//获取第t次操作的结果
		float getderivative(string name1,string name2,std::map<string ,float> phMap);
		void setAnswer(string vname,int t);
};
