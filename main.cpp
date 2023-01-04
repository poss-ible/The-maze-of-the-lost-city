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

void chushihua()
{
	srand((unsigned)time(NULL));
}
void makemaze(int *a[][29],int qx,int qy,int xx,int xy)
{
	if(!(*a[xx+1][xy]+*a[xx-1][xy]+*a[xx][xy+1]+*a[xx][xy-1]))
	{
		*a[xx][xy]=1;
		*a[qx][xy]=1;
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
						makemaze(a,xx+1,xy,xx+2,xy);
						break;
					case 1:
						makemaze(a,xx-1,xy,xx-2,xy);
						break;
					case 2:
						makemaze(a,xx,xy+1,xx,xy+2);
						break;
					case 3:
						makemaze(a,xx,xy-1,xx,xy-2);
				}
			}
		}
	}
	return;
}
int main()
{
	chushihua();
	int a[19][29]={},x=0,y=0;
	makemaze((int* (*)[29])a,x,y,x,y);
	return 0;
}