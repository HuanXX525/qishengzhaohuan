#define COLOR1(msg,r,g,b,bg) "\033[38;2;" #r";" #g";" #b";" #bg"m" msg"\033[0m"//����߼�ǰ��ɫ�ͼ򵥱���ɫ���ָ�Ĭ��
#define COLORS(r,g,b,bg) "\033[5;38;2;" #r";" #g";" #b";" #bg"m"//����߼�ǰ��ɫ�ͼ򵥱���ɫ�����ָ�Ĭ��
#define COLOR(r,g,b,bg) "\033[0;38;2;" #r";" #g";" #b";" #bg"m"//����߼�ǰ��ɫ�ͼ򵥱���ɫ�����ָ�Ĭ��
#define WIND1(msg) COLOR(msg,53,150,151,48)//��Ԫ����ɫ
#define ROCK1(msg) COLOR(msg,222,189,108,48)//��Ԫ����ɫ
#define WATER1(msg) COLOR(msg,0,191,255,48)//ˮԪ����ɫ
#define FIRE1(msg) COLOR(msg,236,73,35,48)//��Ԫ����ɫ
#define GRASS1(msg) COLOR(msg,102,173,22,48)//��Ԫ����ɫ
#define ICE1(msg) COLOR(msg,70,130,180,48)//��Ԫ����ɫ
#define THUNDER1(msg) COLOR(msg,148,93,196,48)//��Ԫ����ɫ
#define RED1(msg) COLOR(msg,255,100,100,48) //HP
#define GREEN1(msg) COLOR(msg,150,255,120,48)//
#define BLUE1(msg) COLOR(msg,102,204,255,48)//
#define WIND COLORS(53,150,151,48)//��Ԫ����ɫ
#define ROCK COLORS(222,189,108,48)//��Ԫ����ɫ
#define WATER COLORS(0,191,255,48)//ˮԪ����ɫ
#define FIRE COLORS(236,73,35,48)//��Ԫ����ɫ
#define GRASS COLORS(102,173,22,48)//��Ԫ����ɫ
#define ICE COLORS(70,130,180,48)//��Ԫ����ɫ
#define THUNDER COLORS(148,93,196,48)//��Ԫ����ɫ
#define RED COLORS(255,100,100,48) //HP
#define GREEN COLORS(150,255,120,48)//
#define BLUE COLORS(102,204,255,48)//
#define DEFAULT COLOR(255,255,255,48)
/*
f�� 30��ɫ����
bg��40��ɫ��41��ɫ��42��ɫ��43��ɫ��44��ɫ��45��ɫ��46��ɫ��47��ɫ
*/