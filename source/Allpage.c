#include "public.h"
#include "Allpage.h"
#include "operator.h"
#include "Bdan.h"
extern const char keypass[10];
extern int n;
extern int n1;
extern int page;
extern  node* node_cur;
extern  node* node_head;
extern Bnode* Bnode_header;
extern Bnode* baod[6];//
node* nodeForDetail;
char tempkeypass[10];
int tmpCarType = 0;//用来记录当前的车辆的车辆的信息，因为在修改信息返回的时候要把框中的信息归位
char tmpPhonenum[15];
char tmpPassport[20];
char tmpCarBandhz[5];
char tmpCarBandstr[10];
char tmpAddr[20];
//输入字符的长度变量
int lenPageMain[2] = {0};
int lenPageRegi[5] = {0};
int lenPageChangeIfm[4] = {0};
int lenPageCarIns[4] = {0};//fg是用来总结while循环的,len是用来记录输入框的所长度
int lenPageCarIfm[3] = {0};
int lenPageHealthIns[4] = {0};
int lenPageAcciIns[4] = {0};
int lenPageTravelIns[4] = {0};
int lenPageAdminLogin = 0;
//信号灯变量
int fgCarIns[3] = {1};//这个用来判断选项是不是已经选择了
int fgHealthIns[3] = {1};
int fgTravelIns[3] = {1};
int fgAcciIns[3] = {1};
int fgCarIfm[3] = {1};
int fgChangeIfm[3] = {1};
//用于登陆的变量
char tempPhonenum[15],tempPassport[20];
//外加的用来解决买保险的相关问题
char tmpInsAddr[20],tmpInsPname[10],tmpInsBandhz[5],tmpInsBandstr[10],tmpInsPhonenum[15];
int tmpInsCar[3];
int tmpIns = 0;
int talPrice_dec = 0;
char talPrice_str[5];
char n_str[3];
int pagefg = 0;//用于判断是哪个界面过去的1、车险 2、健康险 3、意外险 4、旅行险

//用来管理员界面的状态
int pageMenuStatus[3] = {1};
int pageCheckStatus = 1;
int status = 1;
//查看用户信息的相关参数
int pageShowTimes = 0;
int dataRest = 0; 
char tempAdmin[15];
int lenAdminCheck = 0;
node* ptop[6];
node* p_cur;
int pageSeq = 0;
int y = 190;
int i = 1;
int looptimes = 3;
node* pcur;//这个pcur是用来处理点击的时候的将选中的node的内存赋值给它
//办理理赔的相关参数
int pageCheckStatus2 = 1;
int pageShowTimes2 = 0;
int dataRest2 = 0;
int seq = 0;
int j = 1;
char tempAdmin2[15] ;
Bnode* Baop[15];//用来存储未受理的地址
Bnode* Bp_cur;
int Lptimes = 4;
//外加用来接收数字格式的string样式

char tempPrice_str[10];
char tempBills_str[6];
//初始的登陆界面显示函数

void g_pageMain(){
    cleardevice();
	setbkcolor(LIGHTGRAY);
	setfillstyle(1,WHITE);
	//账号和密码的输入框
	bar(120,45,520,90);
	bar(120,135,520,180);
	puthz(60,55,"账号",24,25,WHITE);
	puthz(60,145,"密码",24,25,WHITE);
	
	
	//登陆框
	setcolor(WHITE);
	ellipse(225,280,90,270,20,20);
	ellipse(405,280,270,90,20,20);
	line(225,260,405,260);
	line(225,300,405,300);
	setfillstyle(1,LIGHTRED);
	floodfill(250,280,WHITE);
	puthz(290,270,"登陆",24,30,WHITE);
	
	//新用户
	ellipse(225,340,90,270,20,20);
	ellipse(405,340,270,90,20,20);
	line(225,320,405,320);
	line(225,360,405,360);
	setfillstyle(1,LIGHTRED);
	floodfill(250,330,WHITE);
	puthz(275,329,"新用户",24,30,WHITE);
	
	//退出框
	setfillstyle(1,RED);
	bar(480,395,560,435);
	puthz(505,410,"退出",16,15,WHITE);
	
	//小车
	setcolor(YELLOW);
	moveto(30,350);
	lineto(118,350);//B
	lineto(140,380);//C
	lineto(170,380);
	lineto(175,385);
	lineto(175,422);
	lineto(155,422);
	lineto(155,405);
	lineto(113,405);
	lineto(113,422);
	lineto(88,422);
	lineto(88,405);
	lineto(46,405);
	lineto(46,422);
	lineto(30,422);
	lineto(30,350);
	circle(67,425,15);
	circle(134,425,15);
	setfillstyle(1,DARKGRAY);
	circle(67,425,2);
	circle(134,425,2);
	floodfill(67,425,YELLOW);
	floodfill(134,425,YELLOW);
	setfillstyle(1,WHITE);
	floodfill(134,415,YELLOW);
	floodfill(67,415,YELLOW);
	setfillstyle(1,GREEN);
	floodfill(100,370,YELLOW);

	//admin button
	//admin button
	setcolor(WHITE);
	puthz(280,380,"我是管理员",16,15,LIGHTBLUE);
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	moveto(279,379);
	lineto(355,379);
	lineto(355,396);
}
void s_pageMain(){//（pending）
	mouseinit();
		while(1){
		newmouse(&MouseX,&MouseY,&press);
		//当点击退出时
		if(MouseX>480&&MouseX<560&&MouseY>395&&MouseY<435){
			if(mouse_press(480,395,560,435)==2){
				MouseS = 1;
				continue;
				
			}
			else if(mouse_press(480,395,560,435)== 1)
				clrmous(MouseX,MouseY);
				page = 'q';
				break;
		}
		//点击我是管理员时
		else if(MouseX>279&&MouseX<355&&MouseY>379&&MouseY<396){
			if(mouse_press(279,379,355,396) == 2){
				MouseS = 1;
				continue;
			}
			else if(mouse_press(279,379,355,396) == 1){
				clrmous(MouseX,MouseY);
				page = pageAdminLogin;
				break;
			}
		}
		//当点击新用户时
		else if (MouseX>225&&MouseX<405&&MouseY>320&&MouseY<360){
			if(mouse_press(225,320,405,360)==2){
				MouseS = 1;
				continue;
			}
			else if (mouse_press(225,320,405,360)==1){
				clrmous(MouseX,MouseY);
				page = pageRegi;
				break;
			}
		}
		else if(MouseX>225&&MouseX<405&&MouseY>260&&MouseY<300){//登陆
			if(mouse_press(225,260,405,300)==2){
				MouseS = 1;
				continue;
			}
			else if (mouse_press(225,260,405,300)== 1){
				if(lenPageMain[0]&&lenPageMain[1]){//两个都不为空
					if(strcmp(node_cur->hosts.passport,tempPassport) == 0){
						clrmous(MouseX,MouseY);
						page = pageMenu;
						break;
					}
					else{//显示密码错误（pending）
						setfillstyle(1,WHITE);
						bar(120,135,520,180);
						bar(120,45,520,90);
						lenPageMain[0] = 0;
						lenPageMain[1] = 0;
						puthz(240,400,"账号或密码错误，请重新输入",16,15,RED);
						delay(500);
						setfillstyle(1,LIGHTGRAY);
						bar(235,399,450,440);
						continue;
					}
					
				}
				else{
					puthz(290,400,"输入框为空！",16,15,RED);
					delay(500);
					setfillstyle(1,LIGHTGRAY);
					bar(280,399,440,440);
				}
			}
		}
		//账号
		else if(MouseX>120&&MouseX<520&&MouseY>45&&MouseY<90){
			if(mouse_press(120,45,520,90)==2){
				MouseS = 2;
				continue;
			}
			else if(mouse_press(120,45,520,90)==1){
				lenPageMain[0] = inputadmin(tempPhonenum,125,50,15,WHITE,32);
				
				node_cur = find_node(node_head,tempPhonenum);
				continue;
			}
		}
		//密码
		else if (MouseX>120&&MouseX<520&&MouseY>135&&MouseY<180){
			if(mouse_press(120,135,520,180)==2){
				MouseS = 2;
				continue;
			}
			else if (mouse_press(120,135,520,180)==1){
				lenPageMain[1] = inputpassword(tempPassport,125,140,20,WHITE);
				
			}
		}
		
		if(MouseS!=0)MouseS=0;

	}
	
	
}
void g_pageAdminLogin(){
	cleardevice();
	setbkcolor(LIGHTGRAY);
	setcolor(BLUE);
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	circle(320,110,40);
	ellipse(320,230,0,180,80,80);
	line(240,230,400,230);
	setfillstyle(1,WHITE);
	floodfill(320,140,BLUE);
	floodfill(320,170,BLUE);
	setcolor(BLUE);
	line(170,250,470,250);
	setcolor(WHITE);
	bar(160,270,480,320);
	puthz(170,280,"请输入密钥",32,30,LIGHTGRAY);
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	setcolor(DARKGRAY);
	line(165,276,165,314);
	//确定键
	setfillstyle(1,LIGHTGREEN);
	bar(250,340,390,380);
	puthz(295,350,"确定",24,30,DARKGRAY);
	
	//返回键
	setfillstyle(1,RED);
	bar(50,410,120,450);
	puthz(60,420,"返回",24,25,WHITE);
}
	
void s_pageAdminLogin(){
	//翻页用的一些数据
	//*********************
	n--;
	pageShowTimes = n/3;
	
	dataRest = n%3;
	ptop[0] = node_head;
	if(dataRest){
		pageShowTimes++;
	}
	for(i;i<pageShowTimes;i++){
		ptop[i] = modList(ptop[i-1]);
	}
	//*********************
	
	while(1){
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX>160&&MouseX<480&&MouseY>270&&MouseY<320){//输入框
			if(mouse_press(160,270,480,320) == 2){
				MouseS = 2;
				continue;
			}
			else if(mouse_press(160,270,480,320) == 1){
				setfillstyle(1,WHITE);
				bar(160,270,480,320);
				lenPageAdminLogin = inputadmin(tempkeypass,165,278,9,WHITE,32);
			}
		}
		else if (MouseX>250&&MouseX<390&&MouseY>340&&MouseY<380){//确定键
			if(mouse_press(250,340,390,380) == 2){
				MouseS = 1;
				continue;
			}
			else if(mouse_press(250,340,390,380) == 1){
				do{
					newmouse(&MouseX,&MouseY,&press);
				}while(mouse_press(250,340,390,380) == 1);
				if(lenPageAdminLogin){
					if(strcmp(tempkeypass,keypass) == 0){
						clrmous(MouseX,MouseY);
						page = pageAdminMenu;
						lenPageAdminLogin = 0;
						break;
					}
					else {
						puthz(300,410,"密钥错误",16,15,RED);
						setfillstyle(1,LIGHTGRAY);
						delay(500);
						bar(290,405,370,430);
						lenPageAdminLogin = 0;
						setfillstyle(1,WHITE);
						bar(160,270,480,320);
						continue;
					}
				}
				else {
					puthz(300,410,"输入为空",16,15,RED);
					delay(500);
					setfillstyle(1,LIGHTGRAY);
					bar(290,405,370,430);
					continue;
				}
				
			}
		}
		else if(MouseX>50&&MouseX<120&&MouseY>410&&MouseY<450){
			if(mouse_press(50,410,120,450) == 2){
				MouseS = 1;
				continue;
			}
			else if(mouse_press(50,410,120,450) == 1){
				clrmous(MouseX,MouseY);
				lenPageAdminLogin = 0;
				page = pageMain;
				break;
			}
		}
		if(MouseS!= 0)MouseS = 0;
	}
}
//管理员的操作界面
void g_pageAdminMenu(){
	cleardevice();
	setbkcolor(LIGHTGRAY);
	setfillstyle(1,DARKGRAY);
	bar(50,90,290,270);
	bar(350,90,590,270);
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	setcolor(WHITE);
	moveto(280,200);
	lineto(280,100);
	lineto(60,100);
	lineto(60,250);
	lineto(220,250);
	circle(100,140,10);
	moveto(100,160);
	lineto(80,200);
	lineto(120,200);
	lineto(100,160);
	line(140,140,240,140);
	line(140,160,230,160);
	line(140,180,250,180);
	circle(240,220,20);
	line(260,240,280,260);
	//第二块
	moveto(520,250);
	lineto(360,250);
	lineto(360,100);
	lineto(580,100);
	lineto(580,200);
	circle(400,140,10);
	moveto(400,160);
	lineto(380,200);
	lineto(420,200);
	lineto(400,160);
	line(440,140,540,140);
	line(440,160,530,160);
	line(440,180,550,180);
	moveto(550,210);
	lineto(560,200);
	moveto(550,210);
	lineto(540,200);
	moveto(550,210);
	lineto(550,250);
	line(535,210,565,210);
	line(535,226,565,226);
	//退出系统
	circle(320,380,50);
	circle(320,380,40);
	setfillstyle(1,RED);
	floodfill(320,380,WHITE);
	puthz(298,360,"退出",24,20,WHITE);
	puthz(290,385,"（下班）",16,15,WHITE);
	puthz(100,220,"查看用户信息",16,15,WHITE);
	puthz(400,220,"处理用户理赔",16,15,WHITE);
	puthz(40,40,"你好，管理员",16,15,WHITE);
}
void s_pageAdminMenu(){
	while(1){
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(50,90,290,270) == 0){
			puthz(100,220,"查看用户信息",16,15,WHITE);
			pageMenuStatus[0] = 1;
		}
		if(mouse_press(350,90,590,270) == 0){
			puthz(400,220,"处理用户理赔",16,15,WHITE);
			pageMenuStatus[1] = 1;
		}
		if(mouse_press(270,330,370,430) == 0){
			puthz(298,360,"退出",24,20,WHITE);
			puthz(290,385,"（下班）",16,15,WHITE);
			pageMenuStatus[2] = 1;
		}
		if(MouseX>270&&MouseX<370&&MouseY>330&&MouseY<430){//退出管理员系统
			if(mouse_press(270,330,370,430) == 2){
				MouseS = 1;
				if(pageMenuStatus[2]){
					puthz(298,360,"退出",24,20,YELLOW);
					puthz(290,385,"（下班）",16,15,YELLOW);
					pageMenuStatus[2] = 0;
				}
				continue;
			}
			else if(mouse_press(270,330,370,430) == 1){
				clrmous(MouseX,MouseY);
				page = pageMain;
				break;
			}
		}
		else if(MouseX>50&&MouseX<290&&MouseY>90&&MouseY<270){
			if(mouse_press(50,90,290,270) == 2){
				MouseS = 1;
				if(pageMenuStatus[0]){
					puthz(100,220,"查看用户信息",16,15,YELLOW);
					pageMenuStatus[0] = 0;
				}
				continue;
			}
			else if(mouse_press(50,90,290,270) == 1){
				clrmous(MouseX,MouseY);
				page = pageAdminCheck;
				break;
			}
		}
		else if(MouseX>350&&MouseX<590&&MouseY>90&&MouseY<270){
			if(mouse_press(350,90,590,270) == 2){
				MouseS = 1;
				if(pageMenuStatus[1]){
					puthz(400,220,"处理用户理赔",16,15,YELLOW);
					pageMenuStatus[1] = 0;
				}
				continue;
			}
			else if(mouse_press(350,90,590,270) == 1){
				do{
					newmouse(&MouseX,&MouseY,&press);
				}while(mouse_press(350,90,590,270) == 1);
				clrmous(MouseX,MouseY);
				page = pageAdminDeal1;//临时使用，后面要修改
				break;
			}
		}
	}
	
}

