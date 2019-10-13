#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>

///桶排序，实现isbn编号的排序问题

int main()
{
	int a[1001], n, i, t;
	for (i = 1; i <= 1000; i++)
	{
		a[i] = 0;//初始化
	}

	scanf("%d", &n);//读入n

	for (i = 1; i <= n; i++)//循环读入n个图书的ISBN号
	{
		scanf("%d", &t);//把每一个ISBN号读到变量t中
		a[t] = 1;//标记出现过的ISBN号
	}

	//依次判断1~1000这1000个桶
	for (i = 1; i <= 1000; i++)
	{
		if (a[i] == 1)//如果这个ISBN号出现过则打印出来
		{
			printf("%d ,", i);
		}
	}

	

	system("pause");
	return 0;
}
