#pragma once
#include <string>
#include <map>
#include "NodeFactory.h"
#include "../Node/node.h"
#include "../Node/Operand.h"
#include "../Node/UnaryOperation.h"
#include "../Node/BinaryOperation.h"
#include "../Node/TernaryOperation.h"

extern bool asserted;
using std::string;

class Graph
{
	std::map<string,Node*> nodes;
	std::map<int,float> outvalue;//eval结果历史纪录，key储存eval是第几次操作，value储存eval结果
	int cnt;//总操作次数
	
	void pushNode(const string& str,Node* newnode);//加入新节点
	Node* operator[] (const string& str);//获取节点
	
	public:
		Graph();
		~Graph();//析构时delete所有Node*
		
		//重载了5个创建用于不同参数数量运算节点的函数
		void newnode(const string& placeholderName, const string& type);
		void newnode(const string& Name, const string& type, float value);
		void newnode(const string& Name, const string& type, const string& parentName);
		void newnode(const string& Name, const string& type, const string& parent1Name, const string& parent2Name);
		void newnode(const string& Name, const string& type, const string& parent1Name, const string& parent2Name, const string& parent3Name);
		
		void reset(const string& nodename);//清除之前的计算结果(内部递归清除所有计算过程)，在eval中调用
		float eval(const string& nodename, const std::map<std::string,float> &phMap);//传入placeholder列表进行计算
		void setVariable(const string& vname,float value);//设置variable的值
		float lookupanswer(int t);//获取第t次操作的结果
		float getderivative(const string& name1,const string& name2,std::map<string ,float> phMap);
		void setAnswer(const string& vname,int t);
};
