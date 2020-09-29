#include <bits/stdc++.h>
#include "mergelist.h"

int main(void)
{
	system("color 0D");
	printf("\t\t\t\t\t\t\033[43m 合并两个有序线性表：\033[0m\n");
	SqList ListA,ListB,ListC;
	printf("初始化第一个列表：\n");		InitList_Sq(ListA);
	printf("初始化第二个列表：\n");		InitList_Sq(ListB);
	printf("初始化第三个列表：\n");		InitList_Sq(ListC);
	
	MergeList_Sq(ListA,ListB,ListC);

	printf("第一个列表元素为：\n");		Print_List(ListA);
	printf("第二个列表元素为：\n");		Print_List(ListB);
	printf("合并后的列表元素为：\n");	Print_List(ListC);

	DestoryList_Sq(ListA);
	DestoryList_Sq(ListB);
	DestoryList_Sq(ListC);

	system("pause");

	return 0;
}
