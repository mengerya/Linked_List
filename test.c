#define _CRT_SECURE_NO_WARNINGS 1  
#include<stdio.h>
#include<Windows.h>
#include"LinkedList.h"

enum
{
	EXIT,
	PUSB,
	POPB,
	PRIN,
	POSF,
	POPF,
	INSE,
	FIND,
	ERAS,
	SIZE,
        PRTH,
	DETH,
	DENT,
	INNH,
	JOCI,
	REL1,
	REL2,
	FIMN
};

void menu()
{
	printf("******************************************\n");
	printf("*********      Linked List       *********\n");
	printf("*********  0.exit        1.PusB  *********\n");
	printf("*********  2.PopB        3.Prin  *********\n");
	printf("*********  4.PusF        5.PopF  *********\n");
	printf("*********  6.Inse        7.Find  *********\n");
	printf("*********  8.Eras        9.Size  *********\n");
	printf("*********  10.PrTH       11.DeTH *********\n");
	printf("*********  12.DeNT       13.InNH *********\n");
	printf("*********  13.JoCi       14.ReL1 *********\n");
	printf("*********  15.ReL2       16.FiMN *********\n");
	printf("******************************************\n");
}

void test()
{
	int input = 0;
	/*int d = 0;*/
	pNode pHead;
	InitList(&pHead);
	do
	{
		menu();
		printf("请选择你要进行的操作:>");
		scanf("%d",&input);
		
		switch(input)
		{
		case EXIT:
			DestoryList(&pHead);
			break;
		case PUSB:
			PushBack(&pHead,2);
			break;
		case POPB:
			PopBack(&pHead);
			break;
		case PRIN:
			PrintList(pHead);
			break;
		case POSF:
			PoshFront(&pHead,3);
			break;
		case POPF:
			PopFront(&pHead);
			break;
		case INSE:
			{
				pNode pos;
			    pos = FindList(pHead,2);
			    Insert(pos,4);
			}
			break;
		case FIND:
			break;
		case ERAS:
			{
				pNode pos;
				pos = FindList(pHead,3);
				Erase(&pHead,pos);
			}
			break;
		case SIZE:
			int i=0;
			i = SizeList(pHead);
			printf("该链表的节点个数为：%d\n",i);
			break;
		case PRTH:
			PrintListFromTail2Head(pHead);
			break;
		case DETH:
			DestroyListFromTail2Head(&pHead);
			break;
		case DENT:
			{
				pNode pos;
				pos = FindList(pHead,2);
	            DeleteNotTailNode(pos);
			}
			break;
		case INNH:
			{
				pNode pos;
				pos = FindList(pHead,2);
				InsertNotHead(pos,4);
			}
			break;
		case JOCI:
			JosephCircle(pHead,3);
			break;
		case REL1:
			ReverseList_1(pHead);
			break;
		case REL2:
			ReverseList_2(pHead);
			break;
		case FIMN:
			FindMidNode(pHead);
			break;
		default:
			printf("输入错误，请重新输入:>");
			break;
		}

	}while(input);
}
//检测合成两个单链表
void test1()
{
	pNode pHead1;
	pNode pHead2;
	pNode pHead;
	InitList(&pHead1);
	InitList(&pHead2);
	PushBack(&pHead1,2);
	PushBack(&pHead1,4);
	PushBack(&pHead1,6);
	PushBack(&pHead1,8);
	PushBack(&pHead2,2);
	PushBack(&pHead2,3);
	PushBack(&pHead2,5);
	PushBack(&pHead2,7);
	PrintList(pHead1);
	PrintList(pHead2);
	pHead = MergeList(pHead1,pHead2);
	PrintList(pHead);
}
//检测查找一个单链表的倒数第k个节点
void test2()
{	
	pNode pHead1;
	pNode pHead;
	int k = 2;
	InitList(&pHead1);
	PushBack(&pHead1,2);
	PushBack(&pHead1,4);
	PushBack(&pHead1,6);
	PushBack(&pHead1,8);
	PrintList(pHead1);
	pHead = FindLastKNode(pHead1,k);
	PrintList(pHead);
}
int main()
{
	test2();
	//test1();
	//test();
	system("pause");
	return 0;
}
