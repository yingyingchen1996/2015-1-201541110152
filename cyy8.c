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
	 printf("�����ĵȺ�\n");
	 printf("�����ĵȺ�\n");
	 printf("�����ĵȺ�\n");
     while(1)
     {
        choice=menu();
        if(choice==0) continue;
        switch(choice)
		{
		  case 1:practice_pattern();break;
		  case 2:fight_pattern();break;
		  case 3:EXIT();break;
		  default:printf("������ѡ��˵�\n");break;
		}
	 }
}

int menu()
{
    int i;
    printf("��ѡ����Ϸģʽ\n");
    printf("1����ϰģʽ\n 2����սģʽ\n 3���˳���Ϸ\n");
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
    printf("����������������ֻ�������֡���ĸ���»������)\n");
    scanf("%s",&temp.name); 
    for(ii=0;ii<=(n-1);ii++)	
    {
	    if(strcmp(temp.name,S[ii].name)==0) 
		{printf("�Ѵ��������˺�\n\n");M=ii;N=(n-1);k=0;temp=S[M];break;}
    }
    if(k)
    {
    	printf("���ǵ�%d�������\n\n",n+1);
    	temp.WINs=0;temp.LOSEs=0;temp.DRAWs=0;temp.scores=temp.WINs*2+temp.DRAWs*1;
    	M=n;N=n;
		S[M]=temp; 
    }
    while(i)
    {
	int x,y,win=0,lose=0,draw=0,games_num=1,ii=1;
	double judsment;
	srand((int)time(0));
	printf("����ÿ�ֱ������ֶ�ʤ�������֮�ڲ���ʤ��������Ϊ����ƽ��\nӮ��2�֣�ƽ�ֵ�1�֣����0��\n��ѡ�����ƣ�<0-���� 1-ʯͷ 2-��>\n");
	while((win<2)&&(lose<2)&&(games_num<=5))
	{
	   int z=1;
	   printf("���ֵ�%d��\n",(games_num)); 
	   while(z)
	   {
	   z=0;
	   printf("�����룺");
	   scanf("%d",&x);
	   if (x==0) printf("�ң�����\n");
	   else if (x==1) printf("�ң�ʯͷ\n");
	   else if (x==2) printf("�ң���\n");
 	   else z=1;
 	   if (z==1) printf("�������룺<0-���� 1-ʯͷ 2-��>\n");
	   }
	   
	   y=rand()%3;
	   if (y==0) printf("���ԣ�����\n");
	   else if (y==1) printf("���ԣ�ʯͷ\n");
	   else printf("���ԣ���\n"); 
	   judsment=2*PI*x/3-2*PI*y/3;
	   judsment=sin(judsment);
       if(judsment>0) 
       {
	      printf("������Ӯ��\n");win++;
	   }
	   if(judsment<0)
	   {
	      printf("����������\n");lose++;
	   }
	   if(judsment==0) 
	   {
		   printf("����ƽ��\n");draw++;
	   }
	   games_num++; 
	   printf("\n\n\n"); 
	}
	printf("���ֳɼ�����ʤ%d�֣�����ʤ%d�֣�ƽ��%d��\n",win,lose,draw); 
    if(win==2) {printf("������Ӯ��!\n");WIN++;}
	if(lose==2) {printf("����������!\n");LOSE++;}
    if((win<2)&&(lose<2)) {printf("����ƽ����!\n");DRAW++;}
    printf("�Ƿ������һ����ϰ��Ϸ��< 1-��  0-�� >\n");  
	while (ii)
	{
	scanf("%d",&i);
	if (i==0||i==1) ii=0;
	else printf("���������룺< 1-��  0-�� >\n"); 
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
    
    printf("�÷����а񣡣���\n\n",S[ii].name,S[ii].WINs,S[ii].LOSEs,S[ii].DRAWs,S[ii].scores);
	fp=fopen("score.txt","rb+");
	for(ii=0;ii<=N;ii++)
        {
        fwrite(&S[ii],sizeof(struct player),1,fp);
        printf("������%s\nӮ��%d\t�䣺%d\tƽ�֣�%d\t�÷֣�%d\n\n",S[ii].name,S[ii].WINs,S[ii].LOSEs,S[ii].DRAWs,S[ii].scores);
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
    printf("����������������ֻ�������֡���ĸ���»������)\n");
    scanf("%s",&temp1.name); 
    for(ii=0;ii<=(n-1);ii++)	
    {
	    if(strcmp(temp1.name,S[ii].name)==0) 
		{printf("�Ѵ��������˺�\n\n");M1=ii;N=(n-1);k1=0;temp1=S[M1];break;}
    }
    if(k1)
    {
    	printf("���ǵ�%d�������\n\n",n+1);
    	temp1.WINs=0;temp1.LOSEs=0;temp1.DRAWs=0;temp1.scores=temp1.WINs*2+temp1.DRAWs*1;
    	M1=n;N=n;
		S[M1]=temp1; 
    }
    printf("�����������������ֻ�������֡���ĸ���»������)\n");
	while(h)
	{
	    scanf("%s",&temp2.name); 
		if(strcmp(temp1.name,temp2.name)==0)  {printf("���������������ظ�\n");printf("���������������������\n");} 
		else {h=0;} 
		jj=0;
	}
	for(ii=0;ii<=N;ii++)	
    {
	    if(strcmp(S[ii].name,temp2.name)==0) 
		{printf("�Ѵ��������˺�\n\n");M2=ii;N=N;k2=0;temp2=S[M2];break;}
    }
    if(k2)
    {
    	printf("���ǵ�%d�������\n\n",N+2);
    	temp2.WINs=0;temp2.LOSEs=0;temp2.DRAWs=0;temp2.scores=temp2.WINs*2+temp2.DRAWs*1;
    	M2=N+1;N=N+1;
		S[M2]=temp2;
    }
    
    while(i)
    { 
	int x,y,draw=0,awin=0,alose=0,bwin=0,blose=0,games_num=1,ii=1;
	double judsment;
	srand((int)time(0));
	printf("����ÿ�ֱ������ֶ�ʤ�������֮�ڲ���ʤ��������Ϊ����ƽ��\nӮ��2�֣�ƽ�ֵ�1�֣����0��\n ע�⣺˫�����ƾ�Ϊ�������������\n < 1- ����Ҳ�������  2- ����Ҳ�������>\n");
	while((awin<2)&&(alose<2)&&(games_num<=5))
	{
		int j,m=0,n=0,mn=0;
		printf("���ֵ�%d��\n",(games_num)); 
	    	while(mn==0)
	    {
	    	scanf("%d",&j);
	    	switch(j)
	    	{
	    		case 1:
	    		x=rand()%3;
                if (x==0) printf("�ף�����\n");
                else if (x==1) printf("�ף�ʯͷ\n");
                else printf("�ף���\n");
                m++;break;
                case 2:
                y=rand()%3;
                if (y==0) printf("�ң�����\n");
                else if (y==1) printf("�ң�ʯͷ\n");
                else printf("�ң���\n"); 
                n++;break;
                default:printf("������ѡ��< 1- ����Ҳ�������  2- ����Ҳ�������>\n");break;
	    	}
	    	mn=m*n;
	    }
	    judsment=2*PI*x/3-2*PI*y/3;
	    judsment=sin(judsment);
        if(judsment>0) 
       {
	      printf("���ּ�Ӯ��\n");awin++;blose++;
	   }
	   if(judsment<0)
	   {
	      printf("������Ӯ��\n");bwin++;alose++;
	   }
	   if(judsment==0) 
	   {
		   printf("����ƽ��\n");draw++;
	   }
	   games_num++; 
	   printf("\n\n\n"); 
	}
	printf("���ֳɼ�����ʤ%d�֣���ʤ%d�֣�ƽ��%d��\n",awin,bwin,draw); 
    if(awin==2) {printf("���ּ�Ӯ��!\n");WIN++;}
    if(bwin==2) {printf("������Ӯ��!\n");LOSE++;}
    if((awin<2)&&(bwin<2)) {printf("����ƽ����!\n");DRAW++;}
    printf("�Ƿ������һ�ֶ�ս��Ϸ��< 1-��  0-�� >\n");
    
	while (ii)
	{
	scanf("%d",&i);
	if (i==0||i==1) ii=0;
	else printf("���������룺< 1-��  0-�� >\n"); 
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
    printf("�÷����а񣡣���(�����ɸߵ���)\n\n",S[ii].name,S[ii].WINs,S[ii].LOSEs,S[ii].DRAWs,S[ii].scores);
	fp=fopen("score.txt","rb+");
	for(ii=0;ii<=N;ii++)
        {
        fwrite(&S[ii],sizeof(struct player),1,fp);
        printf("������%s\nӮ��%d\t�䣺%d\tƽ�֣�%d\t�÷֣�%d\n\n",S[ii].name,S[ii].WINs,S[ii].LOSEs,S[ii].DRAWs,S[ii].scores);
        }
    fclose(fp);
}


void EXIT()
{
	int i=1,j=1;
	while(i)
	{
		printf("ȷ���˳�����\n");
		printf("<1-ȷ�� 0-����>\n");
		while(j)
		{
			scanf("%d",&i); 
			if(i==0||i==1) j=0;
			else printf("����������<1-ȷ�� 0-����>\n"); 
		}
		if(i==1) {printf("���˳�\n"); exit(0);break;} 
	}
	
}
		
	
