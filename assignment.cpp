#include"main.h" 

int findshortest()
{
	int min = 10000, i, j = -1, t;
	struct queue *current;
	//printf("find start");
	for(i = 0; i < MaxCheck; i++) 
		if(Securitycheck[i].Off && Securitycheck[i].state)//�жϸô����Ƿ���
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
					j = i;//��¼�µ�ǰ���ʱ��Ĵ��� 
				}
			}
	return j;
}

void assignment()
{
	srand((unsigned)time(NULL));
	int i,j,k,min=10000;
	struct queue *current, *last;
	while((priority || Queue) && (j = findshortest()) != -1)//�ҵ����ʵĴ���j 
	{
		last = NULL;
    	current = Securitycheck[j].head;
		while(current)
	    {
			last = current;
			current = current->next;
		}
		if(priority!=NULL)//���Ȼ���������ʱ 
		{
			if (last) last->next =priority;
			else
		   	{
				Securitycheck[j].head = priority;
				priority->pclock.start = time1;//������һ���˵Ŀ�ʼʱ�� 
				priority->pclock.end = time1 + priority->pclock.rest_time;
				//���ú���һ���˵Ľ���ʱ��
	    	}
		//current��nextȡ�˵�һ�����ݵĵ�ַ ��������������
			if (!lines) system("cls");
			lines++; 
			fprintf(fptr, "�˿�%d�뿪������\n",priority->number);
			priority->image=imgchk[priority->recite];
	    	current = priority->next; 
			priority->next = NULL;//β�ڵ���Ϊ��
			priority = current;//��һ������Ϊͷ�ڵ�
			Securitycheck[j].mans_rest++;
		}
		else if (Queue != NULL)//���Ȼ�����û��ʱ 
		{
	    	if (last) last->next = Queue; else
			{
				Securitycheck[j].head = Queue;
				Queue->pclock.start = time1;//������һ���˵Ŀ�ʼʱ�� 
				Queue->pclock.end = time1 + Queue->pclock.rest_time;
					//���ú���һ���˵Ľ���ʱ��
			}
		//current��nextȡ�˵�һ�����ݵĵ�ַ ��������������

			if (!lines) system("cls");
			lines++;
			fprintf(fptr, "�˿�%d�뿪������\n",Queue->number);
			dynaq += W / 2 / MaxCustLine;
	    	current = Queue->next; 
			Queue->next = NULL;//β�ڵ���Ϊ��
			Queue = current;//��һ������Ϊͷ�ڵ�
			Securitycheck[j].mans_rest++;
	    	ListCustCount--; 
       }
    }
}
