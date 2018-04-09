#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <string.h>

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void yellow()
{
	SetConsoleTextAttribute(hConsole, 14);
}

void white()
{
	SetConsoleTextAttribute(hConsole, 15);
}

void red()
{
	SetConsoleTextAttribute(hConsole, 12);
}

void green()
{
	SetConsoleTextAttribute(hConsole, 11);
}