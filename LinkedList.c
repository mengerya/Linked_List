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