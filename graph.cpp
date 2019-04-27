#include "graph.h"
#include<iostream>
#include <string>

Node* Graph::operator[](const string str)
{
    return nodes[str];
}

void Graph::pushNode(string newNodeName,Node* newnode)
{
    nodes.insert ( make_pair(newNodeName,newnode) );
}

void Graph::reset()
{
    for(auto iter = nodes.begin(); iter != nodes.end(); iter++)
    {
        iter->second->reset();//����variable��constant 
    }
}

float Graph::eval(string nodename,int placeholdernum,string* placeholdernames,float* placeholdervalue)
{
    reset();
    for(int i=0;i<placeholdernum;i++)
        nodes[placeholdernames[i]]->setvalue(placeholdervalue[i]);
    OutputList.push_back(nodes[nodename]->geteval());    
    return *(OutputList.end()-1);
}
void Graph::setVariable(string vname,float value)
{
    nodes[vname]->setvalue(value);
}