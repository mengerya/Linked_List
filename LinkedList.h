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
// 逆向打印单链表 
void PrintListFromTail2Head(pNode pHead);
// 逆向销毁单链表 
void DestroyListFromTail2Head(pNode* pHead);
// 删除单链表的非尾结点 
void DeleteNotTailNode(pNode pos);
// 非头结点前插入data 
void InsertNotHead(pNode pos,DataType data);
// 单链表实现约瑟夫环 
pNode JosephCircle(pNode pHead, size_t M); 
// 单链表的逆置--前后指针 
pNode ReverseList_1(pNode pHead); 
// 单链表的逆置--头插法 
pNode ReverseList_2(pNode pHead); 
// 查找链表的中间结点---要求不能遍历单链表 
pNode FindMidNode(pNode pHead);
//使用冒泡对单链表进行排序
void BubbleSort(pNode pHead);
//合并两个已序链表，合并之后新链表仍然有序
pNode MergeList(pNode pHead1,pNode pHead2);
//查找无头单链表的倒数第K个节点
pNode FindLastKNode(pNode pHead,int K);
//删除无头单链表的倒数第K个节点
pNode DeleteLastKNode(pNode* pHead,int K);
//返回链表的最后一个节点
pNode BackList(pNode pHead);
// 判断链表是否带环，如果带环求环的长度，并给出入口点
pNode HasCircle(pNode pHead);
int GetCircleLen(pNode pHead);
pNode GetEnterNode(pNode pHead,pNode pMeetNode);
#endif //__LINKED_LIST__
