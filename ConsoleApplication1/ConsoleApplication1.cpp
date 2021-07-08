/**
��̬����ռ䴴����˳���
ʵ�ֹ��ܣ�˳���Ĵ��������� ��λ����  ��ֵ���� ��ֵɾ�� ��λɾ�� ���˳����Ԫ��

***/
#include <stdio.h>
#include <stdlib.h>
#define InitSize 100
#pragma warning(disable : 4996)
typedef struct {
	int* data;
	int MaxSize, length;
}SeqList;
bool InitList(SeqList * L ) {
	L->data = (int*)malloc(sizeof(int) * InitSize);
	if (L->data == NULL)
		return false;
	L->length = 0;
	L->MaxSize = InitSize;
	return true;
}
bool Insert(SeqList* L, int i,int e) {
	if (i<1||i>L->length +1)
		return false;
	if (L->length >= L->MaxSize)
		return false;
	for (int j=L->length; j>=i ; j--)
	{
		L->data[j] = L->data[j - 1];
		
	}
	L->data[i - 1] = e;
	L->length++;
	return true;

}
void PrintList(SeqList L)
{
	for (int i = 0; i < L.length; i++)
	{
		printf("%d  ", L.data[i]);
	}
	printf("\n");
}
//��λɾ��
bool DelElem1(SeqList* L,int p,int * e)
{
	if (L->length == 0)
		return false;
	for (int i = p-1; i < L->length; i++)
	{
		L->data[i] = L->data[i + 1];
	}
	*e = L->data[p-1];
	L->length--;
	return true;
}

bool DelList(SeqList* L)
{
	free(L->data);
	L->data =NULL;
	if (L->data!=NULL)
		return false;
	return true;
}
int Search(SeqList L, int e)
{
	for (int i = 0; i < L.length; i++)
	{
		if (L.data[i] == e)
			return i;
		
	}
	return -1;
}
//��ֵɾ��
bool DelElem2(SeqList* L, int e)
{
	if (L->length == 0)
		return false;
	int p = Search(*L, e);
	for (int i = p; i < L->length; i++)
	{
		L->data[i] = L->data[i + 1];
	}
	L->length--;
	return true;
}
void main() {
	SeqList L;
	int e, p, s,t1,t2;
	bool a= InitList(&L);
	if (a == true)
		printf("***********��ʼ���ɹ�**********\n");
	else
		printf("��ʼ��ʧ�ܣ�\n");
	
	do {
		printf("�������������Ԫ�غ�λ�ã�( -1 �����������)\n");
		scanf("%d %d", &p,&e);
		bool f = Insert(&L, p, e);
		if (f == true)
			printf("����Ԫ�سɹ�\n");
		else
		{
			printf("����Ԫ�ز����ѽ���!\n");
			printf("****************\n");
		}
		printf("��ǰ˳���Ϊ��\n");
		PrintList(L);
	} while (p != -1);
	printf("\n����������ѯ��Ԫ�أ�\n");
	scanf("%d",&s);
	int po = Search(L, s);
	if ( po!=-1)
		printf("��ѯԪ�������Ա��е�λ��Ϊ��%d\n",po+1);
	else
		printf("δ�ڴ�˳������ҵ���Ԫ��\n");
	printf("\n��λɾ������������ɾ����Ԫ��λ�ã�\n");
	scanf("%d", &t1);
	int value;//���ɾ��λ�õ�Ԫ��
	bool del1 = DelElem1(&L, t1, &value);
	if (del1 == true)
		printf("Ԫ��ɾ���ɹ���\n");
	else
		printf("Ԫ��ɾ��ʧ�ܣ�\n");
	printf("��ǰ˳���Ϊ��\n");
	PrintList(L);
	printf("\n��ֵɾ������������ɾ����Ԫ�أ�\n");
	scanf("%d", &t2);
	bool del2 = DelElem2(&L,t2);
	if (del2 == true)
		printf("Ԫ��ɾ���ɹ���\n");
	else
		printf("Ԫ��ɾ��ʧ�ܣ�\n");
	printf("��ǰ˳���Ϊ��\n");
	PrintList(L);

	bool del =DelList(&L);
	if (del == true)
	printf("���Ա������٣�");
	else
	printf("���Ա�����ʧ�ܣ�");

}