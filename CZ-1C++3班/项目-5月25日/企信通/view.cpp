#include "menudefine.h"
#include <string.h>
#include <stdio.h> 
#include <Windows.h>
#include <conio.h>

int getKeyBoard()
{
	int a = _getch();
	int result = ((char)a < 0) ? (a << 8 | _getch()) : a;
	return result;
}

int pageMenu()
{
	void (*p[MENUPAGENUM])() = { printSignIn , printSignUp , printSet , printExit };

	p[0]();
	int option = 0;
	while (1)
	{
		switch (getKeyBoard())
		{
		case ARROW_UP:
			option--;
			break;
		case ARROW_DOWN:
			option++;
			break;
		case '\r':
			return option;
		default:;
		}
		option += MENUPAGENUM;
		option %= MENUPAGENUM;

		p[option]();
	}
}

void printSignIn()
{
	char p[1024] = { 0 };
	strcat(p, "█ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ \n");
	strcat(p, "█ 　　　　　　　　　　　　　　　　█ \n");
	strcat(p, "█ 　　　　　　　　　　　　　　　　█ \n");
	strcat(p, "█ 　　　　　 企  信  通 　　　　　█ \n");
	strcat(p, "█ 　　　　　　　　　　　　　　　　█ \n");
	strcat(p, "█ 　　　　　　　　　　　　　　　　█ \n");
	strcat(p, "█ 　　　　　　　　　　　　　　　　█ \n");
	strcat(p, "█ 　　　  　◆登  录        　　　█ \n");
	strcat(p, "█ 　　　  　　注  册    　  　　　█ \n");
	strcat(p, "█ 　　　      设  置    　  　　　█ \n");
	strcat(p, "█ 　　　　  　退  出 　　 　　　　█ \n");
	strcat(p, "█ 　　　　　　　　　　　　　　　　█ \n");
	strcat(p, "█ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ \n");
	strcat(p, "　　　 方向键选择　回车键确认\n");
	strcat(p, "　　　　　　 开始游戏\n");
	system("cls");
	puts(p);
}

void printSignUp()
{
	char p[1024] = { 0 };
	strcat(p, "█ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ \n");
	strcat(p, "█ 　　　　　　　　　　　　　　　　█ \n");
	strcat(p, "█ 　　　　　　　　　　　　　　　　█ \n");
	strcat(p, "█ 　　　　　 企  信  通 　　　　　█ \n");
	strcat(p, "█ 　　　　　　　　　　　　　　　　█ \n");
	strcat(p, "█ 　　　　　　　　　　　　　　　　█ \n");
	strcat(p, "█ 　　　　　　　　　　　　　　　　█ \n");
	strcat(p, "█ 　　　  　　登  录        　　　█ \n");
	strcat(p, "█ 　　　    ◆注  册    　  　　　█ \n");
	strcat(p, "█ 　　　      设  置    　  　　　█ \n");
	strcat(p, "█ 　　　　  　退  出 　　 　　　　█ \n");
	strcat(p, "█ 　　　　　　　　　　　　　　　　█ \n");
	strcat(p, "█ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ \n");
	strcat(p, "　　　 方向键选择　回车键确认\n");
	strcat(p, "　　　　　　 开始游戏\n");
	system("cls");
	puts(p);
}

void printSet()
{
	char p[1024] = { 0 };
	strcat(p, "█ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ \n");
	strcat(p, "█ 　　　　　　　　　　　　　　　　█ \n");
	strcat(p, "█ 　　　　　　　　　　　　　　　　█ \n");
	strcat(p, "█ 　　　　　 企  信  通 　　　　　█ \n");
	strcat(p, "█ 　　　　　　　　　　　　　　　　█ \n");
	strcat(p, "█ 　　　　　　　　　　　　　　　　█ \n");
	strcat(p, "█ 　　　　　　　　　　　　　　　　█ \n");
	strcat(p, "█ 　　　  　　登  录        　　　█ \n");
	strcat(p, "█ 　　　    　注  册    　  　　　█ \n");
	strcat(p, "█ 　　　    ◆设  置    　  　　　█ \n");
	strcat(p, "█ 　　　　  　退  出 　　 　　　　█ \n");
	strcat(p, "█ 　　　　　　　　　　　　　　　　█ \n");
	strcat(p, "█ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ \n");
	strcat(p, "　　　 方向键选择　回车键确认\n");
	strcat(p, "　　　　　　 开始游戏\n");
	system("cls");
	puts(p);
}

