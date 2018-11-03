#include"main.h" 

//#define max 20 //结构体变量初始化，必须是已知结构体数组个数 

struct Security_Check Securitycheck[10];
struct queue* Queue = NULL;
struct queue *priority = NULL;//比缓冲区先安检的人的队列 
struct entry Entry;
int bianhao=0;
int ListCustCount=0;
int Checknum=0;
int off=0;
int lines=0;
double time1=0;//程序运行时间 
FILE *fp,*fptr;
clock_t start;
clock_t finish;
 
void Myclock::set0()
{
	start = end = duration = time_prev = time_count = 0;
}

void    initialization()
 {
	 for(int i=0;i<MaxCheck;i++)
	{
	    Securitycheck[i].Off=0;
		Securitycheck[i].head=NULL;
		Securitycheck[i].mans_complete=0;
		Securitycheck[i].state=0;
		
		Securitycheck[i].myclock_work.set0();
		
		Securitycheck[i].myclock_rest.set0();
		
		Securitycheck[i].count=0;
		Securitycheck[i].mans_rest=0;
	} 
	Entry.type=3;
	for(int i=0;i<MinCheck;i++)
	{
		
		Securitycheck[i].Off=1;
		Securitycheck[i].state=1;
		Securitycheck[i].myclock_work.start=time1;
	}
  
}
