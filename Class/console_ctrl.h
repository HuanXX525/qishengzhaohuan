#pragma once
#include<Windows.h>

void tomiddle(int len);//光标居中；字符串长度
void gotoxy(int x, int y);//设置光标位置
void currentmove(int x, int y);//在当前位置移动多少
void getxy(short& x, short& y);//获取当前位置
void printlogin(void);//登录界面