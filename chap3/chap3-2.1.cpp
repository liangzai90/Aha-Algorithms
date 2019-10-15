#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
///炸弹人

int main()
{
	char a[20][21];//假设这里的地图大小不超过20*20
	int i, j, sum, map = 0, p, q, x, y, n, m;
	//读入n和m，n表示有多少行字符，m表示每行有多少列
	scanf("%d %d", &n, &m);

	//读入n行字符
	for (i = 0; i <= n - 1; i++)
	{
		scanf("%s", a[i]); ///每次读入一行（m个字符串）
	}

	//用两重循环枚举地图的每个点
	for (i = 0; i <= n - 1; i++)
	{
		for (j = 0; j <= m - 1; j++)
		{
			//首先判断这个点是不是平地，是平地才可以被放置炸弹
			if (a[i][j] == '.')
			{
				//sum用来计数（可以消灭的敌人数），所以需要初始化为0
				sum = 0;

				//将当前坐标i,j复制到两个新变量x,y中，以便向上下左右四个方向分别统计可以消灭的敌人数
				/////向上统计可以消灭的敌人数
				x = i;
				y = j;
				//判断是不是墙，如果不是墙就继续
				while (a[x][y] != '#')
				{
					//如果当前点是敌人，则进行计数
					if (a[x][y] == 'G')
					{
						sum++;
					}
					///x--的作用是继续向上统计
					x--;
				}


				///向下统计可以消灭的敌人数
				x = i;
				y = j;
				while (a[x][y] != '#')
				{
					if (a[x][y] == 'G')
					{
						sum++;
					}
					x++;//继续向下
				}


				///向左统计可以消灭的敌人数
				x = i;
				y = j;
				while (a[x][y] != '#')
				{
					if (a[x][y] == 'G')
					{
						sum++;
					}
					y--;//继续向左
				}


				///向右统计可以消灭的敌人数
				x = i;
				y = j;
				while (a[x][y] != '#')
				{
					if (a[x][y] == 'G')
					{
						sum++;
					}
					y++;//继续向右
				}

				//更新map的值
				if (sum > map)
				{
					//如果当前所能消灭的敌人总数大于map，则更新map
					map = sum;
					//并用p,q记录当前点的坐标
					p = i;
					q = j;
				}//end if 
			}//end if

		}//end for
	}//end for


	printf("将炸弹放置在%d,%d，最多可以消灭%d个敌人. \r\n", p, q, map);



	printf("\r\n");
	system("pause");
	return 0;
}


/*

13  13 
#############
#GG.GGG#GGG.#
###.#G#G#G#G#
#.......#..G#
#G#.###.#G#G#
#GG.GGG.#.GG#
#G#.#G#.#.###
##G...G.....#
#G#.#G###.#G#
#...G#GGG.GG#
#G#.#G#G#.#G#
#GG.GGG#G.GG#
#############


运行结果是：在（9,9）处，最多可以消灭8个敌人
*/
