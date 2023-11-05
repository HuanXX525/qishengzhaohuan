/********************************************************************************
* @File name:login.c
* @Author:HXX
* @Version: 1.6
* @Date: 2023-05-10
* @Description: ����ĵ�¼��ڣ�ע����ڣ���login_register(char l_account[])�������ã����ص�¼���˺š�
* @Function: ������ͬ�˺ŵ�ע�ᣬע��ʱ������֤���룬��������ʱ�������룬�˺�����洢���ܣ����������������ʱ�䶳�ᡣ
********************************************************************************/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
/*��ʽ�����麯�������˺�������ʱ�洢����ȫ����ʽ��Ϊ' '*/
void ori(char a[]) { 
	for (int i = 0; i < 20; i++) {
		a[i] = ' ';
	}
	a[20] = '\0';//�ַ���������־
}
/*������ܺ�����ͨ������ascll����˺ź�������м򵥵ļ��ܲ���*/
void encrypt(char account[]) {
	int i = 0, n = 0, j = 0;
	for (i = 0;i < 20;) {
		n = (int)sqrt((i + 33) * i * 5);
		if (n > 32 && n < 127) {//��֤ascll���ڿɼ��ַ���Χ��
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
/*�򵥵Ľ��ܺ������Լ��ܽ���������������*/
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
/*���������һ������ĺ�����Ҫʵ������ʱ������*������Ա�֤��˽��������������ĵ�ַ*/
void input_k(char arr[]) {
	int i = 0;
	char c;
	while ((c = getch()) != '\r') {//getch����Ҫ�س������������ַ����س�����������������˳�ѭ��
		if (c != '\b') {///b���ڻ�����ʾ��*��û�а��˸��ʾ������һ���ַ������*��ʾ�û��������ַ���������
			printf("*");
			arr[i++] = c;
		}
		else {
			if (i > 0) {//��������˸��ҹ�겻��0����i--�����ַ��ÿո���棬ʵ��ɾ������
				i--;
				arr[i] = ' '; 
				printf("\b \b");//ɾ������̨�ϵ�һ��*����ʾ�û�ɾ��ɾ����һ���ַ�
			}
		}
	}
}
/*�˺����뺯���������˺�����ĵ�ַ*/
void input_a(char a[]) { 
	int i = 0;
	char c;
	while ((c = getch()) != '\r') {//getch����Ҫ�س������������ַ����س�����������������˳�ѭ��
		if (c != '\b') {///b���ڻ�����ʾ���ַ���û�а��˸��ʾ������һ���ַ��������Ӧ���ַ���ʾ�û��������ַ���������
			printf("%c", c); 
			a[i++] = c;
		}
		else {
			if (i > 0) {//��������˸��ҹ�겻��0����i--�����ַ��ø�ʽ���Ŀո���棬ʵ��ɾ������
				i--;
				a[i] = ' '; 
				printf("\b \b");//ɾ������̨�ϵ�һ���ַ�����ʾ�û�ɾ���ɹ�
			}
		}
	}
}
/*�ж���������������Ƿ���ͬ�ĺ�������������Ҫ�Ƚϵ�����ĵ�ַ*/
void compare_k(char a[], char b[]) {
	void input_k1(char a[], char b[]);
	int i = 0;
	for (i = 0; a[i] != '\0'; i++) {//ѭ��������δ��������ĩβ
		if (a[i] != b[i]) {//�����һ����һ���ʹ����һ�κ͵ڶ�������Ĳ�ͬ����ʾ�û�
			system("cls");
			printf("\n--------------------------------------------------");printf("\n");
			printf("|                                                |");printf("\n");
			printf("|               �ڶ��������������               |");printf("\n");
			printf("|              ����������ڶ������룺            |");printf("\n");
			printf("|                                                |");printf("\n");
			printf("--------------------------------------------------\n");
			printf("���룺");
			input_k1(a, b);//���������������ڶ������룬�ú������������˱ȽϺ���
		}
	}
}
/*��������ڶ�������ĺ�����ģʽͬ��һ���������뺯��*/
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
	encrypt(b);//��Ϊ��һ������������Ѿ������ܣ�Ҫ�ȽϵĻ���Ҫ�ٴμ���
	compare_k(a, b);//�Ƚ������Ƿ���ͬ
}
/*ע�ắ�������ڲ����ڵ��˻���ע��*/
void Register() {
	FILE* fp, * tem_fp; //�����ļ�ָ��fp���ڶ�ע���˻��ļ�����׷��
	//fp = fopen("./account.txt", "a");
	//fclose(fp);
	system("cls");
	printf("--------------------------------------------------");printf("\n");
	printf("|                                                |");printf("\n");
	printf("|                 ������ע���˻�                 |");printf("\n");
	printf("|             ������С��20λ���˺ţ�             |");printf("\n");
	printf("|                                                |");printf("\n");
	printf("--------------------------------------------------\n");
	int count = 0, i = 0; //�����˺űȽ�
	/*�ֱ��ʾ�ڶ�����������룬��һ����������룬������˺ţ����ļ��ж�ȡ���˺�*/
	char key1[21] = { '\0' }, key[21] = { '\0' }, account[21] = { '\0' }, r_account[21] = { '\0' };
	/*��ʽ������*/
	ori(key);
	ori(key1);
	//ori(account);
	ori(r_account);
change_k://�ڶ����������������������ķ��ص�
	printf("�˺ţ�");
	ori(account);//ÿ���ٴ������˺Ŷ���ʼ������

	input_a(account);//���벢��¼�˺�

	encrypt(account);//�����˺�
	tem_fp = fp = fopen("./account.txt", "r");//ֻ����ʽ���˻��ļ�
	/*�Ƚ�������˺��Ƿ��Ѿ�ע��*/
	while (fgetc(tem_fp) != EOF) {//�ȽϺ���ǰ��
		count = 0;
		fseek(tem_fp, -1, 1);//���ȽϺ���ǰ�ƵĻָ�
		fgets(r_account, 21, tem_fp);//��ȡ�����ʺ�
		for (i = 0; i < 20; i++) {//�������˺��������ʺ����Ա�
			if (r_account[i] != account[i]) {//����в�ͬ�ĵط�count�Ͳ�����0
				count++;
				break;
			}
		}
		if (count == 0) {//count����0˵������ͬ���˺ţ���ʾ�ѱ�ע��
			system("cls");
			decode(account);
			printf("�˺ţ�%s", account);
			encrypt(account);
			printf("\n--------------------------------------------------");printf("\n");
			printf("|                                                |");printf("\n");
			printf("|                  �˺���֤ʧ��                  |");printf("\n");
			printf("|            ���˺��ѱ�ע������������            |");printf("\n");
			printf("|                                                |");printf("\n");
			printf("--------------------------------------------------\n");
			goto change_k;//���ز����ù��
		}
		else
			fseek(tem_fp, 20, 1);//�����ͬ������һ���Ƿ���ͬ
	}
	fclose(fp);//��������˺ž͹ر��ļ�������������׶�
	system("cls");
	decode(account);
	printf("�˺ţ�%s", account);//��ʾ�û�������˺���ʲô
	encrypt(account);
	printf("\n--------------------------------------------------");printf("\n");
	printf("|                                                |");printf("\n");
	printf("|                  �˺���֤�ɹ�                  |");printf("\n");
	printf("|             ������С��20λ�����룺             |");printf("\n");
	printf("|                                                |");printf("\n");
	printf("--------------------------------------------------\n");
	printf("���룺");

	input_k(key);//��һ����������

	encrypt(key);
	printf("\n--------------------------------------------------");
	printf("\n��ȷ�����룺");

	input_k1(key, key1);//�����жϺ���//�ڶ�����������

	system("cls");
	system("color 02");
	printf("\n--------------------------------------------------");printf("\n");
	printf("|                                                |");printf("\n");
	printf("|                   ע��ɹ���                   |");printf("\n");
	printf("|               ���������ǰ����¼               |");printf("\n");
	printf("|                                                |");printf("\n");
	printf("--------------------------------------------------\n");
	system("pause");
	system("cls");
	system("color 0F");
	fp = fopen("./account.txt", "a");//���˻��ļ�
	fputs(account, fp);//���˺�����д���ļ�account.txt
	fputs(key, fp);
	fclose(fp);//�ر��ļ�������
}
/*��¼�������Ƚ������Ƿ��Ӧ���Ƿ񶳽�*/
int login(char chin_a[]) {
	time_t o_time = 0;//�����ʼʱ��
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
	printf("|                   �����ڵ�¼                   |");printf("\n");
	printf("|                   �������˺ţ�                 |");printf("\n");
	printf("|                                                |");printf("\n");
	printf("--------------------------------------------------\n");
	printf("�˺ţ�");
	ori(account);//ÿ������ǰ����ʼ������

	input_a(account);//�����Լ����˺�

	encrypt(account);//�����˺�
	FILE* fp, * tem_fp; //�����ļ�ָ��
	fp = fopen("./account.txt", "a");//��ʼ���ļ�
	fclose(fp);
	tem_fp = fp = fopen("./account.txt", "r");
	count = 1;

	while (fgetc(tem_fp) != EOF) {
		count = 0;
		fseek(tem_fp, -1, 1);//���ȽϵĹ��ǰ�ƻָ�
		fgets(r_account, 21, tem_fp);//��ȡ�˺��б���˺�
		for (int i = 0; i < 20; i++) {//�Ƚ��Ƿ���ͬ
			if (r_account[i] != account[i]) {
				count++;
				break;
			}
		}

		if (count == 0) {//��Ӧ��������������
			time_t timer;
			FILE* freezeacc = fopen("freezeaccount.txt", "r");
			while (fgetc(freezeacc) != EOF) {
				count = 0;
				fseek(freezeacc, -1, 1);
				fgets(r_account, 21, freezeacc);
				for (int i = 0; i < 20; i++) {//�Ƚ��Ƿ���ͬ
					if (r_account[i] != account[i]) {
						count++;
						break;
					}
				}
				if (count == 0)//ƥ������
				{
					char num[11];
					time(&timer);
					fseek(freezeacc, 1, 1);
					fgets(num, 11, freezeacc);
					for (i = 0;i < 10;i++) {
						o_time += (int)(num[i] - 48) * (int)pow(10, 10 - i - 1);
					}
					if ((timer - o_time) < 300) {
						printf("\n\n���˺��ѱ����ᣬ��ʣ%llds\n\n", 300 - timer + o_time);
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
		else//����Ӧ���Ƚ���һ��
			fseek(tem_fp, 20, 1);
	}
	if (count != 0) {//ȫ�Ƚ���û�ж�Ӧ��
		system("cls");
		printf("\n--------------------------------------------------");printf("\n");
		printf("|                                                |");printf("\n");
		printf("|            û�д��˺ţ��Ƿ�ע���˺ţ�          |");printf("\n");
		printf("|            1��ע��    0�����������˺�          |");printf("\n");
		printf("|                                                |");printf("\n");
		printf("--------------------------------------------------\n");
		printf("���������֣�");
		scanf("%d", &x);
		goto change_a;//�����������룬�����ù��
	}
	decode(account);//�����Ѿ�����
	printf("\n--------------------------------------------------\n");
change_k:
	printf("���룺");
	ori(key);//ÿ������ǰ����ʼ������

	input_k(key);//��Ӧ�˺���������

	encrypt(key);

	fgets(r_key, 21, tem_fp);//��ȡ��ʵ����
	fseek(tem_fp, -20, 1);//�ָ����

	count = 0;
	for (i = 0; i < 20; i++) {//�Ƚ����������ʵ��
		if (r_key[i] != key[i]) {
			count++;
			break;
		}
	}

	if (count == 0) {//countΪ0����û�в�ͬ��
		system("color 0F");
		printf("\n��¼�ɹ���");
		i = 0;
		while ((int)account[i] != 32 && i < 20) {
			chin_a[i] = account[i];
			i++;
		}
	}

	else {//���������
		count1--;//ʣ�������һ
		if (count1 == 0) {
			FILE* fp1 = fopen("freezeaccount.txt", "a");
			time(&o_time);
			system("cls");
			printf("�˺��ѱ����ᣬ5�������޷���¼\n\n\n");
			encrypt(account);
			FILE* freezeacc = fopen("freezeaccount.txt", "r+");
			rewind(freezeacc);
			while (fgetc(freezeacc) != EOF) {
				count = 0;
				//fgets(r_account, 21, tem_fp);//��ȡ�˺��б���˺�
				fseek(freezeacc, -1, 1);
				fgets(r_account, 21, freezeacc);
				for (int i = 0; i < 20; i++) {//�Ƚ��Ƿ���ͬ
					if (r_account[i] != account[i]) {
						count++;

						break;
					}
				}
				if (count == 0)//ƥ������
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
			exit(0);//û�д������˳���������һ���˳�������
		}
		system("cls");
		printf("�˺ţ�%s", account);
		printf("\n--------------------------------------------------");printf("\n");
		printf("|                                                |");printf("\n");
		if (count1 < 4) {//ʣ�����
			system("color 04");
			printf("|                ������%d�λ��ᣡ                 |\n", count1);
		}
		printf("|             ����������������룺             |");printf("\n");
		printf("|                                                |");printf("\n");
		printf("--------------------------------------------------\n");
		goto change_k;
	}
	fclose(fp);//�ر��ļ�
	return 0;//�رյ�¼������������
}
/*zhuhanshu*/
void login_register(char l_account[]) {
	ori(l_account);
return1:
	system("cls");
	printf("--------------------------------------------------");printf("\n");
	printf("|                                                |");printf("\n");
	printf("|                 ���Ƿ�ӵ���˻�                 |");printf("\n");
	printf("|                  0)��  1)û��                  |");printf("\n");
	printf("|                                                |");printf("\n");
	printf("--------------------------------------------------\n");
	int x = 1; //�Ƿ����˺ŵ�ѡ��
	printf("���������֣�");
	scanf("%d", &x);
	if (x) {//û�У�ע��
		Register();
		login(l_account);
	}
	else {//�У���¼
		if (login(l_account))
			goto return1;//������������˳�
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