#include <bits/stdc++.h>
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
#define Tab_Top_Left 1
#define Tab_Top_Right 2
#define Tab_Bottom_Left 3
#define Tab_Bottom_Right 4
#define Tab_Horizontal 5
#define Tab_Vertical 6
#define Blank 7
#define Black 8
#define Start 9
#define End 10
using namespace std;

map<int,map<int,bool>> a;
int ex,ey,maxn=0;
void chushihua()
{
	system ("chcp 65001");
	system ("cls");
	srand((unsigned)time(NULL));
}
void makemaze(int qx,int qy,int xx,int xy,int maxm)
{
	if(!(xx<0||xx>=29||xy<0||xy>=19))
	{
		if((a[xx+1][xy]+a[xx-1][xy]+a[xx][xy+1]+a[xx][xy-1])==0)
		{
			++maxm;
			if(maxm>maxn)
			{
				ex=xx;
				ey=xy;
				maxn=maxm;
			}
			a[xx][xy]=1;
			a[qx][qy]=1;
			map<int,int> b;
			while(b.size()!=4)
			{
				int s=rand()%4;
				if(!b[s])
				{
					b[s]=1;
					switch(s)
					{
						case 0:
							makemaze(xx+1,xy,xx+2,xy,maxm);
							break;
						case 1:
							makemaze(xx-1,xy,xx-2,xy,maxm);
							break;
						case 2:
							makemaze(xx,xy+1,xx,xy+2,maxm);
							break;
						case 3:
							makemaze(xx,xy-1,xx,xy-2,maxm);
							break;
					}
				}
			}
		}
	}
}
int main()
{
	chushihua();
	int x=0,y=0;
	makemaze(x,y,x,y,0);
	for(int i=0;i<19;++i)
	{
		for(int j=0;j<29;++j)
		{
			if(i==y&&j==x)
			{
				cout<<"始";
			}
			else
			{
				if(i==ey&&j==ex)
				{
					cout<<"终";
				}
				else
				{
					if(a[j][i])
					{
						cout<<"  ";
					}
					else
					{
						if(a[j-1][i]+a[j+1][i])
						{
							cout<<"| ";
						}
						else
						{
							cout<<"——";
						}
					}
				}
			}
		}
		cout<<'\n';
	}
	return 0;
}