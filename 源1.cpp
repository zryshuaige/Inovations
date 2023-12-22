#include "标头1.h"
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>

#define ROW 25 //游戏区行数
#define COL 50 //游戏区列数

#define KONG 0 //标记空（什么也没有）
#define WALL 1 //标记墙
#define ENEMY 2 //标记敌人
#define ROW //标记剑
#define ARROW//标记御剑#后期加入

#define UP 72 //方向键：上
#define DOWN 80 //方向键：下
#define LEFT 75 //方向键：左
#define RIGHT 77 //方向键：右
#define SPACE 32 //暂停
#define ESC 27 //退出

void ReadGrade(int max)
{
	FILE* pf = fopen("max_grades.txt", "r"); //以只读的方式打开文件
	if (pf == NULL) //打开文件失败
	{
		pf = fopen("max_grades.txt", "w"); //以只写的方式打开文件
		fwrite(&max, sizeof(int), 1, pf); //将max写入文件（此时max为0），即将最高得分初始化为0
	}
	fseek(pf, 0, SEEK_SET); //使文件指针pf指向文件开头
	fread(&max, sizeof(int), 1, pf); //读取文件当中的最高得分到max当中
	fclose(pf); //关闭文件
	pf = NULL; //文件指针及时置空
}

void WriteGrade(int grade)
{
	FILE* pf = fopen("贪吃蛇最高得分记录.txt", "w"); //以只写的方式打开文件
	if (pf == NULL) //打开文件失败
	{
		printf("保存最高得分记录失败\n");
		exit(0);
	}
	fwrite(&grade, sizeof(int), 1, pf); //将本局游戏得分写入文件当中
	fclose(pf); //关闭文件
	pf = NULL; //文件指针及时置空
}

void HideCursor()
{

}


	void InitInterface()
{
	//color(6); //颜色设置为土黄色
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (j == 0 || j == COL - 1)
			{
				face[i][j] = WALL; //标记该位置为墙
				CursorJump(2 * j, i);
				printf("■");
			}
			else if (i == 0 || i == ROW - 1)
			{
				face[i][j] = WALL; //标记该位置为墙
				printf("■");
			}
			else
			{
				face[i][j] = KONG; //标记该位置为空
			}
		}
	}
}


