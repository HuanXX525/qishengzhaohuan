#pragma once
#pragma once
#include <string>
#include"console_ctrl.h"
#include<iomanip>
#include"color.h"
#include<conio.h>
#include<string>
#include<iostream>
using namespace std;
//��ɫ����
#define CHARNUM 6
//������Ԫ�ص�ö������
enum ELEMENT { null, wind, rock, thunder, grass, water, fire, ice };
//��ɫ��
class Character {//��ɫ�ࣻѪ��������������������Ʒ����ͨ������Ԫ��ս����Ԫ�ر�����Ԫ�ظ��ţ�ʳ��״̬
protected:
	string name;//����
	short hitpoint;//Ѫ��
	short shield;//����
	short attack;
	short element;//Ԫ�ظ���
	short elementattach;//Ԫ�ظ���
	bool eatfood;//�Ƿ�ʳ��ʳ��
	string info;
public:
	string getname();
	void printele();
	//string gethp();
	//string getshield();
	//string getattack();
	//string getelement();
	//string getelementa();
	//string geteatfood();
	string getinfo();
};
void Character::printele() {
	switch (element) {
	case 1:
		cout << WIND1("��ɫ���ԣ���") << endl; break;
			case 2:
		cout << ROCK1("��ɫ���ԣ���") << endl; break;
			case 3:
		cout << THUNDER1("��ɫ���ԣ���") << endl; break;
			case 4:
		cout << GRASS1("��ɫ���ԣ���") << endl; break;
			case 5:
		cout << WATER1("��ɫ���ԣ�ˮ") << endl; break;
			case 6:
		cout << FIRE1("��ɫ���ԣ���") << endl; break;
			case 7:
		cout << ICE1("��ɫ���ԣ���") << endl; break;
	}
}
string Character::getname() {
	return name;
}
string Character::getinfo() {
	return info;
}
//ŵ����
class nuoaier :public Character {
public:
	nuoaier();
};
nuoaier::nuoaier() {
	name = "ŵ����";
	hitpoint = 10;
	shield = 0;
	attack = 3;
	element = rock;
	info = "@��ͨ������ 1 �ң�2 ���⣩����� 2 �������˺���  @Ԫ��ս���� 3 �ң������ 1 ����Ԫ���˺������ɻ�������\
��Ϊ�ҷ���ս��ɫ�ṩ 2 �㻤�ܡ��˻��ܺľ�ǰ���ҷ��ܵ��������˺����롣������ȡ������  @Ԫ�ر����� 4 �ң� 2 ����������� 4 ��\
��Ԫ���˺�������ɫ������ɨ������ɫʹ����ͨ����ʱ���ٻ��� 1 ����Ԫ�ء���ÿ�غ�1�Σ���ɫ��ͨ������ɵ��˺� +2 ����ɵ���\
���˺���Ϊ��Ԫ���˺��������غϣ�2����";
}
//ܽ����
class funingna :public Character {
public:
	funingna();
};
funingna::funingna() {
	name = "ܽ����";
	hitpoint = 10;
	shield = 0;
	attack = 3;
	element = water;
	info = "����ѡ��δʵװ";
}
//������
class bannite :public Character {
public:
	bannite();
};
bannite::bannite() {
	name = "������";
	hitpoint = 10;
	shield = 0;
	attack = 3;
	element = fire;
	info = "@��ͨ������ 1 �� 2 ���⣩����� 2 �������˺���  @Ԫ��ս���� 3 �𣩣���� 3 ���Ԫ���˺���\
  @Ԫ�ر����� 4 �� 2 ����������� 2 ���Ԫ���˺������ɹ��������ҷ���ɫʹ�ü���ʱ������ý�ɫ����ֵ����Ϊ7��\
��ʹ���˺�����+2�����ܽ��������ý�ɫ����ֵ������6�������Ƹý�ɫ2�㡣�����غϣ�2����";
}
//����
class xiaogong :public Character {
public:
	xiaogong();
};
xiaogong::xiaogong() {
	name = "����";
	hitpoint = 10;
	shield = 0;
	attack = 3;
	element = fire;
	info = "@��ͨ������ 1 �� 2 ���⣩����� 2 �������˺���  @Ԫ��ս���� 1 �𣩣�����ɫ����ͥ\
����������������ɫ��ͨ�����˺� +1 ����ɵ������˺���Ϊ��Ԫ���˺������ô����� 2 �������˼��ܲ��������ܣ�\
  @Ԫ�ر����� 3 �� 3 ��������� 3 ���Ԫ���˺�����������⣨����������ҷ���ɫʹ�ü��ܺ���� 1 ���Ԫ���˺��������غϣ� 2 ����";
}
//��л��
class feixieer :public Character {
public:
	feixieer();
};
feixieer::feixieer() {
	name = "��л��";
	hitpoint = 10;
	shield = 0;
	attack = 3;
	element = thunder;
	info = "@��ͨ������ 1 �ף� 2 ���⣩����� 2 �������˺���  @Ԫ��ս���� 3 �ף������ 1 ����Ԫ���˺�\
���ٻ����ȣ������׶Σ���� 1 ���˺������ô�����2����  @\
Ԫ�ر����� 3 ������ 3 �ף������ 4 ����Ԫ���˺��������ез���̨��ɫ��� 2 �㴩͸�˺���";
}
//�����
class naxida :public Character {
public:
	naxida();
};
naxida::naxida() {
	name = "�����";
	hitpoint = 10;
	shield = 0;
	attack = 1;
	element = grass;
	info = "@��ͨ������ 1 �ݣ� 2 ���⣩����� 1 ���Ԫ���˺��� @Ԫ��ս���� 3��5�� �ݣ������ 2 ���Ԫ���˺�����Ŀ���ɫ��������ӡ��\
�ܵ�Ԫ�ط�Ӧ�˺�ʱ���ܵ� 1 �㴩͸�˺��������Ѵ�������ӡ����� 3 ���Ԫ���˺�����ȫ���Աʩ������ӡ\
�� @Ԫ�ر����� 3 �ݣ� 2 ����������� 4 ���Ԫ���˺�������ĦҮ֮��ҷ�����Ԫ�ط�Ӧʱ���˺������ 1 ��";
}
//�Ű���
class babala :public Character {
public:
	babala();
};
babala::babala() {
	name = "�Ű���";
	hitpoint = 10;
	shield = 0;
	attack = 1;
	element = water;
	info = "@��ͨ������ 1 ˮ�� 2 ���⣩����� 1 ��ˮԪ���˺�  @Ԫ��ս���� 3 ˮ������� 1 ��ˮԪ���˺����ٻ�����֮���������׶�ʱ�����ҷ����н�ɫ 1 �㣬�ҷ���ս��ɫ����ˮԪ�أ����� 2 �Σ�  \
@Ԫ�ر����� 3 �������� 3 ˮ���������ҷ����н�ɫ4��";
}


