//sequence list func.c
#include <bits/stdc++.h>
#include "mergelist.h"

Status InitList_Sq(SqList &IniList){
	int elem_num; //元素个数
	int i;		  //循环变量
	int temp_elem;
	IniList.elem=(ElemType *) malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if(! IniList.elem) exit(OVERFLOW);  //内存分配失败
	IniList.curr_listlength=0;			//空表长度为0
	IniList.listsize=LIST_INIT_SIZE;	//初始长度
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
	free(CurrList.elem);
}

Status ListAppend_Sq(SqList &AppList, int elem_value){
	ElemType * new_elembase;
	if(AppList.curr_listlength>=AppList.listsize){
		new_elembase=(ElemType *)realloc( AppList.elem,(AppList.listsize+LISTINCREMENT)*sizeof(ElemType) );
		if(! new_elembase) exit(OVERFLOW);
		AppList.elem=new_elembase;
		AppList.listsize+=LISTINCREMENT;
	}
	AppList.elem[AppList.curr_listlength]=elem_value;
	++AppList.curr_listlength;
	return OK;
}

void Print_List(SqList &CurrList){
	for(int i=0;i<CurrList.curr_listlength;i++)
		printf("%d ",CurrList.elem[i]);
	printf("\n");
}

void MergeList_Sq(SqList La, SqList Lb, SqList &Lc) {
  ElemType *pa,*pb,*pc,*pa_last,*pb_last;
  pa = La.elem;  pb = Lb.elem;
  Lc.listsize = Lc.curr_listlength = La.curr_listlength+Lb.curr_listlength;
  pc = Lc.elem = (ElemType *)malloc(Lc.listsize*sizeof(ElemType));
  if (!Lc.elem)
    exit(OVERFLOW);
  pa_last = La.elem+La.curr_listlength-1;
  pb_last = Lb.elem+Lb.curr_listlength-1;
  while (pa <= pa_last && pb <= pb_last) {
    if (*pa <= *pb) *pc++ = *pa++;
    else *pc++ = *pb++;
  }
  while (pa <= pa_last) *pc++ = *pa++;
  while (pb <= pb_last) *pc++ = *pb++;
    // 已知顺序线性表La和Lb的元素按值非递减排列。
  // 归并La和Lb得到新的顺序线性表Lc，Lc的元素也按值非递减排列。
}
