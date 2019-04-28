#include "graph.h"
#include<iostream>
#include <vector>
#include <string>
#include <map>
Node* Graph::operator[](const std::string str)
{
    auto it = nodes.find(str);
    if (it==nodes.end())
        return nullptr;
    return it->second;
}
void Graph::push(std::string str,Node* newnode)
{
    if(nodes[str]!=nullptr)
    {
        std::cout<<"Same name!"<<std::endl;
        return ;
    }
    nodes[str] = newnode;
}
void Graph::reset()
{
    for(auto it=nodes.begin(); it != nodes.end(); it++)
        it->second->reset();
}
float Graph::eval(string nodename,int placeholdernum,std::vector<string> placeholdernames,std::vector<float> placeholdervalue)
{
    reset();
    for(int i=0;i<placeholdernum;i++)
        nodes[placeholdernames[i]]->setvalue(placeholdervalue[i]);
        
    return nodes[nodename]->geteval();
}
void Graph::setvariable(string vname,float value)
{
    nodes[vname]->setvalue(value);
}
