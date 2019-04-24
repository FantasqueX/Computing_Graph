#include "graph.h"
#include<iostream>
#include <string>
int Graph::getid(std::string str)
{
    for (int i = 0;i < used; ++i)
    {
        if(str == nodes[i]->name)
            return i;
    }
    return -1;
}
Graph::Graph(int sz)
{
    maxsize=sz;
    nodes=new Node*[sz];
}
Graph::~Graph()
{
    delete[] nodes;
}
Node* Graph::getNamePointer(string str)
{
    for(int i=0; i<used; i++)
    {
        if(str==nodes[i]->name)
            return nodes[i];
    }
    return nullptr;
}
Node* Graph::operator[](const string str)
{
    return getNamePointer(str);
}
int Graph::push(Node* newnode)
{
    if(getid(newnode->name)!=-1)
    {
        std::cout<<"Same name!"<<std::endl;
    }
    if(used==maxsize)
    {
        std::cout<<"Max size!"<<std::endl;
        return 1;
    }
    nodes[used]=newnode;
    used++;
    return 0;
}
void Graph::reset()
{
    for(int i=0; i<used; i++)
    {
        nodes[i]->reset();//����variable��constant 
    }
}
float Graph::eval(string nodename,int placeholdernum,string* placeholdernames,float* placeholdervalue)
{
    reset();
    for(int i=0;i<placeholdernum;i++)
        getNamePointer(placeholdernames[i])->setvalue(placeholdervalue[i]);
        
    return getNamePointer(nodename)->geteval();
}
void Graph::setvariable(string vname,float value)
{
    getNamePointer(vname)->setvalue(value);
}