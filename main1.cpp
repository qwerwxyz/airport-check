#include"main.h" 
#include"link.h"
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)


int main()
{
	int interf=2,f;
	initialization();//��ʼ������ڶ��У�����������ͷ��ȫ�ֱ���
	random();
	fptr=fopen("output.txt","w");
	initgraph(W+100, H);
	inter(); 
	img = newimage(W, H);
	getimage(img,"8.png", W / 10, H / (MaxCheck + 2));
	imgbuf[0]= newimage(W, H);
	getimage(imgbuf[0],"7.png", W / 2 / MaxCustLine, H * 0.8 / MaxLines);
	imgbuf[1]= newimage(W, H);
	getimage(imgbuf[1],"1.png", W / 2 / MaxCustLine, H * 0.8 / MaxLines);
	imgbuf[2]= newimage(W, H);
	getimage(imgbuf[2],"2.png", W / 2 / MaxCustLine, H * 0.8 / MaxLines);
	imgbuf[3]= newimage(W, H);
	getimage(imgbuf[3],"3.png", W / 2 / MaxCustLine, H * 0.8 / MaxLines);
	imgbuf[4]= newimage(W, H);
	getimage(imgbuf[4],"4.png", W / 2 / MaxCustLine, H * 0.8 / MaxLines);//���������������趨
	imgchk[0]= newimage(W, H);
	getimage(imgchk[0],"7.png", W * 0.4 / MaxCustCheck, H / (MaxCheck + 2));
	imgchk[1]= newimage(W, H);
	getimage(imgchk[1],"1.png",W * 0.4 / MaxCustCheck, H / (MaxCheck + 2));
	imgchk[2]= newimage(W, H);
	getimage(imgchk[2],"2.png", W * 0.4 / MaxCustCheck, H / (MaxCheck + 2));
	imgchk[3]= newimage(W, H);
	getimage(imgchk[3],"3.png", W * 0.4 / MaxCustCheck, H / (MaxCheck + 2));
	imgchk[4]= newimage(W, H);
	getimage(imgchk[4],"4.png", W * 0.4 / MaxCustCheck, H / (MaxCheck + 2));//���������������趨
	imgpri[0] = newimage(W, H);
	if(ok==1)		{
	freopen("������ɱ�׼�����ļ�.txt", "r", stdin);
	}
	time1 = 0;
	start = clock();
	for (;!off || !is_empty() || ListCustCount; )
	{
		delay_fps(30); 
		updatetime();
		assignment();//����˿͵������(���ܣ�������������жϣ�����ڶ��еı䶯������������˿͵������ �� 
		Dynamic_opening_off();
	if(ok==1)
	{
	if(Entry.type == 3 || Entry.sec <= time1)
	{
		if (Entry.type == 2) off = 1;
		if (Entry.type == 0)
			if (!off) spand_queue(Entry.mans);//���������� �����ܣ��жϳ˿��ܷ���뻺�����������������ļ��㣬����ڶ�̬���ţ��������������� 
			else
			{
				if (!lines) system("cls");
				printf("���°࣬�ܾ��˿�\n");
				fprintf(fptr, "���°࣬�ܾ��˿�\n");  
				lines++;
			}
		if (Entry.type == 1) Security_break(Entry.check);//�������Ϣ�����ܣ��� 
		Entry.type = 2;
		scanf("sec=%d type=%d mans=%d check=%d\n", &Entry.sec, &Entry.type, &Entry.mans, &Entry.check);	
	}
	}
	if(ok==3)
	{
		f = 1;
		if (KEY_DOWN('Q'))
		{
			off = 1;
			f = 0;
		}
		if (KEY_DOWN('G'))
		{
			if (nokey)
			if(!off) spand_queue(1);
			else
			{
				if (!lines) system("cls");
				printf("���°࣬�ܾ��˿�\n");
				fprintf(fptr, "���°࣬�ܾ��˿�\n");  
				lines++;
			}
			f = 0;
		}
		for (int i = 0; i <= 9; i++)
			if (KEY_DOWN('0' + i))
			{
				if (nokey) Security_break(i);
				f = 0;
			}
		if (f) nokey = 1; else nokey = 0;
		for (int i = 1; i <= 10; i++) getinput();
		}
		anioutput();
		if(lines) 
		{
			fileoutput();
			cmdoutput();
		}
	}
	
}
