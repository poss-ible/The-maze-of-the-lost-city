#include <bits/stdc++.h>
#include <windows.h>
#include <dir.h>
#include <conio.h>
#include <sys/stat.h>
#include <shlwapi.h>
#pragma comment(lib,"Shlwapi.lib")
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
pair<int,int> last;
const int X=29,Y=19;
char PASSWORD[5];

int wherex()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.dwCursorPosition.X;
}

int wherey()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.dwCursorPosition.Y;
}

inline bool exists (const string name)
{
	struct stat buffer;
	return (stat (name.c_str(), &buffer) == 0); 
}

void SetFont(int size = 20) {
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof cfi;
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;
	cfi.dwFontSize.Y = size;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, L"");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

void gotoxy(int x,int y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle,pos);
}

void Wrap_E (string m)
{
	int size, line;
	
	if (m.size() < 58)
	{
		size = m.size();
	}
	else
	{
		size = 58;
	}
	
	line = ceil(m.size() / 58.0);
	
	for(int j=0; j<size;j++)
    	cout<<m[j];
	
	if (line == 1)
	{
    	return;
	}
	
	gotoxy (2, wherey()+1);
	
	for (int i=1; i<line; i++)
	{
		for(int j=i*58; j<size+i*58;j++)
        	cout<<m[j];
    	gotoxy (2, wherey()+1);
	}
}

