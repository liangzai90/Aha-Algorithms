#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
///图的遍历
/*
最少转机，图的深度优先搜索

*/

const int MAX_LENGTH = 999999;
const int arr_X = 10;//7行，一行代表了一条线路
const int arr_Y = 10;//2列

int arrCity[arr_X][arr_Y] = { 0 };//存放城市间的路线数据.我们这里是7行2列
int book[100] = { 0 };
int minStep = 9999;


//iStrt:出发城市编号，iEnd:终点城市编号，iStep：已经走过的路程
void dfs(int iStart,int iEnd,int iStep)
{	
	if (iStart >= arr_X || iStart >= arr_Y)
	{
		return;
	}
	if (iStart == iEnd)
	{
		if (iStep < minStep)
		{
			minStep = iStep;
			return;
		}
	}
	for (int i = 1; i < arr_X; i++)
	{
		 if(book[i] == 0 && arrCity[iStart][i] != MAX_LENGTH)
		{
			 book[i] = 1;
			 dfs(i, iEnd, iStep + 1);
			 book[i] = 0;
		}
	}
	return;
}



int main()
{
	//初始化二维矩阵
	for (int i = 1; i <arr_X; i++)
	{
		for (int j = 1; j <arr_Y; j++)
		{
			if (i == j)
			{
				arrCity[i][j] = 0;
			}
			else
			{
				arrCity[i][j] = MAX_LENGTH;
			}
		}
	}

	int a, b;
	//读入城市之间的航班
	for (int i = 1; i <= 7; i++)
	{
		scanf("%d %d", &a,&b);
		//注意这里的是无向图
		arrCity[a][b] = 1;
		arrCity[b][a] = 1;
	}

	//城市1是出发点，被标记
	book[1] = 1;
	dfs(1, 5, 0);

	printf("minStep:%d", minStep);


	printf("\r\n");
	system("pause");
	return 0;
}

/*


1 2 
1 3
2 3 
2 4
3 4
3 5 
4 5



*/
