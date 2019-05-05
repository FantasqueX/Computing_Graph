#include "graph.h"

bool asserted=0; //某一次eval是否已经给出error，避免重复输出

Graph::Graph()
{
    cnt = 0;
}

Node* Graph::operator[](const std::string& str)
{
    auto it = nodes.find(str);
    if (it==nodes.end())
        return nullptr;
    return it->second;
}

void Graph::pushNode(std::string str,Node* newnode)
{
    if(nodes[str]!=nullptr)
    {
        nodes[str+"_old"] = nodes[str];//重命名原node
    }
    nodes[str] = newnode;//用新node代替原node
}

void Graph::reset(std::string nodename)
{
    asserted = 0;
    nodes[nodename]->reset();
}

float Graph::eval(std::string nodename, const std::map<std::string,float> &phMap)
{
    ++cnt;
    reset(nodename);
    for(auto iter=phMap.begin(); iter != phMap.end(); iter++)
        nodes[iter->first]->setValue(iter->second);
    outvalue[cnt] = nodes[nodename]->getValue();
    return outvalue[cnt];
}

float Graph::getderivative(std::string name1,std::string name2, std::map<std::string ,float>phMap)
{
    eval(name1,phMap);
    return nodes[name2]->getderivative(nodes[name1]);
}

void Graph::setVariable(std::string vname,float value)
{
    ++cnt;
    nodes[vname]->setValue(value);
}

float Graph::lookupanswer(int t)
{
    return outvalue[t];
}

void Graph::setAnswer(string vname,int t)
{
    setVariable(vname,lookupanswer(t));
}
