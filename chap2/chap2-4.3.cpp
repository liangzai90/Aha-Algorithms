#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
///链表

struct node
{
	int data;
	struct node* next;
};

int main()
{
	struct node *head, *p, *q, *t;
	int i, n, a;
	scanf("%d", &n);
	head = NULL;//头指针初始化为空 
	p = NULL;
	q = NULL;////在vs2013环境下面，此处如果没有初始化会报错
	t = NULL;
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a);

		//动态申请一个空间，用来存放一个结点，并用临时指针p指向这个结点
		p = (struct node*)malloc(sizeof(struct node));
		p->data = a;//将数据存储到当前结点的data域中
		p->next = NULL;//设置当前结点的后记指针指向空，也就是当前结点的下一个结点为空

		if (head == NULL)
		{
			//如果这是第一个创建的结点，则将头指针指向这个结点
			head = p;
		}
		else
		{
			//如果不是第一个创建的结点，则将上一个结点的后继指针指向当前结点
			q->next = p;
		}

		//指针q也指向当前结点。。。p结点使命完成，q接替了p指针
		q = p;   ///very importent
	}

	//输出链表中的所有数
	t = head;
	while (t != NULL)
	{
		printf("%d ,", t->data);
		t = t->next;//继续下一个结点
	}



	printf("\r\n");
	system("pause");
	return 0;
}
