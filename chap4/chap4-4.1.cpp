#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
///层层递进，广度优先搜索

struct node
{
	int x;//横坐标
	int y;//纵坐标
};

char a[20][20];//用来存储地图

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


int main()
{
	struct node que[401];//因为地图大小不超过20*20，因此队列扩展不会超过400个
	int head, tail;
	int book[20][20] = { 0 };//定义一个标记数组并全部初始化为0

	//定义一个用于表示走的方向的数组
	int next[4][2] = {
		{ 0, 1 },
		{ 0, -1 },
		{ 1, 0 },
		{ -1, 0 }
	};

	int i, j, k, sum,max=0, mx, my,n,m, startx, starty, tx, ty;

	scanf("%d %d %d %d", &n, &m, &startx, &starty);

	//读入n行字符
	for (i = 0; i < n; i++)
	{
		scanf("%s", a[i]);
	}

	//队列初始化
	head = 1;
	tail = 1;

	//往队列插入起始坐标
	que[tail].x = startx;
	que[tail].y = starty;
	tail++;
	book[startx][starty] = 1;
	max = getnum(startx, starty);
	mx = startx;
	my = starty;

	//当队列不为空的时候循环
	while (head < tail)
	{
		//枚举4个方向
		for (k = 0; k < 4; k++)
		{
			//计算下一个坐标的点
			tx = que[head].x + next[k][0];
			ty = que[head].y + next[k][1];

			//判断是否越界
			if (tx<0 || tx >n-1 || ty<0 || ty>m-1)
			{
				continue;
			}

			//判断是否是障碍物或者已经在路径中
			if (a[tx][ty] == '.' && book[tx][ty] == 0)
			{
				//把这个点标记为已经走过
				book[tx][ty] = 1;
				//插入新的点到队列中
				que[tail].x = tx;
				que[tail].y = ty;
				tail++;

				//统计当前新扩展的点可以消灭的敌人总数
				sum = getnum(tx, ty);
				//更新max的值
				if (sum > max)
				{
					max = sum;
					mx = tx;
					my = ty;
				}
			}

		}//end for


		////注意这地方千万不要忘记，当一个点扩展结束后，head++才能对后面的点再进行扩展
		//前面的点扩展结束
		head++;

	}//end while 
	
	//最后输出这个点和最多可以消灭的敌人总数
	printf("bomb[%d,%d],kill[%d] \r\n", mx, my, max);




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
#G#.#G#.#.###
##G...G.....#
#G#.#G###.#G#
#...G#GGG.GG#
#G#.#G#G#.#G#
#GG.GGG#G.GG#
#############


*/
