#include "console_ctrl.h"

void tomiddle(int len)
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);//获取当前窗口句柄
	CONSOLE_SCREEN_BUFFER_INFO info;//储存窗口信息的结构体
	GetConsoleScreenBufferInfo(hout, &info);//获取窗口信息
	COORD pos;//位置结构体，设置坐标的函数要用
	pos.X = info.dwSize.X/2-len/2;
	pos.Y = info.dwCursorPosition.Y;
	SetConsoleCursorPosition(hout, pos);//设置光标位置
}
void currentmove(int x, int y) {
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);//获取当前窗口句柄
	CONSOLE_SCREEN_BUFFER_INFO info;//储存窗口信息的结构体
	GetConsoleScreenBufferInfo(hout, &info);//获取窗口信息
	COORD pos;//位置结构体，设置坐标的函数要用
	pos.X = info.dwCursorPosition.X + x;
	pos.Y = info.dwCursorPosition.Y + y;
	SetConsoleCursorPosition(hout, pos);//设置光标位置
}
void getxy(position& p) {
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);//获取当前窗口句柄
	CONSOLE_SCREEN_BUFFER_INFO info;//储存窗口信息的结构体
	GetConsoleScreenBufferInfo(hout, &info);//获取窗口信息
	p.x = info.dwCursorPosition.X;
	p.y = info.dwCursorPosition.Y;
};
void gotoxy(int x, int y)
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);//获取当前窗口句柄
	COORD pos;//位置结构体，设置坐标的函数要用
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hout, pos);//设置光标位置
}
void getsize(position& p) {
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);//获取当前窗口句柄
	CONSOLE_SCREEN_BUFFER_INFO info;//储存窗口信息的结构体
	GetConsoleScreenBufferInfo(hout, &info);//获取窗口信息
	p.x = info.dwSize.X;
	p.y = info.dwSize.Y;
}