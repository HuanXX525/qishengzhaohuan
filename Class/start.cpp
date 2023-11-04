#include "start.h"
#include"console_ctrl.h"
#include<iostream>
#include<conio.h>
using namespace std;
void welcome(void)
{
	string str = "在开始游戏之前请调整好您的窗口大小";
	int i = str.length();
	tomiddle(i);
	cout << "\033[30;44m" << str << "\033[0m" << endl;

	string str1 = "按下任意键开始";
	i = str1.length();
	tomiddle(i);
	cout << str1 << endl;

	char ch = _getch();//等待按下任意键
	system("cls");
}
