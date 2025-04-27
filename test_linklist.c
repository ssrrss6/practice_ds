#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include "test_linklist.h"

int main()
{
	//LinkList head;
	//head = NULL; // 声明一个不带头节点的单链表

	LinkList L = NULL;
	
	//// 测试头插法
	//L = CreateByHead(L);

	// 测试尾插法
	L = CreateList(L);

	//// 测试按位序后插
	//datatype num = 0;
	//int x = 0;
	//printf("请输入位置:>");
	//scanf("%d", &x);
	//printf("请输入数据:>");
	//scanf("%d", &num);
	//Lnode* t = InsertList(L, x, num); // 执行插入操作
	//if (t != NULL)
	//{
	//	L = t;
	//	PrintList(L);
	//}

	//// 测试删除操作
	//int x = 0;
	//printf("请输入要删除的位置:>");
	//scanf("%d", &x);
	//Lnode* t = DeleteList(L, x);
	//if (t != NULL)
	//{
	//	L = t;
	//	PrintList(L);
	//}

	//// 测试按值删除操作
	//int num = 0;
	//printf("请输入要删除的值:>");
	//scanf("%d", &num);
	//Lnode* t = DeleteByContent(L, num);
	//if (t != NULL)
	//{
	//	L = t;
	//	PrintList(L);
	//}

	////测试按位查找
	//int x = 0;
	//printf("请输入要查找的位置:>");
	//scanf("%d", &x);
	//datatype num = GetElem(L, x);
	//printf("%d", num);

	//// 测试按值查找
	//datatype num = 0;
	//printf("输入要查找的值:>");
	//scanf("%d", &num);
	//int x = GetLocate(L, num);
	//printf("%d", x);

	//// 测试修改数据
	//datatype num = 0;
	//printf("输入值:>");
	//scanf("%d", &num);
	//int x = 0;
	//printf("输入要修改的位置:>");
	//scanf("%d", &x);
	//Lnode* t = ModifyData(L, x, num);
	//if (t)
	//{
	//	L = t;
	//	PrintList(L);
	//}

	int x = 0;
	printf("输入位置:>");
	scanf("%d", &x);
	printf("输入值:>");
	int num = 0;
	scanf("%d", &num);
	
	Lnode* t = SearchNode(L, x);
	if (t != NULL)
	{
		InsertNextNode(t, num);
	}
	PrintList(L);

	// 销毁链表

	L = DropList(L);
	PrintList(L);

	/*
		p,s
		s->next = p-next;
		if(p->next != NULL)
		p->next->prior = s;
		s->prior = p;
		p->next = s;

		p,s
		p->next = s->next;
		if(s->next != NULL)
		s->next->prior = p;
		free(s);
	*/

	return 0;
}