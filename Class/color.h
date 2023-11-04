#define COLOR(msg,r,g,b,bg) "\033[38;2;" #r";" #g";" #b";" #bg"m" msg"\033[0m"//定义高级前景色和简单背景色；恢复默认
#define WIND(msg) COLOR(msg,53,150,151,48)//风元素颜色
#define ROCK(msg) COLOR(msg,222,189,108,48)//岩元素颜色
#define WATER(msg) COLOR(msg,0,191,255,48)//水元素颜色
#define FIRE(msg) COLOR(msg,236,73,35,48)//火元素颜色
#define GRASS(msg) COLOR(msg,102,173,22,48)//草元素颜色
#define ICE(msg) COLOR(msg,70,130,180,48)//冰元素颜色
#define THUNDER(msg) COLOR(msg,148,93,196,48)//雷元素颜色
#define RED(msg) COLOR(msg,255,100,100,48) //HP
#define GREEN(msg) COLOR(msg,150,255,120,48)//
#define BLUE(msg) COLOR(msg,102,204,255,48)//
/*
f： 30黑色……
bg：40黑色；41红色；42绿色；43黄色；44蓝色；45紫色；46青色；47灰色
*/