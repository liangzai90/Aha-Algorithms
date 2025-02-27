#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
///最短路径
/*

Bellman-Ford的队列优化

*/



int main()
{
	int n, m, i, j, k;
	//u,v,w，数组大小要根据实际情况来设置，要比m的最大值要大1
	int u[8], v[8], w[8];
	//first要比n的最大值要大1，next要比m的最大值要大1
	int first[6], next[8];
	int dis[6] = { 0 }, book[6] = { 0 };//book数组用来记录哪些顶点已经在队列中
	int que[101] = { 0 }, head = 1, tail = 1;//定义一个队列，并初始化队列
	int inf = 999999;//用inf(infinity的缩写)
	//读入n和m，n表示顶点个数，m表示边的条数
	scanf("%d %d", &n, &m);

	//初始化dis数组，这里是1号顶点到其他
	for (i = 1; i <= n; i++)
	{
		dis[i] = inf;
	}
	dis[1] = 0;

	//初始化book数组，初始化为0，刚开始都不在队列中
	for (i = 1; i <= n; i++)
	{
		book[i] = 0;
	}

	//初始化first数组下标1~n的值为-1，表示1~n顶点暂时都没有边
	for (i = 1; i <= n; i++)
	{
		first[i] = -1;
	}

	for (i = 1; i <= m; i++)
	{
		//读入每一条边
		scanf("%d %d %d", &u[i], &v[i], &w[i]);
		//下面两句是简历邻接表的关键
		next[i] = first[u[i]];
		first[u[i]] = i;
	}

	//1号顶点入队
	que[tail] = 1;
	tail++;
	book[1] = 1;//标记1号顶点已经入队

	//队列不为空的时候循环
	while (head < tail)
	{
		//当前需要处理的队首顶点
		k = first[que[head]];

		//扫描当前顶点所有的边
		while (k != -1)
		{
			//判断是否松弛成功
			if (dis[v[k]] > dis[u[k]] + w[k])
			{
				//更新顶点1到顶点v[k]的路程
				dis[v[k]] = dis[u[k]] + w[k];
				//这的book数组用来判断顶点v[k]是否在队列中
				//如果不使用一个数组来标记的话，判断一个顶点是否在队列中每次都需要从队列的head到tail扫一遍，很浪费时间
				//0表示不在队列中，将顶点v[k]加入到队列
				if (book[v[k]] == 0)
				{
					//下面两句是入队操作
					que[tail] = v[k];
					tail++;
					book[v[k]] = 1;//同时标记顶点v[k]已经入队
				}
			}//if

			k = next[k];
		}//while

		//出队
		book[que[head]] = 0;
		head++;
	}//while

	//输出1号顶点到其余各个顶点的最短路径
	for (i = 1; i <= n; i++)
	{
		printf("%d ,", dis[i]);
	}

	


	printf("\r\n");
	system("pause");
	return 0;
}

/*



5 7
1 2 2 
1 5 10
2 3 3 
2 5 7 
3 4 4 
4 5 5 
5 3 6





*/
