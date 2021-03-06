#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include <string.h>
#define PI 3.1415927

struct player
{
char name[20];
int WINs,LOSEs,DRAWs,scores;
};
struct player S[1000],temp;
FILE* fp;
     
     
int menu();
void practice_pattern();
void fight_pattern();
void EXIT();

void main()
{    
     int choice=0,mm=3,nn=2;
	 printf("请耐心等候！\n");
	 printf("请耐心等候！\n");
	 printf("请耐心等候！\n");
     while(1)
     {
        choice=menu();
        if(choice==0) continue;
        switch(choice)
		{
		  case 1:practice_pattern();break;
		  case 2:fight_pattern();break;
		  case 3:EXIT();break;
		  default:printf("请重新选择菜单\n");break;
		}
	 }
}

int menu()
{
    int i;
    printf("请选择游戏模式\n");
    printf("1—练习模式\n 2—对战模式\n 3—退出游戏\n");
    scanf("%d",&i);
    return i;
}


 void practice_pattern()
{
	int DRAW=0,WIN=0,LOSE=0;
	int i=1;
	int M,N,n,m=1000,ii=0,jj=0,k=1;
	struct player S[1000],temp;
	FILE* fp;
	fp=fopen("score.txt","rb+");
	if(fp==NULL)
	{
		fp=fopen("score.txt","wb+");
	}
	for(ii=0;ii<=m;ii++)	
	{
	    fread(&S[ii],sizeof(struct player),1,fp);
	    if((S[ii].WINs+S[ii].LOSEs+S[ii].DRAWs)==0) 
        {
			n=ii;
			break;
		}
    }
    fclose(fp);
    printf("请甲玩家输入姓名：只能由数字、字母、下划线组成)\n");
    scanf("%s",&temp.name); 
    for(ii=0;ii<=(n-1);ii++)	
    {
	    if(strcmp(temp.name,S[ii].name)==0) 
		{printf("已存在您的账号\n\n");M=ii;N=(n-1);k=0;temp=S[M];break;}
    }
    if(k)
    {
    	printf("您是第%d个新玩家\n\n",n+1);
    	temp.WINs=0;temp.LOSEs=0;temp.DRAWs=0;temp.scores=temp.WINs*2+temp.DRAWs*1;
    	M=n;N=n;
		S[M]=temp; 
    }
    while(i)
    {
	int x,y,win=0,lose=0,draw=0,games_num=1,ii=1;
	double judsment;
	srand((int)time(0));
	printf("规则：每轮比赛三局二胜；若五局之内不分胜负，则认为本轮平局\n赢得2分；平局得1分；输得0分\n请选择手势：<0-剪刀 1-石头 2-布>\n");
	while((win<2)&&(lose<2)&&(games_num<=5))
	{
	   int z=1;
	   printf("本轮第%d局\n",(games_num)); 
	   while(z)
	   {
	   z=0;
	   printf("请输入：");
	   scanf("%d",&x);
	   if (x==0) printf("我：剪刀\n");
	   else if (x==1) printf("我：石头\n");
	   else if (x==2) printf("我：布\n");
 	   else z=1;
 	   if (z==1) printf("重新输入：<0-剪刀 1-石头 2-布>\n");
	   }
	   
	   y=rand()%3;
	   if (y==0) printf("电脑：剪刀\n");
	   else if (y==1) printf("电脑：石头\n");
	   else printf("电脑：布\n"); 
	   judsment=2*PI*x/3-2*PI*y/3;
	   judsment=sin(judsment);
       if(judsment>0) 
       {
	      printf("本局你赢了\n");win++;
	   }
	   if(judsment<0)
	   {
	      printf("本局你输了\n");lose++;
	   }
	   if(judsment==0) 
	   {
		   printf("本局平局\n");draw++;
	   }
	   games_num++; 
	   printf("\n\n\n"); 
	}
	printf("本轮成绩：你胜%d局；电脑胜%d局；平局%d。\n",win,lose,draw); 
    if(win==2) {printf("本轮你赢了!\n");WIN++;}
	if(lose==2) {printf("本轮你输了!\n");LOSE++;}
    if((win<2)&&(lose<2)) {printf("本轮平局了!\n");DRAW++;}
    printf("是否继续新一轮练习游戏！< 1-是  0-否 >\n");  
	while (ii)
	{
	scanf("%d",&i);
	if (i==0||i==1) ii=0;
	else printf("请重新输入：< 1-是  0-否 >\n"); 
	} 
    printf("\n\n\n"); 
    }
    
	temp.WINs=temp.WINs+WIN;
	temp.LOSEs=temp.LOSEs+LOSE;
	temp.DRAWs=temp.DRAWs+DRAW;
	temp.scores=temp.WINs*2+temp.DRAWs*1;
	S[M]=temp;
	
	for(ii=0;ii<=N;ii++)	
	    {
		for(jj=0;jj<N-ii;jj++)
	       {
		   if(S[jj].scores<S[jj+1].scores)
	       {
	       	temp=S[jj];S[jj]=S[jj+1];S[jj+1]=temp;
	       }
	       }
	    }
    
    printf("得分排行榜！！！\n\n",S[ii].name,S[ii].WINs,S[ii].LOSEs,S[ii].DRAWs,S[ii].scores);
	fp=fopen("score.txt","rb+");
	for(ii=0;ii<=N;ii++)
        {
        fwrite(&S[ii],sizeof(struct player),1,fp);
        printf("姓名：%s\n赢：%d\t输：%d\t平局：%d\t得分：%d\n\n",S[ii].name,S[ii].WINs,S[ii].LOSEs,S[ii].DRAWs,S[ii].scores);
        }
    fclose(fp);
}



