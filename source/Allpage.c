#include "public.h"
#include "Allpage.h"
#include "operator.h"

extern int page;
extern  node* node_cur;
extern  node* node_head;
int tmpCarType = 0;//������¼��ǰ�ĳ����ĳ�������Ϣ����Ϊ���޸���Ϣ���ص�ʱ��Ҫ�ѿ��е���Ϣ��λ
char tmpPhonenum[15];
char tmpPassport[20];
char tmpCarBandhz[5];
char tmpCarBandstr[10];
char tmpAddr[20];
//�����ַ��ĳ��ȱ���
int lenPageMain[2] = {0};
int lenPageRegi[5] = {0};
int lenPageChangeIfm[4] = {0};
int lenPageCarIns[4] = {0};//fg�������ܽ�whileѭ����,len��������¼������������
int lenPageCarIfm[3] = {0};
int lenPageHealthIns[4] = {0};
int lenPageAcciIns[4] = {0};
int lenPageTravelIns[4] = {0};

//�źŵƱ���
int fgCarIns[3] = {1};//��������ж�ѡ���ǲ����Ѿ�ѡ����
int fgHealthIns[3] = {1};
int fgTravelIns[3] = {1};
int fgAcciIns[3] = {1};
int fgCarIfm[3] = {1};
int fgChangeIfm[3] = {1};
//���ڵ�½�ı���
char tempPhonenum[15],tempPassport[20];
//��ӵ�����������յ��������
char tmpInsAddr[20],tmpInsPname[10],tmpInsBandhz[5],tmpInsBandstr[10],tmpInsPhonenum[15];
int tmpInsCar[3];
int tmpIns = 0;
int talPrice_dec = 0;
char talPrice_str[5];
int pagefg = 0;//�����ж����ĸ������ȥ��1������ 2�������� 3�������� 4��������
//��ʼ�ĵ�½������ʾ����
void g_pageMain(){
    cleardevice();
	setbkcolor(LIGHTGRAY);
	setfillstyle(1,WHITE);
	//�˺ź�����������
	bar(120,45,520,90);
	bar(120,135,520,180);
	puthz(60,55,"�˺�",24,25,WHITE);
	puthz(60,145,"����",24,25,WHITE);
	
	
	//��½��
	setcolor(WHITE);
	ellipse(225,280,90,270,20,20);
	ellipse(405,280,270,90,20,20);
	line(225,260,405,260);
	line(225,300,405,300);
	setfillstyle(1,LIGHTRED);
	floodfill(250,280,WHITE);
	puthz(290,270,"��½",24,30,WHITE);
	
	//���û�
	ellipse(225,340,90,270,20,20);
	ellipse(405,340,270,90,20,20);
	line(225,320,405,320);
	line(225,360,405,360);
	setfillstyle(1,LIGHTRED);
	floodfill(250,330,WHITE);
	puthz(275,329,"���û�",24,30,WHITE);
	
	//�˳���
	setfillstyle(1,RED);
	bar(480,395,560,435);
	puthz(505,410,"�˳�",16,15,WHITE);
	
	//С��
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


}
void s_pageMain(){//��pending��
	mouseinit();
		while(1){
		newmouse(&MouseX,&MouseY,&press);
		//������˳�ʱ
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
		//��������û�ʱ
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
		else if(MouseX>225&&MouseX<405&&MouseY>260&&MouseY<300){//��½
			if(mouse_press(225,260,405,300)==2){
				MouseS = 1;
				continue;
			}
			else if (mouse_press(225,260,405,300)== 1){
				if(lenPageMain[0]&&lenPageMain[1]){//��������Ϊ��
					if(strcmp(node_cur->hosts.passport,tempPassport) == 0){
						clrmous(MouseX,MouseY);
						page = pageMenu;
						break;
					}
					else{//��ʾ�������pending��
						setfillstyle(1,WHITE);
						bar(120,135,520,180);
						bar(120,45,520,90);
						lenPageMain[0] = 0;
						lenPageMain[1] = 0;
						puthz(240,400,"�˺Ż������������������",16,15,RED);
						delay(500);
						setfillstyle(1,LIGHTGRAY);
						bar(235,390,450,440);
						continue;
					}
					
				}
				else{
					puthz(290,400,"�����Ϊ�գ�",16,15,RED);
					delay(500);
					setfillstyle(1,LIGHTGRAY);
					bar(280,390,440,440);
				}
			}
		}
		//�˺�
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
		//����
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



//���û��Ľ��溯��,���޸�
void g_pageRegi(){
	cleardevice();
	setbkcolor(LIGHTGRAY);
	puthz(70,60,"����",24,25,WHITE);
	puthz(70,130,"�ֻ���",24,25,WHITE);//Ҫ��һ����ʾ���������ֻ���Ҫ��11λ
	puthz(70,200,"����",24,25,WHITE);
	puthz(40,270,"ȷ������",24,25,WHITE);
	setfillstyle(1,WHITE);
	bar(150,50,520,90);//������
	bar(150,120,520,160);//�����
	bar(150,190,520,230);//ȷ�������
	bar(150,260,520,300);
	setfillstyle(1,LIGHTRED);
	bar(120,360,220,400);//��һҳ��
	
	bar(410,360,510,400);//��һҳ��
	puthz(130,370,"��һ��",24,30,WHITE);
	puthz(420,370,"��һ��",24,30,WHITE);
	
	
}
void s_pageRegi(){
	
	while(1){
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX>120&&MouseX<220&&MouseY>360&&MouseY<400){//��һҳ
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
		else if(MouseX>410&&MouseX<510&&MouseY>360&&MouseY<400){//��һҳ
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
						puthz(275,410,"������ʮһλ����",16,15,RED);
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
						puthz(250,420,"���벻ͬ������������",16,15,RED);
						delay(500);
						setfillstyle(1,LIGHTGRAY);
						bar(245,410,400,440);
						continue;
					}
				}
				else{
					puthz(290,410,"�����Ϊ�գ�",16,15,RED);
					delay(500);
					setfillstyle(1,LIGHTGRAY);
					bar(280,400,390,440);
				}
			}
		}
		else if(MouseX>150&&MouseX<520&&MouseY>50&&MouseY<90){//����
			if(mouse_press(150,50,520,90)== 2){
				MouseS = 2;
				continue;
			}
			else if(mouse_press(150,50,520,90)==1){
				lenPageRegi[0] = hz_input(155,52,520,92,node_cur->hosts.m_name,lenPageRegi[0],WHITE,DARKGRAY,32);
				
			}
		}
		else if(MouseX>150&&MouseX<520&&MouseY>120&&MouseY<160){//�ֻ�
			if(mouse_press(150,120,520,160)== 2){
				MouseS=2;
				continue;
			}
			else if(mouse_press(150,120,520,160)==1){
				lenPageRegi[1] = inputadmin(node_cur->hosts.m_phone,155,120,19,WHITE,32);
				
			}
		}
		else if(MouseX>150&&MouseX<520&&MouseY>190&&MouseY<230){//����
			if(mouse_press(150,190,520,230)==2){
				MouseS=2;
				continue;
			}
			else if(mouse_press(150,190,520,230)==1){
				lenPageRegi[2] = inputpassword(tempPassport,155,195,19,WHITE);
			}
		}
		else if(MouseX>150&&MouseX<520&&MouseY>260&&MouseY<300){//ȷ������
			if(mouse_press(150,260,520,300) == 2){
				MouseS = 2;
				continue;
			}
			else if(mouse_press(150,260,520,300) == 1){
				lenPageRegi[3] = inputpassword(node_cur->hosts.passport,155,265,19,WHITE);
			}
			//�����ĺ�����û��ʵ��
		}
		if(MouseS!=0)MouseS=0;
	}
} 


