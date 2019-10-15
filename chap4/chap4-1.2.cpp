#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
///万能的搜索：深度优先搜索

//此处特别说明一下，C语言的全局变量在没有赋值以前默认为0，因此这里的book数组无需全部再次赋初始值0
int a[10], book[10], n;
static int iTotalNum = 0;

//step表示现在站在第几个盒子前面
void dfs(int step)
{
	if (step > n)
	{
		////此处判断是否满足等式要求
		if (a[1] * 100 + a[2] * 10 + a[3] + a[4] * 100 + a[5] * 10 + a[6] == a[7] * 100 + a[8] * 10 + a[9])
		{
			printf("%d%d%d + %d%d%d = %d%d%d \r\n", a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9]);
			iTotalNum++;
		}
		return;
	}

	/// 此处给a[]赋值，分别是1~9，所以不能从0开始索引.
	for (int i = 1; i <= n; i++)
	{
		if (book[i] == 0)
		{
			a[step] = i;
			book[i] = 1;
			dfs(step + 1);
			book[i] = 0;
		}
	}

	return;
}


int main()
 {
	scanf("%d", &n);
	dfs(1);

	///124+659=783
	//659+124=793
	printf("iTotalNum:%d \r\n", iTotalNum/2);//此处要除以2

	printf("\r\n");
	system("pause");
	return 0;
}

