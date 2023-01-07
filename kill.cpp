#include <bits/stdc++.h>
#include <windows.h>
#include <dir.h>
#include <conio.h>
#include <sys/stat.h>
#include <shlwapi.h>
#pragma comment(lib,"Shlwapi.lib")
using namespace std;

inline bool exists (const string name)
{
	struct stat buffer;
	return (stat (name.c_str(), &buffer) == 0); 
}
int main()
{
	while(exists ("main.exe"))
	{
		remove("main.exe");
	}
	return 0;
}