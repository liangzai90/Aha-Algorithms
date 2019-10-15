#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
///最短路径
/*

只有5行的算法--Floyd-warshall

*/



int main()
{
	int e[10][10], k, i, j, n, m, t1, t2, t3;
	int inf = 999999;//用inf(infinity的缩写)存储一个我们认为的正无穷值
	//读入n和m，n表示顶点个数，m表示边的条数

	scanf("%d %d", &n, &m);

	//初始化
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (i == j)
			{
				e[i][j] = 0;
			}
			else
			{
				e[i][j] = inf;
			}
		}
	}

	//读入边
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &t1, &t2, &t3);
		e[t1][t2] = t3;
	}

	//Floyd-Warshall算法核心语句
	for (k = 1; k <= n; k++)
	{
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				//从i到j，需要借助k点.取最短路径
				if (e[i][j] > e[i][k] + e[k][j])
				{
					e[i][j] = e[i][k] + e[k][j];
				}
			}
		}
	}

	//输出最终的结果
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			printf("%10d", e[i][j]);
		}
		printf("\r\n");
	}



	printf("\r\n");
	system("pause");
	return 0;
}

/*


4 8
1 2 2 
1 3 6 
1 4 4 
2 3 3 
3 1 7 
3 4 1 
4 1 5 
4 3 12



此算法可以求出任意两点之间的最短距离
时间复杂度为O(N的3次方)
Floyd-Warshall算法可以处理带负权边（边的值为负数）的图，但不能处理带有“负权回路”（或者叫“负权环”）的图。
因为在“负权回路”的图两点之间可能没有最短路径



*/
