#include<reg51.H>
sbit P3_7 = P3^7;
unsigned char code table[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};    //���������

void delay(unsigned int time){                                       //��ʱ����
		unsigned int j = 0;
		for(;time > 0 ;time--)
			for(j = 0;j<125;j++);
	
}

void main(void)
{ 
	int count = 0;
	P0 = table[count/10];                                       //��ʼ������������ʾ��
	P2 = table[count%10];
	while(1)
		{
		  if(P3_7 == 0)
			{ 
				delay(600);
				  if(P3_7 == 0)
					{
						count++;
						  if(count == 100)                                         //����99ʱ����
								count = 0;
							
							P0 = table[count/10];                                  //P0Ϊʮλ����P2Ϊ��λ����һ�ε�������߿�����99
							P2 = table[count%10];
							
					}		
			}	
		}		
								
}				