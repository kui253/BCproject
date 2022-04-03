#include "public.h"
#include "operator.h"
int n = 0;

//用来读取txt文件中的数据(这个还未完成)
node* Create(node* phead) {
    node* pnew, * pend,*ppre;
    FILE* fp;
    if ((fp = fopen("hosts.txt", "r")) == NULL) {
        printf("file doesn't exist");
        getchar();
        exit(1);
    }

    phead = NULL;
    do {
		n++;
		pnew = (node*)malloc(sizeof(node));
		
		
        if (phead == NULL){
            phead = pnew;
			pend = phead;
		}
        else {
			ppre = pend;
            pend->next = pnew;//如果链表不为空，则把创建的新结点放在表尾结点之后
            pend = pnew;//再把创建的新结点作为表尾
        }
    } while (fscanf(fp,"%s %s %s %s %d %s %s %d %d %d %s %s %s %s %d %s %s %s %s %d %s %s %s %s %d %s %s %s %s %d",
		pnew->hosts.m_name,pnew->hosts.m_phone,pnew->hosts.passport,pnew->hosts.P_addr,&pnew->hosts.carType,pnew->hosts.carBandhz,pnew->hosts.carBandstr,
		&pnew->hosts.Ins_Car[0],&pnew->hosts.Ins_Car[1],&pnew->hosts.Ins_Car[2],pnew->hosts.InsAddr,pnew->hosts.InsBandhz_car,pnew->hosts.InsBandstr_car,pnew->hosts.Insphonenum_car,
		&pnew->hosts.Ins_Health,pnew->hosts.InsPname_health,pnew->hosts.InsBandhz_health,pnew->hosts.InsBandstr_health,pnew->hosts.Insphonenum_health,
		&pnew->hosts.Ins_Acci,pnew->hosts.InsPname_acci,pnew->hosts.InsBandhz_acci,pnew->hosts.InsBandstr_acci,pnew->hosts.Insphonenum_acci,
		&pnew->hosts.Ins_Travel,pnew->hosts.InsPname_travel,pnew->hosts.InsBandhz_travel,pnew->hosts.InsBandstr_travel,pnew->hosts.Insphonenum_travel,&pnew->hosts.BillsPrice)!=EOF);
    ppre->next = NULL;
    free(pend);
	pend = NULL;
	fclose(fp);
    return phead;
}

//根据电话查找相应的人的函数
node* find_node(node* phead , char* phonenum)//这是一个查找指针，输入一个链表头和输入的电话，查找整个是不是存在
{
    node* pcur;
	for (pcur = phead ; pcur->next !=NULL; pcur = pcur->next ) {
        if (strcmp(phonenum, pcur->hosts.m_phone) == 0)
			
            return pcur;//存在，返回当前的结点的地址
	}
	if(pcur->next == NULL){
		if(strcmp(phonenum,pcur->hosts.m_phone) == 0)
			return pcur;
	}
	else {
		return NULL;//不存在就
		//返回空指针
	}
}

//判断密码正确性


void add_back(node* phead,node* _curNode) {
    //首先要找到链表的尾部；
    node* pend,*ppre;
	pend = phead;
	ppre = pend;
    while (pend != NULL) {
		ppre = pend;
        pend = pend->next;
    }
    ppre->next = _curNode;
    _curNode->next = NULL;
}
//2022、2、23、20：06
node* del_node(node* phead,char* phonenum)//用来直接更正phead
{
	node* pcur, * pdel,*pnext;
	if(phead ==NULL||phonenum == NULL){
		return NULL;
	}
    
    if (strcmp(phead->hosts.m_phone, phonenum) == 0) {
        pdel = phead;
        phead = phead->next;//这是防止第一个就是要登陆的对象，直接进行操作

        return phead;
    }
   //这样可以防止最后一个遍历不到
	pcur = phead;
	pnext  = pcur->next;
    while(pcur != NULL){
        if (strcmp(pnext->hosts.m_phone,phonenum) == 0) {
            pdel = pnext;
            pcur->next = pdel->next;
            return phead;
        }
		pcur = pnext;
		pnext = pnext->next;
    }
}

void clear_LinkNode(node* phead){//正常
	node* pcur = phead;
	node* pNext = NULL;
	if(phead ==NULL){
		return;
	}
	
	while(pcur->next!=NULL){
		pNext = pcur->next;
		free(pcur);
		pcur = pNext;
	}
	free(pcur);
}

void writeAll(node* phead){
	FILE* fp;
	node* pcur;
    if ((fp = fopen("hosts.txt", "w")) == NULL) {
        printf("file doesn't exist");
        getchar();
        exit(1);
    }
	pcur = phead;
	while(pcur!=NULL){
	fprintf(fp,"%s %s %s %s %d %s %s ",pcur->hosts.m_name,pcur->hosts.m_phone,pcur->hosts.passport,pcur->hosts.P_addr,pcur->hosts.carType,pcur->hosts.carBandhz,pcur->hosts.carBandstr);
	fprintf(fp,"%d %d %d %s %s %s %s " ,pcur->hosts.Ins_Car[0],pcur->hosts.Ins_Car[1],pcur->hosts.Ins_Car[2],pcur->hosts.InsAddr,pcur->hosts.InsBandhz_car,pcur->hosts.InsBandstr_car,pcur->hosts.Insphonenum_car);
	fprintf(fp,"%d %s %s %s %s ",pcur->hosts.Ins_Health,pcur->hosts.InsPname_health,pcur->hosts.InsBandhz_health,pcur->hosts.InsBandstr_health,pcur->hosts.Insphonenum_health);
	fprintf(fp,"%d %s %s %s %s ",pcur->hosts.Ins_Acci,pcur->hosts.InsPname_acci,pcur->hosts.InsBandhz_acci,pcur->hosts.InsBandstr_acci,pcur->hosts.Insphonenum_acci);
	fprintf(fp,"%d %s %s %s %s %d\n",pcur->hosts.Ins_Travel,pcur->hosts.InsPname_travel,pcur->hosts.InsBandhz_travel,pcur->hosts.InsBandstr_travel,pcur->hosts.Insphonenum_travel,pcur->hosts.BillsPrice);
	pcur = pcur->next;
	}
	fclose(fp);
}
//让它mod3 然后取出3n+1的地址
node* modList(node * ptop){
	int times = 3;
	node * pcur = ptop;
	while(times--){
		pcur = pcur->next;
	}
	return pcur;
}
void printList(node* ptop,int times){
	node* pcur;
	int y = 190;
	pcur = ptop;
	
	while(times--){
		puthz(80,y,pcur->hosts.m_name,24,25,DARKGRAY);
		setcolor(DARKGRAY);
		outtextxy(220,y,pcur->hosts.m_phone);
		puthz(430,y,pcur->hosts.carBandhz,24,1,DARKGRAY);
		outtextxy(465,y,pcur->hosts.carBandstr);
		pcur = pcur->next;
		y += 60;
	}
	
}
void clearBlank(){
	setfillstyle(1,WHITE);
	bar(60,180,580,220);
	bar(60,240,580,280);
	bar(60,300,580,340);
}