//管理员查看用户界面
void g_pageAdminCheck(){
	cleardevice();
	setbkcolor(LIGHTGRAY);
	setcolor(WHITE);
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	circle(480,30,10);
	ellipse(480,60,0,180,20,20);
	line(460,60,500,60);
	ellipse(490,54,0,90,17,14);
	ellipse(490,30,270,90,10,10);
	line(500,54,507,54);
	line(515,70,620,70);
	puthz(515,40,"总用户：",16,15,WHITE);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
	sprintf(n_str,"%d",n);

	outtextxy(585,35,n_str);
	setfillstyle(1,WHITE);
	bar(50,30,360,70);
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	setcolor(LIGHTGRAY);
	line(295,33,295,67);
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	puthz(55,37,"请输入要搜索的账号",24,25,LIGHTGRAY);
	puthz(305,37,"搜索",24,25,BLUE);
	setfillstyle(1,DARKGRAY);
	bar(40,100,600,360);
	setfillstyle(1,WHITE);
	bar(60,180,580,220);
	bar(60,240,580,280);
	bar(60,300,580,340);
	setcolor(BLUE);
	line(80,90+70,150,90+70);
	line(200,90+70,380,90+70);
	line(430,90+70,550,90+70);
	
	setcolor(WHITE);
	moveto(60,420);
	lineto(80,400);
	moveto(60,420);
	lineto(140,420);
	moveto(60,420);
	lineto(80,440);
	
	moveto(580,420);
	lineto(560,400);
	moveto(580,420);
	lineto(500,420);
	moveto(580,420);
	lineto(560,440);
	puthz(90,130,"姓名",24,25,WHITE);
	puthz(240,130,"电话号码",24,25,WHITE);
	puthz(440,130,"车牌号码",24,25,WHITE);
	if(dataRest&&pageSeq ==(pageShowTimes-1)){
		looptimes = dataRest;
		printList(ptop[pageSeq],looptimes);//让他显示现在所在的界面
		looptimes = 3;
	}
	else {
		
		printList(ptop[pageSeq],looptimes);
	}
}
void s_pageAdminCheck(){
	
	y = 190;
	while(1){
		newmouse(&MouseX,&MouseY,&press);
		
		if(MouseX>60&&MouseX<140&&MouseY>400&&MouseY<440){
			if(mouse_press(60,400,140,440) == 2){
				MouseS = 1;
				continue;
			}
			else if(mouse_press(60,400,140,440) == 1){
				do{
					newmouse(&MouseX,&MouseY,&press);
				}while(mouse_press(60,400,140,440) == 1);
				if(pageSeq == 0){
					clrmous(MouseX,MouseY);
					page = pageAdminMenu;
					pageSeq = 0;//重置一下pageSeq
					break;
				}
				else {
					
					pageSeq--;
					pageCheckStatus = 1;
					clearBlank();//清理一次显示的信息框
					printList(ptop[pageSeq],looptimes);
					continue;
				}
			}
		}
		else if(MouseX>500&&MouseX<580&&MouseY>400&&MouseY<440){
			
			if(mouse_press(500,400,580,440) == 2){
						MouseS = 1;
						continue;
				}
			else if(mouse_press(500,400,580,440) == 1){	
				if(pageSeq != (pageShowTimes -1)){
					do{
						newmouse(&MouseX,&MouseY,&press);
					}while(mouse_press(500,400,580,440) == 1);
					pageSeq ++;//这里偷了一下懒，直接用一个判断语句来防止后面继续循环
					if(pageSeq != (pageShowTimes -1)){
						clearBlank();
						printList(ptop[pageSeq],looptimes);
						continue;
					}
				}
				else{
					if(pageCheckStatus){
						//这里用来处理对于余数为0的情况。
						if(dataRest){			
							clearBlank();
							looptimes = dataRest;
							printList(ptop[pageShowTimes -1],looptimes);
							looptimes = 3;
							pageCheckStatus = 0;
						}
						else {
							clearBlank();
							printList(ptop[pageShowTimes-1],looptimes);
							pageCheckStatus = 0;
						}
					}
					
						
					if(mouse_press(500,400,580,440) == 1){
						puthz(290,410,"已经是最后一页了",16,15,RED);
						delay(500);
						setfillstyle(1,LIGHTGRAY);
						bar(285,405,440,470);
						
					}
						
				}
			}
		}
		else if(MouseX>50&&MouseX<295&&MouseY>30&&MouseY<70){
			if(mouse_press(50,30,295,70) == 2){
				MouseS = 2;
				continue;
			}
			else if(mouse_press(50,30,295,70) == 1){
				setfillstyle(1,WHITE);
				bar(50,30,293,70);
				lenAdminCheck = inputadmin(tempAdmin,52,35,11,WHITE,24);
			}
		}
		else if(MouseX>295&&MouseY<360&&MouseY>30&&MouseY<70){
			if(mouse_press(295,30,360,70) == 2){
				MouseS = 1;
				continue;
			}
			else if(mouse_press(295,30,360,70) == 1){
				if(!lenAdminCheck){
					puthz(250,410,"输入为空，请重新输入！",16,15,RED);
					delay(500);
					setfillstyle(1,LIGHTGRAY);
					bar(245,405,430,470);
				}
				else {
					p_cur = find_node(node_head,tempAdmin);
					if(p_cur != NULL){
						nodeForDetail = p_cur;
						clrmous(MouseX,MouseY);
						page = pageAdminDetail;
						break;
					}
					else{
						puthz(290,410,"未找到该用户",16,15,RED);
						delay(500);
						setfillstyle(1,LIGHTGRAY);
						bar(285,405,440,470);
					}
				}
			}
		}
		//后面的查看具体信息的相关参数
		if(pageSeq != (pageShowTimes-1)||!dataRest){
		
			if(MouseX>60&&MouseY<580&&MouseY>180&&MouseY<220){
				if(mouse_press(60,180,580,220) == 2){
					MouseS = 1;
					continue;
				}
				else if(mouse_press(60,180,580,220) == 1){
					clrmous(MouseX,MouseY);
					nodeForDetail = ptop[pageSeq];//把最上面的赋值，方便后面的显示
					page = pageAdminDetail;
					break;
				}
			}
			else if(MouseX>60&&MouseX<580&&MouseY>240&&MouseY<280){
				if(mouse_press(60,240,580,280) == 2){
					MouseS = 1;
					continue;
				}
				else if(mouse_press(60,240,580,280) == 1){
					clrmous(MouseX,MouseY);
					nodeForDetail = ptop[pageSeq]->next;
					page = pageAdminDetail;
					break;
				}
			}
			else if(MouseX>60&&MouseX<580&&MouseY>300&&MouseY<340){
				if(mouse_press(60,300,580,340) == 2){
					MouseS = 1;
					continue;
				}
				else if(mouse_press(60,300,580,340) == 1){
					clrmous(MouseX,MouseY);
					nodeForDetail = ptop[pageSeq]->next->next;
					page = pageAdminDetail;
					break;
				}
			}
		}
		if(pageSeq == (pageShowTimes-1)&& dataRest == 1){
			if(MouseX>60&&MouseY<580&&MouseY>180&&MouseY<220){
				if(mouse_press(60,180,580,220) == 2){
					MouseS = 1;
					continue;
				}
				else if(mouse_press(60,180,580,220) == 1){
					clrmous(MouseX,MouseY);
					nodeForDetail = ptop[pageSeq];//把最上面的赋值，方便后面的显示
					page = pageAdminDetail;
					break;
				}
			}
		}
		if(pageSeq == (pageShowTimes-1)&& dataRest == 2){
			if(MouseX>60&&MouseY<580&&MouseY>180&&MouseY<220){
				if(mouse_press(60,180,580,220) == 2){
					MouseS = 1;
					continue;
				}
				else if(mouse_press(60,180,580,220) == 1){
					clrmous(MouseX,MouseY);
					nodeForDetail = ptop[pageSeq];//把最上面的赋值，方便后面的显示
					page = pageAdminDetail;
					break;
				}
			}
			else if(MouseX>60&&MouseX<580&&MouseY>240&&MouseY<280){
				if(mouse_press(60,240,580,280) == 2){
					MouseS = 1;
					continue;
				}
				else if(mouse_press(60,240,580,280) == 1){
					clrmous(MouseX,MouseY);
					nodeForDetail = ptop[pageSeq]->next;
					page = pageAdminDetail;
					break;
				}
			}
		}	
		if(MouseS != 0)MouseS = 0;
	}
}

//管理员查看用户细节信息
void g_pageAdminDetail(){
	cleardevice();
	setbkcolor(LIGHTGRAY);
	setcolor(WHITE);
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	setfillstyle(1,DARKGRAY);
	bar(30,30,610,350);
	circle(60,55,12);
	moveto(45,75);
	lineto(60,112);
	lineto(75,75);
	lineto(45,75);


	
	//draw a passport
	ellipse(60,160,0,180,15,15);
	line(75,160,75,170);
	line(45,160,45,170);
	moveto(40,170);
	lineto(40,200);
	lineto(80,200);
	lineto(80,170);
	lineto(40,170);
	setfillstyle(1,LIGHTBLUE);
	bar(41,171,79,199);
	//draw a address
	moveto(35,280);
	lineto(60,245);
	lineto(85,280);
	circle(60,270,5);
	moveto(45,270);
	lineto(50,310);
	lineto(70,310);
	lineto(75,270);
	
	//draw a phone
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	setcolor(GREEN);
	setfillstyle(1,GREEN);
	fillellipse(335+10,85-9,35,35);
	setfillstyle(1,WHITE);
	sector(350,70,135,315,25,25);
	setfillstyle(1,GREEN);
	sector(350,70,135,315,11,11);
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);

	
	//draw a carBand
	setfillstyle(1,YELLOW);
	bar(310,150,380,190);
	setfillstyle(1,WHITE);
	bar(314,154,376,186);
	setcolor(DARKGRAY);
	moveto(325,180);
	lineto(335,165);
	lineto(345,180);
	lineto(355,165);
	lineto(365,180);
	
	
	//draw a cartype
	setfillstyle(1,LIGHTRED);
	fillellipse(345,280,35,25);
	setcolor(WHITE);
	line(400,300,580,300);
	line(400,200,580,200);
	line(400,100,580,100);
	line(100,300,280,300);
	line(100,200,280,200);
	line(100,100,280,100);
	//返回
	ellipse(225,400,90,270,20,20);
	ellipse(405,400,270,90,20,20);
	line(225,380,405,380);
	line(225,420,405,420);
	setfillstyle(1,LIGHTRED);
	floodfill(250,390,WHITE);
	puthz(285,389,"返回",24,30,WHITE);
	//显示信息
	puthz(120,60,nodeForDetail->hosts.m_name,32,30,WHITE);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 3);
	outtextxy(120,160,nodeForDetail->hosts.passport);
	outtextxy(410,60,nodeForDetail->hosts.m_phone);
	puthz(120,260,nodeForDetail->hosts.P_addr,24,24,WHITE);
	puthz(45,210,"密码",16,15,WHITE);
	puthz(45,120,"姓名",16,15,WHITE);
	puthz(45,320,"地址",16,15,WHITE);
	puthz(330,120,"电话",16,15,WHITE);
	puthz(330,210,"车牌",16,15,WHITE);
	outtextxy(320,265,"type");
	puthz(330,310,"车型",16,15,WHITE);
	puthz(420,160,nodeForDetail->hosts.carBandhz,32,1,WHITE);
	outtextxy(460,165,nodeForDetail->hosts.carBandstr);
	switch(nodeForDetail->hosts.carType){
		case 1:
			puthz(430,260,"轿车",24,25,WHITE);
			break;
		case 2 :
			puthz(430,260,"越野车",24,25,WHITE);
			break;
		case 3 :
			puthz(430,260,"货车",24,25,WHITE);
			break;
	}
}
void s_pageAdminDetail(){
	
	while(1){
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX>225&&MouseX<405&&MouseY>380&&MouseY<420){
			if(mouse_press(225,380,405,420) == 2){
				MouseS = 1;
				continue;
			}
			else if(mouse_press(225,380,405,420) == 1){
				clrmous(MouseX,MouseY);
				page = pageAdminCheck;
				break;
			}
		}
	}
}

void g_pageAdminDeal1(){
	cleardevice();
	setbkcolor(LIGHTGRAY);
	findChecked(Bnode_header);
	pageShowTimes2 = n1/4;
	dataRest2 = n1%4;
	
	if(dataRest2){
		pageShowTimes2++;
	}

	if(dataRest2&&seq == (pageShowTimes2-1)){
		Lptimes = dataRest2;
		printBList(Baop,Lptimes,seq);
		Lptimes = 4;
	}
	else{
		printBList(Baop,Lptimes,seq);
	}
}
void s_pageAdminDeal1(){
	
	while(1){
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX>80&&MouseX<140&&MouseY>420&&MouseY<460){
			if(mouse_press(80,420,140,460) == 2){
				MouseS = 1;
				continue;
			}
			else if(mouse_press(80,420,140,460) == 1){
				do{
						newmouse(&MouseX,&MouseY,&press);
					}while(mouse_press(80,420,140,460) == 1);
				if(seq == 0){
					clrmous(MouseX,MouseY);
					page = pageAdminMenu;
					seq = 0;
					break;
				}
				else {
					seq--;
					pageCheckStatus2 = 1;
					clearBar();
					printBList(Baop,Lptimes,seq);
					continue;
				}
			}
		}
		else if(MouseX>500&&MouseX<560&&MouseY>420&&MouseY<460){
			if(mouse_press(500,420,560,460) == 2){
				MouseS = 1;
				continue;
			}
			else if(mouse_press(500,420,560,460) == 1){
				if(seq!= (pageShowTimes2-1)){
					do{
						newmouse(&MouseX,&MouseY,&press);
					}while(mouse_press(500,420,560,460) == 1);
					seq++;
					if(seq != (pageShowTimes2-1)){
						clearBar();
						printBList(Baop,Lptimes,seq);
						continue;
					}
				}
				else {
					if(pageCheckStatus2){
						if(dataRest2){
							clearBar();
							Lptimes = dataRest2;
							printBList(Baop,Lptimes,seq);
							Lptimes = 4;
							pageCheckStatus2 = 0;
						}
						else {
							clearBar();
							printBList(Baop,Lptimes,seq);
							pageCheckStatus2 = 0;
						}
					}
				}
				if(mouse_press(500,420,560,460) == 1){
					puthz(290,410,"已经是最后一页了",16,15,RED);
					delay(500);
					setfillstyle(1,LIGHTGRAY);
					bar(285,405,440,470);
				}
			}
		}
		if(MouseS !=0)MouseS = 0;
	}
	
}

