#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//图的最小生成树
/*

1.从任意一个顶点开始构造生成树
2.用一个数组记录生成树到各个顶点的距离
3.从数组中挑选里生成树最近的顶点加入到生成树中。
再以这个点为中间点，更新生成树到每个非树顶点的距离
4.重复第3步，直到生成树中有n个顶点为止


*/



//请从此处开始阅读程序，从主函数开始阅读程序是一个好习惯
int main()
{
	int n, m, i, j, k, min, t1, t2, t3;
	int e[7][7], dis[7], book[7] = { 0 };//这里对book数组进行了初始化
	//inf(infinity)存储一个我们认为的正无穷大
	int inf = 999;
	//count用来记录生成树中顶点的个数，sum用来存储路径之和
	int count = 0, sum = 0;

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

	//开始读入边
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &t1, &t2, &t3);
		//注意这里是无向图，所以需要将边反向再存储一遍
		e[t1][t2] = t3;
		e[t2][t1] = t3;
	}

	//初始化dis数组，这里是1号顶点到各个顶点的初始距离，因为当前生成树中只有1号顶点
	for (i = 1; i <= n; i++)
	{
		dis[i] = e[1][i];
	}

	//Prim核心部分开始
	//将1号顶点加入生成树
	book[1] = 1;//这里用book来标记一个顶点是否已经加入生成树
	count++;
	while (count < n)
	{
		min = inf;
		for (i = 1; i <= n; i++)
		{
			if (book[i] == 0 && dis[i] < min)
			{
				min = dis[i];
				j = i;
			}
		}//end for

		book[j] = 1;
		count++;
		sum = sum + dis[j];

		//扫描当前顶点j所有的边，再以j为中间点，更新生成树到每一个非树顶点的距离
		for (k = 1; k <= n; k++)
		{
			if (book[k] == 0 && dis[k] > e[j][k])
			{
				dis[k] = e[j][k];
			}
		}
	}

	printf("sum:%d", sum);




	printf("\r\n");
	system("pause");
	return 0;
}

/*


6 9 
2 4 11
3 5 13
4 6 3
5 6 4 
2 3 6
4 5 7
1 2 1
3 4 9
1 3 2





*/
