#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
///宝岛探险，深度优先搜索
/*
0：表示海洋
1~9：表示陆地

求有多少个独立小岛???

对地图上每个大于0的点进行一次着色的深度搜索。
*/

////其实这就是求一个图中独立子图的个数。这个算法就是鼎鼎大名的Floodfill漫水填充算法（也称种子填充法）
//Floodfill在计算机图形学中有着非常广泛的运用，比如图像分割、物体识别等。


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


void dfs(int x, int y,int color)
{
	if (x<1 || x>n || y < 1 || y >m)
	{
		return;
	}
	if (a[x][y] == 0)
	{
		return;
	}
	
	int k, tx, ty;
	
	a[x][y] = color;//对a[x][y]这个格子进行染色

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
			dfs(tx, ty,color);
		}
	}
	return;
}




int main()
{
	//读入n行m列数据，以及降落点坐标
	scanf("%d %d %d %d", &n, &m, &startx, &starty);
	int colorNum = 0;
	//读入地图
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}

	///对岛上每一个点今夕一次深度搜索
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			if (a[i][j]>0)
			{
				colorNum--;//小岛需要染色的颜色编号。发现一个小岛应该染以不同的颜色，因此每次要-1
				book[i][j] = 1;
				dfs(i, j, colorNum);
			}
		}
	}


//	printf("sum:%d \r\n", sum);
	//输出已经染色的地图
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			printf("%3d", a[i][j]);
		}
		printf("\r\n");
	}



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
