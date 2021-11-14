#define _CRT_SECURE_NO_WARNINGS 1

//à?II??

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
	printf("----------?à?----------\n");
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
	printf("----------?à?----------\n");
}
void SetMine(char mine[ROWS][COLS], int row, int col)
{
	//zu10¢
	int count = EASY_COUNT;
	while (count)
	{
		//¶¬÷Iº?
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
	//1.?ür?I¿?
	//2.??¿??¥s¥
		//(1)¥ - k?¶ày¹ - à??©
		//(2)s¥ - ??¿?ü?L{¢ - ¶?r?IM§show?Cà??? 
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < row * col - EASY_COUNT)
	{
		printf("??üvr?I¿?:>");
		scanf("%d%d", &x, &y);//x - 19,y - 19
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("k?¶C?íày¹\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else
			{
				//s¥îvºC??x,y¿?ü?L{¢
				int count = get_mine_count(mine, x, y);
				show[x][y] = count + '0';//«®`count???show?I
				//?¦r?oIM§
				DisplayBoard(show, row, col);
				win++;
			}
		}
		else
		{
			printf("¿?s@C?dV?ü\n");
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("±ì?Cr¬÷\n");
		DisplayBoard(mine, row, col);
	}
}