void g_pageAdminDeal2(){
	cleardevice();
	setbkcolor(BLACK);
	setlinestyle(SOLID_LINE,0,1);
    setfillstyle(1,WHITE);
    bar(0,0,640,480);
	setfillstyle(1,LIGHTGRAY);
	bar(0,0,640,60);
	puthz(220,10,"理赔管理",32,50,WHITE);
	puthz(20,80,"您可审核的理赔如下",16,20,GREEN);

	setcolor(LIGHTGRAY);

	line(20,150,620,150);
	puthz(30,115,"投保额",16,20,BLACK);
	line(20,190,620,190);
	puthz(30,160,"申请理赔金额",16,20,BLACK);
	line(20,230,620,230);
	puthz(30,200,"申请人",16,20,BLACK);
	line(20,270,620,270);
	puthz(30,240,"联系电话",16,20,BLACK);
	line(20,350,620,350);
	puthz(45,290,"审批",32,40,BLACK);
	line(170,100,170,350);
	circle(190,290,10);
	puthz(210,285,"审批通过",16,20,BLACK);
	line(170,350,620,350);
	circle(190,325,10);
	puthz(210,325,"审核不通过",16,20,BLACK);
	rectangle(20,100,620,350);
	circle(320,405,40);
	setfillstyle(1,LIGHTGRAY);
	fillellipse(320,405,39,39);
	circle(320,405,25);
	setfillstyle(1,DARKGRAY);
	fillellipse(320,405,24,24);
	puthz(302,395,"返回",16,20,WHITE);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 3);
	sprintf(tempBills_str,"%d",node_cur->hosts.BillsPrice);
	//sprintf(tempPrice_str,"%d",
	// setcolor(BLACK);
	// outtextxy(300,110,"2000");
	// outtextxy(300,155,"20000");
	//outtextxy(300,235,node_cur->hosts);
	//puthz(300,195,node_cur->hosts.m_name,24,25,DARKGRAY);
	
}
void s_pageAdminDeal2(){
	while(1){
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX>280&&MouseX<360&&MouseY>365&&MouseY<445){
			if(mouse_press(280,365,360,445) == 2){
				MouseS = 1;
				continue;
			}
			else if(mouse_press(280,365,360,445) == 1){
				clrmous(MouseX,MouseY);
				page = pageAdminMenu;
				break;
			}
		}
		if(MouseS != 0)MouseS = 0;
	}

}
//新用户的界面函数,已修改
void g_pageRegi(){
	cleardevice();
	setbkcolor(LIGHTGRAY);
	puthz(70,60,"姓名",24,25,WHITE);
	puthz(70,130,"手机号",24,25,WHITE);//要给一个提示，让他的手机号要是11位
	puthz(70,200,"密码",24,25,WHITE);
	puthz(40,270,"确认密码",24,25,WHITE);
	setfillstyle(1,WHITE);
	bar(150,50,520,90);//姓名框
	bar(150,120,520,160);//密码框
	bar(150,190,520,230);//确认密码框
	bar(150,260,520,300);
	setfillstyle(1,LIGHTRED);
	bar(120,360,220,400);//上一页框
	bar(410,360,510,400);//下一页框
	puthz(130,370,"上一步",24,30,WHITE);
	puthz(420,370,"下一步",24,30,WHITE);
}
void s_pageRegi(){
	
	while(1){
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX>120&&MouseX<220&&MouseY>360&&MouseY<400){//上一页
			if(mouse_press(120,360,220,400) == 2){
				MouseS = 1;
				continue;
			}
			else if(mouse_press(120,360,220,400) == 1){
				clrmous(MouseX,MouseY);
				lenPageRegi[0] = 0;
				lenPageRegi[1] = 0;
				lenPageRegi[2] = 0;
				lenPageRegi[3] = 0;
				page = pageMain;
				break;
			}
		}
		else if(MouseX>410&&MouseX<510&&MouseY>360&&MouseY<400){//下一页
			if(mouse_press(410,360,510,400) == 2){
				MouseS = 1;
				continue;
			}
			else if(mouse_press(410,360,510,400) == 1){
				do{
					newmouse(&MouseX,&MouseY,&press);
				}while(mouse_press(410,360,510,400) == 1);
				clrmous(MouseX,MouseY);
				if(lenPageRegi[1]&&lenPageRegi[0]&&lenPageRegi[2]&&lenPageRegi[3]){
					if(lenPageRegi[1] != 11 ){
						puthz(275,410,"请输入十一位号码",16,15,RED);
						delay(500);
						setfillstyle(1,LIGHTGRAY);
						bar(245,410,400,440);
						continue;
					}
					if(strcmp(node_cur->hosts.passport,tempPassport) == 0){
						page = pageCarIfm;
						break;
					}
					else {
						setfillstyle(1,WHITE);
						bar(150,190,520,230);
						bar(150,260,520,300);
						lenPageRegi[2] = 0;
						lenPageRegi[3] = 0;
						puthz(250,420,"密码不同，请重新输入",16,15,RED);
						delay(500);
						setfillstyle(1,LIGHTGRAY);
						bar(245,410,400,440);
						continue;
					}
				}
				else{
					puthz(290,410,"输入框为空！",16,15,RED);
					delay(500);
					setfillstyle(1,LIGHTGRAY);
					bar(280,400,390,440);
				}
			}
		}
		else if(MouseX>150&&MouseX<520&&MouseY>50&&MouseY<90){//姓名
			if(mouse_press(150,50,520,90)== 2){
				MouseS = 2;
				continue;
			}
			else if(mouse_press(150,50,520,90)==1){
				lenPageRegi[0] = hz_input(155,52,520,92,node_cur->hosts.m_name,lenPageRegi[0],WHITE,DARKGRAY,32);
				
			}
		}
		else if(MouseX>150&&MouseX<520&&MouseY>120&&MouseY<160){//手机
			if(mouse_press(150,120,520,160)== 2){
				MouseS=2;
				continue;
			}
			else if(mouse_press(150,120,520,160)==1){
				lenPageRegi[1] = inputadmin(node_cur->hosts.m_phone,155,120,19,WHITE,32);
				
			}
		}
		else if(MouseX>150&&MouseX<520&&MouseY>190&&MouseY<230){//密码
			if(mouse_press(150,190,520,230)==2){
				MouseS=2;
				continue;
			}
			else if(mouse_press(150,190,520,230)==1){
				lenPageRegi[2] = inputpassword(tempPassport,155,195,19,WHITE);
			}
		}
		else if(MouseX>150&&MouseX<520&&MouseY>260&&MouseY<300){//确认密码
			if(mouse_press(150,260,520,300) == 2){
				MouseS = 2;
				continue;
			}
			else if(mouse_press(150,260,520,300) == 1){
				lenPageRegi[3] = inputpassword(node_cur->hosts.passport,155,265,19,WHITE);
			}
			//输入框的函数还没有实现
		}
		if(MouseS!=0)MouseS=0;
	}
} 


//车辆信息的输入函数(注册时)
void g_pageCarIfm(){//已修改
	cleardevice();
	setbkcolor(LIGHTGRAY);
	setfillstyle(1,WHITE);
	bar(140,105,510,150);
	bar(140,170,195,150+65);
	bar(210,170,510,150+65);
	puthz(80,120,"住址",24,20,WHITE);
	puthz(80,120+65,"车牌",24,20,WHITE);
	puthz(80,195+65,"车型",24,20,WHITE);
	setfillstyle(1,LIGHTRED);
	bar(120,360,220,400);//上一页框
	bar(410,360,510,400);//注册框
	puthz(130,370,"上一步",24,30,WHITE);
	puthz(430,370,"注册",24,30,WHITE);
	puthz(240,50,"录入其他信息",32,30,WHITE);
	setfillstyle(1,DARKGRAY);
	bar(160,170+65,440,270+65);
	setcolor(WHITE);
	
	circle(215,210+65,10);
	circle(300,210+65,10);
	circle(375,210+65,10);
	setfillstyle(1,LIGHTGRAY);
	setcolor(BLACK);
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	fillellipse(215,210+65,9,9);
	fillellipse(300,210+65,9,9);
	fillellipse(375,210+65,9,9);
	
	puthz(200,240+65,"轿车",16,15,BLUE);
	puthz(280,240+65,"越野车",16,15,YELLOW);
	puthz(360,240+65,"货车",16,15,RED);

	
	
	
	
}
void s_pageCarIfm(){//（注册的信息写入pending）2022/2/24

	while(1){
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX>120&&MouseX<220&&MouseY>360&&MouseY<400){//上一页
			if(mouse_press(120,360,220,400) == 2){
				MouseS = 1;
				continue;
			}
			else if(mouse_press(120,360,220,400) == 1){
				do{
					newmouse(&MouseX,&MouseY,&press);
				}while(mouse_press(120,360,220,400) == 1);
				lenPageCarIfm[0] = 0;
				lenPageCarIfm[1] = 0;
				fgCarIfm[0] = 1;
				fgCarIfm[1] = 1;
				fgCarIfm[2] = 1;
				
				page = pageRegi;
				break;
			}
		}
		else if(MouseX>410&&MouseX<510&&MouseY>360&&MouseY<400){//注册button
			if(mouse_press(410,360,510,400) == 2){
				MouseS = 1;
				continue;
			}
			else if(mouse_press(410,360,510,400) == 1){//这里还要判断一下输入框是不是输入正确的格式
				clrmous(MouseX,MouseY);
				if(lenPageCarIfm[0]&&lenPageCarIfm[1]&&!(fgCarIfm[0]&&fgCarIfm[1]&&fgCarIfm[2])){
					strcpy(node_cur->hosts.InsAddr,"0");
					strcpy(node_cur->hosts.InsBandhz_car,"0");
					strcpy(node_cur->hosts.InsBandstr_car,"0");
					strcpy(node_cur->hosts.Insphonenum_car,"0");
					strcpy(node_cur->hosts.InsPname_health,"0");
					strcpy(node_cur->hosts.InsBandhz_health,"0");
					strcpy(node_cur->hosts.InsBandstr_health,"0");
					strcpy(node_cur->hosts.Insphonenum_health,"0");
					strcpy(node_cur->hosts.InsPname_acci,"0");
					strcpy(node_cur->hosts.InsBandhz_acci,"0");
					strcpy(node_cur->hosts.InsBandstr_acci,"0");
					strcpy(node_cur->hosts.Insphonenum_acci,"0");
					strcpy(node_cur->hosts.InsPname_travel,"0");
					strcpy(node_cur->hosts.InsBandhz_travel,"0");
					strcpy(node_cur->hosts.InsBandstr_travel,"0");
					strcpy(node_cur->hosts.Insphonenum_travel,"0");
					node_cur->hosts.Ins_Car[0] = 0;
					node_cur->hosts.Ins_Car[1] = 0;
					node_cur->hosts.Ins_Car[2] = 0;
					node_cur->hosts.Ins_Health = 0;
					node_cur->hosts.Ins_Acci = 0;
					node_cur->hosts.Ins_Travel = 0;
					node_cur->hosts.BillsPrice = 0;
					add_back(node_head,node_cur);//把填写完的信息接到总链表中
					
					page = pageMenu;
					break;
				}
				else{
					puthz(290,410,"输入框为空！",16,15,RED);
					delay(500);
					setfillstyle(1,LIGHTGRAY);
					bar(280,400,390,440);
				}
			}
		}
		else if(MouseX>140&&MouseX<510&&MouseY>105&&MouseY<150){
			if(mouse_press(140,105,510,150) == 2){
				MouseS = 2;
				continue;
			}
			else if(mouse_press(140,105,510,150) == 1){
				lenPageCarIfm[0] = hz_input(140+5,105+5,510,150+5,node_cur->hosts.P_addr,lenPageCarIfm[0],WHITE,DARKGRAY,32);
			}
		}
		else if (MouseX>140&&MouseX<195&&MouseY>105+65&&MouseY<150+65){//车牌
			if(mouse_press(140,105+65,195,150+65)== 2){
				MouseS = 2;
				continue;
			}
			else if(mouse_press(140,105+65,195,150+65)== 1){
				lenPageCarIfm[1] = hz_input(140+5,105+5+65,195,150+5+65,node_cur->hosts.carBandhz,0,WHITE,DARKGRAY,32);
				continue;
			} 
			
		}			
	
		else if(MouseX>210&&MouseX<510&&MouseY>105+65&&MouseY<150+65){
			if(mouse_press(210,105+65,510,150+65) == 2){
				MouseS = 2;
				continue;
			}
			else if(mouse_press(210,105+65,510,150+65) == 1){
				lenPageCarIfm[2] = inputadmin(node_cur->hosts.carBandstr,215,110+65,10,WHITE,32);
				
			}
		}
		else if (MouseX>205&&MouseX<225&&MouseY>200+65&&MouseY<220+65){//选择按钮
			if(mouse_press(205,200+65,225,220+65)== 2){
				MouseS = 1;
				continue;
			}
			else if(mouse_press(205,200+65,225,220+65)==1){
				do{
					newmouse(&MouseX,&MouseY,&press);
				}while(mouse_press(205,200+65,225,220+65)==1);
				if(fgCarIfm[0]){
					clrmous(MouseX,MouseY);
					setcolor(BLACK);
					setlinestyle(SOLID_LINE,0,NORM_WIDTH);
					setfillstyle(1,RED);
					fillellipse(215,210+65,9,9);
					setfillstyle(1,LIGHTGRAY);
					fillellipse(300,210+65,9,9);
					fillellipse(375,210+65,9,9);
					fgCarIfm[0] = 0;
					fgCarIfm[1] = 1;
					fgCarIfm[2] = 1;
					node_cur->hosts.carType = 1;
				}
				else{
					clrmous(MouseX,MouseY);
					setcolor(BLACK);
					setlinestyle(SOLID_LINE,0,NORM_WIDTH);
					setfillstyle(1,LIGHTGRAY);
					fillellipse(215,210+65,9,9);
					fgCarIfm[0] = 1;
					
				}
			}
		}
		else if(MouseX>290&&MouseX<310&&MouseY>200+65&&MouseY<220+65){
			if(mouse_press(290,200+65,310,220+65)==2){
				MouseS = 1;
				continue;
			}
			else if(mouse_press(290,200+65,310,220+65)==1){
				do{
					newmouse(&MouseX,&MouseY,&press);
				}while(mouse_press(290,200+65,310,220+65)==1);
				if(fgCarIfm[1]){
					clrmous(MouseX,MouseY);
					setcolor(BLACK);
					setlinestyle(SOLID_LINE,0,NORM_WIDTH);
					setfillstyle(1,RED);
					fillellipse(300,210+65,9,9);
					setfillstyle(1,LIGHTGRAY);
					fillellipse(215,210+65,9,9);
					fillellipse(375,210+65,9,9);
					fgCarIfm[0] = 1;
					fgCarIfm[1] = 0;
					fgCarIfm[2] = 1;
					node_cur->hosts.carType = 2;
				}
				else {
					clrmous(MouseX,MouseY);
					setcolor(BLACK);
					setlinestyle(SOLID_LINE,0,NORM_WIDTH);
					setfillstyle(1,LIGHTGRAY);
					fillellipse(300,210+65,9,9);
					fgCarIfm[1] = 1;
					
				}
			}
		}
		else if(MouseX>365&&MouseX<385&&MouseY>200+65&&MouseY<220+65){
			if(mouse_press(365,200+65,385,220+65)==2){
				MouseS = 1;
				continue;
			}
			else if(mouse_press(365,200+65,385,220+65)==1){
				do{
					newmouse(&MouseX,&MouseY,&press);
				}while(mouse_press(365,200+65,385,220+65)==1);
				if(fgCarIfm[2]){
					clrmous(MouseX,MouseY);
					setcolor(BLACK);
					setlinestyle(SOLID_LINE,0,NORM_WIDTH);
					setfillstyle(1,RED);
					fillellipse(375,210+65,9,9);
					setfillstyle(1,LIGHTGRAY);
					fillellipse(215,210+65,9,9);
					fillellipse(300,210+65,9,9);
					fgCarIfm[0] = 1;
					fgCarIfm[1] = 1;
					fgCarIfm[2] = 0;
					node_cur->hosts.carType = 3;
				}
				else {
					clrmous(MouseX,MouseY);
					setcolor(BLACK);
					setlinestyle(SOLID_LINE,0,NORM_WIDTH);
					setfillstyle(1,LIGHTGRAY);
					fillellipse(375,210+65,9,9);
					fgCarIfm[2] = 1;
					
				}
			}
		}
		if(MouseS!=0)MouseS=0;	
	}
}

