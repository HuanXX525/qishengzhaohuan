#include "class.h"
//������
void Shield::setelement(Element element){
	this->element = element;
}
void Shield::setnum(short num) {
	shieldnum = num;
}
//������
short Attack::getattacknum(void){
	return attacknum;
}
Element Attack::getelement(void) {
	return element;
}
//Ԫ����
short Element::getintense(void) {
	return intense;
}
short Element::gettype(void) {
	return type;
}
//ʳ����
void FoodCard::eat(Character c) {
	c.changehp(this->hpincreasement);
	c.setfoodeffect(increasetype, attackincreasement, time);
}
//������Ϣ��
short AttackInfo::getattacknum(void) {
	return attacknum;
}
Element AttackInfo::getelement(void) {
	return element;
}
//������
void Weapon::ability(Character c) {
	c.setfoodeffect(0, attackincrease1, 0);
	c.setfoodeffect(1, attackincrease1, 0);
	c.setfoodeffect(2, attackincrease1, 0);
}
//��ɫ��
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
	e.setintense(abs(status));//ǿ�Ⱦ�������ľ���ֵ
	if (!status) {//�պõ����޸���
		e.settype(0);
		changelement(e);
	}
	else if (status < 0) {//�����Ĵ����͸�Ϊ������
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
