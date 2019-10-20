#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//二分图最大匹配

/*



*/

int e[101][101];
int match[101];
int book[101];
int n, m;

int dfs(int u)
{
	int i;
	for (i = 1; i <= n; i++)
	{
		if (0 == book[i] && 1 == e[u][i])
		{
			book[i] = 1;//标记点i已访问过

			//如果i点未被配对或者找到了新的匹配
			if (0 == match[i] || dfs(match[i]))
			{
				//更新配对关系
				match[i] = u;
				match[u] = i;
				return 1;
			}
		}
	}

	return 0;
}




//请从此处开始阅读程序，从主函数开始阅读程序是一个好习惯
int main()
{
	int i, j, t1, t2, sum = 0;
	scanf("%d %d", &n, &m);//n个点m条边

	for (i = 1; i <= m; i++)
	{
		scanf("%d %d", &t1, &t2);
		e[t1][t2] = 1;
		e[t2][t1] = 1;
	}

	for (i = 1; i <= n; i++)
	{
		match[i] = 0;
	}

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			book[j] = 0;//清空上次搜索时的标记
		}

		//寻找增广路，如果找不到，配对数加1
		if (dfs(i))
		{
			sum++;
		}
	}

	printf("sum:%d", sum);





	printf("\r\n");
	system("pause");
	return 0;
}

/*


6 5 
1 4 
1 5
2 5
2 6
3 4






*/
