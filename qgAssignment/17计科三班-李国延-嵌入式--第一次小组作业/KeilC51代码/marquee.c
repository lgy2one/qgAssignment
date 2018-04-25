#include <REGX52.H>

void delay(unsigned int t)                    //延时函数
{
	unsigned char n = 0;;
	
	for(;t > 0;t-- )
	   for(n = 0;n <125;n++);
	
}

void main()
{
		unsigned char i,j;
	  unsigned int led;
	  
  while(1)
		{
       delay(500);
			 
			 led = 0xfe;
			   for(i = 0;i < 8;i++)
			      {
							P1 = led;                               //先控制p1亮
							delay(500);
							led = led<<1;                             //控制从左往右依次亮
							   if(P1 == 0x00)
								 {
									  delay(500);
									  led = 0x7f;                         //反向再次依次亮
									  for(j = 0;j < 8;j++)
									  {
										  P1 = led;
										  led = led>>1;
										  delay(500);
									  }
									}
						 }
		}
}							
							
 

				
	


