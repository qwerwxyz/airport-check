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
};//�ж�������ĸ������

/*bool enter_passenger(const int x,const int y){
    return (CLOSE_BUTTON_LEFT < x && x < CLOSE_BUTTON_LEFT + CLOSE_BUTTON_WIDTH) && (CLOSE_BUTTON_TOP < y && y < CLOSE_BUTTON_TOP + CLOSE_BUTTON_HEIGHT);
};//�жϳ˿ͽ���

bool OFF(const int x,const int y){
    return (CLOSE_BUTTON_LEFT < x && x < CLOSE_BUTTON_LEFT + CLOSE_BUTTON_WIDTH) && (CLOSE_BUTTON_TOP < y && y < CLOSE_BUTTON_TOP + CLOSE_BUTTON_HEIGHT);
};//�ж��Ƿ��°� */

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
		}	  //����°� 
	}
	/*
;//���ڻ�ȡһ�������Ϣ�������ǰ�����Ϣ������û�У���һֱ�ȴ���
	if (msg.is_left() && msg.is_up() && OFF(msg.x, msg.y)) 
	{
		off = 1;
	}	  //����°� 
    else if(msg.is_left() && msg.is_up() &&enter_passenger(msg.x, msg.y))
	{
		if(!off)
		spand_queue(1);
	}	//����˿͵��� 
	else if(msg.is_left() && msg.is_up()&&(key!=-1))
	{
		Security_break(key);
	}   //����������Ϣ���ǻָ���Ϣ */
	
}
