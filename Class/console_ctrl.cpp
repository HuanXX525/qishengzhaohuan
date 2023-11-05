#include "console_ctrl.h"


void tomiddle(int len)
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);//��ȡ��ǰ���ھ��
	CONSOLE_SCREEN_BUFFER_INFO info;//���洰����Ϣ�Ľṹ��
	GetConsoleScreenBufferInfo(hout, &info);//��ȡ������Ϣ
	COORD pos;//λ�ýṹ�壬��������ĺ���Ҫ��
	pos.X = info.dwSize.X/2-len/2;
	pos.Y = info.dwCursorPosition.Y;
	SetConsoleCursorPosition(hout, pos);//���ù��λ��
}

void gotoxy(int x, int y)
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);//��ȡ��ǰ���ھ��
	COORD pos;//λ�ýṹ�壬��������ĺ���Ҫ��
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hout, pos);//���ù��λ��
}


