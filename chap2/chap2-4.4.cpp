#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
///链表,；链表里面的数据是从下到大排序的，现在需要再中间插入某个数字，使该链表依然保持从小大到大的顺序

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
		t = t->next;//继续下一个结点  ////进行遍历输出之后，t的值是会改变的，下次再遍历的时候，需要重新用head赋值
	}
	printf("\r\n");


	//读入待插入的数
	printf("Please insert one number:\r\n");

	scanf("%d", &a);
	t = head;////进行遍历输出之后，t的值是会改变的，下次再遍历的时候，需要重新用head赋值

	while (t != NULL)
	{
		//如果当前结点是最后一个节点或下一个结点的值大于待插入数的时候，插入
		if (t->next == NULL || t->next->data > a)
		{
			//动态申请一个空间，用来存放新增结点
			p = (struct node *)malloc(sizeof(struct node));
			p->data = a;
			
			//【新增结点】的后继指针指向【当前结点的后继指针】所指向的结点
			p->next = t->next;

			//【当前结点】的后继指针指向【新增结点】
			t->next = p;
			
			//插入完毕退出循环
			break;
		}

		//继续下一个结点
		t = t->next;
	}


	printf("\r\n插入后的链表： \r\n");
	//输出链表中的所有数
	t = head;////进行遍历输出之后，t的值是会改变的，下次再遍历的时候，需要重新用head赋值
	while (t != NULL)
	{
		printf("%d ,", t->data);
		t = t->next;//继续下一个结点
	}


	printf("\r\n");
	system("pause");
	return 0;
}
