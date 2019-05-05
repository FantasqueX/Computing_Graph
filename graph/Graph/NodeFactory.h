#pragma once
#include "../Node/node.h"
#include "../Node/Operand.h"
#include "../Node/UnaryOperation.h"
#include "../Node/BinaryOperation.h"
#include "../Node/TernaryOperation.h"
#include <string>

using std::string;

class NodeFactory //用于创建Node的简单工厂，使graph不用负责创建
{
    public:
    //对应于参数数量不同的运算节点的创建函数
        static Node* createNode(const string& placeholderName, const string& type);
        static Node* createNode(const string& Name, const string& type, float value);
        static Node* createNode(const string& Name, const string& type, Node* parent1);
        static Node* createNode(const string& Name, const string& type, Node* parent1, Node* parent2);
        static Node* createNode(const string& Name, const string& type, Node* parent1, Node* parent2, Node* parent3);
		
};