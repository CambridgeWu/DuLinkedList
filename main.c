#include "duLinkedList.h"
#include<stdio.h>
#include "malloc.h"
#include<conio.h>
#include<stdlib.h>

DuLinkedList L;
//�����ڵ� 
DuLNode* CreateNode(int data){
	DuLNode* newNode=(DuLNode*)malloc(sizeof(DuLNode));
	newNode->data=data;
	newNode->next=NULL;
	newNode->prior=NULL;
	return newNode; 
}

//Ѱ�ҽڵ�λ�ò����ظýڵ�
DuLNode* FindNode(DuLinkedList* L,int site){
	DuLNode* pMove=*L;
	if((*L)==NULL){
		printf("����Ϊ�գ�");
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
	printf("��������Ҫ�洢������(����):");
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
	printf("1.�ڵ�ǰ����\n");
	printf("2.�ڵ�����\n");
	printf("��ѡ����Ҫ�����Ӧ�ı�ţ�\n");
	int Type;
	scanf("%d",&Type);
	if(Type!=1&&Type!=2){
		printf("�����������");
		return;
	}
	printf("��������Ҫ�ڵڼ���ǰ��/������в��봦��(����):\n");
	int site;
	scanf("%d",&site);
	printf("���������ڵ�����(����)��\n");
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
	printf("��������Ҫɾ���Ľڵ�λ��(����)��\n");
	int Site;
	ElemType e;
	scanf("%d",&Site);
	DuLNode* p=FindNode(&L,Site-1);
	DeleteList_DuL(p,&e);
	printf("�ýڵ��Ӧ��ֵΪ��%d\n",e);
}

void keyDown(){
	printf("-------------DuLinkedList--------------\n");
	printf("             1.�������                \n");
	printf("             2.����ڵ�                \n");
	printf("             3.��������                \n");
	printf("             4.ɾ���ڵ�                \n");
	printf("             5.��������                \n");
	printf("           �������Ӧ���              \n\n\n");
	char ch=getch();
	switch(ch){
		case '1':
			FillNode(L);
			printf("�����������...");
			getch();
			break;
		case '2':
			TraverseList_DuL(L,visit);
			Insert();
			printf("�����������...");
			getch();
			break;
		case '3':
			TraverseList_DuL(L,visit);
			printf("�����������...");
			getch();
			break;
		case '4':
			TraverseList_DuL(L,visit);
			printf("\n");
			DeleteNode(L);
			printf("�����������...");
			getch();
			break;
		case '5':
			DestroyList_DuL(&L);
			break;
		default:
			printf("�����������");
			printf("�����������...");
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
