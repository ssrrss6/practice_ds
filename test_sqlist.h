#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>

#define initsize 10
typedef int datatype;

typedef	struct sqlist
{
	datatype* data; 
	int maxsize; //����󳤶�
	int length;//��ǰ����
}sqlist;

int InitSqlist(sqlist* L) // ��ʼ��˳���
{
	if (L == NULL) // �жϱ��Ƿ�Ϸ�
	{
		return 0;
	}

	L->data = (datatype*)calloc(initsize, sizeof(datatype));
	if (L->data)
	{
		L->maxsize = initsize;
		L->length = 0;
		return 1;
	}
	else
	{
		return 0;
	}
}

// ��չ˳���
int ExtendSqlist(sqlist* L, int length) 
{
	if (L == NULL) // �жϱ��Ƿ�Ϸ�
	{
		return 0;
	}
	datatype* tmp = L->data;
	tmp = (datatype*)realloc(L->data, sizeof(datatype) * (L->maxsize + length));

	if (tmp)
	{
		L->data = tmp;
		L->maxsize += length;
		return 1;
	}
	else
	{
		return 0;
	}
}

// �������
int AddList(sqlist* L, datatype num) 
{
	if (L == NULL)
	{
		return 0;
	}

	L->data[L->length] = num;
	L->length++;

	return 1;
}

// ��������
int InsertList(sqlist* L, datatype num, int x) 
{
	if (L->length >= L->maxsize)
	{
		return 0;
	}

	if (x > L->length+1 || x < 1)
	{
		return 0;
	}

	int i = L->length;
	while (i > x - 1)
	{
		L->data[i] = L->data[i-1];
		i--;
	}
	L->data[x-1] = num;
	L->length += 1;

	return 1;
}

// ��λ��������
datatype GetElem(sqlist* L, int x)
{
	if (x < 1 || x > L -> length)
	{
		return 0;
	}

	return L->data[x - 1];
}

// ��ֵ��������
int LocateElem(sqlist* L, datatype num)
{
	for (int i = 0; i < L->length; i++)
	{
		if (L->data[i] == num)
		{
			return i + 1;
		}
	}

	return 0;
}

// ��λɾ������
datatype DeleteList(sqlist* L, int x) 
{
	if (x < 1 || x > L->length)
	{
		return 0;
	}

	datatype num = L->data[x - 1];
	for (int i = x - 1; i < L->length - 1; i++)
	{
		L->data[i] = L->data[i + 1];
	}
	L->length--;

	return num;
}

// �޸�����

int ModifyElem(sqlist* L, int x, datatype num)
{
	if (x < 1 || x > L->length)
	{
		return 0;
	}

	L->data[x - 1] = num;
	return 1;
}

PrintList(sqlist* L)
{
	for (int i = 0; i < L->length; i++)
	{
		printf("%d ", L->data[i]);
	}
}

