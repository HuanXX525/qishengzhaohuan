#include "start.h"
#include"console_ctrl.h"
#include<iostream>
#include<conio.h>
using namespace std;
void welcome(void)
{
	string str = "�ڿ�ʼ��Ϸ֮ǰ����������Ĵ��ڴ�С";
	int i = str.length();
	tomiddle(i);
	cout << "\033[30;44m" << str << "\033[0m" << endl;

	string str1 = "�����������ʼ";
	i = str1.length();
	tomiddle(i);
	cout << str1 << endl;

	char ch = _getch();//�ȴ����������
	system("cls");
}
