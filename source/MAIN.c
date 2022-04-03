#include "Bdan.h"
#include "public.h"
#include "Allpage.h"
#include "operator.h"
const char keypass[10] = "2111yyds";//密钥
int page = 1,fg1=1;//page 跳转页面函数,seq 用在Bdan里面
node* node_cur;
node* node_head;
//用来查保单的一些变量
Bnode* baod[6];
Bnode* Bnode_header;
	
void main(){
	int graphdriver = VGA;
	int graphmode = VGAHI;
	Bnode_header = initBnode();
	ListCreat(Bnode_header);

	initgraph(&graphdriver, &graphmode, "C:\\borlandc\\bgi");
	
	node_head = Create(node_head);
	node_cur = (node*)malloc(sizeof(node));//给这个临时的变量分配内存。
	while(fg1)
	{
		switch(page){
			case pageMain : 
			{
				g_pageMain();
				s_pageMain();	
				break;
			}
			case pageRegi :
			{	
				g_pageRegi();
				s_pageRegi();
				break;
			}
			case pageCarIfm : 
			{
				g_pageCarIfm();
				s_pageCarIfm();
				break;
			}
			case pageMenu :
			{
				g_pageMenu();
				s_pageMenu();
				break;
			}
			case pageBuy :
			{
				g_pageBuy();
				s_pageBuy();
				break;
			}
			case pageChangeIfm :
			{
				g_pageChangeIfm();
				s_pageChangeIfm();
				break;
			}
			case pageCarIns :
			{
				
				g_pageCarIns();
				s_pageCarIns();
				break;
			}
			case pageHealthIns :
			{
				g_pageHealthIns();
				s_pageHealthIns();
				break;
			}
			case pageTravelIns :
			{
				g_pageTravelIns();
				s_pageTravelIns();
				break;
			}
			case pageAcciIns :
			{
				g_pageAcciIns();
				s_pageAcciIns();
				break;
			}
			case pagePayIns :
			{
				g_pagePayIns();
				s_pagePayIns();
				break;
			}
			case pageShowIfm :
			{
				g_pageShowIfm();
				s_pageShowIfm();
				break;
			}
			case pageAdminLogin :{
				g_pageAdminLogin();
				s_pageAdminLogin();
				break;
			}
			case pageAdminMenu :{
				g_pageAdminMenu();
				s_pageAdminMenu();
				break;
			}
			case pageAdminCheck :{
				g_pageAdminCheck();
				s_pageAdminCheck();
				break;
			}
			case pageAdminDetail :{
				g_pageAdminDetail();
				s_pageAdminDetail();
				break;
			}
			case pageAdminDeal1:{
				g_pageAdminDeal1();
				s_pageAdminDeal1();
				break;
			}
			case pageAdminDeal2 : {
				g_pageAdminDeal2();
				s_pageAdminDeal2();
				break;
			}
			default :
			{
				printf("error!!!");
				fg1 = 0;
				break;
			}
		}
	}

	free(node_cur);
	WriteToTxt(Bnode_header);
	clear_LinkNode(node_head);
	clearBnode(Bnode_header);
	closegraph();
}



