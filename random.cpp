#include<math.h>
#include"main.h" 

int Poisson(double lambda)
{
	double x = (rand() % 1000) / 1000.0, p = exp(-lambda), s = 0;
	for (int k = 0; ; k++)
	{
		if (k) p *= lambda / k;
		s += p;
		if (x <= s) return k;
	}
}
int random(void)
{
	FILE *fptr1;
	int number = 0; 
	int type,mans,check;
	fptr1=fopen("随机生成标准输入文件.txt","w");
	srand((unsigned) time(NULL)); //用时间做种，每次产生随机数不一样
	for(int i=0;i<40;i++)
	{   
		fprintf(fptr1,"sec=");
		number += 1 + Poisson(10);
		fprintf(fptr1,"%d ",number);
		fprintf(fptr1,"type=");
		type = rand() % (2 + (i > 30));
		fprintf(fptr1,"%d ",type);
		fprintf(fptr1,"mans=");
		if(type==0)
	   	{
			mans = 1 + Poisson(50); 
			fprintf(fptr1,"%d ",mans);
			fprintf(fptr1,"check=0\n");
	    }
		else if(type==1||type==2)
	   {
			fprintf(fptr1,"0 check=");
			check = rand() % 10;//安检口数量 
			fprintf(fptr1,"%d\n",check);
	   }
	}
	fclose(fptr1);
	return 0;
}
