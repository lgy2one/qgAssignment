#include<reg51.h>
sbit KEY = P1^7;                //���尴���ͷ�����������
sbit SOUNDER = P3^0;

  unsigned char musicNum;
  unsigned char code high_buff[] = {0,226,229,232,233,236,238,240};     //���ö�ʱ����ʱ��Դ
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
	 TH0 = (8192-700)/32;                  //��ʼ��ʱ����صļĴ���
	 TL0 = (8192 - 700)%32;
	EA = 1;
	ET0 = 1;
	
	SOUNDER = 0;
	
	while(1)
	 {
		  while(KEY == 1) ;                            //�ȴ����ذ��²�����
				while(KEY == 0);
			
			for(musicNum = 1;musicNum < 8;musicNum++)     //����������ֹͣ
			{
					TR0 = 1;                          //��ʱ������
					delayms(500);                    //ͣ��
					TR0 = 0;                        //��ʱ��ֹͣ����
					delayms(50);                       //ͣ��
			}
		}
	
	
}	
	
void Timer0(void) interrupt 1                //���ƶ�ʱ���Ĺ�����ʽ
{
	SOUNDER = ~SOUNDER;
	TH0 = high_buff[musicNum];
	TL0 = low_buff[musicNum];
}
	
	
	
	
	
	
	
	
	
	
	