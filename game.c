#define _CRT_SECURE_NO_WARNINGS 1

//游?的函数的??

#include "game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= rows; i++)
	{
		for (j = 0; j <= cols; j++)
		{
			board[i][j] = set;
		}
	}
}
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("----------?雷游?----------\n");
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	putchar('\n');
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		putchar('\n');
	}
	printf("----------?雷游?----------\n");
}
void SetMine(char mine[ROWS][COLS], int row, int col)
{
	//布置10个雷
	int count = EASY_COUNT;
	while (count)
	{
		//生成随机的下?
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}
int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	return (mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0');
}
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	//1.?入排?的坐?
	//2.??坐??是不是雷
		//(1)是雷 - 很?憾爆炸了 - 游??束
		//(2)不是雷 - ??坐?周?有几个雷 - 存?排?雷的信息到show数?，游??? 
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < row * col - EASY_COUNT)
	{
		printf("??入要排?的坐?:>");
		scanf("%d%d", &x, &y);//x - 1到9,y - 1到9
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("很?憾，?被炸死了\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else
			{
				//不是雷情况下，??x,y坐?周?有几个雷
				int count = get_mine_count(mine, x, y);
				show[x][y] = count + '0';//将整形count???show数?的字符
				//?示排?出的信息
				DisplayBoard(show, row, col);
				win++;
			}
		}
		else
		{
			printf("坐?不合法，?重新?入\n");
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("恭喜?，排雷成功\n");
		DisplayBoard(mine, row, col);
	}
}