#include"main.h" 
void work_to_rest(int number, float t)
{
	Security_Check &s = Securitycheck[number];
	s.myclock_work.time_prev =  s.myclock_work.time_count;
	s.rest_time = t;
	s.state = 0;
    s.myclock_rest.start = time1;//��¼��Ϣ��ʼ��ʱ��
	s.myclock_rest.duration = 0.0;
	s.count++;//��Ϣ������1
}

void rest_to_work(int number)
{
	Security_Check &s = Securitycheck[number];
	s.myclock_rest.time_prev =  s.myclock_rest.time_count;
	s.state = 1;
    s.myclock_work.start = time1;
    s.myclock_work.duration = 0.0;
}

void Security_break(int n)
{
	if (n < 0 || n >= MaxCheck) return;
	if (Securitycheck[n].Off == 0) return;
	if(!Securitycheck[n].state) return; //rest_to_work(n);//����Ϣ״̬������
	//���״̬���ڹ����Ļ� 
	else if(Securitycheck[n].count >= MaxRest)
	{
		refchk = 100;
		if (interf != 2)
		{
			if (!lines) system("cls");
			fprintf(fptr,"��Ϣ�����ﵽ���ޣ���������Ϣ\n");
			lines++;
		}
	}
	else
	{
		work_to_rest(n, rand() % (MaxSec - 1) + 1);//���ȴ�������Ϣ�İ���ڵ�ʱ����Ϣ
		deal_priority(n);//�������ʣ��˿�
	}

}

void updatetime(void)
{
	time1 = 1.0 * (clock() - start) / CLOCKS_PER_SEC;
	int i;
	for(i = 0; i < MaxCheck; i++)
	{
		Security_Check &s = Securitycheck[i];
		if (s.head)
			if (s.head->pclock.end <= time1)//���ͷ�����˴ﵽ�˰������ʱ�� 
			{
				Checknum++;//ȫ�ֱ����������������� 
				queue *t = s.head;
				if (!lines) system("cls");
				fprintf(fptr, "�˿�%d��%d�Ű���ڽ����˰���\n",s.head->number,i);
				lines++;
				dyna[i] += W * 0.4 / MaxCustCheck;
				s.head = s.head->next;
				free(t);
				s.mans_rest--;
				s.mans_complete++;
				if (s.head)
				{
					s.head->pclock.start = time1;//������һ���˵Ŀ�ʼʱ�� 
					s.head->pclock.end = time1 + s.head->pclock.rest_time;
				//���ú���һ���˵Ľ���ʱ��
				}
			}
			else s.head->pclock.rest_time =s.head->pclock.end - time1;
		if(s.Off)		//����ڹر� 
		if(!s.state)//�������Ϣ 
		{
			Myclock &t = s.myclock_rest;
			if ((t.duration = time1 - t.start) >= s.rest_time) rest_to_work(i);//������Ϣʱ�� 
			t.time_count = t.time_prev + t.duration;//����Ϣʱ�� 
		}
		else//����ڹ��� 
		{
		//���°������Ϣʱ�� 
			Myclock &t = s.myclock_work;
			t.duration = time1 - t.start;
			t.time_count = t.time_prev + t.duration;//�ܹ���ʱ�� 
			//���°���ڰ���˿͵�ʱ�� 

			//����ͷ���ʣ���ʱ��
		}
	}
}
