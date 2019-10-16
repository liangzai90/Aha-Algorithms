#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
///最短路径
/*

Bellman-Ford算法，解决负权边

*/



int main()
{
	int dis[10], i, k, n, m, u[10], v[10], w[10],check,flag;
	int inf = 999999;//inf(infinity的缩写)存储一个我们认为的正无穷值
	//读入n和m，n表示顶点个数，m表示边的条数
	scanf("%d %d", &n, &m);

	//读入边
	for (i = 1; i <= n; i++)
	{
		scanf("%d %d %d", &u[i], &v[i], &w[i]);
	}

	//初始化dis数组，这里是1号顶点到其余各个顶点的初始路程
	for (i = 1; i <= m; i++)
	{
		dis[i] = inf;
	}
	dis[1] = 0;

	//Bellman-Ford算法核心语句 
	for (k = 1; k <= n - 1; k++)
	{
		check = 0;//用来标记在本轮松弛中数组dis是否会发生更新

		//进行一轮松弛
		for (i = 1; i <= m; i++)
		{
			if (dis[v[i]] > dis[u[i]] + w[i])
			{
				dis[v[i]] = dis[u[i]] + w[i];
				check = 1;//数组dis发生更新，改变check的值
			}
		}

		//松弛完毕后检测数组dis是否有更新
		if (0 == check)
		{
			break;//如果数组dis没有更新，提前退出循环结束算法
		}
	}

	//检测负权回路
	flag = 0;
	for (i = 1; i <= m; i++)
	{
		if (dis[v[i]] > dis[u[i]] + w[i])
		{
			flag = 1;
		}
	}

	if (1 == flag)
	{
		printf("此图含有负权回路 \r\n");
	}
	else
	{
		//输出最终的结果
		for (i = 1; i <= n; i++)
		{
			printf("%d ,", dis[i]);
		}
	}


	printf("\r\n");
	system("pause");
	return 0;
}

/*



5 5 
2 3 2 
1 2 -3
1 5 5 
4 5 2 
3 4 3



*/
