#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
///链表,了解指针是啥

int main()
{
	int a = 10;
	int *p;//定义一个指针p
	p = &a; //指针p获取变量a的地址
	printf("%d", *p);//输出指针p所指向的内存中的值

	

	printf("\r\n");
	system("pause");
	return 0;
}
