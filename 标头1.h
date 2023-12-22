#pragma once

#ifndef CA_H
#define CA_H
#define ROW 25
#define COL 50

void InitInterface(int face[][COL]);

void HideCursor();
void CursorJump(int x,int y);

void ReadGrade(int max);
void WriteGrade(int grade);

void color(int c);
void run(int x, int y);

void Draw_man(int flag,int x,int y);
void Move_man(int x);


//后期增加项目
//void buff_dog();
//void buff_arrow_normal();
//void buff_arrow;
//void choose_hero(int n);
#endif
