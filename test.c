#define _CRT_SECURE_NO_WARNINGS 1

//扫雷游戏的测试

#include "game.h"

void menu()
{
	printf("****************************\n");
	printf("*******    1.play    *******\n");
	printf("*******    0.exit    *******\n");
	printf("****************************\n");
}
void game()
{
	//创建两个数组，一个存放布置好的雷的信息，一个存放排查出的雷的信息
	//为了确保棋盘每个坐标都可以查找周围8个坐标，而不越栈
	//数组的大小应该大上一圈，即创建时，数组的范围分别+2(左右各多一列，上下各多一行)
	char mine[ROWS][COLS] = { 0 };//布置好的雷的信息,雷对应 - 1，不是雷对应 - 0
	char show[ROWS][COLS] = { 0 };//存放排查出的雷的信息
	//初始化棋盘
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//打印棋盘
	DisplayBoard(show,ROW,COL);
	//布置雷
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);
	//排查雷
	//将mine数组排查到的信息传到show数组中
	FindMine(mine, show, ROW, COL);
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch(input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input);
	return 0;
}