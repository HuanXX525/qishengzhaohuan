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
void tomiddle(int len);//�����У��ַ�������
void gotoxy(int x, int y);//���ù��λ��
void currentmove(int x, int y);//�ڵ�ǰλ���ƶ�����
void getxy(position& p);//��ȡ��ǰλ��
void printlogin(void);//��¼����
void getsize(position& p);//��ȡ���ڵĴ�С