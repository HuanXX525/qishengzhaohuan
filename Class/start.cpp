#include "start.h"
#include"color.h"
#include"console_ctrl.h"
#include<iostream>
#include<conio.h>
#include<fstream>
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

void printlogo(void)//��ӡ��ʥ�ٻ�LOGO
{//���ļ�
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
	for (int j = 0; getline(infile, line); j++) {
		gotoxy(x, j+y);
		//getline(infile, line);
		cout  << line;
	}
	infile.close();
	//����Ϊ���UI
	account(x + 8, y+4);//�˻�������λ��
	//gotoxy(x, y + 4);//�����������˻�����4��
	char arr[21];//�20λ����
	input_k(arr,x+8,y+8);
	string password;
	password = arr;
	currentmove(0, 7);
	cout << password;
}

void input_k(char arr[],short x,short y) {
	gotoxy(x, y);
	int i = 0;
	char c;
	while ((c = getch()) != '\r') {//getch����Ҫ�س������������ַ����س�����������������˳�ѭ��
		if (c != '\b'&&i<20) {///b���ڻ�����ʾ��*��û�а��˸��ʾ������һ���ַ������*��ʾ�û��������ַ���������
			printf("*");
			arr[i++] = c;
		}
		else if(i<20){
			if (i > 0) {//��������˸��ҹ�겻��0����i--�����ַ��ÿո���棬ʵ��ɾ������
				i--;
				arr[i] = ' ';
				printf("\b \b");//ɾ������̨�ϵ�һ��*����ʾ�û�ɾ��ɾ����һ���ַ�
			}
		}
		else {//���볬��20λ�������������
			currentmove(0, 3);
			string str = "���벻�ܳ���20λ";
			tomiddle((short)str.length());
			cout << RED << str << DEFAULT;
			i = 0;
			gotoxy(x,y);
			for (int j = 0; j < 20; j++)
				printf(" ");
			gotoxy(x, y);
		}
	}
	arr[i] = '\0';//�ַ�����ֹ
}

void account(short x, short y) {
	//�˺�
	gotoxy(x, y);
	string account;
	cin >> account;
}
void enroll(short x, short y){
	gotoxy(x, y);
	string account, password;
	cin >> account;
	//����
	gotoxy(x, y + 4);
	char arr[30];
	input_k(arr,x,y+4);
	password = arr;
	currentmove(0, 7);
};
