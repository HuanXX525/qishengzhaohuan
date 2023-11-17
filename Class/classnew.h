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
//角色数量
#define CHARNUM 6
//定义七元素的枚举类型
enum ELEMENT { null, wind, rock, thunder, grass, water, fire, ice };
//角色类
class Character {//角色类；血量，护盾量，武器，物品，普通攻击，元素战技，元素爆发，元素附着，食用状态
protected:
	string name;//姓名
	short hitpoint;//血量
	short shield;//护盾
	short attack;
	short element;//元素附着
	short elementattach;//元素附着
	bool eatfood;//是否食用食物
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
		cout << WIND1("角色属性：风") << endl; break;
			case 2:
		cout << ROCK1("角色属性：岩") << endl; break;
			case 3:
		cout << THUNDER1("角色属性：雷") << endl; break;
			case 4:
		cout << GRASS1("角色属性：草") << endl; break;
			case 5:
		cout << WATER1("角色属性：水") << endl; break;
			case 6:
		cout << FIRE1("角色属性：火") << endl; break;
			case 7:
		cout << ICE1("角色属性：冰") << endl; break;
	}
}
string Character::getname() {
	return name;
}
string Character::getinfo() {
	return info;
}
//诺艾尔
class nuoaier :public Character {
public:
	nuoaier();
};
nuoaier::nuoaier() {
	name = "诺艾尔";
	hitpoint = 10;
	shield = 0;
	attack = 3;
	element = rock;
	info = "@普通攻击（ 1 岩，2 任意）：造成 2 点物理伤害。  @元素战技（ 3 岩）：造成 1 点岩元素伤害，生成护体岩铠\
（为我方出战角色提供 2 点护盾。此护盾耗尽前，我方受到的物理伤害减半。（向上取整））  @元素爆发（ 4 岩， 2 能量）：造成 4 点\
岩元素伤害，本角色附属大扫除（角色使用普通攻击时：少花费 1 个岩元素。（每回合1次）角色普通攻击造成的伤害 +2 ，造成的物\
理伤害变为岩元素伤害。持续回合：2）。";
}
//芙宁娜
class funingna :public Character {
public:
	funingna();
};
funingna::funingna() {
	name = "芙宁娜";
	hitpoint = 10;
	shield = 0;
	attack = 3;
	element = water;
	info = "不能选择未实装";
}
//班尼特
class bannite :public Character {
public:
	bannite();
};
bannite::bannite() {
	name = "班尼特";
	hitpoint = 10;
	shield = 0;
	attack = 3;
	element = fire;
	info = "@普通攻击（ 1 火， 2 任意）：造成 2 点物理伤害。  @元素战技（ 3 火）：造成 3 点火元素伤害。\
  @元素爆发（ 4 火， 2 能量）：造成 2 点火元素伤害，生成鼓舞领域（我方角色使用技能时：如果该角色生命值至少为7，\
则使此伤害额外+2；技能结算后，如果该角色生命值不多于6，则治疗该角色2点。持续回合：2）。";
}
//宵宫
class xiaogong :public Character {
public:
	xiaogong();
};
xiaogong::xiaogong() {
	name = "宵宫";
	hitpoint = 10;
	shield = 0;
	attack = 3;
	element = fire;
	info = "@普通攻击（ 1 火， 2 任意）：造成 2 点物理伤害。  @元素战技（ 1 火）：本角色附属庭\
火焰硝（所附属角色普通攻击伤害 +1 ，造成的物理伤害变为火元素伤害。可用次数： 2 ）。（此技能不产生充能）\
  @元素爆发（ 3 火， 3 能量）造成 3 点火元素伤害，生成琉金火光（宵宫以外的我方角色使用技能后：造成 1 点火元素伤害。持续回合： 2 ）。";
}
//菲谢尔
class feixieer :public Character {
public:
	feixieer();
};
feixieer::feixieer() {
	name = "菲谢尔";
	hitpoint = 10;
	shield = 0;
	attack = 3;
	element = thunder;
	info = "@普通攻击（ 1 雷， 2 任意）：造成 2 点物理伤害。  @元素战技（ 3 雷）：造成 1 点雷元素伤害\
，召唤奥兹（结束阶段：造成 1 点伤害。可用次数：2）。  @\
元素爆发（ 3 能量， 3 雷）：造成 4 点雷元素伤害，对所有敌方后台角色造成 2 点穿透伤害。";
}
//纳西妲
class naxida :public Character {
public:
	naxida();
};
naxida::naxida() {
	name = "纳西妲";
	hitpoint = 10;
	shield = 0;
	attack = 1;
	element = grass;
	info = "@普通攻击（ 1 草， 2 任意）：造成 1 点草元素伤害。 @元素战技（ 3（5） 草）：造成 2 点草元素伤害，对目标角色附属蕴种印（\
受到元素反应伤害时，受到 1 点穿透伤害）；若已存在蕴种印则造成 3 点草元素伤害，对全体成员施加蕴种印\
。 @元素爆发（ 3 草， 2 能量）：造成 4 点草元素伤害，生成摩耶之殿（我方引发元素反应时，伤害额外加 1 ）";
}
//芭芭拉
class babala :public Character {
public:
	babala();
};
babala::babala() {
	name = "芭芭拉";
	hitpoint = 10;
	shield = 0;
	attack = 1;
	element = water;
	info = "@普通攻击（ 1 水， 2 任意）：造成 1 点水元素伤害  @元素战技（ 3 水）：造成 1 点水元素伤害，召唤歌声之环（结束阶段时治疗我方所有角色 1 点，我方出战角色附着水元素，可用 2 次）  \
@元素爆发（ 3 点能量， 3 水）：治疗我方所有角色4点";
}


