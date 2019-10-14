#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
///宝岛探险，广度优先搜索
/*
0：表示海洋
1~9：表示陆地
计算某个点所在岛屿的面积
*/

struct node
{
	int x;//横坐标
	int y;//纵坐标
};

int main()
{
	struct node que[2501];
	int head, tail;
	int a[51][51];
	int book[51][51] = { 0 };
	int i, j, k, sum, max = 0, mx, my, n, m, startx, starty, tx, ty;

	//定义一个方向数组
	int next[4][2] = {
		{ 0, 1 },
		{ 0, -1 },
		{ 1, 0 },
		{ -1, 0 }
	};

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

	//队列初始化
	head = 1;
	tail = 1;
	//我那个队列插入降落点坐标
	que[tail].x = startx;
	que[tail].y = starty;
	tail++;
	book[startx][starty] = 1;
	sum = 1;

	//当队列不为空的时候循环
	while (head < tail)
	{
		for (k = 0; k <= 3; k++)
		{
			//枚举4个方向
			tx = que[head].x + next[k][0];
			ty = que[head].y + next[k][1];

			//判断是否越界
			if (tx<1 || ty<1 || tx>n || ty >m)
			{
				continue;
			}

			//判断是否是陆地或者曾经是否走过
			if (a[tx][ty] > 0 && book[tx][ty] == 0)
			{
				sum++;
				//每个点只入队一次，需要标记这个点已经走过
				book[tx][ty] = 1;
				//将扩展的点加入队列
				que[tail].x = tx;
				que[tail].y = ty;
				tail++;
			}
		}

		//不能忘记
		//当一个点扩展结束后，head++才能继续往下扩展
		head++;
	}
	

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