//������Ϣ�����뺯��(ע��ʱ)
void g_pageCarIfm(){//���޸�
	cleardevice();
	setbkcolor(LIGHTGRAY);
	setfillstyle(1,WHITE);
	bar(140,105,510,150);
	bar(140,170,195,150+65);
	bar(210,170,510,150+65);
	puthz(80,120,"סַ",24,20,WHITE);
	puthz(80,120+65,"����",24,20,WHITE);
	puthz(80,195+65,"����",24,20,WHITE);
	setfillstyle(1,LIGHTRED);
	bar(120,360,220,400);//��һҳ��
	bar(410,360,510,400);//ע���
	puthz(130,370,"��һ��",24,30,WHITE);
	puthz(430,370,"ע��",24,30,WHITE);
	puthz(240,50,"¼��������Ϣ",32,30,WHITE);
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
	
	puthz(200,240+65,"�γ�",16,15,BLUE);
	puthz(280,240+65,"ԽҰ��",16,15,YELLOW);
	puthz(360,240+65,"����",16,15,RED);

	
	
	
	
}
void s_pageCarIfm(){//��ע�����Ϣд��pending��2022/2/24

	while(1){
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX>120&&MouseX<220&&MouseY>360&&MouseY<400){//��һҳ
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
		else if(MouseX>410&&MouseX<510&&MouseY>360&&MouseY<400){//ע��button
			if(mouse_press(410,360,510,400) == 2){
				MouseS = 1;
				continue;
			}
			else if(mouse_press(410,360,510,400) == 1){//���ﻹҪ�ж�һ��������ǲ���������ȷ�ĸ�ʽ
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
					add_back(node_head,node_cur);//����д�����Ϣ�ӵ���������
					
					page = pageMenu;
					break;
				}
				else{
					puthz(290,410,"�����Ϊ�գ�",16,15,RED);
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
		else if (MouseX>140&&MouseX<195&&MouseY>105+65&&MouseY<150+65){//����
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
		else if (MouseX>205&&MouseX<225&&MouseY>200+65&&MouseY<220+65){//ѡ��ť
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

//ʹ�ò˵�
void g_pageMenu(){//���޸�
	cleardevice();
	setbkcolor(LIGHTGRAY);
	puthz(240,20,"��ӭʹ��",32,40,WHITE);
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	setcolor(WHITE);
	//������
	
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
	puthz(125,210,"����",24,25,WHITE);
	//������
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
	puthz(285,210,"�鱣��",24,25,WHITE);
	//������
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
	puthz(445,210,"������",24,25,WHITE);
	//������Ĳ�������
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
	puthz(385,390,"�޸���Ϣ",24,25,WHITE);
	ellipse(290,400,90,270,25,30);
	moveto(290,370);
	lineto(160,370);
	lineto(135,400);
	lineto(160,430);
	lineto(290,430);
	floodfill(240,400,WHITE);
	puthz(180,390,"�˳�",24,25,WHITE);
	puthz(306,393,"�ҵ�",16,15,WHITE);
	
}

void s_pageMenu(){
	
	while(1){
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX>120&&MouseX<200&&MouseY>100&&MouseY<170){//����
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
		else if(MouseX>280&&MouseX<360&&MouseY>90&&MouseY<190){//�鱣��
			if(mouse_press(280,90,360,190) == 2){
				MouseS = 1;
				continue;
			}
			//else if(mouse_press(280,90,360,190)==1){}
		}
		else if(MouseX>440&&MouseX<520&&MouseY>90&&MouseY<190){//������
			if(mouse_press(440,90,520,190)==2){
				MouseS = 1;
				continue;
			}
		//else if(mouse_press(440,90,520,190)==1){}
		}
		else if(MouseX>375&&MouseX<480&&MouseY>370&&MouseY<430){//�޸���Ϣ
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
		else if(MouseX>295&&MouseX<345&&MouseY>375&&MouseY<425){//��ʾ��ϸ��Ϣ
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
		else if(MouseX>160&&MouseX<265&&MouseY>370&&MouseY<430){//�˳�
			if(mouse_press(160,370,265,430)==2){
				MouseS = 1;
				continue;
			}
			else if(mouse_press(160,370,265,430)==1){
				node_head = del_node(node_head,node_cur->hosts.m_phone);
				add_back(node_head,node_cur);
				writeAll(node_head);
				page = 'q';
				break;
			}
		}
		if(MouseS != 0)MouseS=0;
	}
	
}

//��ʾ��ϸ��Ϣ�ĺ���
void g_pageShowIfm(){//done(���Բ��޸���)
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
	//��ʾ���ֺͳ��Ƶ�������
	line(120,70,280,70);
	line(440,70,600,70);
	//������Ϣ����ʾ��
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
	//����
	line(60,180,160,180);
	line(60,220,160,220);
	line(60,260,160,260);
	//������
	line(200,180,300,180);
	line(200,220,300,220);
	line(200,260,300,260);
	//������
	line(340,180,440,180);
	line(340,220,440,220);
	line(340,260,440,260);
	//������
	line(480,180,580,180);
	line(480,220,580,220);
	line(480,260,580,260);
	setfillstyle(1,WHITE);
	//��ʾ����ı��յĹ������
	bar(60,280,160,340);
	bar(200,280,300,340);
	bar(340,280,440,340);
	bar(480,280,580,340);
	//������ҳ��İ�ť
	circle(320,420,40);
	circle(320,420,30);
	setfillstyle(1,DARKGRAY);
	fillellipse(320,420,29,29);
	
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	outtextxy(55,55,"ME");
	outtextxy(370,55,"CAR");
	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	outtextxy(305,417,"MENU");
	puthz(80,110,"����",16,15,WHITE);
	puthz(220,110,"������",16,15,WHITE);
	puthz(360,110,"������",16,15,WHITE);
	puthz(500,110,"������",16,15,WHITE);
	//��ʾ���������
	//����һ�����ͳ��ƺ�
	puthz(160,40,node_cur->hosts.m_name,24,25,DARKGRAY);
	line(440,70,600,70);
	puthz(460,40,node_cur->hosts.carBandhz,24,25,DARKGRAY);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	setcolor(DARKGRAY);
	outtextxy(490,45,node_cur->hosts.carBandstr);
	//����2.1��ʾ���յ���Ϣ
	if(node_cur->hosts.Ins_Car[0]||node_cur->hosts.Ins_Car[1]||node_cur->hosts.Ins_Car[2]){//�����˱��յ����
		puthz(65,160,node_cur->hosts.InsAddr,16,15,WHITE);
		puthz(70,200,node_cur->hosts.InsBandhz_car,16,1,WHITE);
		settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
		outtextxy(90,205,node_cur->hosts.InsBandstr_car);
		outtextxy(65,245,node_cur->hosts.Insphonenum_car);
		if(node_cur->hosts.Ins_Car[0])
			puthz(80,285,"��ҵ��",16,20,RED);
		else 
			puthz(80,285,"��ҵ��",16,20,DARKGRAY);
		if(node_cur->hosts.Ins_Car[1])
			puthz(80,305,"��ǿ��",16,20,RED);
		else 
			puthz(80,305,"��ǿ��",16,20,DARKGRAY);
		if(node_cur->hosts.Ins_Car[2])
			puthz(80,325,"������",16,20,RED);
		else 
			puthz(80,325,"������",16,20,DARKGRAY);
	}
	else{
		settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
		outtextxy(100,195,"\\");
		outtextxy(100,155,"\\");
		outtextxy(100,235,"\\");
		puthz(80,285,"��ҵ��",16,20,DARKGRAY);
		puthz(80,305,"��ǿ��",16,20,DARKGRAY);
		puthz(80,325,"������",16,20,DARKGRAY);
	}
	
	//����2.2��ʾ������
	if(node_cur->hosts.Ins_Health){
		puthz(205,160,node_cur->hosts.InsPname_health,16,15,WHITE);
		puthz(205,200,node_cur->hosts.InsBandhz_health,16,15,WHITE);
		settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
		outtextxy(230,205,node_cur->hosts.InsBandstr_health);
		outtextxy(205,245,node_cur->hosts.Insphonenum_health);
		switch(node_cur->hosts.Ins_Health){
			case 1:
			{
				puthz(235,285,"һ��",16,20,RED);
				puthz(235,305,"����",16,20,DARKGRAY);
				puthz(235,325,"����",16,20,DARKGRAY);
				break;
			}
			case 2:
			{
				puthz(235,285,"һ��",16,20,DARKGRAY);
				puthz(235,305,"����",16,20,RED);
				puthz(235,325,"����",16,20,DARKGRAY);
				break;
			}
			case 3:
			{
				puthz(235,285,"һ��",16,20,DARKGRAY);
				puthz(235,305,"����",16,20,DARKGRAY);
				puthz(235,325,"����",16,20,RED);
				break;
			}
			
		}
	}
	else {
		settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
		outtextxy(240,195,"\\");
		outtextxy(240,155,"\\");
		outtextxy(240,235,"\\");
		puthz(235,285,"һ��",16,20,DARKGRAY);
		puthz(235,305,"����",16,20,DARKGRAY);
		puthz(235,325,"����",16,20,DARKGRAY);
	}
	
	//����2.3��ʾ������
	if(node_cur->hosts.Ins_Acci){
		puthz(345,160,node_cur->hosts.InsPname_acci,16,15,WHITE);
		puthz(345,200,node_cur->hosts.InsBandhz_acci,16,15,WHITE);
		settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
		outtextxy(370,205,node_cur->hosts.InsBandstr_acci);
		outtextxy(345,245,node_cur->hosts.Insphonenum_acci);
		switch(node_cur->hosts.Ins_Acci){
			case 1:
			{
				puthz(375,285,"һ��",16,20,RED);
				puthz(375,305,"����",16,20,DARKGRAY);
				puthz(375,325,"����",16,20,DARKGRAY);
				break;
			}
			case 2:
			{
				puthz(375,285,"һ��",16,20,DARKGRAY);
				puthz(375,305,"����",16,20,RED);
				puthz(375,325,"����",16,20,DARKGRAY);
				break;
			}
			case 3:
			{
				puthz(375,285,"һ��",16,20,DARKGRAY);
				puthz(375,305,"����",16,20,DARKGRAY);
				puthz(375,325,"����",16,20,RED);
				break;
			}
			
		}
	}
	else {
		settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
		outtextxy(380,195,"\\");
		outtextxy(380,155,"\\");
		outtextxy(380,235,"\\");
		puthz(375,285,"һ��",16,20,DARKGRAY);
		puthz(375,305,"����",16,20,DARKGRAY);
		puthz(375,325,"����",16,20,DARKGRAY);
	}
	//����2.4��ʾ������
	if(node_cur->hosts.Ins_Travel){
		puthz(485,160,node_cur->hosts.InsPname_travel,16,15,WHITE);
		puthz(485,200,node_cur->hosts.InsBandhz_travel,16,15,WHITE);
		settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
		outtextxy(510,205,node_cur->hosts.InsBandstr_travel);
		outtextxy(485,245,node_cur->hosts.Insphonenum_travel);
		switch(node_cur->hosts.Ins_Travel){
			case 1:
			{
				puthz(515,285,"һ��",16,20,RED);
				puthz(515,305,"����",16,20,DARKGRAY);
				puthz(515,325,"����",16,20,DARKGRAY);
				break;
			}
			case 2:
			{
				puthz(515,285,"һ��",16,20,DARKGRAY);
				puthz(515,305,"����",16,20,RED);
				puthz(515,325,"����",16,20,DARKGRAY);
				break;
			}
			case 3:
			{
				puthz(515,285,"һ��",16,20,DARKGRAY);
				puthz(515,305,"����",16,20,DARKGRAY);
				puthz(515,325,"����",16,20,RED);
				break;
			}
			
		}
	}
	else {
		settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
		outtextxy(520,195,"\\");
		outtextxy(520,155,"\\");
		outtextxy(520,235,"\\");
		puthz(515,285,"һ��",16,20,DARKGRAY);
		puthz(515,305,"����",16,20,DARKGRAY);
		puthz(515,325,"����",16,20,DARKGRAY);
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
// ���յĺ���
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
	
	//���·�����Ϣ
	moveto(128,180);
	lineto(178,180);
	lineto(178,280);
	lineto(128,310);
	lineto(78,280);
	lineto(78,180);
	lineto(128,180);
	setfillstyle(1,BLUE);
	floodfill(128,190,WHITE);
	puthz(105,220,"����",24,25,WHITE);
	
	moveto(128+128,180);
	lineto(178+128,180);
	lineto(178+128,280);
	lineto(128+128,310);
	lineto(78+128,280);
	lineto(78+128,180);
	lineto(128+128,180);
	setfillstyle(1,LIGHTGREEN);
	floodfill(256,190,WHITE);
	puthz(218,220,"������",24,25,WHITE);
	
	moveto(128+256,180);
	lineto(178+256,180);
	lineto(178+256,280);
	lineto(128+256,310);
	lineto(78+256,280);
	lineto(78+256,180);
	lineto(128+256,180);
	setfillstyle(1,LIGHTCYAN);
	floodfill(384,190,WHITE);
	puthz(346,220,"������",24,25,WHITE);
	
	moveto(128+384,180);
	lineto(178+384,180);
	lineto(178+384,280);
	lineto(128+384,310);
	lineto(78+384,280);
	lineto(78+384,180);
	lineto(128+384,180);
	setfillstyle(1,LIGHTRED);
	floodfill(512,190,WHITE);
	puthz(474,220,"������",24,25,WHITE);
	//����������
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
		if(MouseX>78&&MouseX<178&&MouseY>180&&MouseY<280){//����
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
					puthz(270,330,"���ѹ���ñ��գ�",16,15,RED);
					//puthz(250,350,"�޸ĳ�����Ϣ����ٴι���",16,15,RED);
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
		else if(MouseX>206&&MouseX<306&&MouseY>180&&MouseY<280){//������
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
					puthz(270,330,"���ѹ���ñ���",16,15,RED);
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
		else if(MouseX>334&&MouseX<434&&MouseY>180&&MouseY<280){//������
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
					puthz(270,330,"���ѹ���ñ���",16,15,RED);
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
		else if(MouseX>462&&MouseX<562&&MouseY>180&&MouseY<280){//������
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
					puthz(270,330,"���ѹ���ñ���",16,15,RED);
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
		
		//�·��Ĳ�������
		else if(MouseX>280&&MouseX<360&&MouseY>360&&MouseY<440){//�˵���
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

void g_pageChangeIfm(){//���޸�
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
	
	puthz(170,40,"�������ĸ�����Ϣ",24,30,WHITE);

	puthz(30,110,"�ֻ���",16,15,WHITE);
	puthz(40,170,"����",16,15,WHITE);
	puthz(40,230,"סַ",16,15,WHITE);
	puthz(340,110,"����",16,15,WHITE);
	puthz(340,185+50,"����",16,15,WHITE);
	
	puthz(400,220+50,"�γ�",16,15,WHITE);
	puthz(450,220+50,"ԽҰ��",16,15,WHITE);
	puthz(510,220+50,"����",16,15,WHITE);
	
	
	//����������
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	
	circle(320,400,45);
	setfillstyle(1,DARKGRAY);
	floodfill(320,400,WHITE);
	circle(320,400,35);
	puthz(295,390,"����",24,25,WHITE);
	setcolor(LIGHTRED);
	line(40,440,60,410);
	line(40,440,130,440);
	
	puthz(70,410,"����",24,25,WHITE);
	
	setcolor(LIGHTGRAY);
	puthz(85,172,"�������µ�����",16,20,LIGHTGRAY);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
	outtextxy(95,105,node_cur->hosts.m_phone);
	outtextxy(450,105,node_cur->hosts.carBandstr);
	puthz(85,232,node_cur->hosts.P_addr,16,20,LIGHTGRAY);
	puthz(385,103,node_cur->hosts.carBandhz,32,1,LIGHTGRAY);

}

void s_pageChangeIfm(){
	
	while(1){
		newmouse(&MouseX,&MouseY,&press);
	
		
		//�·��Ĳ�������

		if(MouseX>275&&MouseX<365&&MouseY>355&&MouseY<445){//�����
			if(mouse_press(275,365,355,445)==2){
				MouseS = 1;
				continue;
			}
			else if(mouse_press(275,365,355,445)==1){
				clrmous(MouseX,MouseY);
				if(lenPageChangeIfm[0]&&lenPageChangeIfm[1]&&lenPageChangeIfm[2]&&!(fgChangeIfm[0]&&fgChangeIfm[1]&&fgChangeIfm[2])){
					node_head = del_node(node_head,node_cur->hosts.m_phone);//��ɾ��ԭ�ȵ�
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
					}//һ���޸������Ϣ�Ǿ����ó��յ���Ϣ
					add_back(node_head,node_cur);//Ȼ���ٰ��������ȥ
					
					puthz(460,390,"�޸ĳɹ�",16,15,GREEN);
					delay(500);
					setfillstyle(1,LIGHTGRAY);
					bar(455,385,560,410);
					page = pageMenu;
					break;
				}
				else {
					puthz(460,390,"�����Ϊ�գ�",16,15,RED);
					delay(500);
					setfillstyle(1,LIGHTGRAY);
					bar(455,385,560,410);
				}
			}
		}
		else if(MouseX>40&&MouseX<130&&MouseY>410&&MouseY<440){//�������ʱ������������صı���
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
		else if(MouseX>80&&MouseX<300&&MouseY>100&&MouseY<140){//�ֻ���
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
		else if(MouseX>80&&MouseX<560&&MouseY>160&&MouseY<200){//����
			if(mouse_press(80,160,560,200) == 2){
				MouseS = 2;
				continue;

			}
			else if(mouse_press(80,160,560,200)==1){
				lenPageChangeIfm[1] = inputpassword(tmpPassport,85,160,20,WHITE);
				
			}
		}
		else if(MouseX>80&&MouseX<300&&MouseY>220&&MouseY<260){//סַ
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
		else if(MouseX>380&&MouseX<430&&MouseY>100&&MouseY<140){//����
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
		else if(MouseX>405&&MouseX<425&&MouseY>(180+50)&&MouseY<(200+50)){//����
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
//���յ���غ���
void g_pageCarIns(){//���޸�
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
	
	//���ú���
	puthz(180,20,"Ϊ���İ������ݻ���",32,30,LIGHTBLUE);
	puthz(90,115,"Ͷ������",16,15,WHITE);
	puthz(90,175,"���ƺ���",16,15,WHITE);
	puthz(90,235,"�ֻ�����",16,15,WHITE);
	puthz(100,290,"���",16,15,WHITE);
	puthz(190,290,"��ҵ��",24,25,WHITE);
	puthz(310,290,"��ǿ��",24,25,WHITE);
	puthz(430,290,"������",24,25,WHITE);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	setcolor(RED);
	outtextxy(525,285,"120");
	puthz(580,285,"Ԫ",16,1,WHITE);
	setcolor(WHITE);
	outtextxy(530,305,"/");
	puthz(550,305,"��",16,1,WHITE);
	
	
	//��������
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
	puthz(405+70,390,"ȷ��",24,25,WHITE);
	ellipse(290-70,400,90,270,25,30);
	moveto(290-70,370);
	lineto(160-70,370);
	lineto(135-70,400);
	lineto(160-70,430);
	lineto(290-70,430);
	floodfill(240-70,400,WHITE);
	puthz(180-70,390,"����",24,25,WHITE);
	
}

void s_pageCarIns(){//���޸�
	
	while(1){
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX>160&&MouseX<540&&MouseY>100&&MouseY<140){//Ͷ������
			if(mouse_press(160,100,540,140)==2){
				MouseS = 2;
				continue;
			}
			else if(mouse_press(160,100,540,140) == 1){
				lenPageCarIns[0] = hz_input(160+5,100,540,140,tmpInsAddr,lenPageCarIns[0],WHITE,DARKGRAY,32);
				
			}
		}
		else if(MouseX>160&&MouseX<210&&MouseY>160&&MouseY<200){//���ƺ���
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
		else if(MouseX>160&&MouseX<540&&MouseY>220&&MouseY<260){//�ֻ���
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
		else if(MouseX>(375+70)&&MouseX<(480+70)&&MouseY>370&&MouseY<430){//ȷ����
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
					page = pagePayIns;//�����Ѿ����
					break;
				}
				else{
					puthz(280,400,"�����Ϊ�գ�",16,15,RED);
					delay(500);
					setfillstyle(1,LIGHTGRAY);
					bar(275,395,430,420);
					continue;
				}
			}
		}
		else if(MouseX>(160-70)&&MouseX<(265-70)&&MouseY>370&&MouseY<430){//���ؼ�
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
//�����յ���غ���
void g_pageHealthIns(){//���޸�
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
	
	//���ú���
	puthz(180,20,"Ϊ���Ľ������ݻ���",32,30,LIGHTBLUE);
	puthz(90,115,"��������",16,15,WHITE);
	puthz(90,175,"���ƺ���",16,15,WHITE);
	puthz(90,235,"�ֻ�����",16,15,WHITE);
	puthz(100,290,"����",16,15,WHITE);
	puthz(190,290,"һ��",24,25,WHITE);
	puthz(310,290,"����",24,25,WHITE);
	puthz(430,290,"����",24,25,WHITE);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	setcolor(RED);
	outtextxy(525,285,"100");
	puthz(580,285,"Ԫ",16,1,WHITE);
	setcolor(WHITE);
	outtextxy(530,305,"/");
	puthz(550,305,"��",16,1,WHITE);
	
	//��������
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
	puthz(405+70,390,"ȷ��",24,25,WHITE);
	ellipse(290-70,400,90,270,25,30);
	moveto(290-70,370);
	lineto(160-70,370);
	lineto(135-70,400);
	lineto(160-70,430);
	lineto(290-70,430);
	floodfill(240-70,400,WHITE);
	puthz(180-70,390,"����",24,25,WHITE);
}
	
void s_pageHealthIns(){

	while(1){
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX>160&&MouseX<540&&MouseY>100&&MouseY<140){//��������
			if(mouse_press(160,100,540,140)==2){
				MouseS = 2;
				continue;
			}
			else if(mouse_press(160,100,540,140) == 1){
				lenPageHealthIns[0] = hz_input(160+5,100,540,140,tmpInsPname,lenPageHealthIns[0],WHITE,DARKGRAY,32);
			}                                                
		}
		else if(MouseX>160&&MouseX<210&&MouseY>160&&MouseY<200){//���ƺ���
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
		else if(MouseX>160&&MouseX<540&&MouseY>220&&MouseY<260){//�ֻ�����
			if(mouse_press(160,220,540,260)==2){
				MouseS = 2;
				continue;
			}
			else if(mouse_press(160,220,540,260) == 1){
				lenPageHealthIns[3] = inputadmin(tmpInsPhonenum,165,220,15,WHITE,32);
			}
		}
		else if(MouseX>155&&MouseX<175&&MouseY>290&&MouseY<310){//ѡ��
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
		else if(MouseX>(375+70)&&MouseX<(480+70)&&MouseY>370&&MouseY<430){//ȷ����
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
					puthz(280,400,"�����Ϊ�գ�",16,15,RED);
					delay(500);
					setfillstyle(1,LIGHTGRAY);
					bar(275,395,430,420);
					continue;
				}
			}
		}
		else if(MouseX>(160-70)&&MouseX<(265-70)&&MouseY>370&&MouseY<430){//���ؼ�
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


//�����յ���غ���
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
	
	//���ú���
	puthz(180,20,"Ϊ���İ�ȫ���ݻ���",32,30,LIGHTBLUE);
	puthz(90,115,"��������",16,15,WHITE);
	puthz(90,175,"���ƺ���",16,15,WHITE);
	puthz(90,235,"�ֻ�����",16,15,WHITE);
	puthz(100,290,"����",16,15,WHITE);
	puthz(190,290,"һ��",24,25,WHITE);
	puthz(310,290,"����",24,25,WHITE);
	puthz(430,290,"����",24,25,WHITE);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	setcolor(RED);
	outtextxy(525,285,"105");
	puthz(580,285,"Ԫ",16,1,WHITE);
	setcolor(WHITE);
	outtextxy(530,305,"/");
	puthz(550,305,"��",16,1,WHITE);
	
	//��������
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
	puthz(405+70,390,"ȷ��",24,25,WHITE);
	ellipse(290-70,400,90,270,25,30);
	moveto(290-70,370);
	lineto(160-70,370);
	lineto(135-70,400);
	lineto(160-70,430);
	lineto(290-70,430);
	floodfill(240-70,400,WHITE);
	puthz(180-70,390,"����",24,25,WHITE);
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
		else if(MouseX>(375+70)&&MouseX<(480+70)&&MouseY>370&&MouseY<430){//ȷ����
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
					page = pagePayIns;//���ﻹҪ�ж�һ��������ǲ���������ȷ�ĸ�ʽ
					break;
				}
				else {
					puthz(280,400,"�����Ϊ�գ�",16,15,RED);
					delay(500);
					setfillstyle(1,LIGHTGRAY);
					bar(275,395,430,420);
				}
			}
		}
		else if(MouseX>(160-70)&&MouseX<(265-70)&&MouseY>370&&MouseY<430){//���ؼ�
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


//�����յ���ز���
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
	
	//���ú���
	puthz(180,20,"Ϊ������;���ݻ���",32,30,LIGHTBLUE);
	puthz(90,115,"��������",16,15,WHITE);
	puthz(90,175,"���ƺ���",16,15,WHITE);
	puthz(90,235,"�ֻ�����",16,15,WHITE);
	puthz(100,290,"����",16,15,WHITE);
	puthz(190,290,"һ��",24,25,WHITE);
	puthz(310,290,"����",24,25,WHITE);
	puthz(430,290,"����",24,25,WHITE);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	setcolor(RED);
	outtextxy(525,285,"110");
	puthz(580,285,"Ԫ",16,1,WHITE);
	setcolor(WHITE);
	outtextxy(530,305,"/");
	puthz(550,305,"��",16,1,WHITE);
	
		//��������
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
	puthz(405+70,390,"ȷ��",24,25,WHITE);
	ellipse(290-70,400,90,270,25,30);
	moveto(290-70,370);
	lineto(160-70,370);
	lineto(135-70,400);
	lineto(160-70,430);
	lineto(290-70,430);
	floodfill(240-70,400,WHITE);
	puthz(180-70,390,"����",24,25,WHITE);
}

void s_pageTravelIns(){
	while(1){
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX>160&&MouseX<540&&MouseY>100&&MouseY<140){//����
			if(mouse_press(160,100,540,140)==2){
				MouseS = 2;
				continue;
			}
			else if(mouse_press(160,100,540,140)==1){
				lenPageTravelIns[0] = hz_input(160+5,100,540,140,tmpInsPname,lenPageTravelIns[0],WHITE,DARKGRAY,32);
			}
		}
		else if(MouseX>160&&MouseX<210&&MouseY>160&&MouseY<200){//����
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
		else if(MouseX>160&&MouseX<540&&MouseY>220&&MouseY<260){//�ֻ�
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
		else if(MouseX>(375+70)&&MouseX<(480+70)&&MouseY>370&&MouseY<430){//ȷ����
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
					page = pagePayIns;//���ﻹҪ�ж�һ��������ǲ���������ȷ�ĸ�ʽ
					break;
				}
				else{
					puthz(280,400,"�����Ϊ�գ�",16,15,RED);
					delay(500);
					setfillstyle(1,LIGHTGRAY);
					bar(275,395,430,420);
				}
			}
		}
		else if(MouseX>(160-70)&&MouseX<(265-70)&&MouseY>370&&MouseY<430){//���ؼ�
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


//�������
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
	puthz(305,422,"ȡ��",16,15,WHITE);
	puthz(170,190,"�ܼ�",24,25,WHITE);
	puthz(490,195,"Ԫ",24,1,WHITE);
	puthz(285,30,"ƽ",32,1,LIGHTRED);
	puthz(325,60,"��",32,1,LIGHTRED);
	puthz(270,350,"ȷ��֧��",24,25,DARKGRAY);
	
	
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
				puthz(480,420,"֧���ɹ���",16,18,GREEN);
				delay(500);
				setfillstyle(1,LIGHTGRAY);
				bar(475,415,580,440);
				page = pageMenu;
				break;
			}
		}
		else if(MouseX>290&&MouseX<350&&MouseY>400&&MouseY<460){//�м�İ�ť���൱���Ƿ���
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