#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include "test_linklist.h"

int main()
{
	//LinkList head;
	//head = NULL; // ����һ������ͷ�ڵ�ĵ�����

	LinkList L = NULL;
	
	//// ����ͷ�巨
	//L = CreateByHead(L);

	// ����β�巨
	L = CreateList(L);

	//// ���԰�λ����
	//datatype num = 0;
	//int x = 0;
	//printf("������λ��:>");
	//scanf("%d", &x);
	//printf("����������:>");
	//scanf("%d", &num);
	//Lnode* t = InsertList(L, x, num); // ִ�в������
	//if (t != NULL)
	//{
	//	L = t;
	//	PrintList(L);
	//}

	//// ����ɾ������
	//int x = 0;
	//printf("������Ҫɾ����λ��:>");
	//scanf("%d", &x);
	//Lnode* t = DeleteList(L, x);
	//if (t != NULL)
	//{
	//	L = t;
	//	PrintList(L);
	//}

	//// ���԰�ֵɾ������
	//int num = 0;
	//printf("������Ҫɾ����ֵ:>");
	//scanf("%d", &num);
	//Lnode* t = DeleteByContent(L, num);
	//if (t != NULL)
	//{
	//	L = t;
	//	PrintList(L);
	//}

	////���԰�λ����
	//int x = 0;
	//printf("������Ҫ���ҵ�λ��:>");
	//scanf("%d", &x);
	//datatype num = GetElem(L, x);
	//printf("%d", num);

	//// ���԰�ֵ����
	//datatype num = 0;
	//printf("����Ҫ���ҵ�ֵ:>");
	//scanf("%d", &num);
	//int x = GetLocate(L, num);
	//printf("%d", x);

	//// �����޸�����
	//datatype num = 0;
	//printf("����ֵ:>");
	//scanf("%d", &num);
	//int x = 0;
	//printf("����Ҫ�޸ĵ�λ��:>");
	//scanf("%d", &x);
	//Lnode* t = ModifyData(L, x, num);
	//if (t)
	//{
	//	L = t;
	//	PrintList(L);
	//}

	int x = 0;
	printf("����λ��:>");
	scanf("%d", &x);
	printf("����ֵ:>");
	int num = 0;
	scanf("%d", &num);
	
	Lnode* t = SearchNode(L, x);
	if (t != NULL)
	{
		InsertNextNode(t, num);
	}
	PrintList(L);

	// ��������

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