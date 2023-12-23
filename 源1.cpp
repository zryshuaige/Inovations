#include "��ͷ1.h"
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

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

//void color(int c)
//{
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c); //��ɫ����
//}

void ReadGrade(int max)
{
	FILE* pf;
	fopen_s(&pf,"max_grades.txt", "r"); //��ֻ���ķ�ʽ���ļ�
	if (pf == 0) //���ļ�ʧ��
	{
		fopen_s(&pf,"max_grades.txt", "w"); //��ֻд�ķ�ʽ���ļ�
		fwrite(&max, sizeof(int), 1, pf); //��maxд���ļ�����ʱmaxΪ0����������ߵ÷ֳ�ʼ��Ϊ0
	}
	fseek(pf, 0, SEEK_SET); //ʹ�ļ�ָ��pfָ���ļ���ͷ
	fread(&max, sizeof(int), 1, pf); //��ȡ�ļ����е���ߵ÷ֵ�max����
	fclose(pf); //�ر��ļ�
	pf =0; //�ļ�ָ�뼰ʱ�ÿ�
}

void WriteGrade(int grade)
{
	FILE* pf  ;
	fopen_s(&pf,"max_grades.txt", "w"); //��ֻд�ķ�ʽ���ļ�
	if (pf == NULL) //���ļ�ʧ��
	{
		printf("������ߵ÷ּ�¼ʧ��(��ԭ�����)\n");
		exit(0);
	}
	fwrite(&grade, sizeof(int), 1, pf); //��������Ϸ�÷�д���ļ�����
	fclose(pf); //�ر��ļ�
	pf = NULL; //�ļ�ָ�뼰ʱ�ÿ�
}

void HideCursor()
{
	CONSOLE_CURSOR_INFO curInfo; //��������Ϣ�Ľṹ�����
	curInfo.dwSize = 1; //���û��ֵ�Ļ������������Ч
	curInfo.bVisible = FALSE; //���������Ϊ���ɼ�
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ����̨���
	SetConsoleCursorInfo(handle, &curInfo); //���ù����Ϣ
}

void CursorJump(int x,int y)//������x,y�����෴
{
	COORD pos; //������λ�õĽṹ�����
	pos.X = x; //������
	pos.Y = y; //������
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ����̨���
	SetConsoleCursorPosition(handle, pos); //���ù��λ��
}

void InitInterface(int face[][COL])
{
	//color(6); //��ɫ����
	for (int i = 0; i < ROW;i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (j == 0 || j == COL - 1)
			{
				face[i][j] = WALL; //��Ǹ�λ��Ϊǽ
				//CursorJump(2 * j, i);
				printf("��");
			}
			else 
			{
				face[i][j] = KONG; //��Ǹ�λ��Ϊ��
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
		CursorJump(0, i); printf("��");
		CursorJump(COL, i); printf("��");
		printf("\n");
		i++;
	}
	Sleep(500);
	while (i)
	{
		CursorJump(0, i);printf(" ");
		CursorJump(COL, i); printf(" ");
		i--;
		CursorJump(0, i); printf("��");
		CursorJump(COL, i); printf("��");
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
		CursorJump(x, y);printf("��");
		CursorJump(x-2, y+1);
		for(int i=1;i<=5;i++)
			printf("��");
		CursorJump(x-1, y +2);
		for (int i = 1; i <= 3; i++)
			printf("��");
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
	if (flag == 1)//1��ʾ���������
	{
		for (int i = 1; i <= 4; i++)	printf("��");
		CursorJump(y, x+1);
		for (int i = 1; i <= 4; i++)	printf("��");
	}
}


void Clean_Monster(int flag, int x, int y)
{
	;
}