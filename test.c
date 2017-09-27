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
	SIZE
};

void menu()
{
	printf("******************************************\n");
	printf("*********      Linked List       *********\n");
	printf("*********  0.exit        1.PusB  *********\n");
	printf("*********  2.PopB        3.Prin  *********\n");
	printf("*********  4.PusF        5.PopF  *********\n");
	printf("*********  6.Inse        7.Find  *********\n");
	printf("*********  8.Eras        9.Size*********\n");
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
		default:
			printf("输入错误，请重新输入:>");
			break;
		}

	}while(input);
}

int main()
{
	test();
	system("pause");
	return 0;
}
