#pragma once
#include<Windows.h>
class position {
public:
	short x;
	short y;
};
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
void tomiddle(int len);//光标居中；字符串长度
void gotoxy(int x, int y);//设置光标位置
void currentmove(int x, int y);//在当前位置移动多少
void getxy(position& p);//获取当前位置
void printlogin(void);//登录界面
void getsize(position& p);//获取窗口的大小