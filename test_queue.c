#define _CRT_SECURE_NO_WARNINGS

#include"test_queue.h"

int main()
{
	// ˳����в���
	// 
	//SqQueue Q;
	//SqQueue* Qp = &Q;

	//int test = 0;

	//// ��ʼ��
	//test = InitQueue(Qp);
	//if (test)
	//{
	//	printf("��ʼ���ɹ�\n");
	//}
	//else
	//{
	//	printf("��ʼ��ʧ��\n");
	//}

	//// ��������
	//for (int i = 0; i < 4; i++)
	//{
	//	ElemType num;
	//	printf("������ֵ:>");
	//	scanf("%d", &num);

	//	test = InsertElem(Qp, num);
	//	if (test)
	//	{
	//		printf("�������ݳɹ�\n");
	//	}
	//	else
	//		printf("��������ʧ��\n");
	//}

	//// ����
	//ElemType num = 0;
	//num = GetElem(Qp);
	//if (num != 0)
	//{
	//	printf("\n���ӳɹ���ֵΪ��%d", num);
	//}
	//else
	//	printf("����ʧ��\n");


	//// �ٴ�ִ�����
	//printf("\n������ֵ:>");
	//scanf("%d", &num);

	//test = InsertElem(Qp, num);
	//if (test)
	//{
	//	printf("�������ݳɹ�\n");
	//}
	//else
	//	printf("��������ʧ��\n");
	//
	//// ���ִ�г��ӣ�ֱ������Ϊ��
	//for (int i = 0; i < 5; i++)
	//{
	//	ElemType num = 0;
	//	num = GetElem(Qp);
	//	if (num != 0)
	//	{
	//		printf("���ӳɹ���ֵΪ��%d\n", num);
	//	}
	//	else
	//		printf("����ʧ��\n");
	//}

	//test = IsEmpty(Qp);
	//if (test)
	//{
	//	printf("\n����Ϊ��\n");
	//}
	//else
	//{
	//	printf("�ǿ�\n");
	//}



	// �����в���
	
	LinkQueue Q;

	InitQueue(&Q);

	if (IsEmpty(&Q))
	{
		printf("����Ϊ��\n");
	}

	ElemType num = 0;
	for (int i = 0; i < 4; i++)
	{
		printf("����������:>");
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