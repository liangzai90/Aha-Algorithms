#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
///链表,malloc内存分配

int main()
{
	int *p;//定义一个指针p

	//指针p获取动态分配的内存空间地址
	p = (int*)malloc(sizeof(int));

	*p = 10;//向指针p所指向的内存空间中存入10

	printf("%d", *p);//输出指针p所指向的内存中的值


	printf("\r\n");
	system("pause");
	return 0;
}
