#include<stdio.h>
//#include<windows.h>
#include"main.h" 
#include<unistd.h>
int welcome(void)
{ 
	system("mode con cols=300 lines=200");
	 char buf[1000];
	FILE *file = fopen("test1.txt", "r"); 
	for(int i=0;i<30;i++){
		fgets(buf, 1000, file);
		printf("\t\t\t\t\t"); 
		printf("%s\n",buf);
		if(i%4==0)
		sleep(1);
	}
	fclose(file);
	printf("\n\n"); 
	printf("\t\t\t\t\t\t\t\t\t\t\t\t���ڽ���super47С��ķɻ��������.");
	for(int i=0;i<5;i++)
	{
		sleep(1);
		printf(".");
	}
	system("cls");	
printf("\n\n\n\n\n\n");
printf("\t\t\t\t\t\t\t\t\t\t\t~*************��ӭ�����������ϵͳ*************~\n");
printf("\n\n\n\n\n\n\n\n");
printf("\t\t\t\t\t\t\t\t\t\t\t~*************������:47С��*************~\n");
printf("\n\n\n\n\n\n\n\n");
printf("\t\t\t\t\t\t\t\t\t\t\t~*************��������������˵�*************~");
while(getchar()==0);
system("CLS");
return 0;
}
