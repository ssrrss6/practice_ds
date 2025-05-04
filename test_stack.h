#pragma once

#include<stdlib.h>

#define ElemType int
#define MAX_SIZE 5

//Ë³ÐòÕ¨=Õ»
typedef struct SqStack
{
	ElemType* data;
	int top;
}SqStack;

//³õÊ¼»¯
int InitStack(SqStack* s)
{
	ElemType* t = (ElemType*)malloc(sizeof(ElemType) * MAX_SIZE);
	if (t != NULL)
	{
		s->data = t;
		s->top = -1;

		return 1;
	}
	else
	{
		return 0;
	}
}

//ÅÐ¿Õ
int IsEmpty(SqStack* s)
{
	if (s->top == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

// Ñ¹Õ»
int InsertStack(SqStack* s, ElemType num)
{
	if (s->top >= MAX_SIZE - 1)
	{
		return 0;
	}

	s->data[++s->top] = num;

	return 1;
}

// ³öÕ»
ElemType GetElem(SqStack* s)
{
	if (s->top <= -1)
	{
		return 0;
	}

	return s->data[s->top--];
}

//Ð¤Õ½
int DropStack(SqStack* s)
{
	free(s->data);

	return 1;
}


//--------------------------------------------------------------------------------------------------------------------------


//Á´Õ»
typedef struct LinkNode
{
	ElemType data;
	struct LinkNode* next;
}*LiStack;

//ÅÐ¿Õ£¨²»´øÍ·½ÚµãµÄÕ»£©
int IsLiEmpty(LiStack L)
{
	if (L == NULL)
	{
		return 1;
	}

	return 0;
}

// Ñ¹Õ»
LiStack InsertLiStack(LiStack L, ElemType num)
{
	LiStack s = (LiStack)malloc(sizeof(struct LinkNode));

	if (s == NULL)
	{
		return NULL;
	}

	s->next = L;
	L = s;
	L->data = num;

	return L;
}

// ³öÕ»
LiStack GetLiElem(LiStack L, ElemType* num)
{
	if (L == NULL)
	{
		return NULL;
	}

	LiStack s = NULL;

	s = L;
	L = L->next;
	*num = s->data;
	free(s);

	return L;
}

DropLiStack(LiStack L)
{
	free(L);
}