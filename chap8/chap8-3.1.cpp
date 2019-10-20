#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//重要城市--图的割点
/*

无向连通图中，删除某个顶点后，图不再连通，我们称这样的顶点为割点

*/

int n, m, e[9][9], root;
int num[9], low[9], flag[9], index;//index用来进行时间戳的递增

//求两个数中较小的一个数的函数
int min(int a, int b)
{
	return a < b ? a : b;
}

//割点算法的核心
//需要传入2个参数，当前顶点编号和父顶点的编号
void dfs(int cur, int father)
{
	int child = 0, i;//child用来记录在生成树中当前顶点cur的儿子个数
	index++;//时间戳加1
	num[cur] = index;//当前顶点cur的时间戳
	low[cur] = index;//当前顶点cur能够访问到最早顶点的时间戳，刚开始当然是自己
	for (i = 1; i <= n; i++)
	{
		if (e[cur][i] == 1)
		{
			//如果顶点i的时间戳为0，说明顶点i还没有被访问过
			if (0 == num[i])
			{
				//从生成树的角度来说，此时的i为cur的儿子
				child++;
				dfs(i, cur);//继续往下深度优先遍历

				//更新当前顶点cur能访问到最早顶点的时间戳
				low[cur] = min(low[cur], low[i]);
				//如果当前顶点不是根结点并且满足low[i]>=num[cur]，则当前顶点为割点
				if (cur != root && low[i] >= num[cur])
				{
					flag[cur] = 1;
				}

				//如果当前顶点是根结点，在生成树中根结点必须要有两个儿子，那么这个根结点才是割点
				if (cur == root && 2 == child)
				{
					flag[cur] = 1;
				}
			}
			else if (i != father)
			{
				//否则如果顶点i曾经被访问过，并且这个顶点不是当前顶点cur的父亲，则说明此时的i为cur的祖先，因此需要更新当前结点cur能访问到最早顶点的时间戳
				low[cur] = min(low[cur], num[i]);
			}
		}//end if 
	}//end for
	return;
}




//请从此处开始阅读程序，从主函数开始阅读程序是一个好习惯
int main()
{
	int i, j, x, y;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			e[i][j] = 0;
		}
	}

	for (i = 1; i <= m; i++)
	{
		scanf("%d %d", &x, &y);
		e[x][y] = 1;
		e[y][x] = 1;
	}

	root = 1;
	dfs(1, root);//从1号顶点开始进行深度优先遍历

	for (i = 1; i <= n; i++)
	{
		if (flag[i] == 1)
		{
			printf("%d ,", i);
		}
	}




	printf("\r\n");
	system("pause");
	return 0;
}

/*


6 7 
1 4 
1 3
4 2
3 2
2 5
2 6
5 6



这里用邻接矩阵来存储图。时间复杂度会是O(N的平方)
在实际应用中需要改为使用邻接表来存储，这样整个算法的时间复杂度是O(N+M)




*/
