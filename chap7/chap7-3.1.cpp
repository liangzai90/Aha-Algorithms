#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
///最短路径
/*

堆建立，以及堆排序.【最小堆】

*/


int h[101];//用来存放堆的数组
int n;//用来存放堆中元素的个数，也就是堆的大小

//交换函数，用来交换堆中的两个元素的值
void swap(int x, int y)
{
	int t;
	t = h[x];
	h[x] = h[y];
	h[y] = t;
	return;
}

//向下调整函数
//传入一个需要向下调整的结点编号i,这里传入1，即从堆的顶点开始向下调整
void siftdown(int i)
{
	int t, flag = 0;//flag用来标记是否需要继续向下调整
	//当i结点有儿子（其实是至少有左儿子）并且有需要继续调整的时候，循环就执行
	while (i * 2 <= n && flag == 0)
	{
		//首先判断它和左儿子的关系，并用t记录值较小的结点编号
		if (h[i] > h[i * 2])
		{
			t = i * 2;
		}
		else
		{
			t = i;
		}
		//如果它有右儿子，再对右儿子进行讨论
		if (i * 2 + 1 <= n)
		{
			//如果右儿子的值更小，更新较小的结点编号
			if (h[t] > h[i * 2 + 1])
			{
				t = i * 2 + 1;
			}
		}

		//若果发现最小的结点编号不是自己，说明子节点中有比父节点更小的
		if (t != i)
		{
			swap(t, i);//交换他们（swap是我们自己写的函数）
			i = t;//更新i为刚才与它交换的儿子结点的编号，便于接下来继续向下调整
		}
		else
		{
			//否则说明当前的父节点已经比两个子节点都要小了，不需要再进行调整了
			flag = 1;
		}
	}
	return;
}

//建立堆
void create()
{
	int i;
	//从最后一个非叶子结点到第1个结点依次进行向下调整
	for (i = n / 2; i >= 1; i--)
	{
		siftdown(i);
	}
	return;
}

//删除最大的元素
int deletemax()
{
	int t;
	t = h[1];//用一个临时变量记录堆顶点的值
	h[1] = h[n];//将堆的最后一个点赋值到堆顶
	n--;//堆的元素减少1
	siftdown(1);//向下调整	
	return t;//返回之前记录的堆的顶点的最小值
}


int main()
{
	int i, num;
	//读入要排序的数字的个数
	scanf("%d", &num);

	for (i = 1; i <= num; i++)
	{
		scanf("%d", &h[i]);
	}
	n = num;

	//建堆
	create();

	//删除顶部元素，连续删除n次，其实也就是从大到小把数输出来
	for (i = 1; i <= num; i++)
	{
		printf("%d ,", deletemax());
	}

	printf("\r\n");
	system("pause");
	return 0;
}

/*


14
99 5 36 7 22 17 46 12 2 19 25 28 1 92





*/
