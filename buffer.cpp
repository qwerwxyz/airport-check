#include<time.h> //δ�ж��Ƿ��ܽ��뻺����
#include"main.h" 


void deal_priority(int number)
{
	struct queue *s,*last,*current;
	s=Securitycheck[number].head;
	if(s == NULL) return;
	if (s->next == NULL) return;
	Securitycheck[number].mans_rest = 1;
	if(!priority)
	{
		priority=s->next;
	 } 
	 else
	 {
	 	current=priority;
		 while(current!=NULL)
	 	{
	 		last=current;
	 		current=current->next;
		 }
		 last->next=s->next; 
	 }
	s->next = NULL;
}

void Dynamic_opening_off()
{
	int n = 0;
	for (int i = 0; i < MaxCheck; i++) if (Securitycheck[i].Off) n++;
	if (ListCustCount > n * MaxSeqLen)
	{
		for (int i = 0; i < MaxCheck; i++)
			if (!Securitycheck[i].Off)
			{
				Security_Check &s = Securitycheck[i];
				s.Off = 1;
			    s.state = 1;
    			s.myclock_work.start = time1;
    			s.myclock_work.duration = 0.0;
				break;
			}
	}
	else if (n > 1 && ListCustCount < n * EasySeqLen)
		for (int i = 0; i < MaxCheck; i++)
			if (Securitycheck[i].Off&&Securitycheck[i].state)
			{
				Securitycheck[i].myclock_work.time_prev =  Securitycheck[i].myclock_work.time_count;
				Securitycheck[i].Off = 0;
				deal_priority(i);
				break; 
			}
}

void spand_queue(int n)//bianhaoΪǰһ�����һλ��ţ�struct queue lastΪ��������β�ĵ�ַ ,����ֵΪָ���β��ָ�룻 
{
	randomize();
	queue *cur = Queue, *last = NULL;
	while (cur)
	{
		last = cur;
		cur = cur->next;
	}
	while (n--)
	{
		if(ListCustCount == MaxCustSingleLine*MaxLines)
		{
			refpsg = 100;

			if (!lines) system("cls");
			fprintf(fptr,"�����������ܾ��˿�\n");
			lines++;
			break; 
		}
		cur = new queue;
		cur->pclock.rest_time = Poisson(30) / 10.0;
		cur->number = ++bianhao;
		cur->recite=0; 
		cur->image=imgbuf[cur->recite];
		if (last) last->next = cur; else Queue = cur;
		last = cur;
		ListCustCount++; 
	}
	last->next = NULL;
}
