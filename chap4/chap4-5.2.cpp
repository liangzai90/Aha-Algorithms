#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
///宝岛探险，深度优先搜索
/*
0：表示海洋
1~9：表示陆地
计算某个点所在岛屿的面积
*/

int a[51][51];
int book[51][51] = { 0 };
int i, j, sum=0, n, m, startx, starty;
//定义一个方向数组
int next[4][2] = {
	{ 0, 1 },
	{ 0, -1 },
	{ 1, 0 },
	{ -1, 0 }
};


void dfs(int x, int y)
{
	if (x<1 || x>n || y < 1 || y >m)
	{
		return;
	}
	if (a[x][y] == 0)
	{
		return;
	}
	
	int k, tx, ty; ///递归函数里面的临时变量，不要定义在了外部。这虽然是c语言规则定义变量，但是也要保证基本的合法、无误。
	for (k = 0; k <= 3; k++)
	{
		tx = x + next[k][0];
		ty = y + next[k][1];
		if (tx<1 || tx>n || ty < 1 || ty >m)
		{
			continue; ///越界了
		}
		if (book[tx][ty] == 0 && a[tx][ty] > 0)
		{
			sum++;
			book[tx][ty] = 1;//标记此岛
			dfs(tx, ty);
		}
	}
	return;
}




int main()
{
	//读入n行m列数据，以及降落点坐标
	scanf("%d %d %d %d", &n, &m, &startx, &starty);

	//读入地图
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}

	book[startx][starty] = 1;
	sum = 1;

	dfs(startx, starty);


	printf("sum:%d \r\n", sum);


	printf("\r\n");
	system("pause");
	return 0;
}

/*

10 10 6 8 
1 2 1 0 0 0 0 0 2 3 
3 0 2 0 1 2 1 0 1 2 
4 0 1 0 1 2 3 2 0 1 
3 2 0 0 0 1 2 4 0 0 
0 0 0 0 0 0 1 5 3 0
0 1 2 1 0 1 5 4 3 0
0 1 2 3 1 3 6 2 1 0 
0 0 3 4 8 9 7 5 0 0 
0 0 0 3 7 8 6 0 1 2 
0 0 0 0 0 0 0 0 1 0


*/
