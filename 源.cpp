#include<iostream>
#include<windows.h>
#include"��ͷ1.h"

using namespace std;

#define ROW 25 //��Ϸ������
#define COL 50 //��Ϸ������

#define KONG 0 //��ǿգ�ʲôҲû�У�
#define WALL 1 //���ǽ
#define ENEMY 2 //��ǵ���
#define RAW //��ǽ�
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
	int x, y;//x,y��ʾӢ�۵�ͷ����λ�ã�
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
	system("title zry������"); //����cmd���ڵ�����
	system("mode con cols=200 lines=800"); //����cmd���ڵĴ�С
	HideCursor(); //���ع��
	ReadGrade(maxn); //���ļ���ȡ��߷ֵ�max����
	InitInterface(face); //��ʼ������
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
		case ESC: //�˳�
			system("cls"); //�����Ļ
			//color(7); //��ɫ����Ϊ��ɫ
			//CursorJump(COL - 8, ROW / 2);
			printf("  ��Ϸ����  ");
			//CursorJump(COL - 8, ROW / 2 + 2);
			exit(0);
		default:break;
		}
	}
}