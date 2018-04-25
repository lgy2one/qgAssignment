#include<reg51.H>
sbit P3_7 = P3^7;
unsigned char code table[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};    //定义数码表

void delay(unsigned int time){                                       //延时函数
		unsigned int j = 0;
		for(;time > 0 ;time--)
			for(j = 0;j<125;j++);
	
}

void main(void)
{ 
	int count = 0;
	P0 = table[count/10];                                       //初始化两个数码显示管
	P2 = table[count%10];
	while(1)
		{
		  if(P3_7 == 0)
			{ 
				delay(600);
				  if(P3_7 == 0)
					{
						count++;
						  if(count == 100)                                         //数到99时归零
								count = 0;
							
							P0 = table[count/10];                                  //P0为十位数，P2为个位数，一次递增，最高可数到99
							P2 = table[count%10];
							
					}		
			}	
		}		
								
}				