void Main_Screen ()
{
	printf ("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf ("■                                                          ■\n");
	printf ("■                                                          ■\n");
	printf ("■                                                          ■\n");
	printf ("■                                                          ■\n");
	printf ("■                                                          ■\n");
	printf ("■                                                          ■\n");
	printf ("■                                                          ■\n");
	printf ("■                                                          ■\n");
	printf ("■                                                          ■\n");
	printf ("■                                                          ■\n");
	printf ("■                                                          ■\n");
	printf ("■                                                          ■\n");
	printf ("■                                                          ■\n");
	printf ("■                                                          ■\n");
	printf ("■                                                          ■\n");
	printf ("■                                                          ■\n");
	printf ("■                                                          ■\n");
	printf ("■                                                          ■\n");
	printf ("■                                                          ■\n");
	printf ("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
}

void Screen2 ()
{
	printf ("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf ("■Please enter the password(Enter a character and press \"Ent■\n");
	printf ("■er\" to enter another one):                                ■\n");
	printf ("■                                                          ■\n");
	printf ("■                                                          ■\n");
	printf ("■                                                          ■\n");
	printf ("■                                                          ■\n");
	printf ("■                                                          ■\n");
	printf ("■                  ■■■■■■■■■■■                  ■\n");
	printf ("■                  ■  ■  ■  ■  ■  ■                  ■\n");
	printf ("■                  ■■■■■■■■■■■                  ■\n");
	printf ("■                                                          ■\n");
	printf ("■                                                          ■\n");
	printf ("■                                                          ■\n");
	printf ("■                                                          ■\n");
	printf ("■                                                          ■\n");
	printf ("■                                                          ■\n");
	printf ("■                                                          ■\n");
	printf ("■                                                          ■\n");
	printf ("■                                                          ■\n");
	printf ("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
}

void Clear ()
{
	gotoxy (2, wherey()+1);
	system ("pause");
	system ("cls");
	Main_Screen ();
	gotoxy (2, 1);
}

void chushihua()
{
	//SetFont();
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

void makemaze(int x,int y,int maxm)
{
	if(!(x<0||x>=X||y<0||y>=Y))
	{
		if((a[x+1][y]+a[x-1][y]+a[x][y+1]+a[x][y-1])<=1)
		{
			++maxm;
			if(maxm>maxn)
			{
				ex=x;
				ey=y;
				maxn=maxm;
			}
			a[x][y]=1;
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
							makemaze(x+1,y,maxm);
							break;
						case 1:
							makemaze(x-1,y,maxm);
							break;
						case 2:
							makemaze(x,y+1,maxm);
							break;
						case 3:
							makemaze(x,y-1,maxm);
							break;
					}
				}
			}
		}
	}
}


void plot (string lan, int part)
{
	if (lan == "EN") //English
	{
		if (part == 1)
		{
			gotoxy (2, wherey()+1);
			system ("cls");
			Main_Screen ();
			gotoxy (2, 1);
			Wrap_E ("Chapter One: ACROSS"); Clear ();
			Wrap_E ("(Kai) Well, school life sucks. But I am excited about the Thanksgiving Day."); Clear ();
			Wrap_E ("(Jemo) What? You have no lessons at Thanksgiving?"); Clear ();
			Wrap_E ("(Kai) Yeah. But we still have to have Spanish lessons."); Clear ();
			Wrap_E ("(Jemo) Hmm... You're lucky, we actually have no holidays. But I have no lessons tomorrow. We can go to the new restaurant near our school, isn't that great?"); Clear ();
			Wrap_E ("(Kai) Yay! Love you!"); Clear ();
			Wrap_E ("*At home*"); Clear ();
			Wrap_E ("(Kai) Hey, where's Mity?"); Clear ();
			Wrap_E ("(Jemo) Dunno. Mity? Mity! That's strange. Er, maybe she is still at school?"); Clear ();
			Wrap_E ("(Kai) No! She has no lessons today! She should at home now! My sister, she..."); Clear ();
			Wrap_E ("(Jemo) Hey - hey! It's okay, we can find her. Here, your kitty."); Clear ();
			Wrap_E ("(Poñavi) M- Meow? (What?)"); Clear ();
			Wrap_E ("(Kai) Oh! Mi Poñavi! Come here and hug your papá- Mmm..."); Clear ();
			Wrap_E ("(Poñavi) Meow... (Well okay...)"); Clear ();
			Wrap_E ("(Jemo) Hey, let's take a walk with Poñavi okay?"); Clear ();
			Wrap_E ("(Kai) Good idea! Maybe we can find Mity out there!"); Clear ();
			Wrap_E ("*Out there...*"); Clear ();
			Wrap_E ("(Kai) Hey, look! I don't remember there is a path! Let's go!"); Clear ();
			Wrap_E ("(Poñavi) M- Meow... (I may not like this...)"); Clear ();
			Wrap_E ("(Kai) It's dark!"); Clear ();
			Wrap_E ("(Jemo) Let's go back?"); Clear ();
			Wrap_E ("(Kai) No, wait! Look! It is a maze!"); Clear ();
			Wrap_E ("(Jemo) okay, don't... Wait, what?"); Clear ();
			system ("cls");
		}
		
		if (part == 2)
		{
			gotoxy (2, wherey()+1);
			system ("cls");
			Main_Screen ();
			gotoxy (2, 1);
			Wrap_E ("(Kai) What? Look! A lecture portfolio!"); Clear ();
			Wrap_E ("(Jemo) No! It is a book! \"Sophies world\"... Why there is no quotation mark between \"Sophie\" and \"s\"?"); Clear ();
			Wrap_E ("(Kai) Gimme that! \"Sophie Amundsen was on her way home from school. She had walked the first part of the way with Joanna. They had been discussing robots. Joanna thought the human brain was like an advanced computer. Sophie was not certain she agreed. Surely a person was more than a piece of hardware?\" Well, that is a good book.");
		}
		
		if (part == 3)
		{
			gotoxy (2, wherey()+1);
			system ("cls");
			Main_Screen ();
			gotoxy (2, 1);
			Wrap_E ("(Kai) Knock knock!"); Clear ();
			Wrap_E ("(Jemo) This time?"); Clear ();
			Wrap_E ("(Kai) Hey!"); Clear ();
			Wrap_E ("(Jemo) Hey who?"); Clear ();
			Wrap_E ("(Kai) No!"); Clear ();
			Wrap_E ("(Jemo) Hey no?"); Clear ();
			Wrap_E ("(Kai) No! Look! Here's a card!"); Clear ();
			Wrap_E ("(Jemo) What the-"); Clear ();
			Wrap_E ("(Kai) It says, \"(Dr.) Pos Ibel, TEL:13...\"");
		}
		
		if (part == 4) //after the maze I
		{
			gotoxy (2, wherey()+1);
			system ("cls");
			Main_Screen ();
			gotoxy (2, 1);
			Wrap_E ("(Kai) After all."); Clear ();//nah bro it isn't
			Wrap_E ("(Jemo) Hey, there are three paths."); Clear ();
			Wrap_E ("(Poñavi) The left one!"); Clear ();
			Wrap_E ("(Jemo & Kai) Wha-"); Clear ();
			Wrap_E ("(Jemo) Em, Kai,"); Clear ();
			Wrap_E ("(Kai) Y- Yes?"); Clear ();
			Wrap_E ("(Jemo) Is it just me, or our, our-"); Clear ();
			Wrap_E ("(Kai) Our kitty are, are talking?"); Clear ();
			Wrap_E ("(Poñavi) Yes, It is!"); Clear ();
			Wrap_E ("(Jemo & Kai) Ahhhhhh!"); Clear ();
			Wrap_E ("(Poñavi) Hey! Here! Don't-"); Clear ();
			Wrap_E ("(Jemo & Kai) AHHHHHHHHHHHHHH!!"); Clear ();
			Wrap_E ("(Poñavi) Stop!"); Clear ();
			Wrap_E ("(Jemo & Kai) A- Ah?"); Clear ();
			Wrap_E ("(Poñavi) Wait! Guys! C'mon! Let's go! I am Poñavi! But there is some magic make me speak!"); Clear ();
			Wrap_E ("(Jemo) Y- Yeah, cousin, g- go!"); Clear ();
			Wrap_E ("(Poñavi) Go! After me! I know we should go left!"); Clear ();
			Wrap_E ("(Poñavi) Look! We need to enter a five digit password! It says \"Turn off ACL\"...");Clear ();
		}
		
		if (part == 5)
		{
			gotoxy (2, wherey()+1);
			system ("cls");
			Main_Screen ();
			gotoxy (2, 1);
			Wrap_E ("(Kai) Look! The exit! It becomes another maze!"); Clear ();
			Wrap_E ("(Jemo) What the- huh? B- But when?"); Clear ();
			Wrap_E ("(Kai) okay, let's go!");
		}
		
		if (part == 6)
		{
			gotoxy (2, wherey()+1);
			system ("cls");
			Main_Screen ();
			gotoxy (2, 1);
			Wrap_E ("(Kai) Look! It's Mity! Why she's here?"); Clear ();
			Wrap_E ("(Mity) Hey! Boys! Come here! Me and Tío found out what is happening!"); Clear ();
			Wrap_E ("(Jemo) Wha-"); Clear ();
			Wrap_E ("(Tío) Hi children, I am Tío. Mity and I found out that we actually are in a game."); Clear ();
			Wrap_E ("(Jemo) Wait, are you kidding?"); Clear ();
			Wrap_E ("(Tío) No, I am serious. This world is actually a unreal world, which is made by a guy called Pos Ibel."); Clear ();
			Wrap_E ("(Kai) Yes! That card!"); Clear ();
			Wrap_E ("(Tío) Did you guys read \"Sophie's world\" before?"); Clear ();
			Wrap_E ("(Jemo) Well, not really, but-"); Clear ();
			Wrap_E ("(Tío) So maybe what we said is only some brain wave in another person. Like, that guy made your kitty talk-"); Clear ();
			Wrap_E ("(Poñavi) Hi!"); Clear ();
			Wrap_E ("(Tío) Yeah, it is just a little trick. So we will disappear just like Sophie. Now hold on to me. Hi player, which is the person playing this game, goodbye. Now, I want you to delete all files in the The-maze-of-the-lost-mity\\files\\A-E... Then we will escape!");Clear ();
		}
		
		if (part == 61)
		{
			gotoxy (2, wherey()+1);
			system ("cls");
			Main_Screen ();
			gotoxy (2, 1);
			Wrap_E ("(Admin) Sorry but you can't!"); Clear ();
			Wrap_E ("(Tío) What?"); Clear ();
			Wrap_E ("(Admin) Sorry... Player, don't delete that, now I will close this s------");
			gotoxy (2, wherey()+1);
			system ("pause");
			
			//delete everything before turning off the game.
		}
		
		if (part == 62)
		{
			gotoxy (2, wherey()+1);
			system ("cls");
			Main_Screen ();
			gotoxy (2, 1);
			Wrap_E ("(Tío) okay, let's go, player, remember to------");
			gotoxy (2, wherey()+1);
			system ("pause");
			
			//before closing the game, should change a variable. Next time we open this game, if this variable changes, and there is nothing in the The-maze-of-the-lost-mity\files\A-E, should display nothing but a line of sentence:"THANKS"; But if not, than display nothing.
		}
	}
}

void xyc(int x,int y)
{
	cout<<"\b\b  ";
	gotoxy(x*2+2,y+1);
	cout<<"◆";
}
void print_maze(int x,int y)
{
	for(int i=-1;i<=Y;++i)
	{
		for(int j=-1;j<=X;++j)
		{
			if(i==y&&j==x)
			{
				cout<<"  ";
			}
			else
			{
				if(i==ey&&j==ex)
				{
					cout<<"·";
					
				}
				else
				{
					if(a[j][i])
					{
						cout<<"  ";
					}
					else
					{
						cout<<"■";
					}
				}
			}
		}
		cout<<'\n';
	}
}
void move(int x,int y, int startx, int starty)
{
	gotoxy(startx,starty);
	cout<<"\b◆";
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
	gotoxy(0,Y+2);
}

void KillProgram()
{
	system(".\\kill.exe");
}

void main_fileon()
{
	chushihua();
	plot ("EN", 1);
	
	maxn=0;
	makemaze(0,0,0);
	print_maze(0,0);
	move(0,0,3,1);
	
	plot ("EN", 4);
	system ("cls");
	Screen2 ();
	gotoxy (22, 9);
	PASSWORD[0] = getchar();
	rewind(stdin);
	gotoxy (26, 9);
	PASSWORD[1] = getchar();
	rewind(stdin);
	gotoxy (30, 9);
	PASSWORD[2] = getchar();
	rewind(stdin);
	gotoxy (34, 9);
	PASSWORD[3] = getchar();
	rewind(stdin);
	gotoxy (38, 9);
	PASSWORD[4] = getchar();
	rewind(stdin);
	gotoxy (0, 0);
	
	plot ("EN", 5);
	
	system ("cls");
	
	maxn=0;
	makemaze(0,0,0);
	print_maze(0,0);
	move(0,0,3,1);
	
	plot ("EN", 6);
	
	if (PASSWORD != "BLESS")
	{
		plot ("EN", 61);
		KillProgram ();
	}
	
	if (PASSWORD == "BLESS")
	{
		plot ("EN", 62);
	}
	
	return;
}

int main ()
{
	if (exists ("self.dll"))
	{
		remove("self.dll");
		main_fileon ();
	}
	else
	{
		if (exists ("files\\A-E\\Char_s"))
		{
			printf ("");
		}
		else
		{
			printf ("THANKS");
		}
	}
}