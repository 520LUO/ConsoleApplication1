/**
动态申请空间创建的顺序表
实现功能：顺序表的创建与销毁 按位插入  按值查找 按值删除 按位删除 输出顺序表各元素

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
//按位删除
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
//按值删除
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
		printf("***********初始化成功**********\n");
	else
		printf("初始化失败！\n");
	
	do {
		printf("请输入欲插入的元素和位置：( -1 结束插入操作)\n");
		scanf("%d %d", &p,&e);
		bool f = Insert(&L, p, e);
		if (f == true)
			printf("插入元素成功\n");
		else
		{
			printf("插入元素操作已结束!\n");
			printf("****************\n");
		}
		printf("当前顺序表为：\n");
		PrintList(L);
	} while (p != -1);
	printf("\n请输入欲查询的元素：\n");
	scanf("%d",&s);
	int po = Search(L, s);
	if ( po!=-1)
		printf("查询元素在线性表中的位置为：%d\n",po+1);
	else
		printf("未在此顺序表中找到该元素\n");
	printf("\n按位删除：请输入欲删除的元素位置：\n");
	scanf("%d", &t1);
	int value;//存放删除位置的元素
	bool del1 = DelElem1(&L, t1, &value);
	if (del1 == true)
		printf("元素删除成功！\n");
	else
		printf("元素删除失败！\n");
	printf("当前顺序表为：\n");
	PrintList(L);
	printf("\n按值删除：请输入欲删除的元素：\n");
	scanf("%d", &t2);
	bool del2 = DelElem2(&L,t2);
	if (del2 == true)
		printf("元素删除成功！\n");
	else
		printf("元素删除失败！\n");
	printf("当前顺序表为：\n");
	PrintList(L);

	bool del =DelList(&L);
	if (del == true)
	printf("线性表已销毁！");
	else
	printf("线性表销毁失败！");

}