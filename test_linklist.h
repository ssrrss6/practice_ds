#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>

#define datatype int


typedef struct Lnode
{
	datatype data;
	struct Lnode* next;
}Lnode, *LinkList;

//创建一个带头结点的空链表
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

// 利用头插法创建一个单链表
Lnode* CreateByHead(LinkList L)
{
	L = (Lnode*)malloc(sizeof(Lnode)); // 创建头节点
	if (L == NULL)
	{
		printf("创建失败\n");
		return L;
	}
	L->data = 0;
	L->next = NULL;

	Lnode* p = NULL;

	printf("请输入数据，以输入 -1 表示结束输入\n");
	datatype x = 0; // 数据
	scanf("%d", &x);
	while (x != -1)
	{
		p = (Lnode*)malloc(sizeof(Lnode)); // 创建新节点。
		if (p == NULL)
		{
			printf("创建失败\n");
			return NULL;
		}
		p->data = x;
		p->next = L->next; // 将新节点插入到表头。
		L->next = p; 
		scanf("%d", &x);
	}

	printf("创建成功\n");
	return L;

}

// 尾插法创建链表
Lnode* CreateList(LinkList L)
{
	L = (Lnode*)malloc(sizeof(Lnode)); // 创建头节点
	if (L == NULL)
	{
		printf("创建失败\n");
		return L;
	}
	L->data = 0;
	L->next = NULL;

	Lnode* p = NULL, *s = L;
	
	printf("请输入数据，输入 -1 表示输入结束\n");
	datatype x = 0; // 数据
	scanf("%d", &x);
	while (x != -1)
	{
		p = (Lnode*)malloc(sizeof(Lnode)); // 创建一个新节点
		p->data = x;
		p->next = s->next; // 将新节点连接到表尾
		s->next = p;
		s = p; // 将s指针指向表尾。
		scanf("%d", &x);
	}

	printf("创建成功\n");
	return L;

}

// 打印单链表
int PrintList(LinkList L)
{
		if (L == NULL)
	{
		printf("链表为空");
		return 0;
	}

	Lnode* p = L->next;
	
	printf("链表内容为\n");
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}

	printf("\n");
	return 1;
}

// 查找链表的相应位置，并返回查询位置的前驱节点
Lnode* SearchList(LinkList L, int x)
{
	if (x < 1) 
	{
		printf("位置非法\n");
		return NULL;
	}

	Lnode* p = L;

	while (p != NULL && x > 1) // p == NULL 表示查询位置过长
	{
		p = p->next;
		x--;
	}

	return p;

}

// 按位序插入数据（后插）
Lnode* InsertList(LinkList L, int x, datatype num)
{
	Lnode* p = SearchList(L, x); // 找到插入位值的前驱节点

	if (p == NULL)
	{
		printf("位置非法\n");
		return NULL;
	}
	else 
	{
		Lnode* s;
		s = (Lnode*)malloc(sizeof(Lnode)); // 创建新节点
		if (s == NULL)
		{
			printf("插入失败\n");
			return NULL;
		}
		s->data = num; // 赋值
		s->next = p->next; // 插入
		p->next = s;

		printf("插入成功\n");
		return L;
	}

}

// 按指定节点插入数据（后插）
int InsertNextNode(Lnode* p, datatype num)
{
	if (p == NULL)
	{
		printf("节点为空\n");
		return 0;
	}

	Lnode* s = (Lnode*)malloc(sizeof(Lnode));
	if (s == NULL)
	{
		printf("插入失败\n");
		return 0;
	}
	
	// 插入数据
	s->data = num;
	s->next = p->next;
	p->next = s;
	printf("插入成功\n");
	return 1;

}

int InsertPriorNode(Lnode* p, datatype num)
{
	if (p == NULL)
	{
		printf("节点为空\n");
		return 0;
	}

	Lnode* s = (Lnode*)malloc(sizeof(Lnode));
	if (s == NULL)
	{
		printf("插入失败\n");
		return 0;
	}

	s->next = p->next; // p节点后插入节点
	p->next = s;
	s->data = p->data; // 交换节点数据
	p->data = num;
	printf("插入成功\n");
	return 1;

}

// 按位删除数据
Lnode* DeleteList(LinkList L, int x)
{
	Lnode* p = SearchList(L, x);

	if (p == NULL)
	{
		printf("位置非法\n");
		return NULL;
	}

	Lnode* s = p->next; // 取出要删除的节点
	p->next = s->next; // 删除节点
	free(s); 
	
	printf("删除成功\n");
	return L;
}



// 按值删除
Lnode* DeleteByContent(LinkList L, datatype num)
{

	Lnode* p = L;

	while (p->next) // 按值向后查找
	{
		if (p->next->data == num) // 找到前驱节点
		{
			Lnode* s = p->next;
			p->next = s->next;
			free(s);

			printf("删除成功\n");
			return L;
		}
		else
		{
			p = p->next;
		}
	}

		printf("表中无记录\n");
		return NULL;

}

// 按位查值
datatype GetElem(LinkList L, int x)
{
	Lnode* p = SearchList(L, x + 1);
	
	if (p == NULL)
	{
		printf("查询失败\n");
		return 0;
	}

	return p->data;
}

// 按值值位
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

	printf("查询失败\n");
	return 0;
}

Lnode* SearchNode(LinkList L, int x)
{
	Lnode* p = SearchList(L, x);
	if (p == NULL)
	{
		printf("查找失败\n");
		return NULL;
	}

	return p->next;
}

Lnode* ModifyData(LinkList L, int x, datatype num)
{
	Lnode* p = SearchList(L, x);

	if (p == NULL)
	{
		printf("位置错误\n");
		return NULL;
	}

	p->next->data = num;

	printf("修改成功\n");
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

	printf("销毁成功\n");
	return L;
}

