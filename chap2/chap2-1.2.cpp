#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>

///队列，解密QQ号，模拟队列实现此功能

struct queue
{
	int data[100];//队列的主体，用来存储内容
	int head;//队首
	int tail;//队尾
};


int main()
{
	struct queue q;
	int i;
	// 初始化队列
	q.head = 1;
	q.tail = 1;
	for (i = 1; i <= 9; i++)
	{
		//依次向队列插入9个数
		scanf("%d", &q.data[q.tail]);
		q.tail++;
	}

	//当队列不为空的时候，执行循环
	while (q.head < q.tail)
	{
		//打印队首并将队首出队
		printf("%d ,", q.data[q.head]);
		q.head++;

		//先将新队首的数添加到队尾
		q.data[q.tail] = q.data[q.head];
		q.tail++;

		//再讲队首出队
		q.head++;
	}


	
	system("pause");
	return 0;
}