void fight_pattern()
{
    int DRAW=0,WIN=0,LOSE=0;
	int i=1;
	int M1,M2,N,n,m=1000,ii=0,jj=0,k1=1,k2=1,h=1;
	struct player S[1000],temp1,temp2;
	FILE* fp;
	fp=fopen("score.txt","rb+");
    if(fp==NULL)
	{
		fp=fopen("score.txt","wb+");
	}
	for(ii=0;ii<=m;ii++)	
	{
	    fread(&S[ii],sizeof(struct player),1,fp);
	    if((S[ii].WINs+S[ii].LOSEs+S[ii].DRAWs)==0) 
        {
			n=ii;
			break;
		}
    }
    fclose(fp);
    printf("请甲玩家输入姓名：只能由数字、字母、下划线组成)\n");
    scanf("%s",&temp1.name); 
    for(ii=0;ii<=(n-1);ii++)	
    {
	    if(strcmp(temp1.name,S[ii].name)==0) 
		{printf("已存在您的账号\n\n");M1=ii;N=(n-1);k1=0;temp1=S[M1];break;}
    }
    if(k1)
    {
    	printf("您是第%d个新玩家\n\n",n+1);
    	temp1.WINs=0;temp1.LOSEs=0;temp1.DRAWs=0;temp1.scores=temp1.WINs*2+temp1.DRAWs*1;
    	M1=n;N=n;
		S[M1]=temp1; 
    }
    printf("请乙玩家输入姓名：只能由数字、字母、下划线组成)\n");
	while(h)
	{
	    scanf("%s",&temp2.name); 
		if(strcmp(temp1.name,temp2.name)==0)  {printf("姓名不能与甲玩家重复\n");printf("请乙玩家重新输入姓名：\n");} 
		else {h=0;} 
		jj=0;
	}
	for(ii=0;ii<=N;ii++)	
    {
	    if(strcmp(S[ii].name,temp2.name)==0) 
		{printf("已存在您的账号\n\n");M2=ii;N=N;k2=0;temp2=S[M2];break;}
    }
    if(k2)
    {
    	printf("您是第%d个新玩家\n\n",N+2);
    	temp2.WINs=0;temp2.LOSEs=0;temp2.DRAWs=0;temp2.scores=temp2.WINs*2+temp2.DRAWs*1;
    	M2=N+1;N=N+1;
		S[M2]=temp2;
    }
    
    while(i)
    { 
	int x,y,draw=0,awin=0,alose=0,bwin=0,blose=0,games_num=1,ii=1;
	double judsment;
	srand((int)time(0));
	printf("规则：每轮比赛三局二胜；若五局之内不分胜负，则认为本轮平局\n赢得2分；平局得1分；输得0分\n 注意：双方手势均为随机产生！！！\n < 1- 甲玩家产生手势  2- 乙玩家产生手势>\n");
	while((awin<2)&&(alose<2)&&(games_num<=5))
	{
		int j,m=0,n=0,mn=0;
		printf("本轮第%d局\n",(games_num)); 
	    	while(mn==0)
	    {
	    	scanf("%d",&j);
	    	switch(j)
	    	{
	    		case 1:
	    		x=rand()%3;
                if (x==0) printf("甲：剪刀\n");
                else if (x==1) printf("甲：石头\n");
                else printf("甲：布\n");
                m++;break;
                case 2:
                y=rand()%3;
                if (y==0) printf("乙：剪刀\n");
                else if (y==1) printf("乙：石头\n");
                else printf("乙：布\n"); 
                n++;break;
                default:printf("请重新选择：< 1- 甲玩家产生手势  2- 乙玩家产生手势>\n");break;
	    	}
	    	mn=m*n;
	    }
	    judsment=2*PI*x/3-2*PI*y/3;
	    judsment=sin(judsment);
        if(judsment>0) 
       {
	      printf("本局甲赢了\n");awin++;blose++;
	   }
	   if(judsment<0)
	   {
	      printf("本局乙赢了\n");bwin++;alose++;
	   }
	   if(judsment==0) 
	   {
		   printf("本局平局\n");draw++;
	   }
	   games_num++; 
	   printf("\n\n\n"); 
	}
	printf("本轮成绩：甲胜%d局；乙胜%d局；平局%d。\n",awin,bwin,draw); 
    if(awin==2) {printf("本轮甲赢了!\n");WIN++;}
    if(bwin==2) {printf("本轮乙赢了!\n");LOSE++;}
    if((awin<2)&&(bwin<2)) {printf("本轮平局了!\n");DRAW++;}
    printf("是否继续新一轮对战游戏！< 1-是  0-否 >\n");
    
	while (ii)
	{
	scanf("%d",&i);
	if (i==0||i==1) ii=0;
	else printf("请重新输入：< 1-是  0-否 >\n"); 
	}
    printf("\n\n\n"); 
	}
	temp1.WINs=temp1.WINs+WIN;
	temp1.LOSEs=temp.LOSEs+LOSE;
	temp1.DRAWs=temp1.DRAWs+DRAW;
	temp1.scores=temp1.WINs*2+temp1.DRAWs*1;
	temp2.WINs=temp2.WINs+LOSE;
	temp2.LOSEs=temp2.LOSEs+WIN;
	temp2.DRAWs=temp2.DRAWs+DRAW;
	temp2.scores=temp2.WINs*2+temp2.DRAWs*1;
	S[M1]=temp1;
	S[M2]=temp2;
	for(ii=0;ii<=N;ii++)	
	    {
		for(jj=0;jj<N-ii;jj++)
	       {
		   if(S[jj].scores<S[jj+1].scores)
	       {
	       	temp=S[jj];S[jj]=S[jj+1];S[jj+1]=temp;
	       }
	       }
	    }
    printf("得分排行榜！！！(名次由高到低)\n\n",S[ii].name,S[ii].WINs,S[ii].LOSEs,S[ii].DRAWs,S[ii].scores);
	fp=fopen("score.txt","rb+");
	for(ii=0;ii<=N;ii++)
        {
        fwrite(&S[ii],sizeof(struct player),1,fp);
        printf("姓名：%s\n赢：%d\t输：%d\t平局：%d\t得分：%d\n\n",S[ii].name,S[ii].WINs,S[ii].LOSEs,S[ii].DRAWs,S[ii].scores);
        }
    fclose(fp);
}


void EXIT()
{
	int i=1,j=1;
	while(i)
	{
		printf("确定退出程序？\n");
		printf("<1-确定 0-返回>\n");
		while(j)
		{
			scanf("%d",&i); 
			if(i==0||i==1) j=0;
			else printf("请重新输入<1-确定 0-返回>\n"); 
		}
		if(i==1) {printf("已退出\n"); exit(0);break;} 
	}
	
}
		
	
