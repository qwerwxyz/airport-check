#include"main.h" 

int findshortest()
{
	int min = 10000, i, j = -1, t;
	struct queue *current;
	//printf("find start");
	for(i = 0; i < MaxCheck; i++) 
		if(Securitycheck[i].Off && Securitycheck[i].state)//判断该窗口是否工作
			if(Securitycheck[i].mans_rest < MaxCustCheck)
			{
				t = 0;
				current = Securitycheck[i].head;
				while(current)
				{
					t += current->pclock.rest_time;
					current = current->next;
				}
				if(t < min)
				{
					min = t;
					j = i;//记录下当前最短时间的窗口 
				}
			}
	return j;
}

void assignment()
{
	srand((unsigned)time(NULL));
	int i,j,k,min=10000;
	struct queue *current, *last;
	while((priority || Queue) && (j = findshortest()) != -1)//找到合适的窗口j 
	{
		last = NULL;
    	current = Securitycheck[j].head;
		while(current)
	    {
			last = current;
			current = current->next;
		}
		if(priority!=NULL)//优先缓冲区有人时 
		{
			if (last) last->next =priority;
			else
		   	{
				Securitycheck[j].head = priority;
				priority->pclock.start = time1;//设置下一个人的开始时间 
				priority->pclock.end = time1 + priority->pclock.rest_time;
				//设置好下一个人的结束时间
	    	}
		//current的next取了第一个数据的地址 ，连接两个链表；
			if (!lines) system("cls");
			lines++; 
			fprintf(fptr, "乘客%d离开优先区\n",priority->number);
			priority->image=imgchk[priority->recite];
	    	current = priority->next; 
			priority->next = NULL;//尾节点设为空
			priority = current;//下一个人作为头节点
			Securitycheck[j].mans_rest++;
		}
		else if (Queue != NULL)//优先缓冲区没人时 
		{
	    	if (last) last->next = Queue; else
			{
				Securitycheck[j].head = Queue;
				Queue->pclock.start = time1;//设置下一个人的开始时间 
				Queue->pclock.end = time1 + Queue->pclock.rest_time;
					//设置好下一个人的结束时间
			}
		//current的next取了第一个数据的地址 ，连接两个链表

			if (!lines) system("cls");
			lines++;
			fprintf(fptr, "乘客%d离开缓冲区\n",Queue->number);
			dynaq += W / 2 / MaxCustLine;
	    	current = Queue->next; 
			Queue->next = NULL;//尾节点设为空
			Queue = current;//下一个人作为头节点
			Securitycheck[j].mans_rest++;
	    	ListCustCount--; 
       }
    }
}
