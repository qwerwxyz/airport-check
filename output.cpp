#include<stdio.h>
//#include<unistd.h>
#include<time.h>
#include<Windows.h>
#include<graphics.h> 
#include"main.h"

void anioutput(void)
{
	cleardevice();
	setbkcolor(EGERGB(0xFC,0xFC,0xFC)); 
	setbkmode(OPAQUE);
	setfont(0,0,"����");
	int i,j=0,k1;
	struct queue *current;

	for(i=0;i<MaxCheck;i++)
	{
		if (dyna[i] > 0) dyna[i] -= 10;
		int xx = MaxCheck + 2;
		putimage_transparent(NULL, img, W / 100, H * i / xx, BLACK,0,0,0,0); 
		if(Securitycheck[i].Off)//�������ڿ��ţ����ӡ���ڰ���ڵ���Ϣ 
		{ 
		    k1=0;
			if(!Securitycheck[i].state) xyprintf(W / 100, H * i / xx, "%d����Ϣ:",i); 
            else
            {
				xyprintf(W / 100, H * i / xx, "%d�Ź���:",i);
				xyprintf(W / 100+80, H * i / xx, "%d/%d:",Securitycheck[i].mans_rest,MaxCustCheck); 
				current=Securitycheck[i].head;
				while(current!=NULL)
				{
					putimage_transparent(NULL, current->image, W / 10 + dyna[i] + k1 * W * 0.4 / MaxCustCheck, H * i / xx, BLACK,0,0,0,0); 
					xyprintf(W / 10 + dyna[i] + k1 * W * 0.4 / MaxCustCheck, H * (i + 0.5) / xx, " %d��",current->number);
					current=current->next;
					k1++;
				
				}//��ӡ����ڶ����г˿͵ı��
		    }
		}
		else xyprintf(W / 100, H * i / xx, "%d�Źر�:",i); 
	}
	
	i = 0;
	j = 0;
	int ww = dynaq;
	int dir = 1; 
	if (dynaq > 0) dynaq -= 10;
	current = Queue;
	while(current!=NULL)
	{
		putimage_transparent(NULL, current->image,  W / 2 + (dir? ww:(W / 2 - ww)), j * H * 0.8 / MaxLines, BLACK,0,0,0,0); 
		xyprintf( W / 2 + (dir? ww: (W / 2 - ww)), (j + 0.5) * H * 0.8 / MaxLines, " %d��",current->number);
		ww += W / 2 / MaxCustSingleLine;
		if (ww>W/2)
		{
			ww -= W / 2;
			j++;
			dir = !dir;
		}
		current=current->next;
	}
	if(ListCustCount==MaxLines*MaxCustSingleLine)
	xyprintf(W / 2+150, H / 100, "����"); 
	
	xyprintf(W / 2, H / 100, "��ͨ������"); 
	int a[10]={W / 2, H / 100, (W+100) * 0.99, H / 100, (W+100)* 0.99, H * 0.8, W / 2, H * 0.8, W / 2, H / 100};
	drawpoly(5,a);
	for (int i = 1; i < MaxLines; i++)
	{
		int a[4]={W * 0.52, i * H * 0.8 / MaxLines,(W+100) * 0.98, i * H * 0.8 / MaxLines};
		drawlines(1,a);
	}
	current = priority;
	int cntpri = 0;
	while(current!=NULL)
	{	
		current=current->next;
		cntpri++;
	}
	if (cntpri) {
	getimage(imgpri[0],"7.png", W / 2 / cntpri, H * 0.2);
	imgpri[1] = newimage(W, H);
	getimage(imgpri[1],"1.png", W / 2 / cntpri, H * 0.2);
	imgpri[2] = newimage(W, H);
	getimage(imgpri[2],"2.png", W / 2 / cntpri, H * 0.2);
	imgpri[3] = newimage(W, H);
	getimage(imgpri[3],"3.png", W / 2 / cntpri, H * 0.2);
	imgpri[4] = newimage(W, H);	
	getimage(imgpri[4],"4.png", W / 2 / cntpri, H * 0.2);
	}
	current = priority;
	i=0;
	while(current!=NULL)
	{	
		putimage_transparent(NULL,imgpri[current->recite], W / 2 + i * W / 2 / cntpri, H * 0.8, BLACK,0,0,0,0); 
		xyprintf( W / 2 + i * W / 2 / cntpri, H * 0.9, " %d��",current->number);
		current=current->next;
		i++;
	}
	
	xyprintf(W / 2, H * 0.8, "���Ȼ�����"); 
	int b[10]={W / 2, H * 0.8, (W+100)* 0.99, H *0.8, (W+100) * 0.99, H * 0.99, W / 2, H * 0.99, W / 2, H * 0.8};
	drawpoly(5,b);

	if (key != -1)
	{
		i = key;
		int x = MaxCheck + 2; 
		int c[10]={0, i * H / x, W / 10, i * H / x, W / 10, (i + 1) * H / x,
		0, (i + 1) * H / x,0,  i * H / x};
		drawpoly(5,c);
	}
	xyprintf(W / 100, H * MaxCheck / (MaxCheck + 2), "�ӳ˿�",i);
	xyprintf(W / 100, H * (MaxCheck + 1) / (MaxCheck + 2), off? "���°�": "�°�",i);
	if (refpsg > 0)
	{
		refpsg--;
		xyprintf(W / 10, H * MaxCheck / (MaxCheck + 2), "�ܾ��˿�");
	}
	if (refchk > 0)
	{
		refchk--;
		xyprintf(W / 10, H * (MaxCheck + 1) / (MaxCheck + 2), "��Ϣ�����ﵽ���ޣ���������Ϣ");
	}
	xyprintf(W / 5, H * MaxCheck / (MaxCheck + 2), "ʱ�䣺%.1lf", time1);
	xyprintf(W / 5+150, H * MaxCheck / (MaxCheck + 2), "������������%d", ListCustCount);
	
}


