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

			printf("�������\n");
			int x = 5;
			while (x--)
			{
				datatype num = 0;
				printf("���������ݣ�");
				scanf("%d", & num);
				printf("%d\n", AddList(Lp, num));
				
			}
			PrintList(Lp);
			
			printf("\n��������\n");
			x = 2;
			while (x--)
			{
				datatype num = 0;
				int x = 0;
				printf("���������ݣ�");
				scanf("%d", &num);
				printf("������λ�ã�");
				scanf("%d", &x);
				printf("%d\n", InsertList(Lp, num, x));
				PrintList(Lp);
			}


			printf("\nɾ������\n");
			x = 2;
			while (x--)
			{
				datatype num = 0;
				int x = 0;
				printf("������λ�ã�");
				scanf("%d", &x);
				printf("%d\n", DeleteList(Lp, x));
				PrintList(Lp);
			}

			printf("\n��λ��������\n");
			x = 1;
			while (x--)
			{
				int x = 0;
				printf("������λ�ã�");
				scanf("%d", &x);
				printf("%d\n", GetElem(Lp, x));
			}

			printf("\n��ֵ��������\n");
			x = 1;
			while (x--)
			{
				datatype num = 0;
				printf("���������ݣ�");
				scanf("%d", &num);
				printf("%d\n", LocateElem(Lp, num));
			}

			printf("\n�޸�����\n");
			x = 1;
			while (x--)
			{
				datatype num = 0;
				int x = 0;
				printf("���������ݣ�");
				scanf("%d", &num);
				printf("������λ�ã�");
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