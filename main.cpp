#include <iostream>
#include <string>
#include <cassert>
#include <iomanip>
#include <sstream>
// #include <vector>
#include <map>
#include "node.h"
#include "graph.h"
#include <iostream>

using namespace std;

map <string,float> placeHolderMap;
int main()
{
	Graph gra;
	int n,m,q;
	string name,type,tmp;
	float value;
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>name;
		cin>>type;
		if(type=="C")
		{
			cin>>value;
			gra.push(name,new Constant(value));
		}
		else if(type=="V")
		{
			cin>>value;
			gra.push(name,new Variable(value));
		}
		else if(type=="P")
		{
			gra.push(name,new Placeholder);
		}
		else assert(0);
	}

	cin>>m;
	for(int i=0; i<m; i++)
	{
		cin>>name;
		cin>>tmp;
		assert(tmp=="=");
		string p1,p2,p3,p4;
		cin>>p1;
		if(p1=="COND")
		{
			cin>>p2;
			cin>>p3;
			cin>>p4;
			gra.push(name,new Cond(gra[p2],gra[p3],gra[p4]));
			continue;
		}
		else if(p1=="PRINT")
		{
			cin>>p2;
			gra.push(name,new Print(p2,gra[p2]));
			continue;
		}
		else if(p1=="SIN")
		{
			cin>>p2;
			gra.push(name,new Opn<sin>(gra[p2]));
			continue;
		}
		else if(p1=="EXP")
		{
			cin>>p2;
			gra.push(name,new Exp(gra[p2]));
			continue;
		}
		else if(p1=="LOG")
		{
			cin>>p2;
			gra.push(name,new Log(gra[p2]));
			continue;
		}
		else if(p1=="TANH")
		{
			cin>>p2;
			gra.push(name,new Tanh(gra[p2]));
			continue;
		}
		else if(p1=="SIGMOID")
		{
			cin>>p2;
			gra.push(name,new Sigmoid(gra[p2]));
			continue;
		}
		else
		{
			cin>>type;
			cin>>p2;
			if(type=="+")
			{
				gra.push(name,new sum(gra[p1],gra[p2]));
			}
			else if(type=="-")
			{
				gra.push(name,new subtraction(gra[p1],gra[p2]));
			}
			else if(type=="*")
			{
				gra.push(name,new multiply(gra[p1],gra[p2]));
			}
			else if(type=="/")
			{
				gra.push(name,new division(gra[p1],gra[p2]));
			}
			else if(type==">")
			{
				gra.push(name,new GTR(gra[p1],gra[p2]));
			}
			else if(type=="<")
			{
				gra.push(name,new LSS(gra[p1],gra[p2]));
			}
			else if(type==">=")
			{
				gra.push(name,new GEQ(gra[p1],gra[p2]));
			}
			else if(type=="<=")
			{
				gra.push(name,new LEQ(gra[p1],gra[p2]));
			}
			else if(type=="==")
			{
				gra.push(name,new EQU(gra[p1],gra[p2]));
			}
			else assert(0);
		}
	}

	cin>>q;
//	int t=0;
	for(int i=0; i<q; i++)
	{
		string command;
		getline(cin,command);
		if(command.empty())
		{
			i--;
			continue;
		}
		stringstream ss(command);
		ss>>type;
		if(type=="EVAL")
		{
			placeHolderMap.clear();
			ss>>name;
			string phcountstr;
			ss>>phcountstr;
			int phcount=0;
			if(!phcountstr.empty())
			{
				phcount=stoi(phcountstr);
			}

			//		cout<<phcountstr<<endl;
			for(int j=0; j<phcount; j++)
			{
				string x;
				float y;
				ss>>x>>y;
				placeHolderMap.insert(make_pair(x,y));
			}

			float ov = gra.eval(name,placeHolderMap);
			if(!isnan(ov))
				cout << fixed << setprecision(4) <<ov<<endl;
		}
		else if(type=="SETCONSTANT")
		{
			ss>>name;
			ss>>value;
			gra.setvariable(name,value);
		}
		else if(type=="SETANSWER")
		{
			ss>>name;
			int t;
			ss>>t;
			gra.setvariable(name,gra.lookupanswer(t));
		}
		else assert(0);
	}
}