//使用菜单
void g_pageMenu(){//已修改
	cleardevice();
	setbkcolor(LIGHTGRAY);
	puthz(240,20,"欢迎使用",32,40,WHITE);
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	setcolor(WHITE);
	//画盾牌
	
	ellipse(160,100,0,180,40,13);
	moveto(120,100);
	lineto(120,155);
	lineto(130,170);
	lineto(160,190);
	lineto(190,170);
	lineto(200,155);
	lineto(200,100);
	setfillstyle(1,LIGHTBLUE);
	floodfill(160,100,WHITE);
	moveto(145,125);
	lineto(160,140);
	lineto(185,113);
	puthz(125,210,"买车险",24,25,WHITE);
	//画保单
	moveto(280,90);
	lineto(280,190);
	lineto(320,170);
	lineto(360,190);
	lineto(360,90);
	lineto(280,90);
	setfillstyle(1,GREEN);
	floodfill(290,100,WHITE);
	moveto(320,140);
	lineto(340,160);
	circle(306,126,12);
	puthz(285,210,"查保单",24,25,WHITE);
	//画理赔
	moveto(440,90);
	lineto(440,190);
	lineto(495,190);
	lineto(520,160);
	lineto(520,90);
	lineto(440,90);
	setfillstyle(1,RED);
	floodfill(450,100,WHITE);
	line(460,100,480,120);
	line(500,100,480,120);
	line(460,120,500,120);
	line(480,120,480,170);
	line(460,140,500,140);
	puthz(445,210,"办理赔",24,25,WHITE);
	//画下面的操作按键
	circle(320,400,25);
	setfillstyle(1,DARKGRAY);
	fillellipse(320,400,23,23);
	ellipse(350,400,270,90,25,30);
	moveto(350,370);
	lineto(480,370);
	lineto(505,400);
	lineto(480,430);
	lineto(350,430);
	setfillstyle(1,DARKGRAY);
	floodfill(390,380,WHITE);
	puthz(385,390,"修改信息",24,25,WHITE);
	ellipse(290,400,90,270,25,30);
	moveto(290,370);
	lineto(160,370);
	lineto(135,400);
	lineto(160,430);
	lineto(290,430);
	floodfill(240,400,WHITE);
	puthz(180,390,"退出",24,25,WHITE);
	puthz(306,393,"我的",16,15,WHITE);
	
}

void s_pageMenu(){
	
	while(1){
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX>120&&MouseX<200&&MouseY>100&&MouseY<170){//买保险
			if(mouse_press(120,100,200,170)==2){
				MouseS =1;
				continue;
			}
			else if(mouse_press(120,100,200,170)==1){
				clrmous(MouseX,MouseY);
				page = pageBuy;
				break;
			}
		}
		else if(MouseX>280&&MouseX<360&&MouseY>90&&MouseY<190){//查保单
			if(mouse_press(280,90,360,190) == 2){
				MouseS = 1;
				continue;
			}
			//else if(mouse_press(280,90,360,190)==1){}
		}
		else if(MouseX>440&&MouseX<520&&MouseY>90&&MouseY<190){//办理赔
			if(mouse_press(440,90,520,190)==2){
				MouseS = 1;
				continue;
			}
		//else if(mouse_press(440,90,520,190)==1){}
		}
		else if(MouseX>375&&MouseX<480&&MouseY>370&&MouseY<430){//修改信息
			if(mouse_press(375,370,480,430)==2){
				MouseS = 1;
				continue;
			}
			else if(mouse_press(375,370,480,430)==1){
				clrmous(MouseX,MouseY);
				page = pageChangeIfm;
				break;
			}
		}
		else if(MouseX>295&&MouseX<345&&MouseY>375&&MouseY<425){//显示详细信息
			if(mouse_press(295,375,345,425) == 2){
				MouseS = 1;
				continue;
			}
			else if(mouse_press(295,375,345,425) == 1){
				clrmous(MouseX,MouseY);
				page = pageShowIfm;
				break;
			}
		}
		else if(MouseX>160&&MouseX<265&&MouseY>370&&MouseY<430){//退出
			if(mouse_press(160,370,265,430)==2){
				MouseS = 1;
				continue;
			}
			else if(mouse_press(160,370,265,430)==1){
				node_head = del_node(node_head,node_cur->hosts.m_phone);
				add_back(node_head,node_cur);
				writeAll(node_head);
				page = pageMain;
				break;
			}
		}
		if(MouseS != 0)MouseS=0;
	}
	
}

//显示详细信息的函数
void g_pageShowIfm(){//done(可以不修改了)
	cleardevice();
	setbkcolor(LIGHTGRAY);
	setcolor(WHITE);
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	
	ellipse(70,60,0,360,40,30);
	ellipse(390,60,0,360,40,30);
	setfillstyle(1,LIGHTRED);
	floodfill(60,60,WHITE);
	setfillstyle(1,BLUE);
	floodfill(380,60,WHITE);
	//显示名字和车牌的两条线
	line(120,70,280,70);
	line(440,70,600,70);
	//具体信息的显示框
	moveto(40,100);
	lineto(40,360);
	lineto(600,360);
	lineto(600,100);
	lineto(40,100);
	
	line(40,140,600,140);
	setfillstyle(1,DARKGRAY);
	floodfill(60,120,WHITE);
	
	line(180,100,180,360);
	line(320,100,320,360);
	line(460,100,460,360);
	//车险
	line(60,180,160,180);
	line(60,220,160,220);
	line(60,260,160,260);
	//健康险
	line(200,180,300,180);
	line(200,220,300,220);
	line(200,260,300,260);
	//意外险
	line(340,180,440,180);
	line(340,220,440,220);
	line(340,260,440,260);
	//旅行险
	line(480,180,580,180);
	line(480,220,580,220);
	line(480,260,580,260);
	setfillstyle(1,WHITE);
	//显示具体的保险的购买情况
	bar(60,280,160,340);
	bar(200,280,300,340);
	bar(340,280,440,340);
	bar(480,280,580,340);
	//返回主页面的按钮
	circle(320,420,40);
	circle(320,420,30);
	setfillstyle(1,DARKGRAY);
	fillellipse(320,420,29,29);
	
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	outtextxy(55,55,"ME");
	outtextxy(370,55,"CAR");
	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	outtextxy(305,417,"MENU");
	puthz(80,110,"车险",16,15,WHITE);
	puthz(220,110,"健康险",16,15,WHITE);
	puthz(360,110,"意外险",16,15,WHITE);
	puthz(500,110,"旅行险",16,15,WHITE);
	//显示具体的数据
	//数据一人名和车牌号
	puthz(160,40,node_cur->hosts.m_name,24,25,DARKGRAY);
	line(440,70,600,70);
	puthz(460,40,node_cur->hosts.carBandhz,24,25,DARKGRAY);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	setcolor(DARKGRAY);
	outtextxy(490,45,node_cur->hosts.carBandstr);
	//数据2.1显示车险的信息
	if(node_cur->hosts.Ins_Car[0]||node_cur->hosts.Ins_Car[1]||node_cur->hosts.Ins_Car[2]){//购买了保险的情况
		puthz(65,160,node_cur->hosts.InsAddr,16,15,WHITE);
		puthz(70,200,node_cur->hosts.InsBandhz_car,16,1,WHITE);
		settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
		outtextxy(90,205,node_cur->hosts.InsBandstr_car);
		outtextxy(65,245,node_cur->hosts.Insphonenum_car);
		if(node_cur->hosts.Ins_Car[0])
			puthz(80,285,"商业险",16,20,RED);
		else 
			puthz(80,285,"商业险",16,20,DARKGRAY);
		if(node_cur->hosts.Ins_Car[1])
			puthz(80,305,"交强险",16,20,RED);
		else 
			puthz(80,305,"交强险",16,20,DARKGRAY);
		if(node_cur->hosts.Ins_Car[2])
			puthz(80,325,"财意险",16,20,RED);
		else 
			puthz(80,325,"财意险",16,20,DARKGRAY);
	}
	else{
		settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
		outtextxy(100,195,"\\");
		outtextxy(100,155,"\\");
		outtextxy(100,235,"\\");
		puthz(80,285,"商业险",16,20,DARKGRAY);
		puthz(80,305,"交强险",16,20,DARKGRAY);
		puthz(80,325,"财意险",16,20,DARKGRAY);
	}
	
	//数据2.2显示健康险
	if(node_cur->hosts.Ins_Health){
		puthz(205,160,node_cur->hosts.InsPname_health,16,15,WHITE);
		puthz(205,200,node_cur->hosts.InsBandhz_health,16,15,WHITE);
		settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
		outtextxy(230,205,node_cur->hosts.InsBandstr_health);
		outtextxy(205,245,node_cur->hosts.Insphonenum_health);
		switch(node_cur->hosts.Ins_Health){
			case 1:
			{
				puthz(235,285,"一年",16,20,RED);
				puthz(235,305,"两年",16,20,DARKGRAY);
				puthz(235,325,"三年",16,20,DARKGRAY);
				break;
			}
			case 2:
			{
				puthz(235,285,"一年",16,20,DARKGRAY);
				puthz(235,305,"两年",16,20,RED);
				puthz(235,325,"三年",16,20,DARKGRAY);
				break;
			}
			case 3:
			{
				puthz(235,285,"一年",16,20,DARKGRAY);
				puthz(235,305,"两年",16,20,DARKGRAY);
				puthz(235,325,"三年",16,20,RED);
				break;
			}
			
		}
	}
	else {
		settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
		outtextxy(240,195,"\\");
		outtextxy(240,155,"\\");
		outtextxy(240,235,"\\");
		puthz(235,285,"一年",16,20,DARKGRAY);
		puthz(235,305,"两年",16,20,DARKGRAY);
		puthz(235,325,"三年",16,20,DARKGRAY);
	}
	
	//数据2.3显示意外险
	if(node_cur->hosts.Ins_Acci){
		puthz(345,160,node_cur->hosts.InsPname_acci,16,15,WHITE);
		puthz(345,200,node_cur->hosts.InsBandhz_acci,16,15,WHITE);
		settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
		outtextxy(370,205,node_cur->hosts.InsBandstr_acci);
		outtextxy(345,245,node_cur->hosts.Insphonenum_acci);
		switch(node_cur->hosts.Ins_Acci){
			case 1:
			{
				puthz(375,285,"一年",16,20,RED);
				puthz(375,305,"两年",16,20,DARKGRAY);
				puthz(375,325,"三年",16,20,DARKGRAY);
				break;
			}
			case 2:
			{
				puthz(375,285,"一年",16,20,DARKGRAY);
				puthz(375,305,"两年",16,20,RED);
				puthz(375,325,"三年",16,20,DARKGRAY);
				break;
			}
			case 3:
			{
				puthz(375,285,"一年",16,20,DARKGRAY);
				puthz(375,305,"两年",16,20,DARKGRAY);
				puthz(375,325,"三年",16,20,RED);
				break;
			}
			
		}
	}
	else {
		settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
		outtextxy(380,195,"\\");
		outtextxy(380,155,"\\");
		outtextxy(380,235,"\\");
		puthz(375,285,"一年",16,20,DARKGRAY);
		puthz(375,305,"两年",16,20,DARKGRAY);
		puthz(375,325,"三年",16,20,DARKGRAY);
	}
	//数据2.4显示旅行险
	if(node_cur->hosts.Ins_Travel){
		puthz(485,160,node_cur->hosts.InsPname_travel,16,15,WHITE);
		puthz(485,200,node_cur->hosts.InsBandhz_travel,16,15,WHITE);
		settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
		outtextxy(510,205,node_cur->hosts.InsBandstr_travel);
		outtextxy(485,245,node_cur->hosts.Insphonenum_travel);
		switch(node_cur->hosts.Ins_Travel){
			case 1:
			{
				puthz(515,285,"一年",16,20,RED);
				puthz(515,305,"两年",16,20,DARKGRAY);
				puthz(515,325,"三年",16,20,DARKGRAY);
				break;
			}
			case 2:
			{
				puthz(515,285,"一年",16,20,DARKGRAY);
				puthz(515,305,"两年",16,20,RED);
				puthz(515,325,"三年",16,20,DARKGRAY);
				break;
			}
			case 3:
			{
				puthz(515,285,"一年",16,20,DARKGRAY);
				puthz(515,305,"两年",16,20,DARKGRAY);
				puthz(515,325,"三年",16,20,RED);
				break;
			}
			
		}
	}
	else {
		settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
		outtextxy(520,195,"\\");
		outtextxy(520,155,"\\");
		outtextxy(520,235,"\\");
		puthz(515,285,"一年",16,20,DARKGRAY);
		puthz(515,305,"两年",16,20,DARKGRAY);
		puthz(515,325,"三年",16,20,DARKGRAY);
	}
}

