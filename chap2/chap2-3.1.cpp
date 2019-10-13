#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
///纸牌游戏，小猫钓鱼

struct queue
{
	int data[1000];
	int head;
	int tail;
};

struct stack
{
	int data[10];
	int top;
};

int main()
{
	struct queue q1, q2;
	struct stack s;
	int book[10];
	int i, t;

	//初始化队列
	q1.head = 1;
	q1.tail = 1;
	q2.head = 1;
	q2.tail = 1;

	//处世栈
	s.top = 0;
	//初始化用来标记的数组，用来标记哪些牌已经在桌上
	for (i = 1; i <= 9; i++)
	{
		book[i] = 0;
	}
	//依次向队列插入6个数
	//小哼手上的6张牌
	for (i = 1; i <= 6; i++)
	{
		scanf("%d", &q1.data[q1.tail]);
		q1.tail++;
	}
	//小哈手上的6张牌
	for (i = 1; i <= 6; i++)
	{
		scanf("%d", &q2.data[q2.tail]);
		q2.tail++;
	}

	//当队列不为空的时候执行循环
	while (q1.head < q1.tail && q2.head < q2.tail)
	{
		t = q1.data[q1.head];//小哼出一张牌
		//判断小哼当前打出的牌是否能赢
		if (book[t] == 0)//表明桌上没有牌面为t的牌
		{
			//小哼此轮没有赢牌
			q1.head++;//小哼已经打出一张牌，所以要把打出的牌出队
			s.top++;
			s.data[s.top] = t;//再把打出的牌放到桌上，即入栈
			book[t] = 1;//标记桌上现在已经有牌面为t的牌
		}
		else
		{
			//小哼此轮可以赢牌
			q1.head++;//小哼已经打出一张牌，所以要把打出的牌出队
			q1.data[q1.tail] = t;//紧接着把打出的牌放到手中牌的末尾
			q1.tail++;

			//把桌上可以赢的牌依次放到手中牌的末尾
			while (s.data[s.top] != t)
			{
				book[s.data[s.top]] = 0;//取消标记
				q1.data[q1.tail] = s.data[s.top];//依次放入队尾
				q1.tail++;
				s.top--;//栈中少了一张牌，所以栈顶要减1
			}

			//收回桌上牌面为t的牌
			book[s.data[s.top]] = 0;
			q1.data[q1.tail] = s.data[s.top];
			q1.tail++;
			s.top--;
		}//end else 

		//小哼手中的牌如果已经打完，游戏结束
		if (q1.head == q1.tail)
			break;

		//小哈出一张牌
		t = q2.data[q2.head];

		//判断小哈当前打出的牌是否能赢牌
		if (book[t] == 0)
		{
			//小哈此轮没有赢牌
			q2.head++;
			s.top++;
			s.data[s.top] = t;
			book[t] = 1;
		}
		else
		{
			//小哈可以赢牌
			q2.head++;
			q2.data[q2.tail] = t;
			q2.tail++;

			//把桌上可以赢的牌依次让到手中牌的末尾
			while (s.data[s.top] != t)
			{
				book[s.data[s.top]] = 0;
				q2.data[q2.tail] = s.data[s.top];
				q2.tail++;
				s.top--;
			}//end while
			//收回桌上牌面为t的牌
			book[s.data[s.top]] = 0;
			q2.data[q2.tail] = s.data[s.top];
			q2.tail++;
			s.top--;
		}//end else

	}//end while 

	if (q2.head == q2.tail)
	{
		printf("小哼win\n");
		printf("小哼当前手中的牌是：");
		for (i = q1.head; i < q1.tail - 1; i++)
		{
			printf("%d ,", q1.data[i]);
		}

		//如果桌上有牌则依次输出桌上的牌
		if (s.top>0)
		{
			printf("\n桌上的牌是：");
			for (i = 1; i <= s.top; i++)
			{
				printf("%d ,", s.data[i]);
			}
		}
		else
		{
			printf("\n桌上已经没有牌了");
		}
	}
	else
	{
		printf("小哈win\n");
		printf("小哈当前手中的牌是：");
		for (i = q2.head; i <= q2.tail - 1; i++)
		{
			printf(" %d,", q2.data[i]);
		}
		//如果桌上有牌则依次输出桌上的牌
		if (s.top > 0)
		{
			printf("\n桌上的牌是");
			for (i = 1; i <= s.top; i++)
				printf(" %d,", s.data[i]);
		}
		else
		{
			printf("\n桌上已经没有牌了");
		}
	}
	

	
	system("pause");
	return 0;
}
