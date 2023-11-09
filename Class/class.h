#pragma once
#include <string>
using namespace std;
enum ELEMENT { null, wind, rock, thunder, grass, water, fire, ice };//������Ԫ�ص�ö������

class Character;
class Box {//��λ�ã���С���Ƿ񱻼���
private:
	bool active=0;
public:
	short x;
	short y;
	short width;
	short height;
	Box(short a, short b, short c, short d);
	void print();//��ӡ���
	void toactive();
	void unactive();
};

class Element {//Ԫ���ࣻԪ�����ͣ�Ԫ��ǿ��
private:
	short intense;//Ԫ��ǿ��
	short type;//ͨ��ö�ٻ�ȡ����
public:
	short getintense(void);//��ȡԪ��ǿ��
	short gettype(void);//��ȡԪ������
	void setintense(short intense);//����ǿ��
	void settype(short type);//��������
};

class Attack {//�����ࣻ������������
private:
	short attacknum;//������
	Element element;//��������
public:
	short getattacknum(void);//��ȡ������
	Element getelement(void);//��ȡ��������
};

class Items {//��Ʒ�ࣻ

};

class FoodCard {//ʳ���ࣻѪ����������������
private:
	short increasetype;//�����ĸ�������
	short hpincreasement;//Ѫ������
	short attackincreasement;//��������
	short time;//����ʱ��
public:
	void eat(Character c);//ʹ��Ч��ʵ��
};


class Shield {//�����ࣻ�������ͣ�����ֵ
private:
	Element element;//��������
	short shieldnum = 0;//������
public:
	void setelement(Element element);//���û�������
	Element getelement(void);//��ȡ����
	short getnum(void);//��ȡ��ֵ
	void setnum(short num);//���û�����
};

class AttackInfo {//������Ϣ�ࣻ������ֵ����������
private:
	short attacknum;//��ɵĹ���
	Element element;//�˺���Ԫ������
public:
	short getattacknum(void);//��ȡ��ɵ��˺�
	Element getelement(void);//��ȡ�˺���Ԫ������
};

class Weapon {//�������ࣻ�˺�����
protected:
	short attackincrease1;//��ͨ����
public:
	void ability(Character c);//�������ӽ�ɫ������
};

class FoodEffect {//ʳ��Ч���ࣻ��������������ʱ��
private:
	short increase[3];//����
	short time[3];//����ʱ��
public:
	void setincrease(short type, short increase);//��������
	void settime(short type, short time);//���ó���ʱ��
	short* getincrease(void);//��ȡ����
	short* gettime(void);//��ȡʱ��
};

class Character {//��ɫ�ࣻѪ��������������������Ʒ����ͨ������Ԫ��ս����Ԫ�ر�����Ԫ�ظ��ţ�ʳ��״̬
private:
	string name;//����
	short hitpoint = 10;//Ѫ��
	Shield shield;//����
	Weapon weaponcard;//������
	Items itemscard;//��Ʒ��
	//short itemsnum;//��Ʒ��������
	Attack attack1;//��ͨ����
	Attack attack2;//Ԫ��ս��
	Attack attack3;//Ԫ�ر���
	Element elementattach;//Ԫ�ظ���
	bool eatfood = 0;//�Ƿ�ʳ��ʳ��
	FoodEffect foodeffect;//ʳ��Ч����Ŀǰ�Ǽӹ�
public:
	virtual AttackInfo attack(short type);//����
	void attacked(AttackInfo info);//������
	short gethp(void);//��ȡ��ǰѪ��
	Shield getshield(void);//��ȡ������Ϣ
	Items getitemscard(void);//��ȡ��ɫ����Ʒ��
	Weapon getweapon(void);//��ȡ������Ϣ
	void changehp(short increase);//�ı�Ѫ��
	FoodEffect getfoodeffect(void);//��ȡʳ���������ʽ����Ĺ������ӳ�Ч��
	void setfoodeffect(short type, short num,short time);//���Ĺ������ӳ�
	void changeshield(short increase,AttackInfo info);//�ı令����
	void changelement(Element element);//�ı�Ԫ�ظ���
	Element getelement(void);//��ȡԪ�ظ���
	string getname(void);//��ȡԪ�ظ���
};

class Position {//λ���ࣻx���꣬y����
private:
	short x;
	short y;
public:
	short getx(void);//��ȡx����
	short gety(void);//��ȡy����
};

class UI {//UI�ࣻUI���ƣ�UIλ�ã���ʶ�ؼ��֣���ϸ����
private:
	string name;//UI��
	Position positon;//λ��
	short key;//�ؼ��ֱ�ʶ���ĸ�
	string info;//����
public:
	string getname(void);
	Position getposition(void);
	short getkey(void);
	string getinfo(void);
};