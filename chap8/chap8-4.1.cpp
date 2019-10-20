#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//关键道路--图的割边

/*

在一个无向连通图中，如果删除某条边后，图不再连通。

*/

int n, m, e[9][9], root;
int num[9], low[9], index;

int min(int a, int b)
{
	return a < b ? a : b;
}

void dfs(int cur, int father)
{
	int i;
	index++;
	num[cur] = index;
	low[cur] = index;

	for (i = 1; i <= n; i++)
	{
		if (e[cur][i] == 1)
		{
			if (0 == num[i])
			{
				dfs(i, cur);
				low[cur] = min(low[i], low[cur]);
				if (low[i] > num[cur])
				{
					printf("%d-%d \r\n", cur, i);
				}
			}
			else if (i != father)
			{
				low[cur] = min(low[cur], num[i]);
			}
		}
	}
	return;
}




//请从此处开始阅读程序，从主函数开始阅读程序是一个好习惯
int main()
{
	int i, j, x, y;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			e[i][j] = 0;
		}
	}

	for (i = 1; i <= m; i++)
	{
		scanf("%d %d", &x, &y);
		e[x][y] = 1;
		e[y][x] = 1;
	}

	root = 1;
	dfs(1, root);




	printf("\r\n");
	system("pause");
	return 0;
}

/*


6 6 
1 4
1 3
4 2
3 2
2 5
5 6





*/
