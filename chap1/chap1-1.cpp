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

	//循环读入5个数(数字不要太大，这里只申请了11个空间)
	for (i = 1; i <= 5; i++)
	{
		scanf("%d", &t);//把每一个数读入到变量t中
		a[t]++;//进行计数
	}

	//依次判断a[0]~a[10]
	for (i = 0; i <= 10; i++)
	{
		for (j = 1; j <= a[i]; j++)//【在单个元素上进行循环】，出现几次打印几次
		{
			printf("%d ", i);////数组的编号就是我们存放的数字
		}
	}

	getchar(); getchar();
	////这里的getchar用来暂停程序，以便查看程序输出的内容
	////也可以用system("pause");等来代替
	system("pause");
	return 0;
}

