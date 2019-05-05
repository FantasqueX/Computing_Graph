#pragma once
#include "node.h"
#include <string>

using std::string;

class NodeFactory
{
    public:
        static Node* createNode(string placeholderName, string type);
        static Node* createNode(string Name, string type, float value);
        static Node* createNode(string Name, string type, Node* parent1);
        static Node* createNode(string Name, string type, Node* parent1, Node* parent2);
        static Node* createNode(string Name, string type, Node* parent1, Node* parent2, Node* parent3);
		
};