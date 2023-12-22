#include<iostream>
#include<windows.h>
#include"标头1.h"
#include <Color.Dlg>
#include <Color.Dlg>
using namespace std;

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


struct man
{
	int move_speed, blood;
}man1;
struct row
{
	int num, frequency;
}rows;

int maxn,grade;
int face[ROW][COL];

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
		case RIGHT:run(-1, 0);
		case LEFT:run(1, 0);
		case 'R':system("cls"); main();
		case ESC: //退出
			system("cls"); //清空屏幕
			//color(7); //颜色设置为白色
			CursorJump(COL - 8, ROW / 2);
			printf("  游戏结束  ");
			CursorJump(COL - 8, ROW / 2 + 2);
			exit(0);
		default:break;
		}
	}
}

int main(void)
{
    maxn = 0;
	system("title zry箭箭剑"); //设置cmd窗口的名字
	system("mode con cols=200 lines=100"); //设置cmd窗口的大小
	HideCursor(); //隐藏光标
	ReadGrade(maxn); //从文件读取最高分到max变量
	InitInterface(); //初始化界面


	Game();
	return 0;
}


