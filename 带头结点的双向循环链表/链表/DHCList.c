#define _CRT_SECURE_NO_WARNINGS 
#include "DHCList.h"

#include <malloc.h>
#include <assert.h>
#include <stdio.h>

//带头结点的双向循环链表
DHCLNode* BuyDHCListNode(DLDataType data)
{
	DHCLNode* newNode = (DHCLNode*)malloc(sizeof(DHCLNode));
	if (NULL == newNode)
		return NULL;

	newNode->data = 0;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

//只需要将头结点申请好
DHCLNode* DHCListInit()
{
	DHCLNode* head = BuyDHCListNode(0);
	head->next = head;
	head->prev = head;
	return head;
}

//尾插
void DHCListPushBack(DHCLNode* pHead, DLDataType data)
{
	DHCListInsrt(pHead, data);
}

//尾删
void DHCListPopBack(DHCLNode* pHead)
{
	if (DHCListEmpty(pHead))
		return;

	DHCListErase(pHead->prev);
}

void DHCListPushFront(DHCLNode* pHead, DLDataType data)
{
	if (DHCListEmpty(pHead))
		return;

	DHCListInsrt(pHead->next, data);
}

void DHCListPopFront(DHCLNode* pHead)
{
	if (DHCListEmpty(pHead))
		return;

	DHCListErase(pHead->next);
}

void DHCListInsrt(DHCLNode* pos, DLDataType data)
{
	if (pos == NULL)
		return 0;

	//0.申请新节点
	DHCLNode* newNode = BuyDHCListNode(data);

	//1.将新节点链接到原链表中
	newNode->next = pos;
	newNode->prev = pos->prev;

	//2.断开新链表，插入新节点
	pos->prev = newNode;
	newNode->prev->next = newNode;
}

//任意位置删除
void DHCListErase(DHCLNode* pos)
{
	if (pos == NULL)
		return;

	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
}

DHCLNode* DHCListFind(DHCLNode* pHead, DLDataType data)
{
	DHCLNode* cur = pHead->next;

	while (cur != pHead)
	{
		if (cur->data == data)
			return cur;
		cur = cur->next;
	}
	return NULL;
}

int DHCListSize(DHCLNode* pHead)
{
	DHCLNode* cur = pHead->next;

	int count = 0;
	while (cur != pHead)
	{
			++count;
			cur = cur->next;
	}
	return count;
}

int DHCListEmpty(DHCLNode* pHead)
{
	return pHead->next == pHead;
}

void DHCListClear(DHCLNode* pHead)
{
	DHCLNode* cur = pHead->next;

	while (cur != pHead)
	{
		pHead->next = cur->next;
		free(cur);
		cur = cur->next;
	}

	//链表已经为空
	pHead->next = pHead;
	pHead->prev = pHead;
}

void DHCListDestroy(DHCLNode** pHead)
{
	DHCListClear(*pHead);
	free(*pHead);
	*pHead == NULL;
}


void TestDHCList()
{
	DHCLNode* head = DHCListInit();
	DHCListPushBack(head, 1);
	DHCListPushBack(head, 2);
	DHCListPushBack(head, 3);
	DHCListPushBack(head, 4);
	DHCListPushBack(head, 5);
	PrintDHCList(head);

	DHCListPushFront(head, 0);
	PrintDHCList(head);

	DHCListPopBack(head);
	DHCListPopFront(head);
	PrintDHCList(head);

	DHCListInsrt(DHCListFind(head, 3), 100);
	PrintDHCList(head);

	DHCListErase(DHCListFind(head, 3));
	PrintDHCList(head);

	DHCListDestroy(&head);
}