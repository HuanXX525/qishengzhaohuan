#include "start.h"
#include"color.h"
#include"console_ctrl.h"
#include<iostream>
#include<conio.h>
#include<fstream>
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

void printlogo(void)//打印七圣召唤LOGO
{//读文件
	ifstream infile;
	infile.open("./logo.txt", ios::in);
	string line;
	short len = 114;
	tomiddle(len);
	short x, y;
	getxy(x, y);
	for (int j = 0; j < 5; j++) {
		gotoxy(x, j);
		getline(infile, line);
		cout << ROCK << line;
	}
	getxy(x, y);
	for (int j = 0; j < 5; j++) {
		gotoxy(x, j);
		getline(infile, line);
		cout << FIRE << line;
	}
	getxy(x, y);
	for (int j = 0; j < 5; j++) {
		gotoxy(x, j);
		getline(infile, line);
		cout << BLUE << line;
	}
	cout << DEFAULT<<endl<<endl;
	infile.close();
}

void printlogin(void) {
	ifstream infile;
	infile.open("./login.txt", ios::in);
	string line;
	short len = 42;
	tomiddle(len);
	short x, y;
	getxy(x, y);
	for (int j = 0; j < 12; j++) {
		gotoxy(x, j+y);
		getline(infile, line);
		cout  << line;
	}
	infile.close();
	login(x + 8, y+4);//输入框的位置

}

void input_k(char arr[]) {
	int i = 0;
	char c;
	while ((c = getch()) != '\r') {//getch不需要回车键即可载入字符，回车代表密码输入结束退出循环
		if (c != '\b') {///b用于回退显示的*，没有按退格表示输入了一个字符，输出*提示用户，并将字符存入数组
			printf("*");
			arr[i++] = c;
		}
		else {
			if (i > 0) {//如果按下退格并且光标不在0处，i--并将字符用空格代替，实现删除操作
				i--;
				arr[i] = ' ';
				printf("\b \b");//删除控制台上的一个*，提示用户删除删除了一个字符
			}
		}
	}
	arr[i] = '\0';//字符串截止
}

void login(int x, int y) {
	//账号
	gotoxy(x, y);
	string account,password;
	cin >> account;
	//密码
	gotoxy(x, y+4);
	char arr[30];
	input_k(arr);
	password = arr;
	currentmove(0, 7);
};