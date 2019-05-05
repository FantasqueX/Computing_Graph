#include <cassert>
#include <iomanip>
#include <sstream>
#include <map>
#include "graph/Graph/graph.h"

using namespace std;

map <string,float> placeholderMap;//placeholder的名字与数值一一对应，作为eval的参数
int main()
{
	Graph gra;//计算图
	int n,m,q;//样例中输入的三种操作的个数
	string name,type,tmp;//用到的临时字符串 
	float value;//用到的临时float
	cin>>n;//C V P三种节点数
	for(int i=0; i<n; i++)
	{
		cin>>name;
		cin>>type;
		if(type=="P")
		{
			gra.newnode(name,type);
		}
		else if ((type=="V")||(type=="C"))
		{
			cin>>value;
			gra.newnode(name,type,value);
		}
		else assert(0);
	}

	cin>>m;//运算节点数
	for(int i=0; i<m; i++)
	{
		string expression;
		getline(cin,expression);
		if(expression.empty())//跳过空行
		{
			i--;
			continue;
		}
		stringstream ss(expression);
		string p1,p2,p3,p4;//处理输入
		ss>>name>>tmp>>p1>>p2>>p3>>p4;
		assert(tmp=="=");//断言
		if(p1=="COND")
		{
			gra.newnode(name,p1,p2,p3,p4);
		}
		else if(p3.empty())
		{
			gra.newnode(name,p1,p2);
		}
		else
		{
			gra.newnode(name,p2,p1,p3);
			
		}
	}

	cin>>q;
	for(int i=0; i<q; i++)
	{
		string command;
		getline(cin,command);
		if(command.empty())//跳过空行
		{
			i--;
			continue;
		}
		stringstream ss(command);
		ss>>type;
		if(type=="EVAL")
		{
			placeholderMap.clear();
			ss>>name;
			string phcountstr;
			ss>>phcountstr;
			int phcount=0;
			if(!phcountstr.empty())
			{
				phcount=stoi(phcountstr);
			}

			for(int j=0; j<phcount; j++)
			{
				string x;
				float y;
				ss>>x>>y;
				placeholderMap.insert(make_pair(x,y));
			}

			float ov = gra.eval(name,placeholderMap);
			if(!isnan(ov))
				cout << fixed << setprecision(4) <<ov<<endl;
		}
		else if(type=="DERIVATIVE") //求导测试代码
		{
			placeholderMap.clear();
			string name1,name2;
			ss>>name1>>name2;
			string phcountstr;
			ss>>phcountstr;
			int phcount=0;
			if(!phcountstr.empty())
			{
				phcount=stoi(phcountstr);
			}

			for(int j=0; j<phcount; j++)
			{
				string x;
				float y;
				ss>>x>>y;
				placeholderMap.insert(make_pair(x,y));
			}

			float ov = gra.getderivative(name1,name2,placeholderMap);
			if(!isnan(ov))
				cout << fixed << setprecision(4) <<ov<<endl;
		}
		else if(type=="SETCONSTANT")
		{
			ss>>name;
			ss>>value;
			gra.setVariable(name,value);
		}
		else if(type=="SETANSWER")
		{
			ss>>name;
			int t;
			ss>>t;
			gra.setAnswer(name,t);
		}
		else assert(0);
	}
}
