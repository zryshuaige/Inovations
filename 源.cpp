#include<iostream>
#include<windows.h>
#include<time.h>
#include<conio.h>
#include<time.h>
#include<queue>
#include"��ͷ1.h"

using namespace std;

const int N = 5;//

#define ROW 25 //��Ϸ������
#define COL 50 //��Ϸ������

#define KONG 0 //��ǿգ�ʲôҲû�У�
#define WALL 1 //���ǽ
#define ENEMY 2 //��ǵ���
#define RAW //��ǽ�
#define ARROW//�������#���ڼ���
#define Blood 20//�������Ѫ����������n*Blood��ʾ

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
struct Monsters
{
	int x, y, blood;
}monster[N];
deque<struct Monsters> que_monster;


int maxn,grade,cnt_x= COL / 2, cnt_y= ROW / 2;
time_t t1, t2;
int face[ROW][COL];

void Game(); void Move_man(int move);

int main()
{
	maxn = 0; man1.x = ROW , man1.y = COL/2 - 3;
	monster[1].x = 0, monster[1].y = COL / 2, monster[1].blood = Blood;

	system("title zry������"); //����cmd���ڵ�����
	system("mode con cols=250 lines=250"); //����cmd���ڵĴ�С
	CursorJump(cnt_x-5, cnt_y-5);
	printf("Welcome to Genshin Impact,�����յ�ָ������");
	Sleep(2000);
	system("cls");
	ReadGrade(maxn); //���ļ���ȡ��߷ֵ�max����
	InitInterface(face); //��ʼ������
	Draw_man(1, man1.y, man1.x);
	HideCursor(); //���ع��
	Game();
	return 0;
}


void Game()
{
	CursorJump(cnt_x-5, cnt_y);
	printf("�����Կ�ʼ������");
	Sleep(2000);
	CursorJump(cnt_x-5, cnt_y);
	printf("                ");
	int  n;
	//goto first;

	while (1)
	{
		n=_getch();//_getch()�ǻ�ȡ��ֵ
		//Rollface(face);
		switch (n)
		{
		case RIGHT:Move_man(1); break;
		case LEFT:Move_man(-1); break;
		case 'r':system("cls"); main(); break;
		case 'R':system("cls"); main(); break;
		case ESC: //�˳�
			system("cls"); //�����Ļ
			//color(7); //��ɫ����Ϊ��ɫ
			CursorJump( ROW / 2,COL/2);
			printf("  ��Ϸ����  ");
			//CursorJump(COL - 8, ROW / 2 + 2);
			exit(0);
		default:break;
		}
	}
}

void Move_man(int move)//�����Ϊ-1����Ϊ1��
{
	if (move == -1 && man1.y - 2 >0 || move == 1 && man1.y + 2 < COL)
	{
		Draw_man(0, man1.y, man1.x);
		man1.y += move;
		Draw_man(1, man1.y, man1.x);
	}
}