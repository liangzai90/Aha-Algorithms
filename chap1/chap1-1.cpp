#define _CRT_SECURE_NO_WARNINGS 

#include <stdlib.h>
#include <stdio.h>

int main()
{
	int a[11], i, j, t;

	for (i = 0; i <= 10; i++)
	{
		a[i] = 0;//初始化
	}

	//循环读入5个数
	for (i = 1; i <= 5; i++)
	{
		scanf("%d", &t);//把每一个数读入到变量t中
		a[t]++;//进行计数
	}

	//依次判断a[0]~a[10]
	for (i = 0; i <= 10; i++)
	{
		for (j = 1; j <= a[i]; j++)//出现几次就打印几次
		{
			printf("%d ", i);
		}
	}

	getchar(); getchar();
	////这里的getchar用来暂停程序，以便查看程序输出的内容
	////也可以用system("pause");等来代替
	system("pause");
	return 0;
}

