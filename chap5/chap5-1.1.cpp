#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
///图的遍历
/*
深度优先搜索
*/

int book[101], sum, n, e[101][101];

//cur是当前所在的顶点编号
void dfs(int cur)
{
	int i;
	printf("%d ", cur);
	sum++;//每访问一个顶点，sum就加1
	if (sum == n)
	{
		return;//所有顶点都已经访问过了则直接退出
	}

	//从1号顶点到n号顶点依次尝试，看哪些顶点与当前顶点cur有边相连
	for (i = 1; i <= n; i++)
	{
		//判断当前顶点cur到顶点i是否有边，并判断顶点i是否已经访问过
		if (e[cur][i] == 1 && 0 == book[i])
		{
			//标记顶点i已经访问过
			book[i] = 1;
			dfs(i);//从顶点i再出发，继续访问
		}
	}
	return;
}


int main()
{
	int i, j, m, a, b;
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
				e[i][j] = 999999;//假设999999为无穷大
			}
		}
	}

	//读入顶点之间的边
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d", &a, &b);
		e[a][b] = 1;
		e[b][a] = 1;//这里是无向图，e[b][a]也赋为1
	}

	//从1号顶点出发
	book[1] = 1;//标记1号顶点已访问
	//从1号顶点开始遍历
	dfs(1);



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


*/
