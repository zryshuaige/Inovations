#include<iostream>
#include<windows.h>
#include"标头1.h"

using namespace std;

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


struct man
{
	int move_speed, blood;
	int x, y;//x,y表示英雄的头部的位置；
}man1;
struct row
{
	int num, frequency,speed;
}rows;

int maxn,grade;
int face[ROW][COL];

void Game();

int main(void)
{
	maxn = 0; man1.x = ROW / 2, man1.y = COL - 3;
	system("title zry箭箭剑"); //设置cmd窗口的名字
	system("mode con cols=200 lines=800"); //设置cmd窗口的大小
	HideCursor(); //隐藏光标
	ReadGrade(maxn); //从文件读取最高分到max变量
	InitInterface(face); //初始化界面
	Draw_man(1, man1.x, man1.y);

	Game();
	return 0;
}


void Game()
{
	int n;
	int tmp = 0;
	//goto first;
	while (1);
	{
		n = getchar();
		int tmp = 0;
		switch (n)
		{
		case RIGHT:Move_man(-1);
		case LEFT:Move_man(1);
		case 'r':
		case 'R':system("cls"); main();
		case ESC: //退出
			system("cls"); //清空屏幕
			//color(7); //颜色设置为白色
			//CursorJump(COL - 8, ROW / 2);
			printf("  游戏结束  ");
			//CursorJump(COL - 8, ROW / 2 + 2);
			exit(0);
		default:break;
		}
	}
}