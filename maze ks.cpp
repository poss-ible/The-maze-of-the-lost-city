#include <bits/stdc++.h>
#define q1 q.front().first
#define q2 q.front().second
#define p1 p.first
#define p2 p.second
using namespace std;

map<int,map<int,int>> a;

int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<=n+1;++i)
	{
		a[i][0]=1;
		a[i][m+1]=1;
	}
	for(int i=1;i<=m;++i)
	{
		a[0][i]=1;
		a[n+1][i]=1;
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			cin>>a[i][j];
		}
	}
	int x,y,c,d;
	cin>>x>>y>>c>>d;
	queue<pair<int,int>> q;
	pair<int,int> p;
	p1=x;
	p2=y;
	q.push(p);
	int turns=0;
	while(!q.empty())
	{
		++turns;
		queue<pair<int,int>> t;
		while(!q.empty())
		{
			if(a[q1][q2]==0)
			{
				if((q1==c)&&(q2==d))
				{
					cout<<"short:"<<turns;
					return 0;
				}
				p1=q1+1;
				p2=q2;
				t.push(p);
				p1-=2;
				t.push(p);
				++p1;
				++p2;
				t.push(p);
				p2-=2;
				t.push(p);
				a[q1][q2]=1;
			}
			q.pop();
		}
		q=t;
	}
	cout<<"no answer";
	return 0;
}