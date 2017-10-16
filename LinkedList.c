#include"LinkedList.h"
#include<stdio.h>
#include<assert.h>
#include<malloc.h>

void InitList(pNode* pHead)
{
	assert(pHead);
	*pHead = NULL;
}
pNode BuyNode(DataType data)
{
	pNode pNewNode = (pNode)malloc(sizeof(struct Node));
	if(NULL == pNewNode)
	{
		assert(0);
		return NULL;
	}
	pNewNode->_data = data;
	pNewNode->_pNext = NULL;
	return pNewNode;
}
void PushBack(pNode* pHead,DataType _data)
{
	assert(pHead);
	if(NULL == *pHead)
	{
		*pHead = BuyNode(_data);
	}
	else
	{
		pNode pTailNode = *pHead;
		while(pTailNode->_pNext)
		{
			pTailNode = pTailNode->_pNext;
		}
		pTailNode->_pNext = BuyNode(_data);
	}
}

void PopBack(pNode* pHead)
{
	if(NULL == *pHead)
		return;
	else if(NULL == (*pHead)->_pNext)
	{
		free(*pHead);
		*pHead = NULL;
	}
	else
	{
		pNode pTailNode = *pHead;
		pNode pPre = NULL;
		while(pTailNode->_pNext)
		{
			pPre = pTailNode;
			pTailNode = pTailNode->_pNext;
		}
		pPre->_pNext = NULL;
		free(pTailNode);
	}
}
void PrintList(pNode pHead)
{
	pNode pCur = pHead;
	while(pCur)
	{
		printf("%d--->",pCur->_data);
		pCur = pCur->_pNext;
	}
	printf("NULL\n");
}
void PoshFront(pNode* pHead,DataType data)
{
	pNode pNewNode;
	assert(pHead);
	pNewNode = BuyNode(data);
	if(NULL == pNewNode)
		return;
	pNewNode->_pNext = *pHead;
	*pHead = pNewNode;

}
void PopFront(pNode* pHead)
{
	pNode pCur = *pHead;
	assert(pHead);
	if(NULL == pCur)
		return;
	else
	{
		*pHead = (*pHead)->_pNext;
		free(pCur);
	}
}
pNode FindList(pNode pHead,DataType data)
{
	pNode pCur = pHead;
	while(pCur)
	{
		if(pCur->_data == data)
			return pCur;
		else
			pCur = pCur->_pNext;
	}
	return NULL;
}
pNode Insert(pNode pos,DataType data)
{
	pNode pNewNode;
	if(NULL == pos)
		return NULL;
	pNewNode = BuyNode(data);
	if(NULL == pNewNode)
		return NULL;
	pNewNode->_pNext = pos->_pNext;
	pos->_pNext = pNewNode;
}
void Erase(pNode* pHead,pNode pos)
{
	assert(pHead);
	if(NULL == *pHead || NULL == pos)
		return;
	if(*pHead == pos)
		PopFront(pHead);
	else
	{
		pNode pCur = *pHead;
		while(pCur)
		{
			if(pCur->_pNext == pos)
				break;
			pCur = pCur->_pNext;
		}
		pCur->_pNext = pos->_pNext;
		free(pos);
	}
}
void DestoryList(pNode* pHead)
{
	//正向销毁
	pNode pCur = *pHead;
	pNode pNext = NULL;
	while(pCur)
	{
		pNext = pCur->_pNext;
		free(pCur);
		pCur = pNext;
	}
	*pHead = NULL;
}
int SizeList(pNode pHead)
{
	int count = 1;
	pNode pCur = pHead;
	while(pCur)
	{
		count++;
		pCur = pCur->_pNext;
	}
	return count;
}

void PrintListFromTail2Head(pNode pHead)
{
	assert(pHead);
	if(pHead)
	{
		PrintListFromTail2Head(pHead->_pNext);
		printf("%d--->",pHead->_data);
	}
}

void DestroyListFromTail2Head(pNode* pHead)
{
	assert(pHead);
	if(pHead)
	{
		DestroyListFromTail2Head(&(*pHead)->_pNext);
		free(*pHead);
		*pHead = NULL;
	}
}

