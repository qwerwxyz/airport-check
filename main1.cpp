#include"main.h" 
#include"link.h"
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)


int main()
{
	int interf=2,f;
	initialization();//初始化安检口队列，缓冲区队列头，全局变量
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
	getimage(imgbuf[4],"4.png", W / 2 / MaxCustLine, H * 0.8 / MaxLines);//缓冲区人物像素设定
	imgchk[0]= newimage(W, H);
	getimage(imgchk[0],"7.png", W * 0.4 / MaxCustCheck, H / (MaxCheck + 2));
	imgchk[1]= newimage(W, H);
	getimage(imgchk[1],"1.png",W * 0.4 / MaxCustCheck, H / (MaxCheck + 2));
	imgchk[2]= newimage(W, H);
	getimage(imgchk[2],"2.png", W * 0.4 / MaxCustCheck, H / (MaxCheck + 2));
	imgchk[3]= newimage(W, H);
	getimage(imgchk[3],"3.png", W * 0.4 / MaxCustCheck, H / (MaxCheck + 2));
	imgchk[4]= newimage(W, H);
	getimage(imgchk[4],"4.png", W * 0.4 / MaxCustCheck, H / (MaxCheck + 2));//缓冲区人物像素设定
	imgpri[0] = newimage(W, H);
	if(ok==1)		{
	freopen("随机生成标准输入文件.txt", "r", stdin);
	}
	time1 = 0;
	start = clock();
	for (;!off || !is_empty() || ListCustCount; )
	{
		delay_fps(30); 
		updatetime();
		assignment();//分配乘客到安检口(功能：安检口人数的判断，安检口队列的变动，缓冲区分配乘客到安检口 ） 
		Dynamic_opening_off();
	if(ok==1)
	{
	if(Entry.type == 3 || Entry.sec <= time1)
	{
		if (Entry.type == 2) off = 1;
		if (Entry.type == 0)
			if (!off) spand_queue(Entry.mans);//缓冲区管理 （功能：判断乘客能否进入缓冲区，缓冲区人数的计算，安检口动态开放，缓冲区链表建立） 
			else
			{
				if (!lines) system("cls");
				printf("已下班，拒绝乘客\n");
				fprintf(fptr, "已下班，拒绝乘客\n");  
				lines++;
			}
		if (Entry.type == 1) Security_break(Entry.check);//安检口休息（功能：） 
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
				printf("已下班，拒绝乘客\n");
				fprintf(fptr, "已下班，拒绝乘客\n");  
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
