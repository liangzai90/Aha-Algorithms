#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//深度搜索，遍历所有元素一遍

struct node
{
	int x;//横坐标
	int y;//纵坐标
};

char a[20][21];//用来存储地图
int maxCount = 0;
int px, py;
int book[20][21] = { 0 };//定义一个标记数组并全部初始化为0
int i,max, n, m, startx, starty;


//定义一个用于表示走的方向的数组
int next[4][2] = {
	{ 0, 1 },
	{ 0, -1 },
	{ 1, 0 },
	{ -1, 0 }
};


//统计上下左右4个方向 可以消灭的敌人数
int getnum(int i, int j)
{
	int sum=0, x, y;
	//将当前坐标i,j复制到两个新变量x,y中，以便向上下左右四个方向分别统计可以消灭的敌人数
	/////向上统计可以消灭的敌人数
	x = i;
	y = j;
	//判断是不是墙，如果不是墙就继续
	while (a[x][y] != '#')
	{
		//如果当前点是敌人，则进行计数
		if (a[x][y] == 'G')
		{
			sum++;
		}
		///x--的作用是继续向上统计
		x--;
	}

	///向下统计可以消灭的敌人数
	x = i;
	y = j;
	while (a[x][y] != '#')
	{
		if (a[x][y] == 'G')
		{
			sum++;
		}
		x++;//继续向下
	}

	///向左统计可以消灭的敌人数
	x = i;
	y = j;
	while (a[x][y] != '#')
	{
		if (a[x][y] == 'G')
		{
			sum++;
		}
		y--;//继续向左
	}

	///向右统计可以消灭的敌人数
	x = i;
	y = j;
	while (a[x][y] != '#')
	{
		if (a[x][y] == 'G')
		{
			sum++;
		}
		y++;//继续向右
	}

	return sum;
}


void dfs(int x, int y)
{
	if (x > n - 1 || y > m - 1 || x < 0 || y<0)
	{
		return;
	}
	if (a[x][y] == '#' || a[x][y] == 'G')
	{
		return;
	}

	int sum = getnum(x, y);
	if (sum > maxCount)
	{
		maxCount = sum;
		px = x;
		py = y;
	}

	int tx, ty;
	for (int k = 0; k < 4; k++)
	{
		tx = x + next[k][0];
		ty = y + next[k][1];
		//判断越界条件
		if (tx > n-1 || ty >m-1 || tx < 0 || ty < 0)
		{
			continue;
		}

		///如果把此处的 && 改为 ||，则会变成死循环！！！
		if (a[tx][ty] == '.' && book[tx][ty] == 0)
		{
			book[tx][ty] = 1;
			dfs(tx, ty);

			///不需要进行下一次的遍历，所以这里不需要取消标记。。。这里的深度搜索是想遍历全部结点一次。仅一次。
		/////	book[tx][ty] = 0;
		}
	}

	return;
}


int main()
{
	scanf("%d %d %d %d", &n, &m, &startx, &starty);

	//读入n行字符
	for (i = 0; i < n; i++)
	{
		scanf("%s", a[i]);
	}
	book[startx][starty] = 1;
	max = getnum(startx, starty);
	px = startx;
	py = starty;

	dfs(startx, starty);
		
	//最后输出这个点和最多可以消灭的敌人总数
	printf("bomb[%d,%d],kill[%d] \r\n", px, py, maxCount);

	
	printf("\r\n");
	system("pause");
	return 0;
}

/*


13  13  3  3
#############
#GG.GGG#GGG.#
###.#G#G#G#G#
#.......#..G#
#G#.###.#G#G#
#GG.GGG.#.GG#
#G#.#G#.#.#.#
##G...G.....#
#G#.#G###.#G#
#...G#GGG.GG#
#G#.#G#G#.#G#
#GG.GGG#G.GG#
#############


*/
