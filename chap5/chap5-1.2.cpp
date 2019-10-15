#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
///图的遍历
/*
广度优先搜索
*/

int main()
{
	int i, j, n, m, a, b, cur, book[101] = { 0 }, e[101][101];
	int que[10001], head, tail;
	scanf("%d %d", &n, &m);
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
				e[i][j] = 9999999;//假设为无穷大
			}
		}
	}

	//读入顶点之间的关系
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d", &a, &b);
		e[a][b] = 1;
		e[b][a] = 1;//这里是无向图，所以需要将e[b][a]也赋值为1
	}

	//队列初始化
	head = 1;
	tail = 1;

	//从1号顶点出发，将1号顶点加入队列
	que[tail] = 1;
	tail++;
	book[1] = 1;

	//当队列不为空的时候循环
	while (head < tail && tail <=n)
	{
		cur = que[head];//当前正在访问的顶点编号
		for (i = 1; i <= n; i++)
		{
			//判断从顶点cur到顶点i是否有边，并判断顶点i是否已经访问过
			if (e[cur][i] == 1 && book[i] == 0)
			{
				//如果从顶点cur到顶点i有边，并且顶点i没有被访问过，则将顶点i入队
				que[tail] = i;
				tail++;
				book[i] = 1;//标记顶点i已被访问
			}

			//如果tail大于n，则表明所有顶点都已经被访问过
			if (tail > n)
			{
				break;
			}
		}

		//注意这个地方，千万不要忘记
		//当一个顶点扩展结束后，head++然后才能继续往下扩展
		head++;
	}

	for (i = 1; i < tail; i++)
	{
		printf("%d ,", que[i]);
	}



	printf("\r\n");
	system("pause");
	return 0;
}

/*

5 5
1 2 
1 3
1 5
2 4
3 5


注意:
	scanf("%d %d", &a, &b);  不要写成了  	scanf("%d %d  ", &a, &b);
  scanf 的 第2个%d后面，不要有空格，否则读入数据会有问题。。。（程序会要求再输入一个字符才会继续往下执行）


*/
