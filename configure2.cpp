#include"main.h"
#include<graphics.h>
#define d 45
void configure_output(void);
int revise(void);
void peizhi(void)
{
       configure_output();
	   PIMAGE img1,img2;
	   img2 = newimage();
	   getimage(img2,"confirm.png", W / 10, H / (MaxCheck + 2));
	   img1=newimage();
	   getimage(img1,"12.jpg") ;
	   for(;;delay_fps(60))
	   {	   
	    cleardevice();
	    putimage(0,0,W+100,H,img1,0,0,1150,800);
		putimage_transparent(NULL, img2,W/2, 3*H/4, BLACK,0,0,0,0); 
		if(!revise())
		break;
       }
}
void configure_output(void)
{
	setbkcolor(EGERGB(0xFC,0xFC,0xFC));
	setcolor(EGERGB(0x0, 0xFF, 0x0));
	xyprintf(W/3-300, H/3-10, "安检口最大数:"); 
	xyprintf(W/3-300, H/3-10+d, "安检口最小数:");
	xyprintf(W/3-300, H/3-10+d*2, "单队列最大等待乘客数:");
	xyprintf(W/3-300, H/3-10+d*3, "缓冲区直队数量:");
	xyprintf(W/3-300, H/3-10+d*4, "每条安检队伍最大长度:");
	xyprintf(W/3-300, H/3-10+d*5, "每条安检口队伍最小长度:");
	xyprintf(W/3-300, H/3-10+d*6, "一次安检或休息最长时长:");
	xyprintf(W/3-300, H/3-10+d*7, "安检口最大人数:");
	xyprintf(W/3-300, H/3-10+d*8, "每个安检口最多休息次数:");
	W=150+W;
	H=30+H;
	//setfillstyle(EGERGB(0x54,0x54,0x54));
	int pt1f[]={W/3,H/3,W/3+15,H/3-15,W/3+15,H/3+15,};
    int pt1r[]={W/3+95,H/3,W/3+80,H/3-15,W/3+80,H/3+15,};
	int pt2f[]={W/3,H/3+d,W/3+15,H/3+d-15,W/3+15,H/3+d+15,};
	int pt2r[]={W/3+95,H/3+d,W/3+80,H/3+d-15,W/3+80,H/3+d+15,};
	int pt3f[]={W/3,H/3+d*2,W/3+15,H/3+2*d-15,W/3+15,H/3+2*d+15,};
	int pt3r[]={W/3+95,H/3+d*2,W/3+80,H/3+2*d-15,W/3+80,H/3+2*d+15,};
	int pt4f[]={W/3,H/3+d*3,W/3+15,H/3+3*d-15,W/3+15,H/3+3*d+15,};
	int pt4r[]={W/3+95,H/3+d*3,W/3+80,H/3+3*d-15,W/3+80,H/3+3*d+15,};
	int pt5f[]={W/3,H/3+d*4,W/3+15,H/3+4*d-15,W/3+15,H/3+4*d+15,};	
	int pt5r[]={W/3+95,H/3+d*4,W/3+80,H/3+4*d-15,W/3+80,H/3+4*d+15,};
	int pt6f[]={W/3,H/3+d*5,W/3+15,H/3+5*d-15,W/3+15,H/3+5*d+15,};
	int pt6r[]={W/3+95,H/3+d*5,W/3+80,H/3+5*d-15,W/3+80,H/3+5*d+15,};
	int pt7f[]={W/3,H/3+d*6,W/3+15,H/3+6*d-15,W/3+15,H/3+6*d+15,};
	int pt7r[]={W/3+95,H/3+d*6,W/3+80,H/3+6*d-15,W/3+80,H/3+6*d+15,};
	int pt8f[]={W/3,H/3+d*7,W/3+15,H/3+7*d-15,W/3+15,H/3+7*d+15,};
	int pt8r[]={W/3+95,H/3+d*7,W/3+80,H/3+7*d-15,W/3+80,H/3+7*d+15,};
	int pt9f[]={W/3,H/3+d*8,W/3+15,H/3+8*d-15,W/3+15,H/3+8*d+15,};
	int pt9r[]={W/3+95,H/3+d*8,W/3+80,H/3+8*d-15,W/3+80,H/3+8*d+15,};	   
	fillpoly(3,pt1f);
	fillpoly(3,pt1r);
	fillpoly(3,pt2f);
	fillpoly(3,pt2r);
	fillpoly(3,pt3f);
	fillpoly(3,pt3r);
	fillpoly(3,pt4f);
	fillpoly(3,pt4r);
	fillpoly(3,pt5f);
	fillpoly(3,pt5r);
	fillpoly(3,pt6f);
	fillpoly(3,pt6r);
	fillpoly(3,pt7f);
	fillpoly(3,pt7r);
	fillpoly(3,pt8f);
	fillpoly(3,pt8r);
	fillpoly(3,pt9f);
	fillpoly(3,pt9r);
	
	xyprintf(W/3+25, H/3-10, "%d",MaxCheck); 
	xyprintf(W/3+25, H/3-10+d, "%d",MinCheck);
	xyprintf(W/3+25, H/3-10+d*2, "%d",MaxCustSingleLine);
	xyprintf(W/3+25, H/3-10+d*3, "%d",MaxLines);
	xyprintf(W/3+25, H/3-10+d*4, "%d",MaxSeqLen);
	xyprintf(W/3+25, H/3-10+d*5, "%d",EasySeqLen);
	xyprintf(W/3+25, H/3-10+d*6, "%d",MaxSec);
	xyprintf(W/3+25, H/3-10+d*7, "%d",MaxCustCheck);
	xyprintf(W/3+25, H/3-10+d*8, "%d",MaxRest);
	
	xyprintf(W/3+110, H/3-10, "[2,10)"); 
	xyprintf(W/3+110, H/3-10+d, "[1,2]");
	xyprintf(W/3+110, H/3-10+d*2, "[5,10]");
	xyprintf(W/3+110, H/3-10+d*8, "(0,3]");
	W=W-150;
	H=H-30;
}
int revise(void)
{
	configure_output();
	int i=1;
	FILE *fptr2;
	if((fptr2=fopen("配置文件.dat","rb+"))==NULL)
 			printf("the file can not be opened.");
 	else
	{
	mousepos(&mx, &my);
	for	 (int j=0;j<50;j++)
	{
	if (mousemsg())
	{
		W=150+W;
		H=30+H;
		mouse_msg msg = getmouse();
		if(msg.is_up())
		{
	    if((W/3< mx && mx < W/3+15) && (H/3-15< my && my <H/3+15))
	      {if(MaxCheck>=3&&MaxCheck<=10)MaxCheck--;}
	    else if((W/3+80< mx && mx < W/3+95) && (H/3-15< my && my <H/3+15))
	     {if(MaxCheck>=2&&MaxCheck<=9)MaxCheck++;}
        else if((W/3< mx && mx < W/3+15) && (H/3-15+d< my && my <H/3+15+d))
         {if(MinCheck==2)MinCheck--;}
        else if((W/3+80< mx && mx < W/3+95) && (H/3-15+d< my && my <H/3+15+d))
        {if(MinCheck==1)MinCheck++;}
        else if((W/3< mx && mx < W/3+15) && (H/3-15+2*d< my && my <H/3+15+2*d))
       {if(MaxCustSingleLine>=6&&MaxCustSingleLine<=10)MaxCustSingleLine--;}
        else if((W/3+80< mx && mx < W/3+95) && (H/3-15+2*d< my && my <H/3+15+2*d))
        {if(MaxCustSingleLine>=5&&MaxCustSingleLine<=9)MaxCustSingleLine++;}
        else if((W/3< mx && mx < W/3+15) && (H/3-15+3*d< my && my <H/3+15+3*d))
        MaxLines--;
        else if((W/3+80< mx && mx < W/3+95) && (H/3-15+3*d< my && my <H/3+15+3*d))
        MaxLines++;
        else if((W/3< mx && mx < W/3+15) && (H/3-15+4*d< my && my <H/3+15+4*d))
        MaxSeqLen--;
        else if((W/3+80< mx && mx < W/3+95) && (H/3-15+4*d< my && my <H/3+15+4*d))
        MaxSeqLen++;
        else if((W/3< mx && mx < W/3+15) && (H/3-15+5*d< my && my <H/3+15+5*d))
        EasySeqLen--;
        else if((W/3+80< mx && mx < W/3+95) && (H/3-15+5*d< my && my <H/3+15+5*d))
        EasySeqLen++;
        else if((W/3< mx && mx < W/3+15) && (H/3-15+6*d< my && my <H/3+15+6*d))
        MaxSec--;
        else if((W/3+80< mx && mx < W/3+95) && (H/3-15+6*d< my && my <H/3+15+6*d))
        MaxSec++;
        else if((W/3< mx && mx < W/3+15) && (H/3-15+7*d< my && my <H/3+15+7*d))
        MaxCustCheck--;
        else if((W/3+80< mx && mx < W/3+95) && (H/3-15+7*d< my && my <H/3+15+7*d))
        MaxCustCheck++;
        else if((W/3< mx && mx < W/3+15) && (H/3-15+8*d< my && my <H/3+15+8*d))
       {if(MaxRest>=2&&MaxRest<=3)MaxRest--;}
        else if((W/3+80< mx && mx < W/3+95) && (H/3-15+8*d< my && my <H/3+15+8*d))
        {if(MaxRest>=1&&MaxRest<=2)MaxRest++;}
        else if((W/2-20< mx && mx <W/2+20)&& (3*H/4< my && my <3*H/4+100))
         i=0;
        fseek(fptr2,0,SEEK_SET);
		fwrite(&MaxCheck,sizeof(int),1,fptr2);
		rewind(fptr2);
		
		fseek(fptr2,1*sizeof(int),SEEK_SET);
		fwrite(&MinCheck,sizeof(int),1,fptr2);
		rewind(fptr2);
	    
		fseek(fptr2,2*sizeof(int),SEEK_SET);
		fwrite(&MaxCustLine,sizeof(int),1,fptr2);
		rewind(fptr2);
		
		fseek(fptr2,3*sizeof(int),SEEK_SET);
		fwrite(&MaxLines,sizeof(int),1,fptr2);
		rewind(fptr2);
		
		fseek(fptr2,4*sizeof(int),SEEK_SET);
		fwrite(&MaxSeqLen,sizeof(int),1,fptr2);
		rewind(fptr2);
		
		fseek(fptr2,5*sizeof(int),SEEK_SET);
		fwrite(&EasySeqLen,sizeof(int),1,fptr2);
		rewind(fptr2);
		
		fseek(fptr2,6*sizeof(int),SEEK_SET);
		fwrite(&MaxSec,sizeof(int),1,fptr2);
		rewind(fptr2);
		
		fseek(fptr2,7*sizeof(int),SEEK_SET);
		fwrite(&MaxCustCheck,sizeof(int),1,fptr2);
		rewind(fptr2);
		
		fseek(fptr2,8*sizeof(int),SEEK_SET);
		fwrite(&MaxRest,sizeof(int),1,fptr2);
		rewind(fptr2);
		}
		W=W-150;
	 	H=H-30;
	}
	}fclose(fptr2);
  }
	 return i;
}