void printExit()
{
	char p[1024] = { 0 };
	strcat(p, "█ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ \n");
	strcat(p, "█ 　　　　　　　　　　　　　　　　█ \n");
	strcat(p, "█ 　　　　　　　　　　　　　　　　█ \n");
	strcat(p, "█ 　　　　　 企  信  通 　　　　　█ \n");
	strcat(p, "█ 　　　　　　　　　　　　　　　　█ \n");
	strcat(p, "█ 　　　　　　　　　　　　　　　　█ \n");
	strcat(p, "█ 　　　　　　　　　　　　　　　　█ \n");
	strcat(p, "█ 　　　  　　登  录        　　　█ \n");
	strcat(p, "█ 　　　    　注  册    　  　　　█ \n");
	strcat(p, "█ 　　　      设  置    　  　　　█ \n");
	strcat(p, "█ 　　　　  ◆退  出 　　 　　　　█ \n");
	strcat(p, "█ 　　　　　　　　　　　　　　　　█ \n");
	strcat(p, "█ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ \n");
	strcat(p, "　　　 方向键选择　回车键确认\n");
	strcat(p, "　　　　　　 开始游戏\n");
	system("cls");
	puts(p);
}


int pageSet()
{
	void (*p[SETPAGENUM])() = { printVolume , printColor };

	p[0]();
	int option = 0;
	while (1)
	{
		switch (getKeyBoard())
		{
		case ARROW_UP:
			option--;
			break;
		case ARROW_DOWN:
			option++;
			break;
		case '\r':
			return option;
		default:;
		}
		option += SETPAGENUM;
		option %= SETPAGENUM;

		p[option]();
	}
}

void printVolume()
{
	char p[1024] = { 0 };
	strcat(p, "█ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ \n");
	strcat(p, "█ 　　　　　　　　　　　　　　　　█ \n");
	strcat(p, "█ 　　　　　　　　　　　　　　　　█ \n");
	strcat(p, "█ 　　　　　 企  信  通 　　　　　█ \n");
	strcat(p, "█ 　　　　　　设  置　　　　　　　█ \n");
	strcat(p, "█ 　　　　　　　　　　　　　　　　█ \n");
	strcat(p, "█ 　　　　　　　　　　　　　　　　█ \n");
	strcat(p, "█ 　　　  　◆音  量        　　　█ \n");
	strcat(p, "█ 　　　  　　颜  色    　  　　　█ \n");
	strcat(p, "█ 　　　                　  　　　█ \n");
	strcat(p, "█ 　　　　  　       　　 　　　　█ \n");
	strcat(p, "█ 　　　　　　　　　　　　　　　　█ \n");
	strcat(p, "█ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ \n");
	strcat(p, "　　　 方向键选择　回车键确认\n");
	strcat(p, "　　　　　　 开始游戏\n");
	system("cls");
	puts(p);
}

void printColor()
{
	char p[1024] = { 0 };
	strcat(p, "█ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ \n");
	strcat(p, "█ 　　　　　　　　　　　　　　　　█ \n");
	strcat(p, "█ 　　　　　　　　　　　　　　　　█ \n");
	strcat(p, "█ 　　　　　 企  信  通 　　　　　█ \n");
	strcat(p, "█ 　　　　　　设  置　　　　　　　█ \n");
	strcat(p, "█ 　　　　　　　　　　　　　　　　█ \n");
	strcat(p, "█ 　　　　　　　　　　　　　　　　█ \n");
	strcat(p, "█ 　　　  　  音  量        　　　█ \n");
	strcat(p, "█ 　　　  　◆颜  色    　  　　　█ \n");
	strcat(p, "█ 　　　                　  　　　█ \n");
	strcat(p, "█ 　　　　  　       　　 　　　　█ \n");
	strcat(p, "█ 　　　　　　　　　　　　　　　　█ \n");
	strcat(p, "█ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ \n");
	strcat(p, "　　　 方向键选择　回车键确认\n");
	strcat(p, "　　　　　　 开始游戏\n");
	system("cls");
	puts(p);
}