void s_pageShowIfm(){
	while(1){
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX>280&&MouseX<360&&MouseY>380&&MouseY<460){
			if(mouse_press(280,380,360,460) == 2){
				MouseS = 1;
				continue;
			}
			else if(mouse_press(280,380,360,460) == 1){
				clrmous(MouseX,MouseY);
				page = pageMenu;
				break;
			}
		}
	}
}
// 买车险的函数
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

void s_pageBuy(){
	
	while(1){
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX>78&&MouseX<178&&MouseY>180&&MouseY<280){//车险
			if(mouse_press(78,180,178,280)==2){
				MouseS =1;
				continue;
			}
			else if(mouse_press(78,180,178,280)==1){
				do{
					newmouse(&MouseX,&MouseY,&press);
				}while(mouse_press(78,180,178,280)==1);
				clrmous(MouseX,MouseY);
				if(node_cur->hosts.Ins_Car[0]||node_cur->hosts.Ins_Car[1]||node_cur->hosts.Ins_Car[2]){
					puthz(270,330,"您已购买该保险！",16,15,RED);
					//puthz(250,350,"修改车辆信息后可再次购买",16,15,RED);
					delay(500);
					setfillstyle(1,LIGHTGRAY);
					bar(260,325,400,350);
					continue;
				}
				else{
					page = pageCarIns;
					break;
				}
			}
		}
		else if(MouseX>206&&MouseX<306&&MouseY>180&&MouseY<280){//健康险
			if(mouse_press(206,180,306,280) == 2){
				MouseS = 1;
				continue;
			}
			else if(mouse_press(206,180,306,280)==1){
				do{
					newmouse(&MouseX,&MouseY,&press);
				}while(mouse_press(206,180,306,280)==1);
				clrmous(MouseX,MouseY);
				if(node_cur->hosts.Ins_Health){
					puthz(270,330,"您已购买该保险",16,15,RED);
					delay(500);
					setfillstyle(1,LIGHTGRAY);
					bar(260,325,400,350);
					continue;
				}
				else{
					page = pageHealthIns;
					break;
				}
			}
		}
		else if(MouseX>334&&MouseX<434&&MouseY>180&&MouseY<280){//意外险
			if(mouse_press(334,180,434,280)==2){
				MouseS = 1;
				continue;
			}
			else if(mouse_press(334,180,434,280)==1){
				do{
					newmouse(&MouseX,&MouseY,&press);
				}while(mouse_press(334,180,434,280)==1);
				clrmous(MouseX,MouseY);
				if(node_cur->hosts.Ins_Acci){
					puthz(270,330,"您已购买该保险",16,15,RED);
					delay(500);
					setfillstyle(1,LIGHTGRAY);
					bar(260,325,400,350);
					continue;
				}
				else{
					page = pageAcciIns;
					break;
				}
			}
		}
		else if(MouseX>462&&MouseX<562&&MouseY>180&&MouseY<280){//旅行险
			if(mouse_press(462,180,562,280)==2){
				MouseS = 1;
				continue;
			}
			else if(mouse_press(462,180,562,280)==1){
				do{
					newmouse(&MouseX,&MouseY,&press);
				}while(mouse_press(462,180,562,280)==1);
				clrmous(MouseX,MouseY);
				if(node_cur->hosts.Ins_Travel){
					puthz(270,330,"您已购买该保险",16,15,RED);
					delay(500);
					setfillstyle(1,LIGHTGRAY);
					bar(260,325,400,350);
					continue;
				}
				else{
					page = pageTravelIns;
					break;
				}
			}
		}
		
		//下方的操作界面
		else if(MouseX>280&&MouseX<360&&MouseY>360&&MouseY<440){//菜单键
			if(mouse_press(280,360,360,440) == 2){
				MouseS = 1;
				continue;
			}
			else if(mouse_press(280,360,360,440) == 1){
				clrmous(MouseX,MouseY);
				page = pageMenu;
				break;
			}
		}
		if(MouseS != 0)MouseS=0;
	}
}

void g_pageChangeIfm(){//已修改
	cleardevice();
	setbkcolor(LIGHTGRAY);
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	setcolor(WHITE);
	
	
	moveto(20,80);
	lineto(620,80);
	lineto(620,320);
	lineto(20,320);
	lineto(20,80);
	setfillstyle(1,DARKGRAY);
	floodfill(80,170,WHITE);
	
	line(120,70,500,70);
	line(20,150,620,150);
	
	
	setfillstyle(1,WHITE);
	bar(80,100,310,140);
	bar(80,160,560,200);
	bar(80,220,300,260);
	
	bar(380,100,430,140);
	bar(440,100,610,140);
	
	setfillstyle(1,LIGHTGRAY);
	bar(380,160+50,560,260+40);
	line(320,80,320,150);
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);

	circle(415,190+50,10);
	circle(470,190+50,10);
	circle(525,190+50,10);
	
	puthz(170,40,"更新您的个人信息",24,30,WHITE);

	puthz(30,110,"手机号",16,15,WHITE);
	puthz(40,170,"密码",16,15,WHITE);
	puthz(40,230,"住址",16,15,WHITE);
	puthz(340,110,"车牌",16,15,WHITE);
	puthz(340,185+50,"车型",16,15,WHITE);
	
	puthz(400,220+50,"轿车",16,15,WHITE);
	puthz(450,220+50,"越野车",16,15,WHITE);
	puthz(510,220+50,"货车",16,15,WHITE);
	
	
	//画操作界面
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	
	circle(320,400,45);
	setfillstyle(1,DARKGRAY);
	floodfill(320,400,WHITE);
	circle(320,400,35);
	puthz(295,390,"保存",24,25,WHITE);
	setcolor(LIGHTRED);
	line(40,440,60,410);
	line(40,440,130,440);
	
	puthz(70,410,"返回",24,25,WHITE);
	
	setcolor(LIGHTGRAY);
	puthz(85,172,"请输入新的密码",16,20,LIGHTGRAY);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
	outtextxy(95,105,node_cur->hosts.m_phone);
	outtextxy(450,105,node_cur->hosts.carBandstr);
	puthz(85,232,node_cur->hosts.P_addr,16,20,LIGHTGRAY);
	puthz(385,103,node_cur->hosts.carBandhz,32,1,LIGHTGRAY);

}

void s_pageChangeIfm(){
	
	while(1){
		newmouse(&MouseX,&MouseY,&press);
	
		
		//下方的操作界面

		if(MouseX>275&&MouseX<365&&MouseY>355&&MouseY<445){//保存键
			if(mouse_press(275,365,355,445)==2){
				MouseS = 1;
				continue;
			}
			else if(mouse_press(275,365,355,445)==1){
				clrmous(MouseX,MouseY);
				if(lenPageChangeIfm[0]&&lenPageChangeIfm[1]&&lenPageChangeIfm[2]&&!(fgChangeIfm[0]&&fgChangeIfm[1]&&fgChangeIfm[2])){
					node_head = del_node(node_head,node_cur->hosts.m_phone);//先删除原先的
					strcpy(node_cur->hosts.m_phone,tmpPhonenum);
					strcpy(node_cur->hosts.passport,tmpPassport);
					strcpy(node_cur->hosts.P_addr,tmpAddr);
					if((strcmp(node_cur->hosts.carBandhz,tmpCarBandhz)!=0)||(strcmp(node_cur->hosts.carBandstr,tmpCarBandstr)!=0)||(node_cur->hosts.carType != tmpCarType)){
						strcpy(node_cur->hosts.carBandhz,tmpCarBandhz);
						strcpy(node_cur->hosts.carBandstr,tmpCarBandstr);
						node_cur->hosts.carType = tmpCarType;
						node_cur->hosts.Ins_Car[0] = 0;
						node_cur->hosts.Ins_Car[1] = 0;
						node_cur->hosts.Ins_Car[2] = 0;
					}//一下修改这个信息那就重置车险的信息
					add_back(node_head,node_cur);//然后再把这个接上去
					
					puthz(460,390,"修改成功",16,15,GREEN);
					delay(500);
					setfillstyle(1,LIGHTGRAY);
					bar(455,385,560,410);
					page = pageMenu;
					break;
				}
				else {
					puthz(460,390,"输入框为空！",16,15,RED);
					delay(500);
					setfillstyle(1,LIGHTGRAY);
					bar(455,385,560,410);
				}
			}
		}
		else if(MouseX>40&&MouseX<130&&MouseY>410&&MouseY<440){//点击返回时，重新设置相关的变量
			if(mouse_press(40,410,130,440) == 2){
				MouseS = 1;
				continue;
			}
			
			else if(mouse_press(40,410,130,440) == 1){
				clrmous(MouseX,MouseY);
				lenPageChangeIfm[0] = 0;
				lenPageChangeIfm[1] = 0;
				lenPageChangeIfm[2] = 0;
				lenPageChangeIfm[3] = 0;
				lenPageChangeIfm[4] = 0;
				fgChangeIfm[0] = 1;
				fgChangeIfm[1] = 1;
				fgChangeIfm[2] = 1;
				page = pageMenu;
				break;
			}
		}
		else if(MouseX>80&&MouseX<300&&MouseY>100&&MouseY<140){//手机号
			if(mouse_press(80,100,300,140) == 2){
				MouseS = 2;
				continue;
			}
			else if(mouse_press(80,100,300,140) == 1){
				clrmous(MouseX,MouseY);
				setfillstyle(1,WHITE);
				bar(80,100,300,140);
				lenPageChangeIfm[0] = inputadmin(tmpPhonenum,85,105,11,WHITE,18);
			
			}
		}
		else if(MouseX>80&&MouseX<560&&MouseY>160&&MouseY<200){//密码
			if(mouse_press(80,160,560,200) == 2){
				MouseS = 2;
				continue;

			}
			else if(mouse_press(80,160,560,200)==1){
				lenPageChangeIfm[1] = inputpassword(tmpPassport,85,160,20,WHITE);
				
			}
		}
		else if(MouseX>80&&MouseX<300&&MouseY>220&&MouseY<260){//住址
			if(mouse_press(80,220,300,260)==2){
				MouseS = 2;
				continue;
			}
			else if(mouse_press(80,220,300,260)==1){
				clrmous(MouseX,MouseY);
				setfillstyle(1,WHITE);
				bar(80,220,300,260);
				lenPageChangeIfm[2] = hz_input(85,220+3,300,260+3,tmpAddr,lenPageChangeIfm[2],WHITE,DARKGRAY,24);
				
			}
		}
		else if(MouseX>380&&MouseX<430&&MouseY>100&&MouseY<140){//车牌
			if(mouse_press(380,100,430,140)==2){
				MouseS = 2;
				continue;
			}
			else if(mouse_press(380,100,430,140)==1){
				clrmous(MouseX,MouseY);
				setfillstyle(1,WHITE);
				bar(380,100,430,140);
				lenPageChangeIfm[3] = hz_input(380+5,100+2,430,140+2,tmpCarBandhz,0,WHITE,DARKGRAY,32);
			}
		}
		else if(MouseX>440&&MouseX<600&&MouseY>100&&MouseY<140){//str
			if(mouse_press(440,100,600,140) == 2){
				MouseS = 2;
				continue;
			}
			else if(mouse_press(440,100,600,140) == 1){
				clrmous(MouseX,MouseY);
				setfillstyle(1,WHITE);
				bar(440,100,600,140);
				lenPageChangeIfm[4] = inputadmin(tmpCarBandstr,445,110,8,WHITE,18);
			
			}
		}
		else if(MouseX>405&&MouseX<425&&MouseY>(180+50)&&MouseY<(200+50)){//车型
			if(mouse_press(405,180+50,425,200+50) ==2){
				MouseS = 1;
				continue;
			}
			else if(mouse_press(405,180+50,425,200+50)==1){
				do{
					newmouse(&MouseX,&MouseY,&press);
				}while(mouse_press(405,180+50,425,200+50)==1);
				if(fgChangeIfm[0]){
					clrmous(MouseX,MouseY);
					setcolor(BLACK);
					setlinestyle(SOLID_LINE,0,NORM_WIDTH);
					setfillstyle(1,RED);
					fillellipse(415,190+50,9,9);
					setfillstyle(1,LIGHTGRAY);
					fillellipse(470,190+50,9,9);
					fillellipse(525,190+50,9,9);
					fgChangeIfm[0] = 0;
					fgChangeIfm[1] = 1;
					fgChangeIfm[2] = 1;
					tmpCarType = 1;
					
					
				}
				else{
					clrmous(MouseX,MouseY);
					setcolor(BLACK);
					setlinestyle(SOLID_LINE,0,NORM_WIDTH);
					setfillstyle(1,LIGHTGRAY);
					fillellipse(415,190+50,9,9);
					fgChangeIfm[0] = 1;
					
				}
			}
		}
		else if(MouseX>460&&MouseX<480&&MouseY>(180+50)&&MouseY<(200+50)){
			if(mouse_press(460,180+50,480,200+50) ==2){
				MouseS = 1;
				continue;
			}
			else if(mouse_press(460,180+50,480,200+50)==1){
				do{
					newmouse(&MouseX,&MouseY,&press);
				}while(mouse_press(460,180+50,480,200+50)==1);
				if(fgChangeIfm[1]){
					clrmous(MouseX,MouseY);
					setcolor(BLACK);
					setlinestyle(SOLID_LINE,0,NORM_WIDTH);
					setfillstyle(1,RED);
					fillellipse(470,190+50,9,9);
					setfillstyle(1,LIGHTGRAY);
					fillellipse(415,190+50,9,9);
					fillellipse(525,190+50,9,9);
					fgChangeIfm[0] = 1;
					fgChangeIfm[1] = 0;
					fgChangeIfm[2] = 1;
					tmpCarType = 2;
				}
				else{
					clrmous(MouseX,MouseY);
					setcolor(BLACK);
					setlinestyle(SOLID_LINE,0,NORM_WIDTH);
					setfillstyle(1,LIGHTGRAY);
					fillellipse(470,190+50,9,9);
					fgChangeIfm[1] = 1;
					
				}
			}
		}
		else if(MouseX>515&&MouseX<535&&MouseY>(180+50)&&MouseY<(200+50)){
			if(mouse_press(515,180+50,535,200+50) ==2){
				MouseS = 1;
				continue;
			}
			else if(mouse_press(515,180+50,535,200+50)==1){
				do{
					newmouse(&MouseX,&MouseY,&press);
				}while(mouse_press(515,180+50,535,200+50)==1);
				if(fgChangeIfm[2]){
					clrmous(MouseX,MouseY);
					setcolor(BLACK);
					setlinestyle(SOLID_LINE,0,NORM_WIDTH);
					setfillstyle(1,RED);
					fillellipse(525,190+50,9,9);
					setfillstyle(1,LIGHTGRAY);
					fillellipse(415,190+50,9,9);
					fillellipse(470,190+50,9,9);
					fgChangeIfm[0] = 1;
					fgChangeIfm[1] = 1;
					fgChangeIfm[2] = 0;
					tmpCarType = 3;
				}
				else{
					clrmous(MouseX,MouseY);
					setcolor(BLACK);
					setlinestyle(SOLID_LINE,0,NORM_WIDTH);
					setfillstyle(1,LIGHTGRAY);
					fillellipse(525,190+50,9,9);
					fgChangeIfm[2] = 1;
					
				}
			}
		}
		if(MouseS != 0)MouseS=0;
	}
}
//车险的相关函数
void g_pageCarIns(){//已修改
	cleardevice();
	setbkcolor(LIGHTGRAY);
	setcolor(LIGHTBLUE);
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	line(240,60,400,60);
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	setcolor(WHITE);
	moveto(40,80);
	lineto(40,340);
	lineto(600,340);
	lineto(600,80);
	lineto(40,80);
	setfillstyle(1,DARKGRAY);
	floodfill(150,140,WHITE);
	circle(80,120,6);
	circle(80,180,6);
	circle(80,240,6);
	circle(80,300,6);
	setfillstyle(1,LIGHTRED);
	floodfill(80,120,WHITE);
	floodfill(80,180,WHITE);
	floodfill(80,240,WHITE);
	floodfill(80,300,WHITE);
	setfillstyle(1,WHITE);
	bar(160,100,540,140);
	bar(160,160,210,200);
	bar(220,160,540,200);
	bar(160,220,540,260);
	setfillstyle(1,LIGHTGRAY);
	circle(165,300,10);
	circle(285,300,10);
	circle(405,300,10);
	floodfill(160,300,WHITE);
	floodfill(280,300,WHITE);
	floodfill(400,300,WHITE);
	
	//放置汉字
	puthz(180,20,"为您的爱车保驾护航",32,30,LIGHTBLUE);
	puthz(90,115,"投保城市",16,15,WHITE);
	puthz(90,175,"车牌号码",16,15,WHITE);
	puthz(90,235,"手机号码",16,15,WHITE);
	puthz(100,290,"类别",16,15,WHITE);
	puthz(190,290,"商业险",24,25,WHITE);
	puthz(310,290,"交强险",24,25,WHITE);
	puthz(430,290,"财意险",24,25,WHITE);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	setcolor(RED);
	outtextxy(525,285,"120");
	puthz(580,285,"元",16,1,WHITE);
	setcolor(WHITE);
	outtextxy(530,305,"/");
	puthz(550,305,"类",16,1,WHITE);
	
	
	//操作按键
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	setcolor(WHITE);
	
	ellipse(350+70,400,270,90,25,30);
	moveto(350+70,370);
	lineto(480+70,370);
	lineto(505+70,400);
	lineto(480+70,430);
	lineto(350+70,430);
	setfillstyle(1,DARKGRAY);
	floodfill(390+70,380,WHITE);
	puthz(405+70,390,"确定",24,25,WHITE);
	ellipse(290-70,400,90,270,25,30);
	moveto(290-70,370);
	lineto(160-70,370);
	lineto(135-70,400);
	lineto(160-70,430);
	lineto(290-70,430);
	floodfill(240-70,400,WHITE);
	puthz(180-70,390,"返回",24,25,WHITE);
	
}

