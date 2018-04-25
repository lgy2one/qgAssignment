#include<reg51.h>
sbit KEY = P1^7;                //定义按键和蜂鸣器的引脚
sbit SOUNDER = P3^0;

  unsigned char musicNum;
  unsigned char code high_buff[] = {0,226,229,232,233,236,238,240};     //设置定时器的时钟源
  unsigned char code low_buff[] = {0,4,13,10,20,3,8,6};
	
	void delayms(unsigned int x)
	{
			unsigned char i;
		  while(x--)
			    for(i = 0;i < 120;i++);

  }
	
	 void main()
{   
	 TMOD = 0x00;                         
	 TH0 = (8192-700)/32;                  //初始化时钟相关的寄存器
	 TL0 = (8192 - 700)%32;
	EA = 1;
	ET0 = 1;
	
	SOUNDER = 0;
	
	while(1)
	 {
		  while(KEY == 1) ;                            //等待开关按下并弹起
				while(KEY == 0);
			
			for(musicNum = 1;musicNum < 8;musicNum++)     //控制启动与停止
			{
					TR0 = 1;                          //定时器工作
					delayms(500);                    //停留
					TR0 = 0;                        //定时器停止工作
					delayms(50);                       //停留
			}
		}
	
	
}	
	
void Timer0(void) interrupt 1                //控制定时器的工作方式
{
	SOUNDER = ~SOUNDER;
	TH0 = high_buff[musicNum];
	TL0 = low_buff[musicNum];
}
	
	
	
	
	
	
	
	
	
	
	