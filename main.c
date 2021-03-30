#include "duLinkedList.h"
#include<stdio.h>
#include "malloc.h"
#include<conio.h>
#include<stdlib.h>

DuLinkedList L;
//创建节点 
DuLNode* CreateNode(int data){
	DuLNode* newNode=(DuLNode*)malloc(sizeof(DuLNode));
	newNode->data=data;
	newNode->next=NULL;
	newNode->prior=NULL;
	return newNode; 
}

//寻找节点位置并返回该节点
DuLNode* FindNode(DuLinkedList* L,int site){
	DuLNode* pMove=*L;
	if((*L)==NULL){
		printf("链表为空！");
		return NULL;
	}
	int i=0;
	while(i<site){
		pMove=pMove->next;
		i++;
	}
	return pMove;
} 

void FillNode(DuLinkedList L){
	printf("请输入你要存储的数据(整数):");
	int data;
	scanf("%d",&data);
	DuLNode* newNode=CreateNode(data);
	DuLNode* pMove=L;
	while(pMove->next!=NULL){
		pMove=pMove->next;
	}
	pMove->next=newNode;
	newNode->prior=pMove;
}

void Insert(){
	printf("\n\n\n");
	printf("1.节点前插入\n");
	printf("2.节点后插入\n");
	printf("请选择你要插入对应的编号：\n");
	int Type;
	scanf("%d",&Type);
	if(Type!=1&&Type!=2){
		printf("你的输入有误！");
		return;
	}
	printf("请输入你要在第几个前面/后面进行插入处理(整数):\n");
	int site;
	scanf("%d",&site);
	printf("请输入插入节点数据(整数)：\n");
	int data;
	scanf("%d",&data);
	DuLNode* p=FindNode(&L,site);
	DuLNode* q=CreateNode(data);
	if(Type==1){
		InsertBeforeList_DuL(p,q);
	}
	else if(Type==2){
		InsertAfterList_DuL(p,q);
	}
}

void DeleteNode(DuLinkedList L){
	printf("请输入你要删除的节点位置(整数)：\n");
	int Site;
	ElemType e;
	scanf("%d",&Site);
	DuLNode* p=FindNode(&L,Site-1);
	DeleteList_DuL(p,&e);
	printf("该节点对应的值为：%d\n",e);
}

void keyDown(){
	printf("-------------DuLinkedList--------------\n");
	printf("             1.数据填充                \n");
	printf("             2.插入节点                \n");
	printf("             3.遍历链表                \n");
	printf("             4.删除节点                \n");
	printf("             5.销毁链表                \n");
	printf("           请输入对应编号              \n\n\n");
	char ch=getch();
	switch(ch){
		case '1':
			FillNode(L);
			printf("按任意键继续...");
			getch();
			break;
		case '2':
			TraverseList_DuL(L,visit);
			Insert();
			printf("按任意键继续...");
			getch();
			break;
		case '3':
			TraverseList_DuL(L,visit);
			printf("按任意键继续...");
			getch();
			break;
		case '4':
			TraverseList_DuL(L,visit);
			printf("\n");
			DeleteNode(L);
			printf("按任意键继续...");
			getch();
			break;
		case '5':
			DestroyList_DuL(&L);
			break;
		default:
			printf("你的输入有误！");
			printf("按任意键继续...");
			getch();
			break;
	}
}


int main(){
	InitList_DuL(&L);
	while(1){
		system("cls");
		keyDown();
	}
	return 0;
}
