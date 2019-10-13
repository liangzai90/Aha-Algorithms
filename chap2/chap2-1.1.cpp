#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>

///队列，解密QQ号问题

int main()
{
	int q[102] = { 0, 6, 3, 1, 7, 5, 8, 9, 2, 4 }, head, tail;
	//初始化队列
	head = 1;
	tail = 10;//队列中已经有9个元素了，tail指向队尾的后一个位置（也就是索引10的位置）

	//当队列不为空，执行循环
	while (head < tail)
	{
		//打印队首并将队首出队
		printf("%d", q[head]);
		head++;

		//先将新队首的数添加到队尾
		q[tail] = q[head];
		tail++;

		//再讲队首出队
		head++;
	}

	
	system("pause");
	return 0;
}
