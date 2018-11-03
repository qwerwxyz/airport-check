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
	printf("\t\t\t\t\t\t\t\t\t\t\t\t正在进入super47小组的飞机安检程序.");
	for(int i=0;i<5;i++)
	{
		sleep(1);
		printf(".");
	}
	system("cls");	
printf("\n\n\n\n\n\n");
printf("\t\t\t\t\t\t\t\t\t\t\t~*************欢迎进入机场安检系统*************~\n");
printf("\n\n\n\n\n\n\n\n");
printf("\t\t\t\t\t\t\t\t\t\t\t~*************制作者:47小组*************~\n");
printf("\n\n\n\n\n\n\n\n");
printf("\t\t\t\t\t\t\t\t\t\t\t~*************按任意键进入主菜单*************~");
while(getchar()==0);
system("CLS");
return 0;
}
