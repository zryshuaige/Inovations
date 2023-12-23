#include "标头1.h"
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

#define ROW 25 //游戏区行数
#define COL 50 //游戏区列数

#define KONG 0 //标记空（什么也没有）
#define WALL 1 //标记墙
#define ENEMY 2 //标记敌人
#define RAW //标记剑
#define ARROW//标记御剑#后期加入

#define UP 72 //方向键：上
#define DOWN 80 //方向键：下
#define LEFT 75 //方向键：左
#define RIGHT 77 //方向键：右
#define SPACE 32 //暂停
#define ESC 27 //退出

//void color(int c)
//{
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c); //颜色设置
//}

void ReadGrade(int max)
{
	FILE* pf;
	fopen_s(&pf,"max_grades.txt", "r"); //以只读的方式打开文件
	if (pf == 0) //打开文件失败
	{
		fopen_s(&pf,"max_grades.txt", "w"); //以只写的方式打开文件
		fwrite(&max, sizeof(int), 1, pf); //将max写入文件（此时max为0），即将最高得分初始化为0
	}
	fseek(pf, 0, SEEK_SET); //使文件指针pf指向文件开头
	fread(&max, sizeof(int), 1, pf); //读取文件当中的最高得分到max当中
	fclose(pf); //关闭文件
	pf =0; //文件指针及时置空
}

void WriteGrade(int grade)
{
	FILE* pf  ;
	fopen_s(&pf,"max_grades.txt", "w"); //以只写的方式打开文件
	if (pf == NULL) //打开文件失败
	{
		printf("保存最高得分记录失败(玩原神玩的)\n");
		exit(0);
	}
	fwrite(&grade, sizeof(int), 1, pf); //将本局游戏得分写入文件当中
	fclose(pf); //关闭文件
	pf = NULL; //文件指针及时置空
}

void HideCursor()
{
	CONSOLE_CURSOR_INFO curInfo; //定义光标信息的结构体变量
	curInfo.dwSize = 1; //如果没赋值的话，光标隐藏无效
	curInfo.bVisible = FALSE; //将光标设置为不可见
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //获取控制台句柄
	SetConsoleCursorInfo(handle, &curInfo); //设置光标信息
}

void CursorJump(int x,int y)//与数组x,y定义相反
{
	COORD pos; //定义光标位置的结构体变量
	pos.X = x; //横坐标
	pos.Y = y; //纵坐标
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //获取控制台句柄
	SetConsoleCursorPosition(handle, pos); //设置光标位置
}

void InitInterface(int face[][COL])
{
	//color(6); //颜色设置
	for (int i = 0; i < ROW;i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (j == 0 || j == COL - 1)
			{
				face[i][j] = WALL; //标记该位置为墙
				//CursorJump(2 * j, i);
				printf("■");
			}
			else 
			{
				face[i][j] = KONG; //标记该位置为空
				printf(" ");
			}
		}
		printf("\n");
	}
}

void Rollface(int face[][COL])
{
	int i = 0,j=0;
	while (i <= ROW)
	{
		CursorJump(0, i); printf("■");
		CursorJump(COL, i); printf("■");
		printf("\n");
		i++;
	}
	Sleep(500);
	while (i)
	{
		CursorJump(0, i);printf(" ");
		CursorJump(COL, i); printf(" ");
		i--;
		CursorJump(0, i); printf("■");
		CursorJump(COL, i); printf("■");
		i--;
	}
}


void run(int x, int y)
{

}

void Draw_man(int flag,int x,int y)
{
	if (flag == 1)
	{
		//color(10);
		CursorJump(x, y);printf("■");
		CursorJump(x-2, y+1);
		for(int i=1;i<=5;i++)
			printf("■");
		CursorJump(x-1, y +2);
		for (int i = 1; i <= 3; i++)
			printf("■");
	}
	else
	{
		CursorJump(x, y); printf(" ");
		CursorJump(x - 2, y + 1);
		for (int i = 1; i <= 5; i++)
			printf(" ");
		CursorJump(x - 1, y + 2);
		for (int i = 1; i <= 3; i++)
			printf(" ");
	}
}


void Draw_Monster(int flag, int x, int y)
{
	CursorJump(y,x);
	if (flag == 1)//1表示（基础怪物）
	{
		for (int i = 1; i <= 4; i++)	printf("■");
		CursorJump(y, x+1);
		for (int i = 1; i <= 4; i++)	printf("■");
	}
}


void Clean_Monster(int flag, int x, int y)
{
	;
}