void DeleteNotTailNode(pNode pos)
{
	pNode pCur = NULL;
	if(pos)
	{
		pCur = pos->_pNext;
		pos->_data = pCur->_data;
		pos->_pNext = pCur->_pNext;
		free(pCur);
	}
}
// 非头结点前插入data 
void InsertNotHead(pNode pos,DataType data)
{
	pNode pNewNode;
	pNode pCur;
	if(NULL == pos)
		return;
	pNewNode = BuyNode(data);
	if(NULL == pNewNode)
		return;
	pCur = pos;
	pNewNode->_pNext = pCur->_pNext;
	pCur->_pNext = pNewNode;
}

// 单链表实现约瑟夫环 
pNode JosephCircle(pNode pHead, size_t M)
{
	pNode pCur;
	pNode pDel;
	int count = 0;
	if(NULL == pHead)
		return NULL;
	pCur = pHead;
	//构环
	while(pCur->_pNext)
	{
		pCur=pCur->_pNext;
	}
	pCur->_pNext = pHead;
	while(pCur != pCur->_pNext)
	{
		//报数
	    count = M;
	    while(--count)
	    {
		    pCur = pCur->_pNext;
	    }
	    //删节点
	    pDel = pCur->_pNext;
	    pCur->_data = pDel->_data;
	    pCur->_pNext = pDel->_pNext;
	    free(pDel);
	}
	//解环
	pCur->_pNext = NULL;
	return pCur;
}


// 单链表的逆置--前后指针 
pNode ReverseList_1(pNode pHead)
{
	pNode  pPre;
	pNode  pCur;
	pNode  pNext;
	if(NULL == pHead || NULL == pHead->_pNext)
		return NULL;
	pPre = pHead;
	pCur = pPre->_pNext;
	pNext = pCur->_pNext;
	pHead->_pNext = NULL;
	while(pNext)
	{
		pCur->_pNext = pPre;
		pPre = pCur;
		pCur = pNext;
		pNext = pCur->_pNext;
	}
	pCur->_pNext= pPre;
	return pCur;
}

