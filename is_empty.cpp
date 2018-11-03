#include"main.h"
//判断是否安检口队列全为空  
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
