#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	
#include"test_sqlist.h"

int main()
{
	sqlist L;
	sqlist* Lp = &L;

	int n = 0;
	n = InitSqlist(Lp);
	if (n)
	{
		printf("%d\n", n);
		n = ExtendSqlist(Lp, 5);
		if (n)
		{
			printf("%d\n", n);

			printf("添加数据\n");
			int x = 5;
			while (x--)
			{
				datatype num = 0;
				printf("请输入数据：");
				scanf("%d", & num);
				printf("%d\n", AddList(Lp, num));
				
			}
			PrintList(Lp);
			
			printf("\n插入数据\n");
			x = 2;
			while (x--)
			{
				datatype num = 0;
				int x = 0;
				printf("请输入数据：");
				scanf("%d", &num);
				printf("请输入位置：");
				scanf("%d", &x);
				printf("%d\n", InsertList(Lp, num, x));
				PrintList(Lp);
			}


			printf("\n删除数据\n");
			x = 2;
			while (x--)
			{
				datatype num = 0;
				int x = 0;
				printf("请输入位置：");
				scanf("%d", &x);
				printf("%d\n", DeleteList(Lp, x));
				PrintList(Lp);
			}

			printf("\n按位查找数据\n");
			x = 1;
			while (x--)
			{
				int x = 0;
				printf("请输入位置：");
				scanf("%d", &x);
				printf("%d\n", GetElem(Lp, x));
			}

			printf("\n按值查找数据\n");
			x = 1;
			while (x--)
			{
				datatype num = 0;
				printf("请输入数据：");
				scanf("%d", &num);
				printf("%d\n", LocateElem(Lp, num));
			}

			printf("\n修改数据\n");
			x = 1;
			while (x--)
			{
				datatype num = 0;
				int x = 0;
				printf("请输入数据：");
				scanf("%d", &num);
				printf("请输入位置：");
				scanf("%d", &x);
				printf("%d\n", ModifyElem(Lp, x, num));
				PrintList(Lp);

			}


		}
		else
		{
			printf("%d\n", n);
		}
	}
	else
	{
		printf("%d\n", n);
	}

	

	

	return 0;
}