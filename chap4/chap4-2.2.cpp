#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
///万能的搜索：枚举可以转换为递归

///爬楼问题：100层楼，每次可以爬1层或2层，求有多少种爬法

/*
问题分解：
100层楼，最少爬50次，最多爬100次。
定义next数组，往右走1步，在数组中跨2格；往下走一步，在数组中跨1格。
从[0][0]位置出发，每次判断[x,y]点,x+y=100的地方，就是一种可行路径。

1.将爬楼转换为在数组中向下走或者向右走
2.可以枚举来实现，，，但是对于特别大的数，枚举太复杂，需要将枚举实现转换为递归实现

*/


int a[101][201], book[101][201];

const int iLouCount = 3;//楼层有多少

static int iCountWay = 0;//统计有多少种走法

void dfs(int x, int y, int step)
{
	int next[2][2] = { 
		{ 0, 2 }, //向右走
		{ 1, 0 }, //向下走
	};

	int tx, ty, k;

	if (x + y == iLouCount)
	{
		iCountWay++;
		return;
	}
	if (x > iLouCount || y > iLouCount || step > iLouCount)
	{
		return;//本次查找失败
	}
	
	for (k = 0; k <= 1; k++)
	{
		//计算下一个点的坐标
		tx = x + next[k][0];
		ty = y + next[k][1];

		//判断是否越界
		if (tx>iLouCount || ty>iLouCount)
		{
			continue;
		}

		//判断该店是否为障碍物或者已经走过
		if (a[tx][ty] == 0 && book[tx][ty] == 0)
		{
			book[tx][ty] = 1;//标记这个点已经走过
			dfs(tx, ty, step + 1);
			book[tx][ty] = 0;//尝试下一个点，取消这个点的标记
		}
	}
	return;
}


int main()
{
	dfs(0, 0, 0);

	//总共有多少种解法
	printf("iCountWay:%d", iCountWay);


	printf("\r\n");
	system("pause");
	return 0;
}

