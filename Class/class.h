#pragma once
#include <string>
using namespace std;
enum ELEMENT { null, wind, rock, thunder, grass, water, fire, ice };//定义七元素的枚举类型

class Character;
class Box {//框；位置，大小，是否被激活
private:
	bool active=0;
public:
	short x;
	short y;
	short width;
	short height;
	Box(short a, short b, short c, short d);
	void print();//打印框架
	void toactive();
	void unactive();
};

class Element {//元素类；元素类型，元素强度
private:
	short intense;//元素强度
	short type;//通过枚举获取种类
public:
	short getintense(void);//获取元素强度
	short gettype(void);//获取元素类型
	void setintense(short intense);//设置强度
	void settype(short type);//设置类型
};

class Attack {//攻击类；攻击力，类型
private:
	short attacknum;//攻击力
	Element element;//攻击类型
public:
	short getattacknum(void);//获取攻击力
	Element getelement(void);//获取攻击类型
};

class Items {//物品类；

};

class FoodCard {//食物类；血量增幅，攻击增幅
private:
	short increasetype;//增加哪个攻击力
	short hpincreasement;//血量增幅
	short attackincreasement;//攻击增幅
	short time;//持续时间
public:
	void eat(Character c);//使用效果实现
};


class Shield {//护盾类；护盾类型，护盾值
private:
	Element element;//护盾类型
	short shieldnum = 0;//护盾量
public:
	void setelement(Element element);//设置护盾类型
	Element getelement(void);//获取类型
	short getnum(void);//获取数值
	void setnum(short num);//设置护盾量
};

class AttackInfo {//攻击信息类；攻击数值，攻击类型
private:
	short attacknum;//造成的攻击
	Element element;//伤害的元素类型
public:
	short getattacknum(void);//获取造成的伤害
	Element getelement(void);//获取伤害的元素类型
};

class Weapon {//武器基类；伤害增幅
protected:
	short attackincrease1;//普通增幅
public:
	void ability(Character c);//用于增加角色攻击力
};

class FoodEffect {//食物效果类；攻击增量，持续时间
private:
	short increase[3];//增量
	short time[3];//持续时间
public:
	void setincrease(short type, short increase);//设置增量
	void settime(short type, short time);//设置持续时间
	short* getincrease(void);//读取增量
	short* gettime(void);//读取时间
};

class Character {//角色类；血量，护盾量，武器，物品，普通攻击，元素战技，元素爆发，元素附着，食用状态
private:
	string name;//姓名
	short hitpoint = 10;//血量
	Shield shield;//护盾
	Weapon weaponcard;//武器卡
	Items itemscard;//物品卡
	//short itemsnum;//物品卡的数量
	Attack attack1;//普通攻击
	Attack attack2;//元素战技
	Attack attack3;//元素爆发
	Element elementattach;//元素附着
	bool eatfood = 0;//是否食用食物
	FoodEffect foodeffect;//食物效果，目前是加攻
public:
	virtual AttackInfo attack(short type);//攻击
	void attacked(AttackInfo info);//被攻击
	short gethp(void);//获取当前血量
	Shield getshield(void);//获取护盾信息
	Items getitemscard(void);//获取角色的物品卡
	Weapon getweapon(void);//获取武器信息
	void changehp(short increase);//改变血量
	FoodEffect getfoodeffect(void);//获取食物或其他方式引起的攻击力加成效果
	void setfoodeffect(short type, short num,short time);//更改攻击力加成
	void changeshield(short increase,AttackInfo info);//改变护盾量
	void changelement(Element element);//改变元素附着
	Element getelement(void);//获取元素附着
	string getname(void);//获取元素附着
};

class Position {//位置类；x坐标，y坐标
private:
	short x;
	short y;
public:
	short getx(void);//获取x坐标
	short gety(void);//获取y坐标
};

class UI {//UI类；UI名称，UI位置，标识关键字，详细描述
private:
	string name;//UI名
	Position positon;//位置
	short key;//关键字标识是哪个
	string info;//描述
public:
	string getname(void);
	Position getposition(void);
	short getkey(void);
	string getinfo(void);
};