#include"main.h" 

void changedata(void){ 
FILE*fptr2;
 		if((fptr2=fopen("�����ļ�.dat","rb+"))==NULL)
 			printf("the file can not be opened.");
 		else{
 	 		printf("����ݶ�Ӧ���ѡ������Ҫ�޸ĵĲ���(��0�ɱ��沢�˳�)\n");
 	 		printf(" '1'for[MaxCheck]  //����������\n '2'for[MinCheck] //�������С��\n \
'3'for[MaxCustSingleLine] //���������ȴ��˿���\n '4'for[MaxLines] //������ֱ������\n \
'5'for[MaxSeqLen] //ÿ�����������󳤶�\n '6'for[EasySeqLen]//ÿ������ڶ�����С����\n \
'7'for [MaxSec] //һ�ΰ������Ϣ�ʱ��\n '8'for [MaxCustCheck] //������������\n \
'9'for[Maxrest] //ÿ������������Ϣ����" );
		
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
	 
	if((cfPtr=fopen("�����ļ�.dat","rb"))==NULL)
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

