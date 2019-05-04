#include <cassert>
#include <iomanip>
#include <sstream>

#include <map>
#include "graph/node.h"
#include "graph/graph.h"

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
		if(type=="C")
		{
			cin>>value;
			gra.pushNode(name,new Constant(name,value));
		}
		else if(type=="V")
		{
			cin>>value;
			gra.pushNode(name,new Variable(name,value));
		}
		else if(type=="P")
		{
			gra.pushNode(name,new Placeholder(name));
		}
		else assert(0);
	}

	cin>>m;//运算节点数
	for(int i=0; i<m; i++)
	{
		cin>>name;
		cin>>tmp;
		assert(tmp=="=");//断言
		string p1,p2,p3,p4;//处理输入 
		cin>>p1;
		if(p1=="COND")
		{
			cin>>p2;
			cin>>p3;
			cin>>p4;
			gra.pushNode(name,new Cond(name,gra[p2],gra[p3],gra[p4]));
		}
		else if(p1=="PRINT")
		{
			cin>>p2;
			gra.pushNode(name,new Print(name,p2,gra[p2]));
		}
		else if(p1=="SIN")
		{
			cin>>p2;
			gra.pushNode(name,new Sin(name,gra[p2]));
		}
		else if(p1=="EXP")
		{
			cin>>p2;
			gra.pushNode(name,new Exp(name,gra[p2]));
		}
		else if(p1=="LOG")
		{
			cin>>p2;
			gra.pushNode(name,new Log(name,gra[p2]));
		}
		else if(p1=="TANH")
		{
			cin>>p2;
			gra.pushNode(name,new Tanh(name,gra[p2]));
		}
		else if(p1=="SIGMOID")
		{
			cin>>p2;
			gra.pushNode(name,new Sigmoid(name,gra[p2]));
		}
		else
		{
			cin>>type;
			cin>>p2;
			if(type=="+")
			{
				gra.pushNode(name,new Sum(name,gra[p1],gra[p2]));
			}
			else if(type=="-")
			{
				gra.pushNode(name,new Subtraction(name,gra[p1],gra[p2]));
			}
			else if(type=="*")
			{
				gra.pushNode(name,new Multiply(name,gra[p1],gra[p2]));
			}
			else if(type=="/")
			{
				gra.pushNode(name,new Division(name,gra[p1],gra[p2]));
			}
			else if(type==">")
			{
				gra.pushNode(name,new GTR(name,gra[p1],gra[p2]));
			}
			else if(type=="<")
			{
				gra.pushNode(name,new LSS(name,gra[p1],gra[p2]));
			}
			else if(type==">=")
			{
				gra.pushNode(name,new GEQ(name,gra[p1],gra[p2]));
			}
			else if(type=="<=")
			{
				gra.pushNode(name,new LEQ(name,gra[p1],gra[p2]));
			}
			else if(type=="==")
			{
				gra.pushNode(name,new EQU(name,gra[p1],gra[p2]));
			}
			else assert(0);
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
		else if(type=="DERIVATIVE")
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