void s_pageCarIns(){//已修改
	
	while(1){
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX>160&&MouseX<540&&MouseY>100&&MouseY<140){//投保城市
			if(mouse_press(160,100,540,140)==2){
				MouseS = 2;
				continue;
			}
			else if(mouse_press(160,100,540,140) == 1){
				lenPageCarIns[0] = hz_input(160+5,100,540,140,tmpInsAddr,lenPageCarIns[0],WHITE,DARKGRAY,32);
				
			}
		}
		else if(MouseX>160&&MouseX<210&&MouseY>160&&MouseY<200){//车牌号码
			if(mouse_press(160,160,210,200)==2){
				MouseS = 2;
				continue;
			}
			else if(mouse_press(160,160,210,200) == 1){
				lenPageCarIns[1] = hz_input(160+5,160,210,200,tmpInsBandhz,0,WHITE,DARKGRAY,32);
			}
		}
		else if(MouseX>220&&MouseX<540&&MouseY>160&&MouseY<200){
			if(mouse_press(220,160,540,200) == 2){
				MouseS = 2;
				continue;
			}
			else if(mouse_press(220,160,540,200) == 1){
				lenPageCarIns[2] = inputadmin(tmpInsBandstr,225,160,13,WHITE,32);
			}
		}
		else if(MouseX>160&&MouseX<540&&MouseY>220&&MouseY<260){//手机号
			if(mouse_press(160,220,540,260)==2){
				MouseS = 2;
				continue;
			}
			else if(mouse_press(160,220,540,260) == 1){
				lenPageCarIns[3] = inputadmin(tmpInsPhonenum,165,220,15,WHITE,32);
	
			}
		}
		else if(MouseX>155&&MouseX<175&&MouseY>290&&MouseY<310){
			if(mouse_press(155,290,175,310)==2){
				MouseS =1;
				continue;
			}
			else if(mouse_press(155,290,175,310) == 1){
				do {
					newmouse(&MouseX, &MouseY, &press);
				}while (mouse_press(155,290,175,310) == 1);
				if(fgCarIns[0]){
					clrmous(MouseX,MouseY);
					setcolor(BLACK);
					setlinestyle(SOLID_LINE,0,NORM_WIDTH);
					setfillstyle(1,RED);
					fillellipse(165,300,9,9);
					fgCarIns[0] = 0;
					tmpInsCar[0] = 1;
				}
				else {
					clrmous(MouseX,MouseY);
					setcolor(BLACK);
					setlinestyle(SOLID_LINE,0,NORM_WIDTH);
					setfillstyle(1,LIGHTGRAY);
					fillellipse(165,300,9,9);
					fgCarIns[0] = 1;
					tmpInsCar[0] = 0;
					
				}
				
			}
			
			
		}
		else if(MouseX>275&&MouseX<295&&MouseY>290&&MouseY<310){
			if(mouse_press(275,290,295,310)==2){
				MouseS = 1;
				
				continue;
			}
			else if(mouse_press(275,290,295,310)==1){
				do {
					newmouse(&MouseX, &MouseY, &press);
				}while (mouse_press(275,290,295,310) == 1);
				if(fgCarIns[1]){	
					clrmous(MouseX,MouseY);
					setcolor(BLACK);
					setlinestyle(SOLID_LINE,0,NORM_WIDTH);
					setfillstyle(1,RED);
					fillellipse(285,300,9,9);
					fgCarIns[1] = 0;
					tmpInsCar[1] = 1;
				}
				else {
					clrmous(MouseX,MouseY);
					setcolor(BLACK);
					setlinestyle(SOLID_LINE,0,NORM_WIDTH);
					setfillstyle(1,LIGHTGRAY);
					fillellipse(285,300,9,9);
					fgCarIns[1] = 1;
					tmpInsCar[1] = 0;
				}
			}
			
		}
		else if(MouseX>395&&MouseX<415&&MouseY>290&&MouseY<310){
			if(mouse_press(395,290,415,310)==2){
				MouseS = 1;
				continue;
			}
			else if(mouse_press(395,290,415,310)==1){
				do {
					newmouse(&MouseX, &MouseY, &press);
				}while (mouse_press(395,290,415,310) == 1);
				if(fgCarIns[2]){	
					clrmous(MouseX,MouseY);
					setcolor(BLACK);
					setlinestyle(SOLID_LINE,0,NORM_WIDTH);
					setfillstyle(1,RED);
					fillellipse(405,300,9,9);
					fgCarIns[2] = 0;
					tmpInsCar[2] = 1;
				}
				else {
					clrmous(MouseX,MouseY);
					setcolor(BLACK);
					setlinestyle(SOLID_LINE,0,NORM_WIDTH);
					setfillstyle(1,LIGHTGRAY);
					fillellipse(405,300,9,9);
					fgCarIns[2] = 1;
					tmpInsCar[2] = 0;
				
				}
			}
		}
		else if(MouseX>(375+70)&&MouseX<(480+70)&&MouseY>370&&MouseY<430){//确定键
			if(mouse_press(375+70,370,480+70,430)==2){
				MouseS = 1;
				continue;
			}
			else if(mouse_press(375+70,370,480+70,430) == 1){
				clrmous(MouseX,MouseY);
				if(lenPageCarIns[0]&&lenPageCarIns[1]&&lenPageCarIns[2]&&lenPageCarIns[3]&&!(fgCarIns[0]&&fgCarIns[1]&&fgCarIns[2])){
					strcpy(node_cur->hosts.InsAddr,tmpInsAddr);
					strcpy(node_cur->hosts.Insphonenum_car,tmpInsPhonenum);
					strcpy(node_cur->hosts.InsBandhz_car,tmpInsBandhz);
					strcpy(node_cur->hosts.InsBandstr_car,tmpInsBandstr);
					node_cur->hosts.Ins_Car[0] = tmpInsCar[0];
					node_cur->hosts.Ins_Car[1] = tmpInsCar[1];
					node_cur->hosts.Ins_Car[2] = tmpInsCar[2];
					pagefg = 1;
					page = pagePayIns;//这里已经完成
					break;
				}
				else{
					puthz(280,400,"输入框为空！",16,15,RED);
					delay(500);
					setfillstyle(1,LIGHTGRAY);
					bar(275,395,430,420);
					continue;
				}
			}
		}
		else if(MouseX>(160-70)&&MouseX<(265-70)&&MouseY>370&&MouseY<430){//返回键
			if(mouse_press(160-70,370,265-70,430)==2){
				MouseS = 1;
				continue;
			}
			else if(mouse_press(160-70,370,265-70,430)==1){
				clrmous(MouseX,MouseY);
				lenPageCarIns[0] = 0;
				lenPageCarIns[1] = 0;
				lenPageCarIns[2] = 0;
				lenPageCarIns[3] = 0;
				fgCarIns[0] = 1;
				fgCarIns[1] = 1;
				fgCarIns[2] = 1;
				page = pageBuy;
				break;
			}
		}
		
		if(MouseS != 0)MouseS=0;
	}
}
//健康险的相关函数
void g_pageHealthIns(){//已修改
	cleardevice();
	setbkcolor(LIGHTGRAY);
	setcolor(LIGHTBLUE);
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	line(240,60,400,60);
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	setcolor(WHITE);
	moveto(40,80);
	lineto(40,340);
	lineto(600,340);
	lineto(600,80);
	lineto(40,80);
	setfillstyle(1,DARKGRAY);
	floodfill(150,140,WHITE);
	circle(80,120,6);
	circle(80,180,6);
	circle(80,240,6);
	circle(80,300,6);
	setfillstyle(1,LIGHTRED);
	floodfill(80,120,WHITE);
	floodfill(80,180,WHITE);
	floodfill(80,240,WHITE);
	floodfill(80,300,WHITE);
	setfillstyle(1,WHITE);
	bar(160,100,540,140);
	bar(160,160,210,200);
	bar(220,160,540,200);
	bar(160,220,540,260);
	setfillstyle(1,LIGHTGRAY);
	circle(165,300,10);
	circle(285,300,10);
	circle(405,300,10);
	floodfill(160,300,WHITE);
	floodfill(280,300,WHITE);
	floodfill(400,300,WHITE);
	
	//放置汉字
	puthz(180,20,"为您的健康保驾护航",32,30,LIGHTBLUE);
	puthz(90,115,"被保人名",16,15,WHITE);
	puthz(90,175,"车牌号码",16,15,WHITE);
	puthz(90,235,"手机号码",16,15,WHITE);
	puthz(100,290,"期限",16,15,WHITE);
	puthz(190,290,"一年",24,25,WHITE);
	puthz(310,290,"两年",24,25,WHITE);
	puthz(430,290,"三年",24,25,WHITE);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	setcolor(RED);
	outtextxy(525,285,"100");
	puthz(580,285,"元",16,1,WHITE);
	setcolor(WHITE);
	outtextxy(530,305,"/");
	puthz(550,305,"年",16,1,WHITE);
	
	//操作按键
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	setcolor(WHITE);
	
	ellipse(350+70,400,270,90,25,30);
	moveto(350+70,370);
	lineto(480+70,370);
	lineto(505+70,400);
	lineto(480+70,430);
	lineto(350+70,430);
	setfillstyle(1,DARKGRAY);
	floodfill(390+70,380,WHITE);
	puthz(405+70,390,"确定",24,25,WHITE);
	ellipse(290-70,400,90,270,25,30);
	moveto(290-70,370);
	lineto(160-70,370);
	lineto(135-70,400);
	lineto(160-70,430);
	lineto(290-70,430);
	floodfill(240-70,400,WHITE);
	puthz(180-70,390,"返回",24,25,WHITE);
}
	