void cmdoutput(void)
{
	int i,j=0;
	struct queue *current;
	for(i=0;i<MaxCheck;i++)
	if(Securitycheck[i].Off)//�������ڿ��ţ����ӡ���ڰ���ڵ���Ϣ 
		{
			if(!Securitycheck[i].state)
            printf( "�����%d: ��Ϣ\n",i);
            else
            {
			printf("�����%d",i);
			printf("  �˿ͣ�");
			current=Securitycheck[i].head;
			while(current!=NULL)
			{
				printf( "%d ",current->number);
				current=current->next;
			}//��ӡ����ڶ����г˿͵ı��
			printf("\n");
			printf("\t�����ʣ��������%d\n",Securitycheck[i].mans_rest);
		    }
		    printf("\t���������%d\n",Securitycheck[i].mans_complete);
			printf("\t����Ϣ������%d\n",Securitycheck[i].count);
			printf("\t�ܹ���ʱ�䣺%2lf\n",Securitycheck[i].myclock_work.time_count);
			printf("\t����Ϣʱ�䣺%2lf\n",Securitycheck[i].myclock_rest.time_count); 
		}
		else
		 {
		  j++;
		  printf("�����%d: �رգ�\n",i);	
		 }
	lines = 0;
	
}

void fileoutput(void)
{
	int i,j=0;
	struct queue *current;
	fprintf(fptr, "ʱ�䣺%.2lf\n",time1);  
	for(i=0;i<MaxCheck;i++)
		if(Securitycheck[i].Off)//�������ڿ��ţ����ӡ���ڰ���ڵ���Ϣ 
		{
			if(!Securitycheck[i].state)
            fprintf(fptr, "�����%d: ��Ϣ\n",i);
            else
            {
			fprintf(fptr, "�����%d",i);
			fprintf(fptr, "  �˿ͣ�");
			current=Securitycheck[i].head;
			while(current!=NULL)
			{
				fprintf(fptr, "%d ",current->number);
				current=current->next;
			}//��ӡ����ڶ����г˿͵ı��
			fprintf(fptr, "\n");
			fprintf(fptr, "\t�����ʣ��������%d\n",Securitycheck[i].mans_rest);
		    }
		    fprintf(fptr, "\t���������%d\n",Securitycheck[i].mans_complete);
			fprintf(fptr, "\t����Ϣ������%d\n",Securitycheck[i].count);
			fprintf(fptr, "\t�ܹ���ʱ�䣺%2lf\n",Securitycheck[i].myclock_work.time_count);
			fprintf(fptr, "\t����Ϣʱ�䣺%2lf\n",Securitycheck[i].myclock_rest.time_count); 
		}
		else
		 {
		  j++;
		  fprintf(fptr, "�����%d: �رգ�\n",i);	
		 }
	fprintf(fptr, "�����Ŷӻ�������\n");
	current = priority;
	i=1;
	while(current!=NULL)
	{
		if(i%10!=0)fprintf(fptr, "%-4d->",current->number);
		else
		fprintf(fptr, "%-4d\n",current->number);
		current=current->next;
		i++;
	}
	fprintf(fptr, "\n"); 
	fprintf(fptr, "�������˿���������%d\n",ListCustCount);
	fprintf(fptr, "�Ŷӻ������˿ͱ�ţ�\n");
	current = Queue;
	i=1;
	while(current!=NULL)
	{
		if(i%10!=0&&i!=ListCustCount)fprintf(fptr, "%-4d->",current->number);
		else
		fprintf(fptr, "%-4d\n",current->number);
		current=current->next;
		i++;
	}
	//for(int k=1;k<=10-ListCustCount/10;k++)
	//printf("\n");
	if (off) fprintf(fptr, "��ǰ״̬���°�\n");
	else fprintf(fptr, "��ǰ״̬�����°�\n");
	fprintf(fptr, "�Ѱ�����������%d",Checknum);
}
