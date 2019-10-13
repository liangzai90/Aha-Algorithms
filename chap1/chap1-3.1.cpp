#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>

///快速排序：找一个数作为基准，两端探测。
////最差时间复杂度和冒泡排序一样是(O(N的平方)），平均时间复杂度是O(NlogN)

int a[101], n;//定义全局变量，这两个变量需要在子函数中使用

void quicksort(int left, int right)
{
	int i, j, t, temp;
	if (left > right)
	{
		return;
	}
	temp = a[left];//temp中存的就是基准数
	i = left;
	j = right;
	while (i != j)
	{
		//顺序很重要，要先从右往左找.
		while (a[j] >= temp && i < j)
		{
			j--;
		}
		///再从左往右找
		while (a[i] <= temp && i < j)
		{
			i++;
		}

		//交换两个数在数组中的位置
		if (i < j)//当哨兵i和哨兵j没有相遇时
		{
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}//end while

	////最终将基准数归位。相遇的地方就是基准数归位的地方
	a[left] = a[i];
	a[i] = temp;

	quicksort(left, i - 1);//继续处理左边的，这里是一个递归的过程
	
	quicksort(i + 1, right);//继续处理右边的，这里是一个递归的过程

	////第i位置的元素归位了，其他位置的元素还是乱序！！！！

	return;
}

int main()
{
	int i, j;
	//读入数据
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}

	quicksort(1, n);//快速排序调用

	//输出排序后的结果
	for (i = 1; i <= n; i++)
	{
		printf("%d,", a[i]);
	}

	system("pause");
	return 0;
}
