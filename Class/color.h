#define COLOR(msg,color) "\033[" #color"m" msg"\033[0m"//不带背景颜色的输出,用完之后恢复默认颜色
#define BCOLOR(msg,color,bcolor) "\033[" #bcolor";" #color"m" msg"\033[0m"//带背景颜色的输出，用完之后恢复默认颜色