// 单链表的逆置--头插法 
pNode ReverseList_2(pNode pHead)
{
	pNode pPre = NULL;
	pNode pCur = NULL;
	pNode pNewHead = NULL;
	if(NULL == pNewHead)
		return NULL;
	pPre = pHead;
	pCur = pHead->_pNext;
	while(pCur)
	{
		pPre->_pNext = pNewHead;
		pNewHead = pPre;
		pPre = pCur;
		pCur = pPre->_pNext;
	}
	pPre->_pNext = pNewHead;
	pNewHead = pPre;
	return pNewHead;
}
// 查找链表的中间结点---要求不能遍历单链表 
pNode FindMidNode(pNode pHead)
{
	pNode pSlow = pHead;
	pNode pFast = pHead;
	if(NULL == pHead)
		return NULL;
	while(pFast && pFast->_pNext)
	{
		pSlow = pSlow->_pNext;
		pFast = pFast->_pNext->_pNext;
	}
	return pSlow;
}
//冒泡排序
void BubbleSort(pNode pHead){
	pNode pCur = pHead;
	pNode pPreCur = NULL;
	pNode pTail = NULL;
	int ischange = 0;
	if(NULL == pHead || NULL == pHead->_pNext)
		return;
	while(pTail != pHead){
		pPreCur = pHead;
		pCur = pHead->_pNext;
		ischange = 0;
		while(pCur != pTail){
			if(pPreCur->_data > pCur->_data){
				DataType temp = 0;
				temp = pPreCur->_data;
				pPreCur->_data = pCur->_data;
				pCur->_data = temp;
				ischange = 1;
			}
			pPreCur = pCur;
			pCur = pCur->_pNext;
		}
		if(!ischange)
			pTail = pPreCur;
	}
}
//合并两个已序链表，合并之后新链表仍然有序
pNode MergeList(pNode pHead1,pNode pHead2){
	pNode pNewHead = NULL;
	pNode pCur1 = pHead1;
	pNode pCur2 = pHead2;
	pNode pTailNode = NULL;
	if(NULL == pCur1)
		return pCur2;
	if(NULL == pCur2)
		return pCur1;
	if(pCur1->_data <= pCur2->_data){
		pNewHead = pCur1;
		pTailNode = pCur1;
		pCur1 = pCur1->_pNext;
	}
	else{
		pNewHead = pCur2;
		pTailNode = pCur2;
		pCur2 = pCur2->_pNext;
	}
	while( pCur1 && pCur2){
		if(pCur1->_data < pCur2->_data){
			pTailNode->_pNext = pCur1;
			pCur1 = pCur1->_pNext;
		}
		else{
			pTailNode->_pNext = pCur2;
			pCur2 = pCur2->_pNext;
		}
		pTailNode = pTailNode->_pNext;
	}
	if(pCur1)
		pTailNode->_pNext = pCur1;
	if(pCur2)
		pTailNode->_pNext = pCur2;

	return pNewHead;
}
//查找无头单链表的倒数第K个节点
pNode FindLastKNode(pNode pHead,int K)
{
	pNode pFast = pHead;
	pNode pSlow = pHead;
	if(NULL == pHead || K<=0)
		return NULL;
	while(K--)
	{
		if(NULL == pFast)
			return NULL;
		pFast = pFast->_pNext;
	}
	while(pFast)
	{
		pFast = pFast->_pNext;
		pSlow = pSlow->_pNext;
	}
	return pSlow;
}
//删除无头单链表的倒数第K个节点
pNode DeleteLastKNode(pNode* pHead,int K){
	pNode pFast = *pHead;
	pNode pPreSlow = NULL;
	pNode pSlow = *pHead;
	if(NULL == *pHead || K<=0)
		return NULL;
	while(K--){
		if(NULL == pFast)
			return NULL;
		pFast = pFast->_pNext;
	}
	while(pFast){
		pFast = pFast->_pNext;
		pPreSlow = pSlow;
		pSlow = pSlow->_pNext;
	}
	pPreSlow->_pNext = pSlow->_pNext;
	return *pHead;
}
//判断链表是否带环
pNode HasCircle(pNode pHead)
{
	pNode pFast = pHead;
	pNode pSlow = pHead;
	if(NULL == pHead)
		return NULL;
	while(pFast && pFast->_pNext)
	{
		pFast = pFast->_pNext->_pNext;
		pSlow = pSlow->_pNext;
		if(pSlow == pFast)
			return pFast;
	}
	return NULL;
}
//得到带环链表环的长度
int GetCircleLen(pNode pHead)
{
	pNode pMeetNode = HasCircle(pHead);
	pNode pCur = pMeetNode;
	int count = 1;
	if(NULL == pMeetNode)
		return 0;
	while(pCur->_pNext != pMeetNode)
	{
		count++;
		pCur = pCur->_pNext;
	}
	return count;
}
//含环链表入口点
pNode GetEnterNode(pNode pHead,pNode pMeetNode)
{
	pNode pH = pHead;
	pNode pM = pMeetNode;
	if(NULL == pHead || NULL == pMeetNode)
		return NULL;
	while(pH != pM)
	{
		pH = pH->_pNext;
		pM = pM->_pNext;
	}
	return pH;
}

//判断两个链表是否相交(不含环)
int IsCrossWithoutCircle(pNode pHead1,pNode pHead2)
{
	pNode pTailNode1 = NULL;
	pNode pTailNode2 = NULL;
	if(NULL == pHead1 || NULL == pHead2)
		return 0;
	pTailNode1 = BackList(pHead1);
	pTailNode2 = BackList(pHead2);
	if(pTailNode1 == pTailNode2)
		return 1;
	return 0;
}
//两个链表相交的交点(不含环)
pNode GetCrossWithoutCircle(pNode pHead1,pNode pHead2)
{
	int size1 = 0,size2 = 0;
	int grap = 0;
	pNode pCur1 = pHead1;
	pNode pCur2 = pHead2;
	if(!IsCrossWithoutCircle(pHead1,pHead2))
		return NULL;
	size1 = SizeList(pHead1);
	size2 = SizeList(pHead2);
	grap = size1 - size2;
	if(grap>0)
	{
		while(grap--)
			pCur1 = pCur1->_pNext;
	}
	else
	{
		while(grap++)
			pCur2 = pCur2->_pNext;
	}
	while(pCur1 != pCur2)
	{
		pCur1 = pCur1->_pNext;
		pCur2 = pCur2->_pNext;
	}
	return pCur1;
}
