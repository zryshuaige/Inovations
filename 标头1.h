#pragma once

#ifndef CA_H
#define CA_H
#define ROW 25
#define COL 50


void HideCursor();
void ReadGrade(int max);
void InitInterface(int face[][COL]); //初始化界面
void WriteGrade(int grade);
void color(int c);
void run(int x, int y);
void CursorJump(int x, int y);
void Move_man(int x);
#endif