void s_pageHealthIns(){

	while(1){
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX>160&&MouseX<540&&MouseY>100&&MouseY<140){//被保人名
			if(mouse_press(160,100,540,140)==2){
				MouseS = 2;
				continue;
			}
			else if(mouse_press(160,100,540,140) == 1){
				lenPageHealthIns[0] = hz_input(160+5,100,540,140,tmpInsPname,lenPageHealthIns[0],WHITE,DARKGRAY,32);
			}                                                
		}
		else if(MouseX>160&&MouseX<210&&MouseY>160&&MouseY<200){//车牌号码
			if(mouse_press(160,160,210,200)==2){
				MouseS = 2;
				continue;
			}
			else if(mouse_press(160,160,210,200) == 1){
				lenPageHealthIns[1] = hz_input(160+3,160,210,200,tmpInsBandhz,0,WHITE,DARKGRAY,32);
			}
		}
		else if(MouseX>220&&MouseX<540&&MouseY>160&&MouseY<200){
			if(mouse_press(220,160,540,200)==2){
				MouseS = 2;
				continue;
			}
			else if(mouse_press(220,160,540,200) == 1){
				lenPageHealthIns[2] = inputadmin(tmpInsBandstr,225,160,10,WHITE,32);
			}
		}
		else if(MouseX>160&&MouseX<540&&MouseY>220&&MouseY<260){//手机号码
			if(mouse_press(160,220,540,260)==2){
				MouseS = 2;
				continue;
			}
			else if(mouse_press(160,220,540,260) == 1){
				lenPageHealthIns[3] = inputadmin(tmpInsPhonenum,165,220,15,WHITE,32);
			}
		}
		else if(MouseX>155&&MouseX<175&&MouseY>290&&MouseY<310){//选择
			if(mouse_press(155,290,175,310)==2){
				MouseS =1;
				continue;
			}
			else if(mouse_press(155,290,175,310) == 1){
				do {
					newmouse(&MouseX, &MouseY, &press);
				}while (mouse_press(155,290,175,310) == 1);
				if(fgHealthIns[0]){
					clrmous(MouseX,MouseY);
					setcolor(BLACK);
					setlinestyle(SOLID_LINE,0,NORM_WIDTH);
					setfillstyle(1,RED);
					fillellipse(165,300,9,9);
					setfillstyle(1,LIGHTGRAY);
					fillellipse(285,300,9,9);
					fillellipse(405,300,9,9);
					fgHealthIns[0] = 0;
					fgHealthIns[1] = 1;
					fgHealthIns[2] = 1;
					tmpIns = 1;
					
				}
				else {
					clrmous(MouseX,MouseY);
					setcolor(BLACK);
					setlinestyle(SOLID_LINE,0,NORM_WIDTH);
					setfillstyle(1,LIGHTGRAY);
					fillellipse(165,300,9,9);
					fgHealthIns[0] = 1;
					tmpIns = 0;
				}
				
			}
			
			
		}
		else if(MouseX>275&&MouseX<295&&MouseY>290&&MouseY<310){
			if(mouse_press(275,290,295,310)==2){
				MouseS = 1;
				
				continue;
			}
			else if(mouse_press(275,290,295,310)==1){
				do {
					newmouse(&MouseX, &MouseY, &press);
				}while (mouse_press(275,290,295,310) == 1);
				if(fgHealthIns[1]){	
					clrmous(MouseX,MouseY);
					setcolor(BLACK);
					setlinestyle(SOLID_LINE,0,NORM_WIDTH);
					setfillstyle(1,RED);
					fillellipse(285,300,9,9);
					setfillstyle(1,LIGHTGRAY);
					fillellipse(165,300,9,9);
					fillellipse(405,300,9,9);
					fgHealthIns[0] = 1;
					fgHealthIns[1] = 0;
					fgHealthIns[2] = 1;
					tmpIns = 2;
					
				}
				else{
					clrmous(MouseX,MouseY);
					setcolor(BLACK);
					setlinestyle(SOLID_LINE,0,NORM_WIDTH);
					setfillstyle(1,LIGHTGRAY);
					fillellipse(285,300,9,9);
					
					fgHealthIns[1] = 1;
					tmpIns= 0;
				}
			}
			
		}
		else if(MouseX>395&&MouseX<415&&MouseY>290&&MouseY<310){
			if(mouse_press(395,290,415,310)==2){
				MouseS = 1;
				continue;
			}
			else if(mouse_press(395,290,415,310)==1){
				do {
					newmouse(&MouseX, &MouseY, &press);
				}while (mouse_press(395,290,415,310) == 1);
				if(fgHealthIns[2]){	
					clrmous(MouseX,MouseY);
					setcolor(BLACK);
					setlinestyle(SOLID_LINE,0,NORM_WIDTH);
					setfillstyle(1,RED);
					fillellipse(405,300,9,9);
					setfillstyle(1,LIGHTGRAY);
					fillellipse(165,300,9,9);
					fillellipse(285,300,9,9);
					fgHealthIns[0] = 1;
					fgHealthIns[1] = 1;
					fgHealthIns[2] = 0;
					tmpIns = 3;
				}
				else {
					clrmous(MouseX,MouseY);
					setcolor(BLACK);
					setlinestyle(SOLID_LINE,0,NORM_WIDTH);
					setfillstyle(1,LIGHTGRAY);
					fillellipse(405,300,9,9);
					fgHealthIns[2] = 1;
					tmpIns = 0;
				}
			}
		}
		else if(MouseX>(375+70)&&MouseX<(480+70)&&MouseY>370&&MouseY<430){//确定键
			if(mouse_press(375+70,370,480+70,430)==2){
				MouseS = 1;
				continue;
			}
			else if(mouse_press(375+70,370,480+70,430) == 1){
				clrmous(MouseX,MouseY);
				if(lenPageHealthIns[0]&&lenPageHealthIns[1]&&lenPageHealthIns[2]&&lenPageHealthIns[3]&&!(fgHealthIns[0]&&fgHealthIns[1]&&fgHealthIns[2])){
					
					strcpy(node_cur->hosts.InsPname_health,tmpInsPname);
					strcpy(node_cur->hosts.InsBandhz_health,tmpInsBandhz);
					strcpy(node_cur->hosts.InsBandstr_health,tmpInsBandstr);
					strcpy(node_cur->hosts.Insphonenum_health,tmpInsPhonenum);
					node_cur->hosts.Ins_Health = tmpIns;
					pagefg = 2;
					page = pagePayIns;
					break;
				}
				else{
					puthz(280,400,"输入框为空！",16,15,RED);
					delay(500);
					setfillstyle(1,LIGHTGRAY);
					bar(275,395,430,420);
					continue;
				}
			}
		}
		else if(MouseX>(160-70)&&MouseX<(265-70)&&MouseY>370&&MouseY<430){//返回键
			if(mouse_press(160-70,370,265-70,430)==2){
				MouseS = 1;
				continue;
			}
			else if(mouse_press(160-70,370,265-70,430)==1){
				clrmous(MouseX,MouseY);
				lenPageHealthIns[0] = 0;
				lenPageHealthIns[1] = 0;
				lenPageHealthIns[2] = 0;
				lenPageHealthIns[3] = 0;
				fgHealthIns[0] = 1;
				fgHealthIns[1] = 1;
				fgHealthIns[2] = 1;
				
				page = pageBuy;
				break;
			}
		}
		
		if(MouseS != 0)MouseS=0;
	}
}


//意外险的相关函数
void g_pageAcciIns(){
	cleardevice();
	setbkcolor(LIGHTGRAY);
	setcolor(LIGHTBLUE);
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	line(240,60,400,60);
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	setcolor(WHITE);
	moveto(40,80);
	lineto(40,340);
	lineto(600,340);
	lineto(600,80);
	lineto(40,80);
	setfillstyle(1,DARKGRAY);
	floodfill(150,140,WHITE);
	circle(80,120,6);
	circle(80,180,6);
	circle(80,240,6);
	circle(80,300,6);
	setfillstyle(1,LIGHTRED);
	floodfill(80,120,WHITE);
	floodfill(80,180,WHITE);
	floodfill(80,240,WHITE);
	floodfill(80,300,WHITE);
	setfillstyle(1,WHITE);
	bar(160,100,540,140);
	bar(160,160,210,200);
	bar(220,160,540,200);
	bar(160,220,540,260);
	setfillstyle(1,LIGHTGRAY);
	circle(165,300,10);
	circle(285,300,10);
	circle(405,300,10);
	floodfill(160,300,WHITE);
	floodfill(280,300,WHITE);
	floodfill(400,300,WHITE);
	
	//放置汉字
	puthz(180,20,"为您的安全保驾护航",32,30,LIGHTBLUE);
	puthz(90,115,"被保人名",16,15,WHITE);
	puthz(90,175,"车牌号码",16,15,WHITE);
	puthz(90,235,"手机号码",16,15,WHITE);
	puthz(100,290,"期限",16,15,WHITE);
	puthz(190,290,"一年",24,25,WHITE);
	puthz(310,290,"两年",24,25,WHITE);
	puthz(430,290,"三年",24,25,WHITE);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	setcolor(RED);
	outtextxy(525,285,"105");
	puthz(580,285,"元",16,1,WHITE);
	setcolor(WHITE);
	outtextxy(530,305,"/");
	puthz(550,305,"年",16,1,WHITE);
	
	//操作按键
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	setcolor(WHITE);
	
	ellipse(350+70,400,270,90,25,30);
	moveto(350+70,370);
	lineto(480+70,370);
	lineto(505+70,400);
	lineto(480+70,430);
	lineto(350+70,430);
	setfillstyle(1,DARKGRAY);
	floodfill(390+70,380,WHITE);
	puthz(405+70,390,"确定",24,25,WHITE);
	ellipse(290-70,400,90,270,25,30);
	moveto(290-70,370);
	lineto(160-70,370);
	lineto(135-70,400);
	lineto(160-70,430);
	lineto(290-70,430);
	floodfill(240-70,400,WHITE);
	puthz(180-70,390,"返回",24,25,WHITE);
}	

void s_pageAcciIns(){
	while(1){
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX>160&&MouseX<540&&MouseY>100&&MouseY<140){
			if(mouse_press(160,100,540,140)==2){
				MouseS = 2;
				continue;
			}
			else if(mouse_press(160,100,540,140) == 1){
				lenPageAcciIns[0] = hz_input(160+5,100,540,140,tmpInsPname,lenPageAcciIns[0],WHITE,DARKGRAY,32);
			}
		}
		else if(MouseX>160&&MouseX<210&&MouseY>160&&MouseY<200){
			if(mouse_press(160,160,210,200)==2){
				MouseS = 2;
				continue;
			}
			else if(mouse_press(160,160,210,200) == 1){
				lenPageAcciIns[1] = hz_input(160+5,160,210,200,tmpInsBandhz,0,WHITE,DARKGRAY,32);
			}
		}
		else if(MouseX>220&&MouseX<540&&MouseY>160&&MouseY<200){
			if(mouse_press(220,160,540,200) == 2){
				MouseS = 2;
				continue;
			}
			else if(mouse_press(220,160,540,200) == 1){
				lenPageAcciIns[2] = inputadmin(tmpInsBandstr,225,160,13,WHITE,32);
			}
		}
		else if(MouseX>160&&MouseX<540&&MouseY>220&&MouseY<260){
			if(mouse_press(160,220,540,260)==2){
				MouseS = 2;
				continue;
			}
			else if(mouse_press(160,220,540,260) == 1){
				lenPageAcciIns[3] = inputadmin(tmpInsPhonenum,165,220,13,WHITE,32);
			}
		}
		else if(MouseX>155&&MouseX<175&&MouseY>290&&MouseY<310){
			if(mouse_press(155,290,175,310)==2){
				MouseS =1;
				continue;
			}
			else if(mouse_press(155,290,175,310) == 1){
				do {
					newmouse(&MouseX, &MouseY, &press);
				}while (mouse_press(155,290,175,310) == 1);
				if(fgAcciIns[0]){
					clrmous(MouseX,MouseY);
					setcolor(BLACK);
					setlinestyle(SOLID_LINE,0,NORM_WIDTH);
					setfillstyle(1,RED);
					fillellipse(165,300,9,9);
					setfillstyle(1,LIGHTGRAY);
					fillellipse(285,300,9,9);
					fillellipse(405,300,9,9);
					fgAcciIns[0] = 0;
					fgAcciIns[1] = 1;
					fgAcciIns[2] = 1;
					tmpIns = 1;
				}
				else {
					clrmous(MouseX,MouseY);
					setcolor(BLACK);
					setlinestyle(SOLID_LINE,0,NORM_WIDTH);
					setfillstyle(1,LIGHTGRAY);
					fillellipse(165,300,9,9);
					fgAcciIns[0] = 1;
					tmpIns = 0;
				}
				
			}
			
			
		}
		else if(MouseX>275&&MouseX<295&&MouseY>290&&MouseY<310){
			if(mouse_press(275,290,295,310)==2){
				MouseS = 1;
				
				continue;
			}
			else if(mouse_press(275,290,295,310)==1){
				do {
					newmouse(&MouseX, &MouseY, &press);
				}while (mouse_press(275,290,295,310) == 1);
				if(fgAcciIns[1]){	
					clrmous(MouseX,MouseY);
					setcolor(BLACK);
					setlinestyle(SOLID_LINE,0,NORM_WIDTH);
					setfillstyle(1,RED);
					fillellipse(285,300,9,9);
					setfillstyle(1,LIGHTGRAY);
					fillellipse(165,300,9,9);
					fillellipse(405,300,9,9);
					fgAcciIns[0] = 1;
					fgAcciIns[1] = 0;
					fgAcciIns[2] = 1;
					tmpIns = 2;
				}
				else{
					clrmous(MouseX,MouseY);
					setcolor(BLACK);
					setlinestyle(SOLID_LINE,0,NORM_WIDTH);
					setfillstyle(1,LIGHTGRAY);
					fillellipse(285,300,9,9);
					
					fgAcciIns[1] = 1;
					tmpIns = 0;
				}
			}
			
		}
		else if(MouseX>395&&MouseX<415&&MouseY>290&&MouseY<310){
			if(mouse_press(395,290,415,310)==2){
				MouseS = 1;
				continue;
			}
			else if(mouse_press(395,290,415,310)==1){
				do {
					newmouse(&MouseX, &MouseY, &press);
				}while (mouse_press(395,290,415,310) == 1);
				if(fgAcciIns[2]){	
					clrmous(MouseX,MouseY);
					setcolor(BLACK);
					setlinestyle(SOLID_LINE,0,NORM_WIDTH);
					setfillstyle(1,RED);
					fillellipse(405,300,9,9);
					setfillstyle(1,LIGHTGRAY);
					fillellipse(165,300,9,9);
					fillellipse(285,300,9,9);
					fgAcciIns[0] = 1;
					fgAcciIns[1] = 1;
					fgAcciIns[2] = 0;
					tmpIns = 3;
				}
				else {
					clrmous(MouseX,MouseY);
					setcolor(BLACK);
					setlinestyle(SOLID_LINE,0,NORM_WIDTH);
					setfillstyle(1,LIGHTGRAY);
					fillellipse(405,300,9,9);
					fgAcciIns[2] = 1;
					tmpIns = 0;
				}
			}
		}
		else if(MouseX>(375+70)&&MouseX<(480+70)&&MouseY>370&&MouseY<430){//确定键
			if(mouse_press(375+70,370,480+70,430)==2){
				MouseS = 1;
				continue;
			}
			else if(mouse_press(375+70,370,480+70,430) == 1){
				clrmous(MouseX,MouseY);
				if(!(fgAcciIns[0]&&fgAcciIns[1]&&fgAcciIns[2])&&lenPageAcciIns[0]&&lenPageAcciIns[1]&&lenPageAcciIns[2]&&lenPageAcciIns[3]){
					strcpy(node_cur->hosts.InsPname_acci,tmpInsPname);
					strcpy(node_cur->hosts.Insphonenum_acci,tmpInsPhonenum);
					strcpy(node_cur->hosts.InsBandhz_acci,tmpInsBandhz);
					strcpy(node_cur->hosts.InsBandstr_acci,tmpInsBandstr);
					node_cur->hosts.Ins_Acci = tmpIns;
					pagefg = 3;
					page = pagePayIns;//这里还要判断一下输入框是不是输入正确的格式
					break;
				}
				else {
					puthz(280,400,"输入框为空！",16,15,RED);
					delay(500);
					setfillstyle(1,LIGHTGRAY);
					bar(275,395,430,420);
				}
			}
		}
		else if(MouseX>(160-70)&&MouseX<(265-70)&&MouseY>370&&MouseY<430){//返回键
			if(mouse_press(160-70,370,265-70,430)==2){
				MouseS = 1;
				continue;
			}
			else if(mouse_press(160-70,370,265-70,430)==1){
				clrmous(MouseX,MouseY);
				lenPageAcciIns[0] = 0;
				lenPageAcciIns[1] = 0;
				lenPageAcciIns[2] = 0;
				lenPageAcciIns[3] = 0;
				fgAcciIns[0] = 1;
				fgAcciIns[1] = 1;
				fgAcciIns[2] = 1;
				page = pageBuy;
				break;
			}
		}
		
		if(MouseS != 0)MouseS=0;
	}
}


