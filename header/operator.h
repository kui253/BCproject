#ifndef _OPERATOR_H_
#define _OPERATOR_H_



typedef struct HOST {

	char m_name[10];//这个人的名字
	char m_phone[15];//记录这个人的电话号码
	char passport[20];//这个人的登陆密码
	char P_addr[20];//这个人的地址

	int carType;//车辆的类型
	char carBandhz[5];//用来储存车牌号中的汉字；
	char carBandstr[10];//用来储存汉字中的车牌号

	char InsAddr[20];//投保的城市
	char InsBandhz_car[5];//投保的车牌
	char InsBandstr_car[10];//投保的车牌2
	char Insphonenum_car[15];//投保的电话号码
	int Ins_Car[3];

	char InsPname_health[10];
	char InsBandhz_health[5];
	char InsBandstr_health[10];
	char Insphonenum_health[15];
	int Ins_Health;

	char InsPname_acci[10];
	char InsBandhz_acci[5];
	char InsBandstr_acci[10];
	char Insphonenum_acci[15];
	int Ins_Acci;

	char InsPname_travel[10];
	char InsBandhz_travel[5];
	char InsBandstr_travel[10];
	char Insphonenum_travel[15];
	int Ins_Travel;




}host;
typedef struct NODE {
	host hosts;
	struct NODE* next;
}node;
#endif
#include "public.h"
/*************************************************
这些函数是对应登陆的时候的操作
*************************************************/
//用来判断输入的密码是否正确

node* find_node(node* phead, char* phonenum);//这是一个查找指针，输入一个链表头和输入的电话，查找整个是不是存在

node* Create(node* phead);//用来读取txt文件中的数据，并创建链表

void writeAll(node* phead);//讲数据格式化写入
/************************************************
这些函数是对应新用户的相关操作
************************************************/
void add_back(node* phead,node* _curNode);//用来尾插新的数据结点，在新用户填写完相关信息之后就可以直接在系统里接上数据。

node* del_node(node* phead, char* phonenum);//在phead这个链表中删除指定的结点,这个结点同电话来索引

void clear_LinkNode(node* phead);//清空链表
