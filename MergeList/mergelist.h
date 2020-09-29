//mergelist.h
//若进行链表实验，请 define linked-list
//#define linked-list
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define OK 1

#ifdef linked-list
typedef struct NODE{
	int value;
	struct NODE *next;
}node;
typedef node ElemType;
typedef struct{
	ElemType * elem=NULL;	//链表的首地址
	ElemType * now=NULL;    //链表的当前地址
	ElemType * tail=NULL;   //链表的尾地址
	int curr_listlength=0;	//线性表当前长度
	int listsize=0;			//目前已分配存储空间的线性表长度
}SqList;
#else
typedef int ElemType;
typedef struct{
	ElemType * elem=NULL;	//顺序表的首地址
	int curr_listlength=0;	//线性表当前长度
	int listsize=0;			//目前已分配存储空间的线性表长度
}SqList;
#endif
typedef int Status;

Status InitList_Sq(SqList &IniList);
void DestoryList_Sq(SqList &CurrList);
Status ListAppend_Sq(SqList &AppList, int elem_value);
void Print_List(SqList &CurrList);
void MergeList_Sq(SqList La, SqList Lb, SqList &Lc);
