#include "��ͷ1.h"
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>

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

void ReadGrade(int max)
{
	FILE* pf = fopen("max_grades.txt", "r"); //��ֻ���ķ�ʽ���ļ�
	if (pf == NULL) //���ļ�ʧ��
	{
		pf = fopen("max_grades.txt", "w"); //��ֻд�ķ�ʽ���ļ�
		fwrite(&max, sizeof(int), 1, pf); //��maxд���ļ�����ʱmaxΪ0����������ߵ÷ֳ�ʼ��Ϊ0
	}
	fseek(pf, 0, SEEK_SET); //ʹ�ļ�ָ��pfָ���ļ���ͷ
	fread(&max, sizeof(int), 1, pf); //��ȡ�ļ����е���ߵ÷ֵ�max����
	fclose(pf); //�ر��ļ�
	pf = NULL; //�ļ�ָ�뼰ʱ�ÿ�
}

void WriteGrade(int grade)
{
	FILE* pf = fopen("̰������ߵ÷ּ�¼.txt", "w"); //��ֻд�ķ�ʽ���ļ�
	if (pf == NULL) //���ļ�ʧ��
	{
		printf("������ߵ÷ּ�¼ʧ��\n");
		exit(0);
	}
	fwrite(&grade, sizeof(int), 1, pf); //��������Ϸ�÷�д���ļ�����
	fclose(pf); //�ر��ļ�
	pf = NULL; //�ļ�ָ�뼰ʱ�ÿ�
}

void HideCursor()
{

}


	void InitInterface()
{
	//color(6); //��ɫ����Ϊ����ɫ
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (j == 0 || j == COL - 1)
			{
				face[i][j] = WALL; //��Ǹ�λ��Ϊǽ
				CursorJump(2 * j, i);
				printf("��");
			}
			else if (i == 0 || i == ROW - 1)
			{
				face[i][j] = WALL; //��Ǹ�λ��Ϊǽ
				printf("��");
			}
			else
			{
				face[i][j] = KONG; //��Ǹ�λ��Ϊ��
			}
		}
	}
}


