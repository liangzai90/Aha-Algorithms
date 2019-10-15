#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
///图的遍历
/*
最少转机，图的广度优先遍历

*/

const int MAX_LENGTH = 999999;

struct node
{
	int x;//城市编号
	int s;//转机次数
};


int main()
{
	struct node que[2501];
	int e[51][51] = { 0 }, book[51] = { 0 };
	int head, tail;
	int i, j, n, m, a, b, cur, start, end, flag = 0;

	scanf("%d %d %d %d", &n, &m, &start, &end);

	//初始化二维矩阵
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
				e[i][j] = MAX_LENGTH;
			}
		}
	}

	//读入城市之间的航班
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d", &a,&b);
		//注意这里的是无向图
		e[a][b] = 1;
		e[b][a] = 1;
	}

	//队列初始化
	head = 1;
	tail = 1;

	//从start号城市出发，将start城市加入队列
	que[tail].x = start;
	que[tail].s = 0;
	tail++;
	book[start] = 1;//标记start号城市已在队列中

	//当队列不为空的时候循环
	while (head < tail)
	{
		cur = que[head].x;//当前队列中 首（队列前面）城市的编号
		for (j = 1; j <= n; j++)
		{
			//从城市cur到城市j是否有航班并且判断城市j是否已经在队列中
			if (e[cur][j] != MAX_LENGTH && book[j] == 0)
			{
				// 如果从城市cur到城市j有航班并且城市j不在队列中，则将j号城市入队
				que[tail].x = j;
				que[tail].s = que[head].s + 1;//转机次数+1
				tail++;

				//标记城市j已在队列中
				book[j] = 1;
			}

			//如果到达目标城市，停止扩展，任务结束，退出循环
			if (que[tail - 1].x == end)
			{
				flag = 1;
				break;
			}
		}

		if (1 == flag)
		{
			break;
		}

		//注意这个地方，千万不要忘记。当一个点扩展结束后，head++才能继续扩展
		head++;
	}

	//打印队列中末尾最后一个（目标城市）的转机次数
	//注意tail是指向队列队尾的下一个位置，所以这里需要-1
	printf("setp:%d", que[tail - 1].s);



	printf("\r\n");
	system("pause");
	return 0;
}

/*


5 7 1 5
1 2 
1 3
2 3 
2 4
3 4
3 5 
4 5


第一行5表示有5个城市（城市编号1~5），7表示有7条航线
1表示起点城市，5表示目标城市；
接下来的7行是一条类似(a,b)这样的数据，表示城市a和城市b之间有航线

这里我们用【邻接矩阵】来存储地图，需要注意的是这里是无向图。
城市的编号就是图的顶点，而航班则是两点之间的边。
小哼要求的是转机次数最少，所以我们可以认为所有边的长度都是1.


*/
