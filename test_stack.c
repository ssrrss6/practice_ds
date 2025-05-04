#define _CRT_SECURE_NO_WARNINGS

#include "test_stack.h"
#include<stdio.h>

int main()
{
	/*
	// 顺序栈测试

	SqStack s;
	SqStack* sp = &s;
	int test = 0;

	test = InitStack(sp);
	if (test)
		printf("创建成功\n");
	else
		printf("创建失败\n");

	test = IsEmpty(sp);
	if (test)
		printf("栈为空\n");
	else
		printf("栈非空\n");

	ElemType num = 0;
	printf("请输入要压入栈中的值:>");
	scanf("%d", &num);

	test = InsertStack(sp, num);
	if (test)
	{
		printf("入栈成功\n");
	}
	else
		printf("入栈失败\n");

	num = GetElem(sp);
	if (num == 0)
	{
		printf("出栈失败\n");
	}
	else
	{
		printf("出栈成功，值为：%d", num);
	}

	DropStack(sp);*/


	// 链栈测试

	LiStack Lp = NULL;

	// 判空
	if (IsLiEmpty(Lp))
	{
		printf("栈为空\n");
	}
	else
		printf("栈非空\n");

	// 测试压栈

	ElemType num = 0;
	printf("请输入值:>");
	scanf("%d", &num);
	LiStack s = NULL;
	s = InsertLiStack(Lp, num);
	if (s != NULL)
	{
		Lp = s;
		printf("压栈成功\n");
	}
	else
		printf("压栈失败\n");

	// 测试出栈
	ElemType x = 0;

	s = GetLiElem(Lp, &x);
	Lp = s;
	printf("出栈成功，值为：%d", x);


	DropLiStack(Lp);

	return 0;
}