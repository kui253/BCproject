#ifndef _BDAN_H_
#define _BDAN_H_
#include "operator.h"
struct Bdan{
	//char B_sheetId[15];// 用来储存保单的单号(自动生成)

	char Bm_phone[15];//储存这个人的电话号码（来自txt）

	int B_price;//金额
	int isDeal;//是否审理成功
	int isHurt;//判断是不是受伤
	int isInLocal;//判断是不是在本地
	int isdamage;//判断又没有车损
	int ispassed;//用来判断是否审理
};

typedef struct BNode{
	struct Bdan B;
	struct BNode* next;
}Bnode;

void refund(Bnode* Bpcur,node* pcur);//理赔的函数

Bnode* initBnode();//初始化

void ListCreat(Bnode* header);//创建链表

void WriteToTxt(Bnode* header);//把这些写入到文件中

void clearBnode(Bnode* header);

void printBList(Bnode** Bpcur, int Lptimes, int seq);

void findChecked(Bnode* header);

// Bnode*mod4List(Bnode* Bptop);

void clearBar();
#endif