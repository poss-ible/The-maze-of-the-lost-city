#include <bits/stdc++.h>
#include <windows.h>
#include <dir.h>
#include <conio.h>
using namespace std;

int lan = 0;

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

void gotoxy(int x,int y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle,pos);
}

void Main_Screen ()
{
	printf("┌──────────────────────────────────────────────────────────┐\n");
	printf("│                                                          │\n");
	printf("│                                                          │\n");
	printf("│                                                          │\n");
	printf("│                                                          │\n");
	printf("│                                                          │\n");
	printf("│                                                          │\n");
	printf("│                                                          │\n");
	printf("│                                                          │\n");
	printf("│                                                          │\n");
	printf("│                                                          │\n");
	printf("│                                                          │\n");
	printf("│                                                          │\n");
	printf("│                                                          │\n");
	printf("│                                                          │\n");
	printf("│                                                          │\n");
	printf("│                                                          │\n");
	printf("│                                                          │\n");
	printf("│                                                          │\n");
	printf("│                                                          │\n");
	printf("└──────────────────────────────────────────────────────────┘\n");
}

void Clear ()
{
	system ("pause");
	system ("cls");
	Main_Screen ();
	gotoxy (1, 1);
}

void plot (int lan, int part)
{
	if (lan == 1) //english
	{
		if (part == 1)
		{
			printf ("Chapter One: ACROSS"); Clear ();
			//clear (); Clear ();
			printf ("(Kai) Well, school life sucks. But I am excited about the Thanksgiving Day."); Clear ();
			printf ("(Jemo) What? You have no lessons at Thanksgiving?"); Clear ();
			printf ("(Kai) Yeah. But we still have to have Spanish lessons."); Clear ();
			printf ("(Jemo) Hmm... You're lucky, we actually have no holidays. But I have no lessons tomorrow. We can go to the new restaurant near our school, isn't that great?"); Clear ();
			printf ("(Kai) Yay! Love you!"); Clear ();
			printf ("*At home*"); Clear ();
			printf ("(Kai) Hey, where's Mity?"); Clear ();
			printf ("(Jemo) Dunno. Mity? Mity! That's strange. Er, maybe she is still at school?"); Clear ();
			printf ("(Kai) No! She has no lessons today! She should at home now! My sister, she..."); Clear ();
			printf ("(Jemo) Hey - hey! It's okay, we can find her. Here, your kitty."); Clear ();
			printf ("(Poñavi) M- Meow? (What?)"); Clear ();
			printf ("(Kai) Oh! Mi Poñavi! Come here and hug your papá- Mmm..."); Clear ();
			printf ("(Poñavi) Meow... (Well okay...)"); Clear ();
			printf ("(Jemo) Hey, let's take a walk with Poñavi okay?"); Clear ();
			printf ("(Kai) Good idea! Maybe we can find Mity out there!"); Clear ();
			printf ("*Out there...*"); Clear ();
			printf ("(Kai) Hey, look! I don't remember there is a path! Let's go!"); Clear ();
			printf ("(Poñavi) M- Meow... (I may not like this...)"); Clear ();
			printf ("(Kai) It's dark!"); Clear ();
			printf ("(Jemo) Let's go back?"); Clear ();
			printf ("(Kai) No, wait! Look! It is a maze!"); Clear ();
			printf ("(Jemo) okay, don't... Wait, what?"); Clear ();
		}
		
		if (part == 2)
		{
			printf ("(Kai) What? Look! A lecture portfolio!"); Clear ();
			printf ("(Jemo) No! It is a book! \"Sophies world\"... Why there is no quotation mark between \"Sophie\" and \"s\"?"); Clear ();
			printf ("(Kai) Gimme that! \"Sophie Amundsen was on her way home from school. She had walked the first part of the way with Joanna. They had been discussing robots. Joanna thought the human brain was like an advanced computer. Sophie was not certain she agreed. Surely a person was more than a piece of hardware?\" Well, that is a good book."); Clear ();
		}
		
		if (part == 3)
		{
			printf ("(Kai) Knock knock!"); Clear ();
			printf ("(Jemo) This time?"); Clear ();
			printf ("(Kai) Hey!"); Clear ();
			printf ("(Jemo) Hey who?"); Clear ();
			printf ("(Kai) No!"); Clear ();
			printf ("(Jemo) Hey no?"); Clear ();
			printf ("(Kai) No! Look! Here's a card!"); Clear ();
			printf ("(Jemo) What the-"); Clear ();
			printf ("(Kai) It says, \"(Dr.) Pos Ibel, TEL:13...\""); Clear ();
		}
		
		if (part == 4) //after the maze I
		{
			printf ("(Kai) After all."); Clear ();//nah bro it isn't
			printf ("(Jemo) Hey, there are three paths."); Clear ();
			printf ("(Poñavi) The left one!"); Clear ();
			printf ("(Jemo & Kai) Wha-"); Clear ();
			printf ("(Jemo) Em, Kai,"); Clear ();
			printf ("(Kai) Y- Yes?"); Clear ();
			printf ("(Jemo) Is it just me, or our, our-"); Clear ();
			printf ("(Kai) Our kitty are, are talking?"); Clear ();
			printf ("(Poñavi) Yes, It is!"); Clear ();
			printf ("(Jemo & Kai) Ahhhhhh!"); Clear ();
			printf ("(Poñavi) Hey! Here! Don't-"); Clear ();
			printf ("(Jemo & Kai) AHHHHHHHHHHHHHH!!"); Clear ();
			printf ("(Poñavi) Stop!"); Clear ();
			printf ("(Jemo & Kai) A- Ah?"); Clear ();
			printf ("(Poñavi) Wait! Guys! C'mon! Let's go! I am Poñavi! But there is some magic make me speak!"); Clear ();
			printf ("(Jemo) Y- Yeah, cousin, g- go!"); Clear ();
			printf ("(Poñavi) Go! After me! I know we should go left!"); Clear ();
			printf ("(Poñavi) Look! We need to enter a five digit password! It says \"Turn off ACL\"..."); Clear ();
		}
		
		if (part == 5)
		{
			printf ("(Kai) Look! The exit! It becomes another maze!"); Clear ();
			printf ("(Jemo) What the- huh? B- But when?"); Clear ();
			printf ("(Kai) okay, let's go!"); Clear ();
		}
		
		if (part == 6)
		{
			printf ("(Kai) Look! It's Mity! Why she's here?"); Clear ();
			printf ("(Mity) Hey! Boys! Come here! Me and Tío found out what is happening!"); Clear ();
			printf ("(Jemo) Wha-"); Clear ();
			printf ("(Tío) Hi children, I am Tío. Mity and I found out that we actually are in a game."); Clear ();
			printf ("(Jemo) Wait, are you kidding?"); Clear ();
			printf ("(Tío) No, I am serious. This world is actually a unreal world, which is made by a guy called Pos Ibel."); Clear ();
			printf ("(Kai) Yes! That card!"); Clear ();
			printf ("(Tío) Did you guys read \"Sophie's world\" before?"); Clear ();
			printf ("(Jemo) Well, not really, but-"); Clear ();
			printf ("(Tío) So maybe what we said is only some brain wave in another person. Like, that guy made your kitty talk-"); Clear ();
			printf ("(Poñavi) Hi!"); Clear ();
			printf ("(Tío) Yeah, it is just a little trick. So we will disappear just like Sophie. Now hold on to me. Hi player, which is the person playing this game, goodbye. Now, I want you to delete all files in the The-maze-of-the-lost-mity\\files\\A-E... Then we will escape!"); Clear ();
		}
		
		if (part == 61)
		{
			printf ("(Admin) Sorry but you can't!"); Clear ();
			printf ("(Tío) What?"); Clear ();
			printf ("(Admin) Sorry... Player, don't delete that, now I will close this s------"); Clear ();
			
			//delete everything before turning off the game.
		}
		
		if (part == 62)
		{
			printf ("(Tío) okay, let's go, player, remember to------"); Clear ();
			
			//before closing the game, should change a variable. Next time we open this game, if this variable changes, and there is nothing in the The-maze-of-the-lost-mity\files\A-E, should display nothing but a line of sentence:"THANKS"; But if not, than display nothing.
		}
	}
}