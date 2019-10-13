#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>

///冒泡排序，实现isbn编号排序问题

int main()
{
	int a[101], n, i, j, t;
	scanf("%d", &n);//读入n

	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}

	//开始冒泡排序
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}

	printf("%d ,", a[1]);//输出第1个数
	for (i = 2; i <= n; i++)
	{
		//如果当前这个数是第一次出现则输出
		if (a[i] != a[i - 1])
			printf("%d ,", a[i]);
	}
	
	system("pause");
	return 0;
}
