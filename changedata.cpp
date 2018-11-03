#include"main.h" 

void changedata(void){ 
FILE*fptr2;
 		if((fptr2=fopen("配置文件.dat","rb+"))==NULL)
 			printf("the file can not be opened.");
 		else{
 	 		printf("请根据对应序号选择您想要修改的参数(按0可保存并退出)\n");
 	 		printf(" '1'for[MaxCheck]  //安检口最大数\n '2'for[MinCheck] //安检口最小数\n \
'3'for[MaxCustSingleLine] //单队列最大等待乘客数\n '4'for[MaxLines] //缓冲区直队数量\n \
'5'for[MaxSeqLen] //每条安检队伍最大长度\n '6'for[EasySeqLen]//每条安检口队伍最小长度\n \
'7'for [MaxSec] //一次安检或休息最长时长\n '8'for [MaxCustCheck] //安检口最大人数\n \
'9'for[Maxrest] //每个安检口最多休息次数" );
		
			int change,data;
			for (;;)
			{
				scanf("%d",&change);
			
				if (change == 0) break;
				printf("Please input the new data:");
				scanf("%d",&data);
				fseek(fptr2,(change-1)*sizeof(int),SEEK_SET);
				fwrite(&data,sizeof(int),1,fptr2);
				rewind(fptr2);
			}			
			fclose(fptr2);
		}
}		
void readdata(void)
{
	FILE *cfPtr;
	 
	if((cfPtr=fopen("配置文件.dat","rb"))==NULL)
 		printf("File could not be opened\n");
 	else{
 		fread(&MaxCheck,sizeof(int),1,cfPtr);
 		fread(&MinCheck,sizeof(int),1,cfPtr);
	 	fread(&MaxCustSingleLine,sizeof(int),1,cfPtr);
	 	fread(&MaxLines,sizeof(int),1,cfPtr);
	 	fread(&MaxSeqLen,sizeof(int),1,cfPtr);
	 	fread(&EasySeqLen,sizeof(int),1,cfPtr);
	 	fread(&MaxSec,sizeof(int),1,cfPtr);
		fread(&MaxCustCheck,sizeof(int),1,cfPtr);
	 	fread(&MaxRest,sizeof(int),1,cfPtr);
	}
	fclose(cfPtr);
} 

