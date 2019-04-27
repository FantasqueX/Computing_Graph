#include "graph.h"
#include<iostream>
#include <string>


Graph::Graph(int sz)//确定节点数的构造函数
{
    size=sz;
}

Graph::~Graph()
{
    delete[] nodes;
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