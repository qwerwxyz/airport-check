#include"main.h"
//�ж��Ƿ񰲼�ڶ���ȫΪ��  
int is_empty()
{
//	Securitycheck[1].mans_rest=1;
	int ok=1;
	for(int i=0;i<MaxCheck;i++)
	{
		if(Securitycheck[i].mans_rest!=0)
			ok=0;
		
	}
	return ok;	
}
