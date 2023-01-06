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
map<int,map<int,bool>> been;
int ex,ey,maxn=0;
pair<int,int> last;
const int X=59,Y=19;
void SetFont(int size = 20) {
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof cfi;
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;
	cfi.dwFontSize.Y = size;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, L"等线 light");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}
void chushihua()
{
	been[0][0]=1;
	SetFont();
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
void makemaze(int qx,int qy,int xx,int xy,int maxm)
{
	if(!(xx<0||xx>=X||xy<0||xy>=Y))
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
	if(been[x][y])
	{
		gotoxy(last.first+1,last.second+1);
		cout<<" ";
		been[x][y]=0;
	}
	gotoxy(x+1,y+1);
	cout<<"*";
}
void print_maze(int x,int y)
{
	for(int i=-2;i<=Y+1;++i)
	{
		a[-2][i]=1;
		a[X+1][i]=1;
	}
	for(int i=-2;i<=X+1;++i)
	{
		a[i][-2]=1;
		a[i][Y+1]=1;
	}
	for(int i=-1;i<=Y;++i)
	{
		for(int j=-1;j<=X;++j)
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
	gotoxy(1,1);
	cout<<'*';
	while(x!=ex||y!=ey)
	{
		#define canx(x) (x>=0&&x<X&&a[x][y]!=0)
		#define cany(y) (y>=0&&y<Y&&a[x][y]!=0)
		char c=getch();
		if(c<='Z')
		{
			c-='A';
			c+='a';
		}
		bool b=1;
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
					b=0;
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
					b=0;
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
					b=0;
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
					b=0;
				}
				break;
			}
			default:
			{
				b=0;
			}
		}
		if(b)
		{
			been[x][y]=1;
			last.first=x;
			last.second=y;
		}
	}
	gotoxy(0,21);
}
int main()
{
	chushihua();
	makemaze(0,0,0,0,0);
	print_maze(0,0);
	move(0,0);
	cout<<"you win";
	return 0;
}