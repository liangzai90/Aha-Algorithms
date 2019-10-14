#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
///层层递进，广度优先搜索

struct node
{
	int x;//横坐标
	int y;//纵坐标
	int f;//父亲在队列中的编号，本题不要求输出路径，可以不需要f
	int s;//步数
};


int main()
{
	struct node que[2501];//因为地图大小不超过50*50，因此队列扩展不会超过2500个
	int a[51][51] = { 0 }, book[51][51] = { 0 };
	//定义一个用于表示走的方向的数组
	int next[4][2] = {
		{ 0, 1 },
		{ 0, -1 },
		{ 1, 0 },
		{ -1, 0 }
	};

	int head, tail;
	int i, j, k, n, m, startx, starty, p, q, tx, ty, flag;

	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}

	//起点，终点
	scanf("%d %d %d %d", &startx, &starty, &p, &q);

	//队列初始化
	head = 1;
	tail = 1;

	//往队列插入迷宫入口坐标
	que[tail].x = startx;
	que[tail].y = starty;
	que[tail].f = 0;
	que[tail].s = 0;
	tail++;
	book[startx][starty] = 1;

	//用来标记是否到达目标点，0表示暂时还没有到达，1表示到达
	flag = 0;
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
			if (tx<1 || tx >n || ty<1 || ty>m)
			{
				continue;
			}

			//判断是否是障碍物或者已经在路径中
			if (a[tx][ty] == 0 && book[tx][ty] == 0)
			{
				//把这个点标记为已经走过
				//注意宽度搜索每个点只入队一次，所以和深度搜索不同，不需要将book数组还原
				book[tx][ty] = 1;
				//插入新的点到队列中
				que[tail].x = tx;
				que[tail].y = ty;
				//因为这个点是从head扩展出来的，所以它的father就是head.本题不需要求路径，因此本句可以省略
				que[tail].f = head;
				//步数是父亲的步数+1
				que[tail].s = que[head].s + 1;
				tail++;
			}

			//如果到目标点了，停止扩展，任务结束，退出循环
			if (tx == p && ty == q)
			{
				//注意下面两句话的位置千万不要写颠倒了

				flag = 1;

				break;//退出循环
			}//end if 
		}//end for

		//停止扩展
		if (1 == flag)
		{
			break;
		}

		////注意这地方千万不要忘记，当一个点扩展结束后，head++才能对后面的点再进行扩展
		//前面的点扩展结束
		head++;

	}//end while 

	//打印队列中末尾最后一个点（目标点）的步数
	//注意tail是指向队列末尾（即最后一位）的下一个位置，所以这里需要-1
	printf("step:%d \r\n", que[tail - 1].s);




	printf("\r\n");
	system("pause");
	return 0;
}

