#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//图的最小生成树
/*

首先，按照边的权值进行从小到大排序，
每次从剩余的边中选择权值较小且边的两个顶点不在同一个集合内的边（就是不会产生回路的边）
加入到生成树中，直到加入了n-1条边为止

*/


struct edge
{
	int u;
	int v;
	int w;
};//为了方便创建，这里创建了一个结构体来存储边的关系

struct edge e[10];//数组大小根据实际情况来设置，要比m的最大值大1
int n, m;
int f[7] = { 0 }, sum = 0, count = 0;//并查集需要用到的一些变量
//f数组大小根据实际情况来设置，要比n的最大值大1


//
void quicksort(int left, int right)
{
	int i, j;
	struct edge t;
	if (left > right)
	{
		return;
	}
	i = left;
	j = right;
	while (i != j)
	{
		//顺序很重要，要先从右边开始找
		while (e[j].w >= e[left].w && i < j)
		{
			j--;
		}

		//再从左边开始找
		while (e[i].w <= e[left].w && i < j)
		{
			i++;
		}

		//交换
		if (i < j)
		{
			t = e[i];
			e[i] = e[j];
			e[j] = t;
		}
	}

	//最终将基准数归位，将left和i互换
	t = e[left];
	e[left] = e[i];
	e[i] = t;

	//继续处理左边的，这里是一个递归的过程
	quicksort(left, i - 1);
	quicksort(i + 1, right);//继续处理右边的，这里是一个递归的过程
	return;
}


//并查集寻找祖先的函数
int getf(int v)
{
	if (f[v] == v)
	{
		return v;
	}
	else
	{
		//这里是路径压缩
		f[v] = getf(f[v]);//找它的父节点
		return f[v];
	}
}

//并查集合并两子集合的函数
int merge(int v, int u)
{
	int t1, t2;
	t1 = getf(v);
	t2 = getf(u);
	//判断两个点是否在同一个集合中
	if (t1 != t2)
	{
		f[t2] = t1;
		return 1;
	}

	return 0;
}



//请从此处开始阅读程序，从主函数开始阅读程序是一个好习惯
int main()
{
	int i;

	//读入n和m，n表示顶点个数，m表示边的条数
	scanf("%d %d", &n, &m);

	//读入边，这里用一个结构体来存储边的关系
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
	}

	quicksort(1, m);// 按照权值从小到大金星快速排序

	//并查集初始化
	for (i = 1; i <= n; i++)
	{
		f[i] = i;
	}

	//Kruskal算法核心部分
	//开始从小到大枚举每一条边
	for (i = 1; i <= m; i++)
	{
		//判断一条边的两个顶点是否已经连通，即判断是否已在同一个集合中
		//如果目前尚未连通，则选用这条边
		if (merge(e[i].u, e[i].v))
		{
			count++;
			sum = sum + e[i].w;
		}

		//直到选用了n-1条边之后退出循环
		if (n - 1 == count)
		{
			break;
		}
	}//end for 

	//打印结果
	printf("sum=%d", sum);

	

	printf("\r\n");
	system("pause");
	return 0;
}

/*

6 9 
2 4 11
3 5 13
4 6 3
5 6 4 
2 3 6
4 5 7
1 2 1
3 4 9 
1 3 2




*/
