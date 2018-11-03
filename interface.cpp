#include<stdio.h>
#include<stdlib.h> 
#include<graphics.h>
#include<unistd.h>
#include<string.h>
#include"configure2.cpp" 
void interface1(void);
void interface2(void);
//写程序应该按思路来写 
void inter(void)
{
	int counter=0;
	PIMAGE inter;
	inter=newimage(W+100, H);
	getimage(inter,"34.jpg",W+100, H);
	putimage(0,0,W+100, H, inter, 0, 0,5906,3514);
//	delay(3000);
	getch();
	int motivate=0;
	PIMAGE images;
	PIMAGE images2;
	images= newimage(W+100, H);
	images2= newimage(W+100, H);
	for ( ; ; delay_fps(60))
{
	if((ok==2&&motivate<0)||(ok==2&&motivate==0)) interface1();
	if(ok==1) break;
	if(ok==3) break;
	cleardevice();  
	int x,y;
	
	setcolor(EGERGB(0xFF, 0x0, 0x0));
	getimage(images,"1.jpg",W+100, H);
	putimage(0,0,W+100, H, images, 0, 0,1500,900);
	setbkmode(TRANSPARENT); 
	setfont(-W/40, -H/40,"【墨黑】雨沫体-加粗改小");
	xyprintf(W/10, H/10, "第47小组飞机安检系统");
	setcolor(EGERGB(0x0, 0x0, 0x0));
	xyprintf(W/5*3+50, H/3*2+35, "更改配置参数");
	if(motivate>0)
	{
		counter+=30;
		xyprintf(W/5*3+180+counter, H/3*2+170, "运行安检系统");
		motivate-=30;
	}
	else
	xyprintf(W/5*3+180, H/3*2+170, "运行安检系统");
	mousepos(&x, &y);
	for(int j=0;j<50;j++) 
	if(mousemsg())
		{
			mouse_msg msg = getmouse();
			if(msg.is_up())
			{
				if(x<W/5*3+230&&x>W/5*3+40&&y>H/3*2+20&y<H/3*2+90)
				{
					cleardevice(); 
					peizhi();	
				}
				else if(x<W/5*3+360&&x>W/5*3+170&&y>H/3*2+155&y<H/3*2+225)
				{
					motivate+=W/5*2-100;
					ok=2;
				}	
				else ;
			}
		}	

	if(x<W/5*3+230&&x>W/5*3+40&&y>H/3*2+20&y<H/3*2+90)
		{
			int a[10]={W/5*3+40,H/3*2+20,W/5*3+230,H/3*2+20,W/5*3+230,H/3*2+90,W/5*3+40,H/3*2+90,W/5*3+40,H/3*2+20};
			drawpoly(5,a);		 
		}
	if(x<W/5*3+360&&x>W/5*3+170&&y>H/3*2+155&y<H/3*2+225)
		{
			int a[10]={W/5*3+170,H/3*2+155,W/5*3+360,H/3*2+155,W/5*3+360,H/3*2+225,W/5*3+170,H/3*2+225,W/5*3+170,H/3*2+155};
			drawpoly(5,a);		 
		}
	
	
} 
	return;
}
void interface1(void)
{
	int judge=0;
	int motivate=W/5*2-170;
	int x,y;
	for(;motivate>0;delay_fps(60))
	{
		cleardevice();
		PIMAGE images;
		images= newimage(W+100, H);
		setcolor(EGERGB(0xFF, 0x0, 0x0));
		getimage(images,"1.jpg",W+100, H);
		putimage(0,0,W+100, H, images, 0, 0,1500,900);
		setbkmode(TRANSPARENT); 
		setfont(-W/40, -H/40,"【墨黑】雨沫体-加粗改小");
		xyprintf(W/10, H/10, "第47小组飞机安检系统");
		setcolor(EGERGB(0x0, 0x0, 0x0));
		motivate-=20;
		xyprintf(W/5*3+50+motivate, H/3*2+35, "键盘鼠标输入");
		xyprintf(W/5*3+180+motivate, H/3*2+170, "文件输入");
	}
	for(;;delay_fps(60))
	{
		cleardevice();
		if(judge==1)	break;
		PIMAGE images;
		images= newimage(W+100, H);
		setcolor(EGERGB(0xFF, 0x0, 0x0));
		getimage(images,"1.jpg",W+100, H);
		putimage(0,0,W+100, H, images, 0, 0,1500,900);
		setbkmode(TRANSPARENT); 
		setfont(-W/40, -H/40,"【墨黑】雨沫体-加粗改小");
		xyprintf(W/10, H/10, "第47小组飞机安检系统");
		setcolor(EGERGB(0x0, 0x0, 0x0));
		xyprintf(W/5*3+50, H/3*2+35, "键盘鼠标输入");
		xyprintf(W/5*3+180, H/3*2+170, "文件输入");
		mousepos(&x, &y);
		for(int i=0;i<2;i++)
		if(x<W/5*3+230&&x>W/5*3+40&&y>H/3*2+20&y<H/3*2+90)
		{
			int a[10]={W/5*3+40,H/3*2+20,W/5*3+230,H/3*2+20,W/5*3+230,H/3*2+90,W/5*3+40,H/3*2+90,W/5*3+40,H/3*2+20};
			drawpoly(5,a);		 
		}
		if(x<W/5*3+360&&x>W/5*3+170&&y>H/3*2+155&y<H/3*2+225)
		{
			int a[10]={W/5*3+170,H/3*2+155,W/5*3+360,H/3*2+155,W/5*3+360,H/3*2+225,W/5*3+170,H/3*2+225,W/5*3+170,H/3*2+155};
			drawpoly(5,a);		 
		}
		for(int j=0;j<50;j++) 
		if(mousemsg())
		{
			mouse_msg msg = getmouse();
			if(msg.is_up())
			{
				if(x<W/5*3+230&&x>W/5*3+40&&y>H/3*2+20&y<H/3*2+90)
				{
					ok=3;
					judge=1;	
				}
				else if(x<W/5*3+360&&x>W/5*3+170&&y>H/3*2+155&y<H/3*2+225)
				{
					ok=1;
					judge=1;
				}	
				else ;
			}
		}	
	}
}
void interface2(void)
{
	for(;;delay_fps(60))
	{
	cleardevice(); 	
	PIMAGE image;
	image=newimage();
	getimage(image,"12.jpg",1200,1100);
	putimage(0,0,W+100, H, image, 0, 0,1150,800);
	setcolor(EGERGB(0x0, 0xFF, 0x0));
	setfont(-35, -20,"宋体");
	xyprintf(100, 50, "组长:肖敏");
	xyprintf(100, 250, "组员1：吴欣雅");
	xyprintf(100, 450,"组员2：张业勤");
	xyprintf(100, 750,"退出");
/*	int x,y; 
	mousepos(&x, &y);
	if(x<750&&x>400&&y>300+200*i&y<420+200*i)
		{
			int a[10]={400,300+200*i,750,300+200*i,750,420+200*i,400,420+200*i,400,300+200*i};
			drawpoly(5,a);
		}
*/	}
}
