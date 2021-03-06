#include"stdafx.h"
#include <stdio.h> //头文件
#include <stdlib.h>
#include <malloc.h>
typedef int DataType;
typedef struct Node
{
	DataType data;
	struct Node *next;
} SLNode;

void ListInit(SLNode **head) //初始化单链表
{
	*head = (SLNode *)malloc(sizeof(SLNode));
	(*head)->next = NULL;
}

int ListLength(SLNode *head) //计算长度
{
	SLNode *p = head;
	int size = 0;

	while (p->next != NULL)
	{
		p = p->next;
		size++;
	}
	return size;
}

int ListInsert(SLNode *head, int i, DataType x) //插入数据
{
	SLNode *p, *q;
	int j;

	p = head;
	j = -1;
	while (p->next != NULL && j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (j != i - 1) //判断插入位置是否合法
	{
		printf("插入位置参数错！");
		return 0;
	}
	q = (SLNode *)malloc(sizeof(SLNode));
	q->data = x;
	q->next = p->next;
	p->next = q;
	return 1;
}
int ListDelete(SLNode *head, int i, DataType *x) //删除函数
{
	SLNode *p, *s;
	int j;
	p = head;
	j = -1;
	while (p->next != NULL && p->next->next != NULL && j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (j != i - 1) //判断删除位置是否合法
	{
		printf("删除位置参数错！");
		return 0;
	}

	s = p->next;
	*x = s->data;
	p->next = p->next->next;
	free(s);
	return 1;
}

int ListGet(SLNode *head, int i, DataType *x) //输出数据函数
{
	SLNode *p;
	int j;

	p = head;
	j = -1;
	while (p->next != NULL && j < i)
	{
		p = p->next;
		j++;
	}

	if (j != i)
	{
		printf("取元素位置错！");
		return 0;
	}
	*x = p->data;
	return 1;
}
void Destroy(SLNode **head) //销毁内存空间，以免造成内存泄漏
{
	SLNode *p, *p1;

	p = *head;
	while (p != NULL)
	{
		p1 = p;
		p = p->next;
		free(p1);
	}
	*head = NULL;
}

int main() //主函数
{
	SLNode *head;
	int i, x;

	ListInit(&head);
	for (i = 0; i < 10; i++)
		ListInsert(head, i, i + 1);
	ListDelete(head, 4, &x);
	for (i = 0; i < ListLength(head); i++)
	{
		ListGet(head, i, &x);
		printf("%d   ", x);
	}
	Destroy(&head);
	system("pause");
	return 0;
}