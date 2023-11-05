/********************************************************************************
* @File name:login.c
* @Author:HXX
* @Version: 1.6
* @Date: 2023-05-10
* @Description: 程序的登录入口，注册入口，用login_register(char l_account[])函数调用，返回登录的账号。
* @Function: 区分相同账号的注册，注册时二次验证密码，密码输入时隐藏密码，账号密码存储加密，多次输入密码错误短时间冻结。
********************************************************************************/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
/*格式化数组函数，将账号密码临时存储数组全部格式化为' '*/
void ori(char a[]) { 
	for (int i = 0; i < 20; i++) {
		a[i] = ' ';
	}
	a[20] = '\0';//字符串结束标志
}
/*数组加密函数，通过操作ascll码对账号和密码进行简单的加密操作*/
void encrypt(char account[]) {
	int i = 0, n = 0, j = 0;
	for (i = 0;i < 20;) {
		n = (int)sqrt((i + 33) * i * 5);
		if (n > 32 && n < 127) {//保证ascll码在可见字符范围内
			account[i] = account[i] + n;
			i++;
		}
		else {
			for (j = 0;n > 127;j++)
				n = n - 126 + 32;
			for (j = 0;n < 32;j++)
				n = 32 * 2 - n;
			account[i] = account[i] + n;
			i++;
		}
	}
}
/*简单的解密函数，对加密进行逆运算来解密*/
void decode(char account[]) {
	int i = 0, n = 0, j = 0;
	for (i = 0;i < 20;) {
		n = (int)sqrt((i + 33) * i * 5);
		if (n > 32 && n < 127) {
			account[i] = account[i] - n;
			i++;
		}
		else {
			for (j = 0;n > 127;j++)
				n = n - 126 + 32;
			for (j = 0;n < 32;j++)
				n = 32 * 2 - n;
			account[i] = account[i] - n;
			i++;
		}
	}
}
/*用于输入第一次密码的函数，要实现输入时密码用*替代，以保证隐私，传入密码数组的地址*/
void input_k(char arr[]) {
	int i = 0;
	char c;
	while ((c = getch()) != '\r') {//getch不需要回车键即可载入字符，回车代表密码输入结束退出循环
		if (c != '\b') {///b用于回退显示的*，没有按退格表示输入了一个字符，输出*提示用户，并将字符存入数组
			printf("*");
			arr[i++] = c;
		}
		else {
			if (i > 0) {//如果按下退格并且光标不在0处，i--并将字符用空格代替，实现删除操作
				i--;
				arr[i] = ' '; 
				printf("\b \b");//删除控制台上的一个*，提示用户删除删除了一个字符
			}
		}
	}
}
/*账号输入函数，传入账号数组的地址*/
void input_a(char a[]) { 
	int i = 0;
	char c;
	while ((c = getch()) != '\r') {//getch不需要回车键即可载入字符，回车代表密码输入结束退出循环
		if (c != '\b') {///b用于回退显示的字符，没有按退格表示输入了一个字符，输出相应的字符提示用户，并将字符存入数组
			printf("%c", c); 
			a[i++] = c;
		}
		else {
			if (i > 0) {//如果按下退格并且光标不在0处，i--并将字符用格式化的空格代替，实现删除操作
				i--;
				a[i] = ' '; 
				printf("\b \b");//删除控制台上的一个字符，提示用户删除成功
			}
		}
	}
}
/*判断两次输入的密码是否相同的函数，传入两个要比较的数组的地址*/
void compare_k(char a[], char b[]) {
	void input_k1(char a[], char b[]);
	int i = 0;
	for (i = 0; a[i] != '\0'; i++) {//循环条件，未到达数组末尾
		if (a[i] != b[i]) {//如果有一个不一样就代表第一次和第二次输入的不同，提示用户
			system("cls");
			printf("\n--------------------------------------------------");printf("\n");
			printf("|                                                |");printf("\n");
			printf("|               第二次输入密码错误               |");printf("\n");
			printf("|              请重新输入第二次密码：            |");printf("\n");
			printf("|                                                |");printf("\n");
			printf("--------------------------------------------------\n");
			printf("密码：");
			input_k1(a, b);//输入错误重新输入第二次密码，该函数里面套用了比较函数
		}
	}
}
/*用于输入第二次密码的函数，模式同第一次输入密码函数*/
void input_k1(char a[], char b[]) {
	int i = 0;
	ori(b);
	char c;
	while ((c = getch()) != '\r') {
		if (c != '\b') {
			printf("*");
			b[i++] = c;
		}
		else {
			if (i > 0) {
				i--;
				b[i] = ' '; 
				printf("\b \b");
			}
		}
	}
	encrypt(b);//因为第一次输入的密码已经被加密，要比较的话需要再次加密
	compare_k(a, b);//比较密码是否相同
}
/*注册函数，用于不存在的账户的注册*/
void Register() {
	FILE* fp, * tem_fp; //创建文件指针fp用于对注册账户文件进行追加
	//fp = fopen("./account.txt", "a");
	//fclose(fp);
	system("cls");
	printf("--------------------------------------------------");printf("\n");
	printf("|                                                |");printf("\n");
	printf("|                 您正在注册账户                 |");printf("\n");
	printf("|             请输入小于20位的账号：             |");printf("\n");
	printf("|                                                |");printf("\n");
	printf("--------------------------------------------------\n");
	int count = 0, i = 0; //用于账号比较
	/*分别表示第二次输入的密码，第一次输入的密码，输入的账号，从文件中读取的账号*/
	char key1[21] = { '\0' }, key[21] = { '\0' }, account[21] = { '\0' }, r_account[21] = { '\0' };
	/*格式化数组*/
	ori(key);
	ori(key1);
	//ori(account);
	ori(r_account);
change_k://第二次密码输入错误重新输入的返回点
	printf("账号：");
	ori(account);//每次再次输入账号都初始化数组

	input_a(account);//输入并记录账号

	encrypt(account);//加密账号
	tem_fp = fp = fopen("./account.txt", "r");//只读方式打开账户文件
	/*比较输入的账号是否已经注册*/
	while (fgetc(tem_fp) != EOF) {//比较后光标前移
		count = 0;
		fseek(tem_fp, -1, 1);//将比较后光标前移的恢复
		fgets(r_account, 21, tem_fp);//读取已有帐号
		for (i = 0; i < 20; i++) {//将输入账号与已有帐号做对比
			if (r_account[i] != account[i]) {//如果有不同的地方count就不等于0
				count++;
				break;
			}
		}
		if (count == 0) {//count等于0说明有相同的账号，提示已被注册
			system("cls");
			decode(account);
			printf("账号：%s", account);
			encrypt(account);
			printf("\n--------------------------------------------------");printf("\n");
			printf("|                                                |");printf("\n");
			printf("|                  账号验证失败                  |");printf("\n");
			printf("|            该账号已被注册请重新输入            |");printf("\n");
			printf("|                                                |");printf("\n");
			printf("--------------------------------------------------\n");
			goto change_k;//返回并重置光标
		}
		else
			fseek(tem_fp, 20, 1);//如果不同查找下一个是否相同
	}
	fclose(fp);//如果是新账号就关闭文件进入设置密码阶段
	system("cls");
	decode(account);
	printf("账号：%s", account);//提示用户输入的账号是什么
	encrypt(account);
	printf("\n--------------------------------------------------");printf("\n");
	printf("|                                                |");printf("\n");
	printf("|                  账号验证成功                  |");printf("\n");
	printf("|             请输入小于20位的密码：             |");printf("\n");
	printf("|                                                |");printf("\n");
	printf("--------------------------------------------------\n");
	printf("密码：");

	input_k(key);//第一次输入密码

	encrypt(key);
	printf("\n--------------------------------------------------");
	printf("\n请确认密码：");

	input_k1(key, key1);//包含判断函数//第二次输入密码

	system("cls");
	system("color 02");
	printf("\n--------------------------------------------------");printf("\n");
	printf("|                                                |");printf("\n");
	printf("|                   注册成功！                   |");printf("\n");
	printf("|               按下任意键前往登录               |");printf("\n");
	printf("|                                                |");printf("\n");
	printf("--------------------------------------------------\n");
	system("pause");
	system("cls");
	system("color 0F");
	fp = fopen("./account.txt", "a");//打开账户文件
	fputs(account, fp);//将账号密码写入文件account.txt
	fputs(key, fp);
	fclose(fp);//关闭文件并保存
}
/*登录函数，比较密码是否对应，是否冻结*/
int login(char chin_a[]) {
	time_t o_time = 0;//冻结初始时间
	char account[21], key[21], r_account[21], r_key[21];
	int count = 0, i = 0, count1 = 5, x = 0;
	ori(r_account);
	ori(r_key);
change_a:
	system("cls");
	if (x) {
		Register();
	}
	printf("\n--------------------------------------------------");printf("\n");
	printf("|                                                |");printf("\n");
	printf("|                   您正在登录                   |");printf("\n");
	printf("|                   请输入账号：                 |");printf("\n");
	printf("|                                                |");printf("\n");
	printf("--------------------------------------------------\n");
	printf("账号：");
	ori(account);//每次输入前都初始化数组

	input_a(account);//输入自己的账号

	encrypt(account);//加密账号
	FILE* fp, * tem_fp; //创建文件指针
	fp = fopen("./account.txt", "a");//初始化文件
	fclose(fp);
	tem_fp = fp = fopen("./account.txt", "r");
	count = 1;

	while (fgetc(tem_fp) != EOF) {
		count = 0;
		fseek(tem_fp, -1, 1);//将比较的光标前移恢复
		fgets(r_account, 21, tem_fp);//读取账号列表的账号
		for (int i = 0; i < 20; i++) {//比较是否相同
			if (r_account[i] != account[i]) {
				count++;
				break;
			}
		}

		if (count == 0) {//对应，继续输入密码
			time_t timer;
			FILE* freezeacc = fopen("freezeaccount.txt", "r");
			while (fgetc(freezeacc) != EOF) {
				count = 0;
				fseek(freezeacc, -1, 1);
				fgets(r_account, 21, freezeacc);
				for (int i = 0; i < 20; i++) {//比较是否相同
					if (r_account[i] != account[i]) {
						count++;
						break;
					}
				}
				if (count == 0)//匹配上了
				{
					char num[11];
					time(&timer);
					fseek(freezeacc, 1, 1);
					fgets(num, 11, freezeacc);
					for (i = 0;i < 10;i++) {
						o_time += (int)(num[i] - 48) * (int)pow(10, 10 - i - 1);
					}
					if ((timer - o_time) < 300) {
						printf("\n\n该账号已被冻结，还剩%llds\n\n", 300 - timer + o_time);
						exit(0);
					}
					else {
						break;
					}
				}
				else
					fseek(freezeacc, 1, 1);
				while (fgetc(freezeacc) != '|')
					if (fgetc(freezeacc) == EOF) {
						count = 0;
						break;
					}
			}
		count = 0;
			break;
		}
		else//不对应，比较下一个
			fseek(tem_fp, 20, 1);
	}
	if (count != 0) {//全比较完没有对应的
		system("cls");
		printf("\n--------------------------------------------------");printf("\n");
		printf("|                                                |");printf("\n");
		printf("|            没有此账号，是否注册账号？          |");printf("\n");
		printf("|            1）注册    0）重新输入账号          |");printf("\n");
		printf("|                                                |");printf("\n");
		printf("--------------------------------------------------\n");
		printf("请输入数字：");
		scanf("%d", &x);
		goto change_a;//返回重新输入，并重置光标
	}
	decode(account);//以下已经解密
	printf("\n--------------------------------------------------\n");
change_k:
	printf("密码：");
	ori(key);//每次输入前都初始化数组

	input_k(key);//对应账号输入密码

	encrypt(key);

	fgets(r_key, 21, tem_fp);//读取真实密码
	fseek(tem_fp, -20, 1);//恢复光标

	count = 0;
	for (i = 0; i < 20; i++) {//比较输入的与真实的
		if (r_key[i] != key[i]) {
			count++;
			break;
		}
	}

	if (count == 0) {//count为0代表没有不同的
		system("color 0F");
		printf("\n登录成功！");
		i = 0;
		while ((int)account[i] != 32 && i < 20) {
			chin_a[i] = account[i];
			i++;
		}
	}

	else {//密码错误则
		count1--;//剩余次数减一
		if (count1 == 0) {
			FILE* fp1 = fopen("freezeaccount.txt", "a");
			time(&o_time);
			system("cls");
			printf("账号已被冻结，5分钟内无法登录\n\n\n");
			encrypt(account);
			FILE* freezeacc = fopen("freezeaccount.txt", "r+");
			rewind(freezeacc);
			while (fgetc(freezeacc) != EOF) {
				count = 0;
				//fgets(r_account, 21, tem_fp);//读取账号列表的账号
				fseek(freezeacc, -1, 1);
				fgets(r_account, 21, freezeacc);
				for (int i = 0; i < 20; i++) {//比较是否相同
					if (r_account[i] != account[i]) {
						count++;

						break;
					}
				}
				if (count == 0)//匹配上了
				{
					fseek(freezeacc, 1, 1);
					fprintf(freezeacc,"%lld|",o_time);
					break;
				}
				else
					while (fgetc(freezeacc) != '|')
						if (fgetc(freezeacc) == EOF) {
							//count = 0;
							break;
						};
			}
			if (count != 0) {
				fprintf(fp1, "%s|%lld|", account, o_time);
				system("color 04");
			}
			exit(0);//没有次数就退出函数，进一步退出主函数
		}
		system("cls");
		printf("账号：%s", account);
		printf("\n--------------------------------------------------");printf("\n");
		printf("|                                                |");printf("\n");
		if (count1 < 4) {//剩余次数
			system("color 04");
			printf("|                您还有%d次机会！                 |\n", count1);
		}
		printf("|             密码错误！请重新输入：             |");printf("\n");
		printf("|                                                |");printf("\n");
		printf("--------------------------------------------------\n");
		goto change_k;
	}
	fclose(fp);//关闭文件
	return 0;//关闭登录函数继续操作
}
/*zhuhanshu*/
void login_register(char l_account[]) {
	ori(l_account);
return1:
	system("cls");
	printf("--------------------------------------------------");printf("\n");
	printf("|                                                |");printf("\n");
	printf("|                 您是否拥有账户                 |");printf("\n");
	printf("|                  0)有  1)没有                  |");printf("\n");
	printf("|                                                |");printf("\n");
	printf("--------------------------------------------------\n");
	int x = 1; //是否有账号的选择
	printf("请输入数字：");
	scanf("%d", &x);
	if (x) {//没有，注册
		Register();
		login(l_account);
	}
	else {//有，登录
		if (login(l_account))
			goto return1;//密码持续错误退出
	}
}

/*char num[12];
for (i = 0;i < 10;i++) {
	int n = o_time / (int)pow(10, 9 - i) % 10 + 48;
	num[i] = n;
	char ch = n;
	num[i] = ch;
}
num[10] = '|';
num[11] = '\0';*/