#include "public.h"
#include "Allpage.h"
char tempname[10];
int a = 0;

void main(){
	int graphdriver = VGA;
	int graphmode = VGAHI;
	FILE* fp;
	
	initgraph(&graphdriver, &graphmode, "C:\\borlandc\\bgi");
	g_pageBuy();

	getchar();
	closegraph();
}
void g_pageBuy(){
	
	cleardevice();
	setbkcolor(LIGHTGRAY);
	setcolor(WHITE);
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	circle(128,120,50);
	circle(256,120,50);
	circle(384,120,50);
	circle(512,120,50);
	setfillstyle(1,BLUE);
	floodfill(128,120,WHITE);
	setfillstyle(1,LIGHTGREEN);
	floodfill(256,120,WHITE);
	setfillstyle(1,LIGHTCYAN);
	floodfill(384,120,WHITE);
	setfillstyle(1,LIGHTRED);
	floodfill(512,120,WHITE);
	
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	outtextxy(95,113,"Car");
	line(256,90,256,150);
	line(226,120,286,120);
	ellipse(384,110,0,360,5,20);
	circle(384,150,3);
	outtextxy(465,113,"travel");
	
	//画下方的信息
	moveto(128,180);
	lineto(178,180);
	lineto(178,280);
	lineto(128,310);
	lineto(78,280);
	lineto(78,180);
	lineto(128,180);
	setfillstyle(1,BLUE);
	floodfill(128,190,WHITE);
	puthz(105,220,"车险",24,25,WHITE);
	
	moveto(128+128,180);
	lineto(178+128,180);
	lineto(178+128,280);
	lineto(128+128,310);
	lineto(78+128,280);
	lineto(78+128,180);
	lineto(128+128,180);
	setfillstyle(1,LIGHTGREEN);
	floodfill(256,190,WHITE);
	puthz(218,220,"健康险",24,25,WHITE);
	
	moveto(128+256,180);
	lineto(178+256,180);
	lineto(178+256,280);
	lineto(128+256,310);
	lineto(78+256,280);
	lineto(78+256,180);
	lineto(128+256,180);
	setfillstyle(1,LIGHTCYAN);
	floodfill(384,190,WHITE);
	puthz(346,220,"意外险",24,25,WHITE);
	
	moveto(128+384,180);
	lineto(178+384,180);
	lineto(178+384,280);
	lineto(128+384,310);
	lineto(78+384,280);
	lineto(78+384,180);
	lineto(128+384,180);
	setfillstyle(1,LIGHTRED);
	floodfill(512,190,WHITE);
	puthz(474,220,"旅行险",24,25,WHITE);
	//画操作界面
	circle(320,400,30);
	circle(320,400,40);
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	setfillstyle(1,DARKGRAY);
	setcolor(BLACK);
	fillellipse(320,400,29,29);
	setcolor(WHITE);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	outtextxy(305,395,"MENU");
}

