#define _CRT_SECURE_NO_WARNINGS

#include "test_stack.h"
#include<stdio.h>

int main()
{
	/*
	// ˳��ջ����

	SqStack s;
	SqStack* sp = &s;
	int test = 0;

	test = InitStack(sp);
	if (test)
		printf("�����ɹ�\n");
	else
		printf("����ʧ��\n");

	test = IsEmpty(sp);
	if (test)
		printf("ջΪ��\n");
	else
		printf("ջ�ǿ�\n");

	ElemType num = 0;
	printf("������Ҫѹ��ջ�е�ֵ:>");
	scanf("%d", &num);

	test = InsertStack(sp, num);
	if (test)
	{
		printf("��ջ�ɹ�\n");
	}
	else
		printf("��ջʧ��\n");

	num = GetElem(sp);
	if (num == 0)
	{
		printf("��ջʧ��\n");
	}
	else
	{
		printf("��ջ�ɹ���ֵΪ��%d", num);
	}

	DropStack(sp);*/


	// ��ջ����

	LiStack Lp = NULL;

	// �п�
	if (IsLiEmpty(Lp))
	{
		printf("ջΪ��\n");
	}
	else
		printf("ջ�ǿ�\n");

	// ����ѹջ

	ElemType num = 0;
	printf("������ֵ:>");
	scanf("%d", &num);
	LiStack s = NULL;
	s = InsertLiStack(Lp, num);
	if (s != NULL)
	{
		Lp = s;
		printf("ѹջ�ɹ�\n");
	}
	else
		printf("ѹջʧ��\n");

	// ���Գ�ջ
	ElemType x = 0;

	s = GetLiElem(Lp, &x);
	Lp = s;
	printf("��ջ�ɹ���ֵΪ��%d", x);


	DropLiStack(Lp);

	return 0;
}