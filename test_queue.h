#pragma once
#include<stdio.h>
#include<stdlib.h>


// 顺序队列
//
// 
//#define ElemType int
//#define MAX_SIZE 5
//
//typedef struct SqQueue
//{
//	ElemType data[MAX_SIZE];
//	int front;
//	int rear;
//}SqQueue;
//
//// 初始化顺序队列
//int InitQueue(SqQueue* S)
//{
//	if (S == NULL)
//	{
//		return 0;
//	}
//
//	S->front = 0;
//	S->rear = 0;
//
//	return 1;
//}
//
//// 判断是否为空
//int IsEmpty(SqQueue* S)
//{
//	if (S == NULL)
//	{
//		return 0;
//	}
//
//	if (S->front == S->rear)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//// 入队
//int InsertElem(SqQueue* S, ElemType num)
//{
//	if (S == NULL)
//	{
//		printf("地址非法\n");
//		return 0;
//	}
//
//	if ((S->rear + 1) % MAX_SIZE == S->front)
//	{
//		printf("队列已满\n");
//		return 0;
//	}
//
//	S->data[S->rear++] = num;
//	S->rear %= MAX_SIZE;
//
//	return 1;
//}
//
//// 出队
//int GetElem(SqQueue* S)
//{
//	if (S == NULL)
//	{	
//		return 0;
//	}
//
//	if (S->front == S->rear)
//	{
//		printf("队列为空\n");
//		return 0;
//	}
//
//	ElemType data = 0;
//
//	data = S->data[S->front++];
//	S->front %= MAX_SIZE;
//
//	return data;
//}
//
//// 查询数据
//ElemType SearchElem(SqQueue S)
//{
//	if (S.front == S.rear)
//	{
//		return 0;
//	}
//
//	return S.data[S.front];
//}


// 链队列

#define ElemType int

typedef struct LinkNode
{
	ElemType data;
	struct LinkNode* next;
}LinkNode;

typedef struct LinkQueue
{
	LinkNode* front;
	LinkNode* rear;
}LinkQueue;

int InitQueue(LinkQueue* Q)
{
	LinkNode* t = (LinkNode*)malloc(sizeof(LinkNode));
	if (t == NULL)
	{
		printf("初始化失败\n");
		return 0;
	}

	Q->front = t;
	Q->rear = t;
	t->next = NULL;
	printf("初始化成功\n");

	return 1;
}

int IsEmpty(LinkQueue* Q)
{
	if (Q->front == Q->rear)
	{
		return 1;
	}

	return 0;
}

int EntryElem(LinkQueue* Q, ElemType num)
{
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	if (s == NULL)
	{
		return 0;
	}

	s->data = num;
	s->next = NULL;
	Q->rear->next = s;
	Q->rear = s;
	printf("增加成功\n");

	return 1;
}

int GetElem(LinkQueue* Q, ElemType* num)
{
	if (Q->front == Q->rear)
	{
		printf("队列为空\n");
		return 0;
	}
	LinkNode* s = Q->front->next;
	if (Q->rear == s)
	{
		Q->rear = Q->front;
	}
	Q->front->next = s->next;
	
	*num = s->data;

	free(s);

	return 1;
}

