#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
///最短路径
/*

堆建立，合并集

*/

int f[1000] = { 0 }, n, m, k, sum = 0;
//这里是初始化，非常地重要，数组里面存的是自己的数组下标的编号就好了
void init()
{
	for (int i = 1; i <= n; i++)
	{
		f[i] = i;
	}
	return;
}

//这是找爹的递归函数，不停地去找爹，直到找到祖宗位置
//擒贼先擒王原则
int getf(int v)
{
	if (f[v] == v)
	{
		return v;
	}
	else
	{
		//这里是路径压缩，每次在函数返回的时候，顺带把路上遇到的人的boss改为最后找到的祖宗编号，也就是犯罪团伙的最高领导人编号。这样可以提高今后找到犯罪团伙的最高领导人（其实就是树的祖先）的速度
		f[v] = getf(f[v]);
		return f[v];
	}
}

//这里是合并两个集合的函数
void merge(int v, int u)
{
	int t1, t2;//t1,t2分别为v和u的大boss，每次双方的会谈都必须是给自最高领导人才行
	t1 = getf(v);
	t2 = getf(u);
	//判断两个结点是否在同一个集合中，即是否为同一个祖先
	if (t1 != t2)
	{
		f[t2] = t1;
		//“靠左”原则，左边变成右边boss，即把右边的集合，作为左边集合的子集合
		//经过路径压缩以后，将f[u]的根的值也赋值为v的祖先f[t1]
	}
}




int main()
{
	int i, x, y;
	scanf("%d %d", &n, &m);

	//初始化是必须的
	init();
	for (i = 1; i <= m; i++)
	{
		//开始合并犯罪团伙
		scanf("%d %d", &x, &y);
		merge(x, y);
	}

	//最后扫描有多少个独立的犯罪团伙
	for (i = 1; i <= n; i++)
	{
		printf("%d ,", f[i]);
		if (f[i] == i)
		{
			sum++;
		}
	}
	printf("\r\n");

	printf("sum:%d \r\n", sum);

	

	printf("\r\n");
	system("pause");
	return 0;
}

/*


10 9 
1 2 
3 4
5 2
4 6
2 6
8 7 
9 7
1 6
2 4




f[5]=5
f[9]=9
f[10]=10
因此，有3个独立的犯罪团伙


*/
