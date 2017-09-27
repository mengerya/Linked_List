#ifndef __LINKED_LIST__
#define __LINKED_LIST__

typedef int DataType;
typedef struct Node
{
	DataType _data;
	struct Node * _pNext;
}*pNode;

void InitList(pNode* pHead);//初始化
void PushBack(pNode* pHead,DataType _data);//尾插数据
pNode BuyNode(DataType data);//构建新节点
void PopBack(pNode* pHead);//尾删
void PrintList(pNode pHead);//打印链表
void PoshFront(pNode* pHead,DataType data);//头插数据
void PopFront(pNode* pHead);//头删
void DestoryList(pNode* pHead);//销毁链表
pNode Insert(pNode pos,DataType data);//定向插入
pNode FindList(pNode pHead,DataType data);//查找
void Erase(pNode* pHead,pNode pos);//定向删除
int SizeList(pNode pHead);//节点个数
#endif //__LINKED_LIST__
