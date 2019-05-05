#include "graph.h"
#include "NodeFactory.h"

using std::string;

bool asserted=0; //某一次eval是否已经给出error，避免重复输出

Graph::Graph()//构造（初始化）
{
    cnt = 0;
    srand(time(0));
}

Graph::~Graph()//析构并delete所有节点
{
    for (auto iter = nodes.begin(); iter != nodes.end(); iter++)
    {
        delete iter->second;
    }
}

Node* Graph::operator[](const string& str)//下标运算，返回一个Node指针
{
    auto it = nodes.find(str);
    if (it==nodes.end())
        return nullptr;
    return it->second;
}

void Graph::pushNode(const string& str,Node* newnode) //将Node加入map中
{
    if(nodes[str]!=nullptr)//重命名原node,采用随机数避免重名
    {
        string tmp = str;
        while(nodes[tmp] != nullptr)
            tmp += char('a' + rand()%26);
        nodes[tmp] = nodes[str];
    }
    nodes[str] = newnode;//用新node代替原node
}

void Graph::reset(const string& nodename) //清除之前计算的结果(内部递归清除所有计算过程)
{
    asserted = 0;
    nodes[nodename]->reset();
}

float Graph::eval(const string& nodename, const std::map<string,float> &phMap)//传入placeholder列表进行计算
{
    ++cnt;
    reset(nodename);//刷新
    for(auto iter=phMap.begin(); iter != phMap.end(); iter++)
        nodes[iter->first]->setValue(iter->second);
    outvalue[cnt] = nodes[nodename]->getValue();
    return outvalue[cnt];
}

float Graph::getderivative(const string& name1,const string& name2, std::map<string ,float>phMap)
{
    eval(name1,phMap);
    return nodes[name2]->getderivative(nodes[name1]);
}

void Graph::setVariable(const string& vname,float value)
{
    ++cnt;
    nodes[vname]->setValue(value);
}

float Graph::lookupanswer(int t)
{
    return outvalue[t];
}

void Graph::setAnswer(const string& vname,int t)
{
    setVariable(vname,lookupanswer(t));
}



//以下用来添加节点的函数都直接调用了工厂类的方法，new的过程被隐藏在工厂类中

void Graph::newnode(const string& placeholderName, const string& type)
{
    pushNode(placeholderName, NodeFactory::createNode(placeholderName,type));
}

void Graph::newnode(const string& Name, const string& type, float value)
{
    pushNode(Name, NodeFactory::createNode(Name, type, value));
}

void Graph::newnode(const string& Name, const string& type, const string& parentName)
{
    pushNode(Name, NodeFactory::createNode(Name, type, nodes[parentName]));
}

void Graph::newnode(const string& Name, const string& type, const string& parent1Name, const string& parent2Name)
{
    pushNode(Name, NodeFactory::createNode(Name, type, nodes[parent1Name],nodes[parent2Name]));
}

void Graph::newnode(const string& Name, const string& type, const string& parent1Name, const string& parent2Name, const string& parent3Name)
{
    pushNode(Name, NodeFactory::createNode(Name, type, nodes[parent1Name],nodes[parent2Name],nodes[parent3Name]));
}