//旅行险的相关操作
void g_pageTravelIns(){
	cleardevice();
	setbkcolor(LIGHTGRAY);
	setcolor(LIGHTBLUE);
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	line(240,60,400,60);
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	setcolor(WHITE);
	moveto(40,80);
	lineto(40,340);
	lineto(600,340);
	lineto(600,80);
	lineto(40,80);
	setfillstyle(1,DARKGRAY);
	floodfill(150,140,WHITE);
	circle(80,120,6);
	circle(80,180,6);
	circle(80,240,6);
	circle(80,300,6);
	setfillstyle(1,LIGHTRED);
	floodfill(80,120,WHITE);
	floodfill(80,180,WHITE);
	floodfill(80,240,WHITE);
	floodfill(80,300,WHITE);
	setfillstyle(1,WHITE);
	bar(160,100,540,140);
	bar(160,160,210,200);
	bar(220,160,540,200);
	bar(160,220,540,260);
	setfillstyle(1,LIGHTGRAY);
	circle(165,300,10);
	circle(285,300,10);
	circle(405,300,10);
	floodfill(160,300,WHITE);
	floodfill(280,300,WHITE);
	floodfill(400,300,WHITE);
	
	//放置汉字
	puthz(180,20,"为您的旅途保驾护航",32,30,LIGHTBLUE);
	puthz(90,115,"被保人名",16,15,WHITE);
	puthz(90,175,"车牌号码",16,15,WHITE);
	puthz(90,235,"手机号码",16,15,WHITE);
	puthz(100,290,"期限",16,15,WHITE);
	puthz(190,290,"一年",24,25,WHITE);
	puthz(310,290,"两年",24,25,WHITE);
	puthz(430,290,"三年",24,25,WHITE);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	setcolor(RED);
	outtextxy(525,285,"110");
	puthz(580,285,"元",16,1,WHITE);
	setcolor(WHITE);
	outtextxy(530,305,"/");
	puthz(550,305,"年",16,1,WHITE);
	
		//操作按键
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	setcolor(WHITE);
	
	ellipse(350+70,400,270,90,25,30);
	moveto(350+70,370);
	lineto(480+70,370);
	lineto(505+70,400);
	lineto(480+70,430);
	lineto(350+70,430);
	setfillstyle(1,DARKGRAY);
	floodfill(390+70,380,WHITE);
	puthz(405+70,390,"确定",24,25,WHITE);
	ellipse(290-70,400,90,270,25,30);
	moveto(290-70,370);
	lineto(160-70,370);
	lineto(135-70,400);
	lineto(160-70,430);
	lineto(290-70,430);
	floodfill(240-70,400,WHITE);
	puthz(180-70,390,"返回",24,25,WHITE);
}

void s_pageTravelIns(){
	while(1){
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX>160&&MouseX<540&&MouseY>100&&MouseY<140){//人名
			if(mouse_press(160,100,540,140)==2){
				MouseS = 2;
				continue;
			}
			else if(mouse_press(160,100,540,140)==1){
				lenPageTravelIns[0] = hz_input(160+5,100,540,140,tmpInsPname,lenPageTravelIns[0],WHITE,DARKGRAY,32);
			}
		}
		else if(MouseX>160&&MouseX<210&&MouseY>160&&MouseY<200){//车牌
			if(mouse_press(160,160,210,200)==2){
				MouseS = 2;
				continue;
			}
			else if(mouse_press(160,160,210,200) == 1){
				lenPageTravelIns[1] = hz_input(160+5,160,210,200,tmpInsBandhz,0,WHITE,DARKGRAY,32);
			}
		}
		else if(MouseX>220&&MouseY>160&&MouseX<540&&MouseY<200){
			if(mouse_press(220,160,540,200) == 2){
				MouseS = 2;
				continue;
			}
			else if(mouse_press(220,160,540,200) == 1){
				lenPageTravelIns[2] = inputadmin(tmpInsBandstr,225,160,10,WHITE,32);
			}
		}
		else if(MouseX>160&&MouseX<540&&MouseY>220&&MouseY<260){//手机
			if(mouse_press(160,220,540,260)==2){
				MouseS = 2;
				continue;
			}
			else if(mouse_press(160,220,540,260) == 1){
				lenPageTravelIns[3] = inputadmin(tmpInsPhonenum,165,220,11,WHITE,32);
			}
		}
		else if(MouseX>155&&MouseX<175&&MouseY>290&&MouseY<310){
			if(mouse_press(155,290,175,310)==2){
				MouseS =1;
				continue;
			}
			else if(mouse_press(155,290,175,310) == 1){
				do {
					newmouse(&MouseX, &MouseY, &press);
				}while (mouse_press(155,290,175,310) == 1);
				if(fgTravelIns[0]){
					clrmous(MouseX,MouseY);
					setcolor(BLACK);
					setlinestyle(SOLID_LINE,0,NORM_WIDTH);
					setfillstyle(1,RED);
					fillellipse(165,300,9,9);
					setfillstyle(1,LIGHTGRAY);
					fillellipse(285,300,9,9);
					fillellipse(405,300,9,9);
					fgTravelIns[0] = 0;
					fgTravelIns[1] = 1;
					fgTravelIns[2] = 1;
					tmpIns = 1;
				}
				else {
					clrmous(MouseX,MouseY);
					setcolor(BLACK);
					setlinestyle(SOLID_LINE,0,NORM_WIDTH);
					setfillstyle(1,LIGHTGRAY);
					fillellipse(165,300,9,9);
					fgTravelIns[0] = 1;
					tmpIns = 0;
				}
				
			}
			
			
		}
		else if(MouseX>275&&MouseX<295&&MouseY>290&&MouseY<310){
			if(mouse_press(275,290,295,310)==2){
				MouseS = 1;
				
				continue;
			}
			else if(mouse_press(275,290,295,310)==1){
				do {
					newmouse(&MouseX, &MouseY, &press);
				}while (mouse_press(275,290,295,310) == 1);
				if(fgTravelIns[1]){	
					clrmous(MouseX,MouseY);
					setcolor(BLACK);
					setlinestyle(SOLID_LINE,0,NORM_WIDTH);
					setfillstyle(1,RED);
					fillellipse(285,300,9,9);
					setfillstyle(1,LIGHTGRAY);
					fillellipse(165,300,9,9);
					fillellipse(405,300,9,9);
					fgTravelIns[0] = 1;
					fgTravelIns[1] = 0;
					fgTravelIns[2] = 1;
					tmpIns = 2;
				}
				else{
					clrmous(MouseX,MouseY);
					setcolor(BLACK);
					setlinestyle(SOLID_LINE,0,NORM_WIDTH);
					setfillstyle(1,LIGHTGRAY);
					fillellipse(285,300,9,9);
					
					fgTravelIns[1] = 1;
					tmpIns = 0;
				}
			}
			
		}
		else if(MouseX>395&&MouseX<415&&MouseY>290&&MouseY<310){
			if(mouse_press(395,290,415,310)==2){
				MouseS = 1;
				continue;
			}
			else if(mouse_press(395,290,415,310)==1){
				do {
					newmouse(&MouseX, &MouseY, &press);
				}while (mouse_press(395,290,415,310) == 1);
				if(fgTravelIns[2]){	
					clrmous(MouseX,MouseY);
					setcolor(BLACK);
					setlinestyle(SOLID_LINE,0,NORM_WIDTH);
					setfillstyle(1,RED);
					fillellipse(405,300,9,9);
					setfillstyle(1,LIGHTGRAY);
					fillellipse(165,300,9,9);
					fillellipse(285,300,9,9);
					fgTravelIns[0] = 1;
					fgTravelIns[1] = 1;
					fgTravelIns[2] = 0;
					tmpIns = 3;
				}
				else {
					clrmous(MouseX,MouseY);
					setcolor(BLACK);
					setlinestyle(SOLID_LINE,0,NORM_WIDTH);
					setfillstyle(1,LIGHTGRAY);
					fillellipse(405,300,9,9);
					fgTravelIns[2] = 1;
					tmpIns = 0;
				}
			}
		}
		else if(MouseX>(375+70)&&MouseX<(480+70)&&MouseY>370&&MouseY<430){//确定键
			if(mouse_press(375+70,370,480+70,430)==2){
				MouseS = 1;
				continue;
			}
			else if(mouse_press(375+70,370,480+70,430) == 1){
				clrmous(MouseX,MouseY);
				if(lenPageTravelIns[0]&&lenPageTravelIns[1]&&lenPageTravelIns[2]&&lenPageTravelIns[3]&&!(fgTravelIns[0]&&fgTravelIns[1]&&fgTravelIns[2])){
					strcpy(node_cur->hosts.InsPname_travel,tmpInsPname);
					strcpy(node_cur->hosts.InsBandhz_travel,tmpInsBandhz);
					strcpy(node_cur->hosts.InsBandstr_travel,tmpInsBandstr);
					strcpy(node_cur->hosts.Insphonenum_travel,tmpInsPhonenum);
					node_cur->hosts.Ins_Travel = tmpIns;
					pagefg = 4;
					page = pagePayIns;//这里还要判断一下输入框是不是输入正确的格式
					break;
				}
				else{
					puthz(280,400,"输入框为空！",16,15,RED);
					delay(500);
					setfillstyle(1,LIGHTGRAY);
					bar(275,395,430,420);
				}
			}
		}
		else if(MouseX>(160-70)&&MouseX<(265-70)&&MouseY>370&&MouseY<430){//返回键
			if(mouse_press(160-70,370,265-70,430)==2){
				MouseS = 1;
				continue;
			}
			else if(mouse_press(160-70,370,265-70,430)==1){
				clrmous(MouseX,MouseY);
				lenPageTravelIns[0] = 0;
				lenPageTravelIns[1] = 0;
				lenPageTravelIns[2] = 0;
				lenPageTravelIns[3] = 0;
				fgTravelIns[0] = 1;
				fgTravelIns[1] = 1;
				fgTravelIns[2] = 1;
				page = pageBuy;
				break;
			}
		}
		
		if(MouseS != 0)MouseS=0;
	}
}


//付款界面
void g_pagePayIns(){
	cleardevice();
	setbkcolor(LIGHTGRAY);
	setcolor(WHITE);
	setfillstyle(1,DARKGRAY);
	bar(100,60,540,300);
	fillellipse(320,430,20,20);
	setfillstyle(1,LIGHTGREEN);
	bar(200,340,440,380);
	setfillstyle(1,LIGHTBLUE);
	fillellipse(320,60,50,50);
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	line(160,160,480,160);
	line(160,240,480,240);
	
	circle(320,430,30);
	setfillstyle(1,LIGHTGRAY);
	
	bar(260,180,460,220);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	setcolor(WHITE);
	switch(pagefg){
		case 1:{
			talPrice_dec = 120*(node_cur->hosts.Ins_Car[0]+node_cur->hosts.Ins_Car[1]+node_cur->hosts.Ins_Car[2]);
			sprintf(talPrice_str,"%d",talPrice_dec);
			break;
		}
		case 2:{
			talPrice_dec = 100*tmpIns;
			sprintf(talPrice_str,"%d",talPrice_dec);
			break;
		}
		case 3:{
			talPrice_dec = 105*tmpIns;
			sprintf(talPrice_str,"%d",talPrice_dec);
			break;
		}
		case 4:{
			talPrice_dec = 110*tmpIns;
			sprintf(talPrice_str,"%d",talPrice_dec);
			break;
		}
	}	
	outtextxy(340,195,talPrice_str);
	puthz(305,422,"取消",16,15,WHITE);
	puthz(170,190,"总计",24,25,WHITE);
	puthz(490,195,"元",24,1,WHITE);
	puthz(285,30,"平",32,1,LIGHTRED);
	puthz(325,60,"安",32,1,LIGHTRED);
	puthz(270,350,"确认支付",24,25,DARKGRAY);
	
	
}

void s_pagePayIns(){
	while(1){
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX>200&&MouseX<440&&MouseY>340&&MouseY<380){
			if(mouse_press(200,340,440,380) == 2){
				MouseS = 1;
				continue;
			}
			else if(mouse_press(200,340,440,380)==1){
				clrmous(MouseX,MouseY);
				puthz(480,420,"支付成功！",16,18,GREEN);
				delay(500);
				setfillstyle(1,LIGHTGRAY);
				bar(475,415,580,440);
				node_cur->hosts.BillsPrice += talPrice_dec;
				page = pageMenu;
				break;
			}
		}
		else if(MouseX>290&&MouseX<350&&MouseY>400&&MouseY<460){//中间的按钮，相当于是返回
			if(mouse_press(290,400,350,460)==2){
				MouseS = 1;
				continue;
			}
			else if (mouse_press(290,400,350,460) == 1){
				clrmous(MouseX,MouseY);
				page = pageBuy;
				break;
			}
		}
	}
}





