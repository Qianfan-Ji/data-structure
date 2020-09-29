//linked list func.c
#include <bits/stdc++.h>
#include "mergelist.h"

Status InitList_Sq(SqList &IniList){
	int elem_num; //元素个数
	int temp_elem,i;
	ElemType *anew=NULL,*p=NULL;
	IniList.elem=p=IniList.now=(ElemType *) malloc(sizeof(ElemType));
	if(! IniList.elem) exit(OVERFLOW);
	for(i=1;i<LIST_INIT_SIZE;++i){
		anew=(ElemType*)malloc(sizeof(ElemType));
		p=p->next=anew;
	}
	IniList.tail=p;
	IniList.listsize=LIST_INIT_SIZE;
	printf("输入元素个数：");
	scanf("%d",&elem_num);
	printf("输入%d个元素值（整数）：\n",elem_num);
	if(elem_num>0){
		for(i=1;i<=elem_num;i++){
		scanf("%d",&temp_elem);
		ListAppend_Sq(IniList,temp_elem);
		}
	}
	return OK;
}

void DestoryList_Sq(SqList &CurrList){
	ElemType *p=NULL,*q=CurrList.elem;
	for(int i=0;i<CurrList.listsize;++i){
		p=q;
		q=p->next;
		free(p);
	}
}

Status ListAppend_Sq(SqList &AppList, int elem_value){
	ElemType *anew=NULL,*p=AppList.tail;
	if(AppList.curr_listlength>=AppList.listsize-1){
		for(int i=0;i<LISTINCREMENT;++i){
		anew=(ElemType*)malloc(sizeof(ElemType));
		p=p->next=anew;
		}
		AppList.listsize+=LISTINCREMENT;
		AppList.tail=p;
	}
	AppList.now->value=elem_value;
	AppList.now=AppList.now->next;
	++AppList.curr_listlength;
	return OK;
}

void Print_List(SqList &CurrList){
	ElemType *p=CurrList.elem;
	for(int i=0;i<CurrList.curr_listlength;++i){
		printf("%d ",p->value);
		p=p->next;
	}
	printf("\n");
}

void MergeList_Sq(SqList La, SqList Lb, SqList &Lc) {
  	ElemType *pa=La.elem,*pb=Lb.elem,*pc=Lc.elem;
  	Lc.curr_listlength=La.curr_listlength+Lb.curr_listlength;
  	while(Lc.listsize<=La.curr_listlength+Lb.curr_listlength-2){
  		ElemType *anew=NULL,*p=Lc.tail;
  		for(int i=0;i<LISTINCREMENT;++i){
			anew=(ElemType*)malloc(sizeof(ElemType));
			p=p->next=anew;
			}
		Lc.listsize+=LISTINCREMENT;
		Lc.tail=p;
  	}
  	while (pa!=La.now && pb!=Lb.now) {
    	if (pa->value <= pb->value) {pc->value = pa->value;pc=pc->next;pa=pa->next;}
    	else {pc->value = pb->value;pc=pc->next;pb=pb->next;}
  	}
  	while (pa!=La.now) {pc->value = pa->value;pc=pc->next;pa=pa->next;}
  	while (pb!=Lb.now) {pc->value = pb->value;pc=pc->next;pb=pb->next;}
  	Lc.now=pc;
    // 已知顺序线性表La和Lb的元素按值非递减排列。
  	// 归并La和Lb得到新的顺序线性表Lc，Lc的元素也按值非递减排列。
}
