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
	position p;
	getxy(p);
	for (int j = 0; j < 5; j++) {
		gotoxy(p.x, j);
		getline(infile, line);
		cout << ROCK << line;
	}
	getxy(p);
	for (int j = 0; j < 5; j++) {
		gotoxy(p.x, j);
		getline(infile, line);
		cout << FIRE << line;
	}
	getxy(p);
	for (int j = 0; j < 5; j++) {
		gotoxy(p.x, j);
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
	position p;
	getxy(p);
	for (int j = 0; getline(infile, line); j++) {
		gotoxy(p.x, j+p.y);
		//getline(infile, line);
		cout  << line;
	}
	infile.close();
	//以上为输出UI
	account(p.x + 8, p.y+4);//账户输入框的位置
	//gotoxy(x, y + 4);//密码输入在账户下面4格
	char arr[21];//最长20位密码
	input_k(arr,p.x+8,p.y+8);
	string password;
	password = arr;
	currentmove(0, 7);
	cout << password;
}

void input_k(char arr[],short x,short y) {
	gotoxy(x, y);
	int i = 0;
	char c;
	while ((c = getch()) != '\r') {//getch不需要回车键即可载入字符，回车代表密码输入结束退出循环
		if (c != '\b'&&i<20) {///b用于回退显示的*，没有按退格表示输入了一个字符，输出*提示用户，并将字符存入数组
			printf("*");
			arr[i++] = c;
		}
		else if(i<20){
			if (i > 0) {//如果按下退格并且光标不在0处，i--并将字符用空格代替，实现删除操作
				i--;
				arr[i] = ' ';
				printf("\b \b");//删除控制台上的一个*，提示用户删除删除了一个字符
			}
		}
		else {//密码超过20位就清空重新输入
			currentmove(0, 3);
			string str = "密码不能超过20位";
			tomiddle((short)str.length());
			cout << RED << str << DEFAULT;
			i = 0;
			gotoxy(x,y);
			for (int j = 0; j < 20; j++)
				printf(" ");
			gotoxy(x, y);
		}
	}
	arr[i] = '\0';//字符串截止
}

void account(short x, short y) {
	//账号
	gotoxy(x, y);
	string account;
	cin >> account;
}
void enroll(short x, short y){
	gotoxy(x, y);
	string account, password;
	cin >> account;
	//密码
	gotoxy(x, y + 4);
	char arr[30];
	input_k(arr,x,y+4);
	password = arr;
	currentmove(0, 7);
};
