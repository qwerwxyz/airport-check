#include"main.h" 
void work_to_rest(int number, float t)
{
	Security_Check &s = Securitycheck[number];
	s.myclock_work.time_prev =  s.myclock_work.time_count;
	s.rest_time = t;
	s.state = 0;
    s.myclock_rest.start = time1;//记录休息开始的时间
	s.myclock_rest.duration = 0.0;
	s.count++;//休息次数加1
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
	if(!Securitycheck[n].state) return; //rest_to_work(n);//在休息状态，则工作
	//如果状态是在工作的话 
	else if(Securitycheck[n].count >= MaxRest)
	{
		refchk = 100;
		if (interf != 2)
		{
			if (!lines) system("cls");
			fprintf(fptr,"休息次数达到上限，不允许休息\n");
			lines++;
		}
	}
	else
	{
		work_to_rest(n, rand() % (MaxSec - 1) + 1);//首先处理即将休息的安检口的时间信息
		deal_priority(n);//处理安检口剩余乘客
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
			if (s.head->pclock.end <= time1)//如果头结点的人达到了安检结束时间 
			{
				Checknum++;//全局变量安检总人数增加 
				queue *t = s.head;
				if (!lines) system("cls");
				fprintf(fptr, "乘客%d在%d号安检口进行了安检\n",s.head->number,i);
				lines++;
				dyna[i] += W * 0.4 / MaxCustCheck;
				s.head = s.head->next;
				free(t);
				s.mans_rest--;
				s.mans_complete++;
				if (s.head)
				{
					s.head->pclock.start = time1;//设置下一个人的开始时间 
					s.head->pclock.end = time1 + s.head->pclock.rest_time;
				//设置好下一个人的结束时间
				}
			}
			else s.head->pclock.rest_time =s.head->pclock.end - time1;
		if(s.Off)		//安检口关闭 
		if(!s.state)//安检口休息 
		{
			Myclock &t = s.myclock_rest;
			if ((t.duration = time1 - t.start) >= s.rest_time) rest_to_work(i);//计算休息时间 
			t.time_count = t.time_prev + t.duration;//总休息时间 
		}
		else//安检口工作 
		{
		//更新安检口休息时间 
			Myclock &t = s.myclock_work;
			t.duration = time1 - t.start;
			t.time_count = t.time_prev + t.duration;//总工作时间 
			//更新安检口安检乘客的时间 

			//更新头结点剩余的时间
		}
	}
}
