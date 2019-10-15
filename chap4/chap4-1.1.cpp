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
	int i;

	//如果站在第n+1个盒子前面，则表示前面n个盒子以及放好扑克牌
	if (step == n + 1)
	{
		//输出一种排列（1~n号盒子中的扑克牌编号）
		for (i = 1; i <= n; i++)
		{
			printf("%d", a[i]);
		}
		iTotalNum++;
		printf("\r\n");

		return;//返回之前的一步（最近一次调用dfs函数的地方）
	}

	//此时站在第step个盒子面前，应该放哪张牌呢？
	//按照1,2,3，...n的顺序一一尝试
	for (i = 1; i <= n; i++)
	{
		//判断扑克牌i是否还在手上
		if (book[i] == 0)  //book[i]==0表示i号扑克牌在手上
		{
			//开始尝试使用扑克牌i
			a[step] = i;//将i号扑克牌放入到第step个盒子中
			book[i] = i;//将book[i]设为1，表示i号扑克牌已经不在手上

			//第step个盒子已经放好扑克牌，接下来需要走到下一个盒子面前
			dfs(step + 1);//这里通过函数的递归调用来实现

			//这是非常重要的一步，一定要将刚才尝试的扑克牌收回，才能进行下一次尝试
			book[i] = 0;
		}
	}

	return;
}


int main()
 {
	scanf("%d", &n);
	dfs(1);

	printf("iTotalNum:%d \r\n", iTotalNum);

	printf("\r\n");
	system("pause");
	return 0;
}



