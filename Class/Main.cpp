#include<iostream>
#include"color.h"
#include<iomanip>
#include"start.h"
#include"classnew.h"
#include"console_ctrl.h"
using namespace std;
void note() {
	tomiddle(8);
	cout << "按下任意键继续";
	getch();
}
int main(void) {
	//system("cls");
	welcome();
	printlogo();
	note();
	system("cls");
	UIList<Character> uilist1;
	uilist1.list[0].ui = new nuoaier;
	uilist1.list[1].ui = new funingna;
	uilist1.list[2].ui = new naxida;
	uilist1.list[3].ui = new xiaogong;
	uilist1.list[4].ui = new babala;
	uilist1.list[5].ui = new bannite;
	Player p1(0);
	Player p2(1);
	//玩家选择
	uilist1.uisel(3,p1);
	system("cls");
	p1.showchara();
	note();
	system("cls");
	uilist1.uisel(3, p2);
	system("cls");
	p2.showchara();
	note();
	system("cls");
	//玩家选择

}