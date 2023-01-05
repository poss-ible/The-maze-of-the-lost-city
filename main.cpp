#include <bits/stdc++.h>
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

int a[21][31],ex,ey;
void chushihua()
{
	srand((unsigned)time(NULL));
}
void makemaze(int qx,int qy,int xx,int xy)
{
	if((a[xx+1][xy]+a[xx-1][xy]+a[xx][xy+1]+a[xx][xy-1])==0||(ex==xx&&ey==xy))
	{
		a[xx][xy]=1;
		a[qx][xy]=1;
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
						makemaze(xx+1,xy,xx+2,xy);
						break;
					case 1:
						makemaze(xx-1,xy,xx-2,xy);
						break;
					case 2:
						makemaze(xx,xy+1,xx,xy+2);
						break;
					case 3:
						makemaze(xx,xy-1,xx,xy-2);
						break;
				}
			}
		}
	}
}
int main()
{
	chushihua();
	int x=1,y=1;
	ex=x;
	ey=y;
	for(int i=0;i<21;++i)
	{
		a[i][0]=1;
		a[i][20]=1;
	}
	for(int j=0;j<31;++j)
	{
		a[0][j]=1;
		a[30][j]=1;
	}
	makemaze(x,y,x,y);
	for(int i=1;i<=19;++i)
	{
		for(int j=1;j<=29;++j)
		{
			cout<<a[i][j];
		}
		cout<<endl;
	}
	return 0;
}