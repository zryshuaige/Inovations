#include<iostream>
#include<windows.h>
#include"��ͷ1.h"
#include <Color.Dlg>
#include <Color.Dlg>
using namespace std;

#define ROW 25 //��Ϸ������
#define COL 50 //��Ϸ������

#define KONG 0 //��ǿգ�ʲôҲû�У�
#define WALL 1 //���ǽ
#define ENEMY 2 //��ǵ���
#define ROW //��ǽ�
#define ARROW//�������#���ڼ���

#define UP 72 //���������
#define DOWN 80 //���������
#define LEFT 75 //���������
#define RIGHT 77 //���������
#define SPACE 32 //��ͣ
#define ESC 27 //�˳�


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
		case ESC: //�˳�
			system("cls"); //�����Ļ
			//color(7); //��ɫ����Ϊ��ɫ
			CursorJump(COL - 8, ROW / 2);
			printf("  ��Ϸ����  ");
			CursorJump(COL - 8, ROW / 2 + 2);
			exit(0);
		default:break;
		}
	}
}

int main(void)
{
    maxn = 0;
	system("title zry������"); //����cmd���ڵ�����
	system("mode con cols=200 lines=100"); //����cmd���ڵĴ�С
	HideCursor(); //���ع��
	ReadGrade(maxn); //���ļ���ȡ��߷ֵ�max����
	InitInterface(); //��ʼ������


	Game();
	return 0;
}


