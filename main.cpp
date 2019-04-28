#include <iostream>
#include <string>
#include <assert.h>
#include <cmath>
#include <iomanip>
#include <vector>
#include "node.h"
#include "graph.h"
#include <iostream>
using namespace std;
vector <float> phvalues;
vector <string> phnames;
int main()
{
	Graph gra(100);
	int n,m,q;
	string name,type,tmp;
	float value;
	float outvalue[100];
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>name;
		cin>>type;
		if(type=="C")
		{
			cin>>value;
			gra.push(new Constant(name,value));
		}
		else if(type=="V")
		{
			cin>>value;
			gra.push(new Variable(name,value));
		}
		else if(type=="P")
		{
			gra.push(new Placeholder(name));
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
			gra.push(new Cond(name,gra[p2],gra[p3],gra[p4]));
			continue;
		}
		else if(p1=="PRINT")
		{
			cin>>p2;
			gra.push(new Print(name,gra[p2]));
			continue;
		}
		else if(p1=="SIN")
		{
			cin>>p2;
			gra.push(new Opn<Sin>(name,gra[p2]));
			continue;
		}
		else if(p1=="EXP")
		{
			cin>>p2;
			gra.push(new Opn<Exp>(name,gra[p2]));
			continue;
		}
		else if(p1=="LOG")
		{
			cin>>p2;
			gra.push(new Opn<Log>(name,gra[p2]));
			continue;
		}
		else if(p1=="TANH")
		{
			cin>>p2;
			gra.push(new Opn<Tanh>(name,gra[p2]));
			continue;
		}
		else if(p1=="SIGMOID")
		{
			cin>>p2;
			gra.push(new Opn<Sigmoid>(name,gra[p2]));
			continue;
		}
		else
		{
			cin>>type;
			cin>>p2;
			if(type=="+")
			{
				gra.push(new Tpn<sum>(name,gra[p1],gra[p2]));
			}
			else if(type=="-")
			{
				gra.push(new Tpn<subtraction>(name,gra[p1],gra[p2]));
			}
			else if(type=="*")
			{
				gra.push(new Tpn<multiply>(name,gra[p1],gra[p2]));
			}
			else if(type=="/")
			{
				gra.push(new Tpn<division>(name,gra[p1],gra[p2]));
			}
			else if(type==">")
			{
				gra.push(new Tpn<GTR>(name,gra[p1],gra[p2]));
			}
			else if(type=="<")
			{
				gra.push(new Tpn<LSS>(name,gra[p1],gra[p2]));
			}
			else if(type==">=")
			{
				gra.push(new Tpn<GEQ>(name,gra[p1],gra[p2]));
			}
			else if(type=="<=")
			{
				gra.push(new Tpn<LEQ>(name,gra[p1],gra[p2]));
			}
			else if(type=="==")
			{
				gra.push(new Tpn<EQU>(name,gra[p1],gra[p2]));
			}
			else assert(0);
		}
	}

	cin>>q;
	for(int i=0; i<q; i++)
	{
		cin>>type;
		if(type=="EVAL")
		{

			cin>>name;
			int phcount;
			cin>>phcount;
			phnames.clear();
			phvalues.clear();
			for(int j=0; j<phcount; j++)
			{
				string x;
				float y;
				cin>>x>>y;
				phnames.push_back(x);
				phvalues.push_back(y);
			}
			outvalue[i]=gra.eval(name,phcount,phnames,phvalues);
			if(!isnan(outvalue[i]))cout<<fixed<<setprecision(4)<<outvalue[i]<<endl;
		}
		else if(type=="SETCONSTANT")
		{
			cin>>name;
			cin>>value;
			gra.setvariable(name,value);
		}
		else if(type=="SETANSWER")
		{
			cin>>name;
			int t;
			cin>>t;
			gra.setvariable(name,outvalue[t-1]);
		}
		else assert(0);
		
	}
}
