#define _CRT_SECURE_NO_WARNINGS

#include"test_queue.h"

int main()
{
	// 顺序队列测试
	// 
	//SqQueue Q;
	//SqQueue* Qp = &Q;

	//int test = 0;

	//// 初始化
	//test = InitQueue(Qp);
	//if (test)
	//{
	//	printf("初始化成功\n");
	//}
	//else
	//{
	//	printf("初始化失败\n");
	//}

	//// 增加数据
	//for (int i = 0; i < 4; i++)
	//{
	//	ElemType num;
	//	printf("请输入值:>");
	//	scanf("%d", &num);

	//	test = InsertElem(Qp, num);
	//	if (test)
	//	{
	//		printf("增加数据成功\n");
	//	}
	//	else
	//		printf("增加数据失败\n");
	//}

	//// 出队
	//ElemType num = 0;
	//num = GetElem(Qp);
	//if (num != 0)
	//{
	//	printf("\n出队成功，值为：%d", num);
	//}
	//else
	//	printf("出队失败\n");


	//// 再次执行入队
	//printf("\n请输入值:>");
	//scanf("%d", &num);

	//test = InsertElem(Qp, num);
	//if (test)
	//{
	//	printf("增加数据成功\n");
	//}
	//else
	//	printf("增加数据失败\n");
	//
	//// 多次执行出队，直到队列为空
	//for (int i = 0; i < 5; i++)
	//{
	//	ElemType num = 0;
	//	num = GetElem(Qp);
	//	if (num != 0)
	//	{
	//		printf("出队成功，值为：%d\n", num);
	//	}
	//	else
	//		printf("出队失败\n");
	//}

	//test = IsEmpty(Qp);
	//if (test)
	//{
	//	printf("\n队列为空\n");
	//}
	//else
	//{
	//	printf("非空\n");
	//}



	// 链队列测试
	
	LinkQueue Q;

	InitQueue(&Q);

	if (IsEmpty(&Q))
	{
		printf("队列为空\n");
	}

	ElemType num = 0;
	for (int i = 0; i < 4; i++)
	{
		printf("请输入数据:>");
		scanf("%d", &num);
		EntryElem(&Q, num);

	}


	for (int i = 0; i < 5; i++)
	{
		num = 0;
		GetElem(&Q, &num);
		printf("%d\n", num);
	}


	return 0;
}