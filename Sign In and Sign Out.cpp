#include<iostream>
#include<string>
using namespace std;
struct inform
{
	string id;
	int inhh,inmm,inss;
	int outhh,outmm,outss;
};

int main()
{
	int i,m,first,last;
	inform *p;
	cin>>m;
	p=new inform[m];
	for(i=0;i<m;i++)
	{
		cin>>p[i].id;
		scanf("%d:%d:%d %d:%d:%d",&p[i].inhh,&p[i].inmm,
			&p[i].inss,&p[i].outhh,&p[i].outmm,&p[i].outss);
	}
	for(first=0,last=0,i=1;i<m;i++)
	{
		if(p[i].inhh<p[first].inhh)
			first=i;
		else if(p[i].inhh==p[first].inhh)
		{
			if(p[i].inmm<p[first].inmm)
				first=i;
			else if(p[i].inmm==p[first].inmm)
			{
				if(p[i].inss<p[first].inss)
					first=i;
			}
		}
		if(p[i].outhh>p[last].outhh)
			last=i;
		else if(p[i].outhh==p[last].outhh)
		{
			if(p[i].outmm>p[last].outmm)
				last=i;
			else if(p[i].outmm==p[last].outmm)
			{
				if(p[i].outss>p[last].outss)
					last=i;
			}			
		}
	}
	cout<<p[first].id<<" "<<p[last].id<<endl;
	delete []p;
	return 0;
}