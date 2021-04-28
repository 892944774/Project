#pragma once

typedef int DLDataType;
typedef struct DHCListNode
{
	DLDataType data;
	struct DHCListNode* next;   // 指向当前节点的下一个节点
	struct DHCListNode* prev;   // 指向当前节点的前一个节点
}DHCLNode;

// 将头节点创建好
DHCLNode* DHCListInit();
void DHCListPushBack(DHCLNode* pHead, DLDataType data);
void DHCListPopBack(DHCLNode* pHead);
void DHCListPushFront(DHCLNode* pHead, DLDataType data);
void DHCListPopFront(DHCLNode* pHead);
void DHCListInsrt(DHCLNode* pos, DLDataType data);
void DHCListErase(DHCLNode* pos);
DHCLNode* DHCListFind(DHCLNode* pHead, DLDataType data);
int DHCListSize(DHCLNode* pHead);
int DHCListEmpty(DHCLNode* pHead);
void DHCListClear(DHCLNode* pHead);
void DHCListDestroy(DHCLNode** pHead);


void TestDHCList();