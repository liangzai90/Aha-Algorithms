#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
///链表;模拟链表

int main()
{
	//data存放序列中具体数字
	//right存放当前序列中每一个元素右边的元素在数组data中的位置
	int data[101], right[101];
	int i, n, t, len;
	//读入已有的数
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &data[i]);
	}
	len = n;

	//初始化数组right
	for (i = 1; i <= n; i++)
	{
		if (i != n)
		{
			right[i] = i + 1;////初始值都是指向下一个 [索引]
		}
		else
		{
			right[i] = 0;
		}
	}

	//直接在数组data的末尾增加一个数
	len++;
	//right[len] = 0;
	printf("please insert one number:\r\n");
	scanf("%d", &data[len]);

	//从链表的头部开始遍历
	t = 1;
	while (t != 0)
	{
		//如果当前结点下一个结点的值大于待插入数，将数插入到中间
		if (data[right[t]] > data[len])
		{
			//新插入数的下一个结点标号等于当前结点的下一个结点
			right[len] = right[t];

			//当前结点的下一个结点编号就是新插入数的编号
			right[t] = len;

			//插入完成，跳出循环
			break;
		}
		
		t = right[t];
	}

	printf("right[t]:%d,right[len]:%d,t:%d,len:%d\r\n", right[t], right[len],t,len);

	//如果插入的元素在最末尾
	if (0 == t)
	{
		right[len] = 0;
		right[len - 1] = len;
	}

	//输出链表中所有的数
	t = 1;
	while (t != 0)
	{
		printf("%d ,", data[t]);
		t = right[t];
	}


	printf("\r\n");
	system("pause");
	return 0;
}
