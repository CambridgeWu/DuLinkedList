#include "duLinkedList.h"
#include "malloc.h"
#include<stdio.h>
/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {
	*L=(DuLinkedList)malloc(sizeof(DuLNode));
	if(*L==NULL){
		return ERROR;
	}
	(*L)->prior=NULL;
	(*L)->next=NULL;
	return SUCCESS;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {
	DuLinkedList *p;
	while((*L)->next){
		*p=*L;
		*L=(*L)->next;
		free(*p);
	}
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
	if(p==NULL){
		return ERROR;
	}
	if(p->prior==NULL){
		q->next=p;
		p->prior=q;
		return SUCCESS;
	}
	DuLNode* pfront=p->prior;
	q->next=p;
	p->prior=q;
	pfront->next=q;
	q->prior=pfront;
	return SUCCESS;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
	if(p==NULL){
		return ERROR;
	}
	if(p->next==NULL){
		p->next=q;
		q->prior=p;
		return SUCCESS;
	}
	DuLNode* pbehind=p->next;
	q->next=pbehind;
	pbehind->prior=q;
	p->next=q;
	q->prior=p;
	return SUCCESS;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
	if(p==NULL||p->next==NULL){
		return ERROR;
	}
	DuLNode* pbehind=p->next;
	if(pbehind->next==NULL){
		*e=pbehind->data;
		p->next=NULL;
		free(pbehind);
		return SUCCESS;
	}
	(*e)=pbehind->data;
	p->next=pbehind->next;
	pbehind->next->prior=p;
	free(pbehind);
	return SUCCESS;
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void visit(ElemType e){
	printf("%d\t",e);
}
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
	DuLNode* pMove=L->next;
	while(pMove!=NULL){
		visit(pMove->data);
		pMove=pMove->next;
		}
}
