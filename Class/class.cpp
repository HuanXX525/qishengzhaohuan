#include "class.h"
#include"console_ctrl.h"
#include<iostream>
#include"color.h"
//护盾类
void Shield::setelement(Element element){
	this->element = element;
}
void Shield::setnum(short num) {
	shieldnum = num;
}
Element Shield::getelement(void) {
	return element;
}
short Shield::getnum(void) {
	return shieldnum;
}
//攻击类
short Attack::getattacknum(void){
	return attacknum;
}
Element Attack::getelement(void) {
	return element;
}
//元素类
short Element::getintense(void) {
	return intense;
}
short Element::gettype(void) {
	return type;
}
void Element::setintense(short intense) {
	this->intense = intense;
}
void Element::settype(short type) {
	this->type = type;
}
//食物类
void FoodCard::eat(Character c) {
	c.changehp(this->hpincreasement);
	c.setfoodeffect(increasetype, attackincreasement, time);
}
//攻击信息类
short AttackInfo::getattacknum(void) {
	return attacknum;
}
Element AttackInfo::getelement(void) {
	return element;
}
//武器类
void Weapon::ability(Character c) {
	c.setfoodeffect(0, attackincrease1, 0);
	c.setfoodeffect(1, attackincrease1, 0);
	c.setfoodeffect(2, attackincrease1, 0);
}
//食物效果类
void FoodEffect::setincrease(short type, short increase) {
	this->increase[type] = increase;
}
void FoodEffect::settime(short type, short time) {
	this->time[type] = time;
}
short* FoodEffect::getincrease(void) {
	return increase;
}
short* FoodEffect::gettime(void) {
	return time;
}
//角色类
//AttackInfo Character::attack(short type) {
//	switch (type) {
//	case 1:
//	case 2:
//	case 3:
//	}
//}
void Character::attacked(AttackInfo info) {
	changehp(info.getattacknum());
	Element e = getelement();
	short status = e.getintense() - info.getelement().getintense();
	e.setintense(abs(status));//强度就是做差的绝对值
	if (!status) {//刚好抵消无附着
		e.settype(0);
		changelement(e);
	}
	else if (status < 0) {//新来的大，类型改为新来的
		e.settype(info.getelement().getintense());
		changelement(e);
	}
}
short Character::gethp(void) {
	return hitpoint;
}
Shield Character::getshield(void) {
	return shield;
}
Items Character::getitemscard(void) {
	return itemscard;
}
Weapon Character::getweapon(void) {
	return weaponcard;
}
void Character::changehp(short increase) {
	hitpoint += increase;
}
FoodEffect Character::getfoodeffect(void) {
	return foodeffect;
}
void Character::setfoodeffect(short type, short num, short time) {
	foodeffect.setincrease(type, num);
	foodeffect.settime(type, time);
}
void Character::changeshield(short increase,AttackInfo info) {//!!!!!!!
	if (!getshield().getnum()) {
		shield.setnum(increase);
		shield.setnum(-info.getattacknum());
		if (getshield().getnum() < 0) {
			getshield().setnum(0);
			//Element e = { 0,0 };
			//getshield().setelement(e);
		}
	}
	
}
void Character::changelement(Element element) {
	elementattach = element;
}
Element Character::getelement(void) {
	return elementattach;
}
string Character::getname(void) {
	return name;
}
//框架类
void Box::print()
{
	if (!active) {
		gotoxy(x, y);
		for (short i = 0; i < width; i++)
			std::cout << '_';
		cout << endl;
		for (short i = 0; i < height - 2; i++) {
			gotoxy(x, y + i + 1);
			cout << '|';
			currentmove(width - 2, 0);
			cout << '|'<<endl;
		}
		gotoxy(x, y + height - 1);
		for (short i = 0; i < width; i++)
			std::cout << '-';
		cout << endl;
	}else{//放大加背景
		gotoxy(x-1, y-1);
		cout << BG(100, 200, 255);
		for (short i = 0; i < width+2; i++)
			std::cout << '_';
		cout << endl;
		for (short i = 0; i < height; i++) {
			gotoxy(x-1, y + i );
			cout << '|';
			currentmove(width, 0);
			cout << '|' << endl;
		}
		gotoxy(x-1, y + height);
		for (short i = 0; i < width+2; i++)
			std::cout << '-';
		cout << endl<<DEFAULT;
	}
}
void Box::toactive() {
	active = 1;
}
void Box::unactive() {
	active = 0;
}
Box::Box(short a, short b, short c, short d) :x(a), y(b), width(c), height(d){
}
