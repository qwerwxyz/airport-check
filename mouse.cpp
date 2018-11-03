#include "main.h"

int oncheck(const int x, const int y) {
	int i;
  for(i=0;i<MaxCheck + 2;i++)
  {
  	int xx = MaxCheck + 2; 
  	if((0< x && x < W / 10) && (i * H / xx < y && y < (i + 1) * H / xx))
  	{

  		return i;
  	}
  }
  return -1;
};//判断鼠标在哪个安检口

/*bool enter_passenger(const int x,const int y){
    return (CLOSE_BUTTON_LEFT < x && x < CLOSE_BUTTON_LEFT + CLOSE_BUTTON_WIDTH) && (CLOSE_BUTTON_TOP < y && y < CLOSE_BUTTON_TOP + CLOSE_BUTTON_HEIGHT);
};//判断乘客进入

bool OFF(const int x,const int y){
    return (CLOSE_BUTTON_LEFT < x && x < CLOSE_BUTTON_LEFT + CLOSE_BUTTON_WIDTH) && (CLOSE_BUTTON_TOP < y && y < CLOSE_BUTTON_TOP + CLOSE_BUTTON_HEIGHT);
};//判断是否下班 */

void getinput()
{
	mousepos(&mx, &my);
	key = oncheck(mx, my);
	if (mousemsg())
	{
		mouse_msg msg = getmouse();
		if (msg.is_up()) 
		{
			if (key < MaxCheck) Security_break(key);
			else if (key == MaxCheck)
			{
				if (!off) spand_queue(1);
				else refpsg = 100;
			}
			else off = 1;
		}	  //点击下班 
	}
	/*
;//用于获取一个鼠标消息。如果当前鼠标消息队列中没有，就一直等待。
	if (msg.is_left() && msg.is_up() && OFF(msg.x, msg.y)) 
	{
		off = 1;
	}	  //点击下班 
    else if(msg.is_left() && msg.is_up() &&enter_passenger(msg.x, msg.y))
	{
		if(!off)
		spand_queue(1);
	}	//点击乘客到来 
	else if(msg.is_left() && msg.is_up()&&(key!=-1))
	{
		Security_break(key);
	}   //点击安检口休息或是恢复休息 */
	
}