//玩家类
class Player {
protected:
	bool num;//0代表玩家1，1代表玩家2
	Character** chara;//三个角色
public:
	Player(bool b);
	int findchara(Character* chara);
	void print();
	void showchara() {//输出已选择的角色
		tomiddle(10);
		print();
		cout << "的角色:" << endl;
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
int Player::findchara(Character* chara) {//设置角色，返回的时count的增量
	int i = 0;
	for (i = 0; i < 3 && this->chara[i]; i++) {
		//有相同的角色就删除，并赋值为空
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

//UI系列
template<class T>
class UI {//UI类；名称，打印之前的位置，UI的指针，可以放不同的UI
public:
	position pos;//位置
	bool active;
	T* ui;
	UI();
};
template<class T>
UI<T>::UI():active(0){}
template<class T>
class UIList {//目前设计用来选择UI界面
public:
	UI<T>* list;
	void uisel(int num,Player& player);//卡牌的选择
	UIList<T>(){
		list = new UI<T>[CHARNUM];
	}
};
template<class T>
void UIList<T>::uisel(int num,Player& player) {//返回指针
	//信息垂直位移量
	int dd = 3;
	//复原用
	string str1 = "                                                                              ";
	//窗口大小
	position p;
	getsize(p);
	//中间的分割线
	for (int i = 0; i < p.y-2;i++) {
		tomiddle(4);
		cout << BG(255, 255, 255) << " " <<DEFAULT<< endl;
	}
	//打印玩家名称
	gotoxy(0, 0);
	player.print();
	cout << "方向键选择，空格键确定 \n选择3位，重复选择可取消";
	currentmove(0, 1);
	//ui数组下标
	short mark = 0;
	//设置每行输出多少个
	short linenum = p.x / 20;
	//选项
	char ch = 1;
	//选项的垂直最小值
	position info = {0,0};
	info.x = p.x / 2 + 2;
	info.y = 0;
	//遍历选项获取打印位置
	gotoxy(info.x-2, 0);
	for (int i = 0; i < CHARNUM; i++) {
		if (!(i % linenum) && i)
			gotoxy(info.x-2, i);
		getxy(list[i].pos);
		cout << left << setw(10) << setfill(' ') << list[i].ui->getname();
	}

	int i = 0;
	//增量，两字节是一个汉字，必须让增量是偶数
	int ins = p.x / 4 * 2 - 2-4;
	//UI选择数量
	int count = 0;
	//选择循环选够了退出
	while (count<num) {
		ch = getch();//获取选项
		//恢复原状
		for (int j = 0; j <=i; j++) {
			gotoxy(0, info.y + j+dd);
			cout << str1.substr(0, ins);
		}
		gotoxy(list[mark].pos.x, list[mark].pos.y);
		if (list[mark].active)
			cout << left << setw(10) << setfill(' ') << BG(70, 130, 180) << list[mark].ui->getname() << DEFAULT;
		else
			cout << left << setw(10) << setfill(' ') << list[mark].ui->getname();
		//选项的选择，使mark一直在范围内
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
		//选完后打印不同的颜色
		gotoxy(list[mark].pos.x, list[mark].pos.y);
		cout << left << setw(10) << setfill(' ') << BG(70, 130, 180) << list[mark].ui->getname() << DEFAULT;
		//在左侧侧输出信息
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
	//激活值恢复
	for (int i = 0; i < CHARNUM; i++)
		list[i].active = 0;
}