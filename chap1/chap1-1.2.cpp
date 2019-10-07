#define _CRT_SECURE_NO_WARNINGS 

#include <stdlib.h>
#include <stdio.h>

////对数据范围0~10000的整数进行排序(从打到小排序)
int main()
{
	int book[10001], i, j, t, n;
	for (i = 0; i <= 10000; i++)
	{
		book[i] = 0;
	}

	//输入一个数N，表示接下来有N个数
	scanf("%d", &n);

	//循环读入n个数，并进行桶排序
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &t);//把每一个数读到变量t中
		book[t]++;//进行计数，对编号为t的桶做标记
	}

	//依次判断编号10000~0的桶
	for (i = 10000; i >= 0; i--)
	{
		//出现了几次就将桶的编号打印几次
		for (j = 1; j <= book[i]; j++)
		{
			printf("%d ", i);
		}
	}

	system("pause");
	return 0;
}
