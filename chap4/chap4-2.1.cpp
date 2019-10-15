#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
///万能的搜索：深度优先搜索，查找最短路径


int n, m, p, q, min = 9999999;
int a[51][51], book[51][51];

void dfs(int x, int y, int step)
{
	int next[4][2] = { 
		{ 0, 1 }, //向右走
		{ 1, 0 }, //向下走
		{ 0, -1 }, //向左走
		{ 1, 0 }, //向上走
	};

	int tx, ty, k;
	//判断是否到达小哈的位置
	if (x == p && y == q)
	{
		//更新最小值
		if (step < min)
		{
			min = step;
		}

		//此处返回非常重要
		return;
	}

	//枚举4种走法
	for (k = 0; k <= 3; k++)
	{
		//计算下一个点的坐标
		tx = x + next[k][0];
		ty = y + next[k][1];

		//判断是否越界
		if (tx<1 || tx>n || ty<1 || ty>m)
		{
			continue;
		}

		//判断该店是否为障碍物或者已经走过
		if (a[tx][ty] == 0 && book[tx][ty] == 0)
		{
			book[tx][ty] = 1;//标记这个点已经走过
			dfs(tx, ty, step + 1);//开始尝试下一个点
			book[tx][ty] = 0;//尝试下一个点，取消这个点的标记
		}
	}
	return;
}


int main()
 {
	int i, j, startx, starty;
	//读入n,m,n为行，m为列
	scanf("%d %d", &n, &m);

	//读入迷宫
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}

	//读入起点
	scanf("%d %d", &startx, &starty);

	//读入终点
	scanf("%d %d", &p, &q);

	//从起点开始搜索
	book[startx][starty] = 1;//标记已经在路径中，防止后面重复走
	
	//第一个参数是起点的x坐标，第2个参数是起点的y坐标，第3个参数是初始步数
	dfs(startx, starty, 0);

	//输出最短步数
	printf("MinStep:%d", min);


	printf("\r\n");
	system("pause");
	return 0;
}

/*

5 4 
0 0 1 0
0 0 0 0 
0 0 1 0
0 1 0 0 
0 0 0 1
1 1 4 3 

*/


