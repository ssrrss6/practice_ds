#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>

#define datatype int


typedef struct Lnode
{
	datatype data;
	struct Lnode* next;
}Lnode, *LinkList;

//����һ����ͷ���Ŀ�����
Lnode* GetLinkList(LinkList L)
{
	L = (Lnode*)malloc(sizeof(Lnode));
	if (L == NULL)
	{
		return L;
	}
	L->data = 0;
	L->next = NULL;
	
	return L;
}

// ����ͷ�巨����һ��������
Lnode* CreateByHead(LinkList L)
{
	L = (Lnode*)malloc(sizeof(Lnode)); // ����ͷ�ڵ�
	if (L == NULL)
	{
		printf("����ʧ��\n");
		return L;
	}
	L->data = 0;
	L->next = NULL;

	Lnode* p = NULL;

	printf("���������ݣ������� -1 ��ʾ��������\n");
	datatype x = 0; // ����
	scanf("%d", &x);
	while (x != -1)
	{
		p = (Lnode*)malloc(sizeof(Lnode)); // �����½ڵ㡣
		if (p == NULL)
		{
			printf("����ʧ��\n");
			return NULL;
		}
		p->data = x;
		p->next = L->next; // ���½ڵ���뵽��ͷ��
		L->next = p; 
		scanf("%d", &x);
	}

	printf("�����ɹ�\n");
	return L;

}

// β�巨��������
Lnode* CreateList(LinkList L)
{
	L = (Lnode*)malloc(sizeof(Lnode)); // ����ͷ�ڵ�
	if (L == NULL)
	{
		printf("����ʧ��\n");
		return L;
	}
	L->data = 0;
	L->next = NULL;

	Lnode* p = NULL, *s = L;
	
	printf("���������ݣ����� -1 ��ʾ�������\n");
	datatype x = 0; // ����
	scanf("%d", &x);
	while (x != -1)
	{
		p = (Lnode*)malloc(sizeof(Lnode)); // ����һ���½ڵ�
		p->data = x;
		p->next = s->next; // ���½ڵ����ӵ���β
		s->next = p;
		s = p; // ��sָ��ָ���β��
		scanf("%d", &x);
	}

	printf("�����ɹ�\n");
	return L;

}

// ��ӡ������
int PrintList(LinkList L)
{
		if (L == NULL)
	{
		printf("����Ϊ��");
		return 0;
	}

	Lnode* p = L->next;
	
	printf("��������Ϊ\n");
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}

	printf("\n");
	return 1;
}

// �����������Ӧλ�ã������ز�ѯλ�õ�ǰ���ڵ�
Lnode* SearchList(LinkList L, int x)
{
	if (x < 1) 
	{
		printf("λ�÷Ƿ�\n");
		return NULL;
	}

	Lnode* p = L;

	while (p != NULL && x > 1) // p == NULL ��ʾ��ѯλ�ù���
	{
		p = p->next;
		x--;
	}

	return p;

}

// ��λ��������ݣ���壩
Lnode* InsertList(LinkList L, int x, datatype num)
{
	Lnode* p = SearchList(L, x); // �ҵ�����λֵ��ǰ���ڵ�

	if (p == NULL)
	{
		printf("λ�÷Ƿ�\n");
		return NULL;
	}
	else 
	{
		Lnode* s;
		s = (Lnode*)malloc(sizeof(Lnode)); // �����½ڵ�
		if (s == NULL)
		{
			printf("����ʧ��\n");
			return NULL;
		}
		s->data = num; // ��ֵ
		s->next = p->next; // ����
		p->next = s;

		printf("����ɹ�\n");
		return L;
	}

}

// ��ָ���ڵ�������ݣ���壩
int InsertNextNode(Lnode* p, datatype num)
{
	if (p == NULL)
	{
		printf("�ڵ�Ϊ��\n");
		return 0;
	}

	Lnode* s = (Lnode*)malloc(sizeof(Lnode));
	if (s == NULL)
	{
		printf("����ʧ��\n");
		return 0;
	}
	
	// ��������
	s->data = num;
	s->next = p->next;
	p->next = s;
	printf("����ɹ�\n");
	return 1;

}

int InsertPriorNode(Lnode* p, datatype num)
{
	if (p == NULL)
	{
		printf("�ڵ�Ϊ��\n");
		return 0;
	}

	Lnode* s = (Lnode*)malloc(sizeof(Lnode));
	if (s == NULL)
	{
		printf("����ʧ��\n");
		return 0;
	}

	s->next = p->next; // p�ڵ�����ڵ�
	p->next = s;
	s->data = p->data; // �����ڵ�����
	p->data = num;
	printf("����ɹ�\n");
	return 1;

}

// ��λɾ������
Lnode* DeleteList(LinkList L, int x)
{
	Lnode* p = SearchList(L, x);

	if (p == NULL)
	{
		printf("λ�÷Ƿ�\n");
		return NULL;
	}

	Lnode* s = p->next; // ȡ��Ҫɾ���Ľڵ�
	p->next = s->next; // ɾ���ڵ�
	free(s); 
	
	printf("ɾ���ɹ�\n");
	return L;
}



// ��ֵɾ��
Lnode* DeleteByContent(LinkList L, datatype num)
{

	Lnode* p = L;

	while (p->next) // ��ֵ������
	{
		if (p->next->data == num) // �ҵ�ǰ���ڵ�
		{
			Lnode* s = p->next;
			p->next = s->next;
			free(s);

			printf("ɾ���ɹ�\n");
			return L;
		}
		else
		{
			p = p->next;
		}
	}

		printf("�����޼�¼\n");
		return NULL;

}

// ��λ��ֵ
datatype GetElem(LinkList L, int x)
{
	Lnode* p = SearchList(L, x + 1);
	
	if (p == NULL)
	{
		printf("��ѯʧ��\n");
		return 0;
	}

	return p->data;
}

// ��ֵֵλ
int GetLocate(LinkList L, datatype num)
{
	int x = 0;
	Lnode* p = L;
	p = L->next;

	while (p)
	{
		if (p->data == num)
		{
			return x + 1;
		}
		else
		{
			p = p->next;
			x++;
		}
	}

	printf("��ѯʧ��\n");
	return 0;
}

Lnode* SearchNode(LinkList L, int x)
{
	Lnode* p = SearchList(L, x);
	if (p == NULL)
	{
		printf("����ʧ��\n");
		return NULL;
	}

	return p->next;
}

Lnode* ModifyData(LinkList L, int x, datatype num)
{
	Lnode* p = SearchList(L, x);

	if (p == NULL)
	{
		printf("λ�ô���\n");
		return NULL;
	}

	p->next->data = num;

	printf("�޸ĳɹ�\n");
	return L;
}


Lnode* DropList(LinkList L)
{
	Lnode* p = NULL;

	while (L)
	{
		p = L;
		L = L->next;
		free(p);
	}

	printf("���ٳɹ�\n");
	return L;
}