//�����
class Player {
protected:
	bool num;//0�������1��1�������2
	Character** chara;//������ɫ
public:
	Player(bool b);
	int findchara(Character* chara);
	void print();
	void showchara() {//�����ѡ��Ľ�ɫ
		tomiddle(10);
		print();
		cout << "�Ľ�ɫ:" << endl;
		for (int i = 0; i < 3 && chara[i];i++) {
			tomiddle(5);
			cout << chara[i]->getname()<<endl;
		}
	}
};
void Player::print() {
	if (num)
		cout << "Player 2";
	else
		cout << "Player 1";
}
Player::Player(bool b) {
	num = b;
	chara = new Character*[3];
	chara[0] = chara[1] = chara[2] = NULL;
}
int Player::findchara(Character* chara) {//���ý�ɫ�����ص�ʱcount������
	int i = 0;
	for (i = 0; i < 3 && this->chara[i]; i++) {
		//����ͬ�Ľ�ɫ��ɾ��������ֵΪ��
		if (this->chara[i]->getname() == chara->getname()) {
			delete(this->chara[i]);
			this->chara[i] = NULL;
			return -1;
		}
	}
	this->chara[i] = new Character;
	*this->chara[i] = *chara;
	return 1;
}

//UIϵ��
template<class T>
class UI {//UI�ࣻ���ƣ���ӡ֮ǰ��λ�ã�UI��ָ�룬���ԷŲ�ͬ��UI
public:
	position pos;//λ��
	bool active;
	T* ui;
	UI();
};
template<class T>
UI<T>::UI():active(0){}
template<class T>
class UIList {//Ŀǰ�������ѡ��UI����
public:
	UI<T>* list;
	void uisel(int num,Player& player);//���Ƶ�ѡ��
	UIList<T>(){
		list = new UI<T>[CHARNUM];
	}
};
template<class T>
void UIList<T>::uisel(int num,Player& player) {//����ָ��
	//��Ϣ��ֱλ����
	int dd = 3;
	//��ԭ��
	string str1 = "                                                                              ";
	//���ڴ�С
	position p;
	getsize(p);
	//�м�ķָ���
	for (int i = 0; i < p.y-2;i++) {
		tomiddle(4);
		cout << BG(255, 255, 255) << " " <<DEFAULT<< endl;
	}
	//��ӡ�������
	gotoxy(0, 0);
	player.print();
	cout << "�����ѡ�񣬿ո��ȷ�� \nѡ��3λ���ظ�ѡ���ȡ��";
	currentmove(0, 1);
	//ui�����±�
	short mark = 0;
	//����ÿ��������ٸ�
	short linenum = p.x / 20;
	//ѡ��
	char ch = 1;
	//ѡ��Ĵ�ֱ��Сֵ
	position info = {0,0};
	info.x = p.x / 2 + 2;
	info.y = 0;
	//����ѡ���ȡ��ӡλ��
	gotoxy(info.x-2, 0);
	for (int i = 0; i < CHARNUM; i++) {
		if (!(i % linenum) && i)
			gotoxy(info.x-2, i);
		getxy(list[i].pos);
		cout << left << setw(10) << setfill(' ') << list[i].ui->getname();
	}

	int i = 0;
	//���������ֽ���һ�����֣�������������ż��
	int ins = p.x / 4 * 2 - 2-4;
	//UIѡ������
	int count = 0;
	//ѡ��ѭ��ѡ�����˳�
	while (count<num) {
		ch = getch();//��ȡѡ��
		//�ָ�ԭ״
		for (int j = 0; j <=i; j++) {
			gotoxy(0, info.y + j+dd);
			cout << str1.substr(0, ins);
		}
		gotoxy(list[mark].pos.x, list[mark].pos.y);
		if (list[mark].active)
			cout << left << setw(10) << setfill(' ') << BG(70, 130, 180) << list[mark].ui->getname() << DEFAULT;
		else
			cout << left << setw(10) << setfill(' ') << list[mark].ui->getname();
		//ѡ���ѡ��ʹmarkһֱ�ڷ�Χ��
		switch (ch) {
		case UP:
			if (mark - linenum >= 0)
				mark -= linenum;
			break;
		case DOWN:
			if (mark + linenum < CHARNUM)
				mark += linenum;
			break;
		case LEFT:
			if (mark - 1 >= 0)
				mark -= 1;
			break;
		case RIGHT:
			if (mark + 1 < CHARNUM)
				mark += 1;
			break;
		//case '\r':
		case ' ':
			list[mark].active = !list[mark].active;
			count+=player.findchara(list[mark].ui);
		}
		//ѡ����ӡ��ͬ����ɫ
		gotoxy(list[mark].pos.x, list[mark].pos.y);
		cout << left << setw(10) << setfill(' ') << BG(70, 130, 180) << list[mark].ui->getname() << DEFAULT;
		//�����������Ϣ
		string str = list[mark].ui->getinfo();
		int len = str.length();
		int start=0;
		gotoxy(0, dd-1);
		list[mark].ui->printele();
		for (i = 0; i <= len / ins; i++) {
			gotoxy(0, info.y+i+dd);
			cout << str.substr(start,ins);
			start += ins;
		}
	}
	//����ֵ�ָ�
	for (int i = 0; i < CHARNUM; i++)
		list[i].active = 0;
}