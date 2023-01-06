#include <bits/stdc++.h>
#include <windows.h>
#include <dir.h>
#include <conio.h>
/*
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
*/
using namespace std;

map<int,map<int,bool>> a;
int ex,ey,maxn=0;
void chushihua()
{
	HANDLE HOUT = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD NewSize = GetLargestConsoleWindowSize(HOUT);
    NewSize.X -= 1;
    NewSize.Y -= 1;
    SetConsoleScreenBufferSize(HOUT, NewSize);
    SMALL_RECT DisplayArea={0,0,0,0};
    DisplayArea.Right = NewSize.X;
    DisplayArea.Bottom = NewSize.Y;
    SetConsoleWindowInfo(HOUT, TRUE, &DisplayArea);
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SW_MAXIMIZE);
	system ("chcp 65001");
	system ("cls");
	srand((unsigned)time(NULL));
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode;
	GetConsoleMode(hStdin, &mode);
	mode &= ~ENABLE_QUICK_EDIT_MODE;
	SetConsoleMode(hStdin, mode);
}
void makemaze()
{
	#define q1 q.front().first
	#define q2 q.front().second
	#define p1 p.first
	#define p2 p.second
	queue<pair<int,int>> q;
	pair<int,int> p;
	p1=0;
	p2=0;
	a[0][0]=1;
	q.push(p);
	while(!q.empty())
	{
		if(!(q1<0||q1>=29||q2<0||q2>=19))
		{
			if(a[q1][q2]+a[q1+1][q2]+a[q1-1][q2]+a[q1][q2+1]+a[q1][q2-1]==1)
			{
				a[q1][q2]=1;
				ex=q1;
				ey=q2;
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
							{
								++q1;
								q.push(q.front());
								--q1;
								break;
							}
							case 1:
							{
								--q1;
								q.push(q.front());
								++q1;
								break;
							}
							case 2:
							{
								++q2;
								q.push(q.front());
								--q2;
								break;
							}
							case 3:
							{
								--q2;
								q.push(q.front());
								++q2;
								break;
							}
						}
					}
				}
			}
		}
		q.pop();
	}
}
void gotoxy(int x,int y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle,pos);
}
void xyc(int x,int y)
{
	gotoxy(x+1,y+1);
	cout<<"•";
}
void print_maze(int x,int y)
{
	for(int i=-2;i<=20;++i)
	{
		a[-2][i]=1;
		a[30][i]=1;
	}
	for(int i=-2;i<=30;++i)
	{
		a[i][-2]=1;
		a[i][20]=1;
	}
	for(int i=-1;i<=19;++i)
	{
		for(int j=-1;j<=29;++j)
		{
			if(i==y&&j==x)
			{
				cout<<"S";
			}
			else
			{
				if(i==ey&&j==ex)
				{
					cout<<"E";
				}
				else
				{
					if(a[j][i])
					{
						cout<<" ";
					}
					else
					{
						if(a[j-1][i]+a[j+1][i]+a[j][i+1]+a[j][i-1]==0)
						{
							cout<<"┼";
						}
						else
						{
							if(a[j][i+1]+a[j][i-1]+a[j+1][i]==0)
							{
								cout<<"├";
							}
							else
							{
								if(a[j][i+1]+a[j][i-1]+a[j-1][i]==0)
								{
									cout<<"┤";
								}
								else
								{
									if(a[j+1][i]+a[j-1][i]+a[j][i+1]==0)
									{
										cout<<"┬";
									}
									else
									{
										if(a[j+1][i]+a[j-1][i]+a[j][i-1]==0)
										{
											cout<<"┴";
										}
										else
										{
											if(a[j+1][i]+a[j-1][i]==0)
											{
												cout<<"─";
											}
											else
											{
												if(a[j][i+1]+a[j][i-1]==0)
												{
													cout<<"│";
												}
												else
												{
													if(a[j][i+1]+a[j+1][i]==0)
													{
														cout<<"┌";
													}
													else
													{
														if(a[j][i-1]+a[j+1][i]==0)
														{
															cout<<"└";
														}
														else
														{
															if(a[j][i+1]+a[j-1][i]==0)
															{
																cout<<"┐";
															}
															else
															{
																if(a[j][i-1]+a[j-1][i]==0)
																{
																	cout<<"┘";
																}
																else
																{
																	if(a[j][i+1]==0||a[j][i-1]==0)
																	{
																		cout<<"│";
																	}
																	else
																	{
																		cout<<"─";
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<'\n';
	}
}
void move(int x,int y)
{
	xyc(0,0);
	while(x!=ex||y!=ey)
	{
		#define cany(y) (y>=0&&y<19&&a[x][y]!=0)
		#define canx(x) (x>=0&&x<29&&a[x][y]!=0)
		char c=getch();
		switch(c)
		{
			case 'a':
			{
				--x;
				if(canx(x))
				{
					xyc(x,y);
				}
				else
				{
					++x;
				}
				break;
			}
			case 'd':
			{
				++x;
				if(canx(x))
				{
					xyc(x,y);
				}
				else
				{
					--x;
				}
				break;
			}
			case 'w':
			{
				--y;
				if(cany(y))
				{
					xyc(x,y);
				}
				else
				{
					++y;
				}
				break;
			}
			case 's':
			{
				++y;
				if(cany(y))
				{
					xyc(x,y);
				}
				else
				{
					--y;
				}
				break;
			}
		}
	}
	gotoxy(0,21);
}
int main()
{
	chushihua();
	makemaze();
	print_maze(0,0);
	move(0,0);
	cout<<"you win";
	return 0;
}