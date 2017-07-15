#include "led.h"
#include "delay.h"
#include "sys.h"
#include "pwm.h"

#define FGDD 10
#define CBDD 100

#define XS     10   
#define MBFDY  10		
#define MBFDE  MBFDY*2
#define FGFD 	 58          

 
#define MBSD    15
#define FGSD    12 
#define JBHWSD  50
 
float ServoPos[6] = {1500,1500,1500,1500,1498,1500};  
//////////////////////2    0    3    1    4    5
float HomePos [6] = {1500,1500,1500,1500,1498,1500};
//////////////////////2    0    3    1    4    5
float PerAngle[6] = {1500,1500,1500,1500,1498,1500};

void step1(void)						
{
		unsigned char i;
		for(i = XS;i>0;i--)						
		{	
				ServoPos[2] = ServoPos[2] + 2*PerAngle[2]/90.0;
				TIM4_OC3(ServoPos[2]);	
			
				ServoPos[5] = ServoPos[5] + 1*PerAngle[5]/90.0;				
				TIM5_OC4(ServoPos[5]);
				delay_ms(JBHWSD);				
		}
		for(i = XS;i>0;i--)						
		{	
				ServoPos[2] = ServoPos[2] - 1*PerAngle[2]/90.0;
				TIM4_OC3(ServoPos[2]);				
				delay_ms(JBHWSD);
		}
		for(i = MBFDY;i>0;i--)						
		{	
				ServoPos[0] = ServoPos[0] - 1*PerAngle[0]/90.0;
				TIM4_OC4(ServoPos[0]);
				ServoPos[1] = ServoPos[1] - 1*PerAngle[1]/90.0;
				TIM5_OC2(ServoPos[1]);
				ServoPos[3] = ServoPos[3] - 1*PerAngle[3]/90.0;
				TIM5_OC1(ServoPos[3]);
				ServoPos[4] = ServoPos[4] - 1*PerAngle[4]/90.0;
				TIM5_OC3(ServoPos[4]);
				delay_ms(MBSD);
		}
		for(i = XS;i>0;i--)						
		{	
				ServoPos[2] = ServoPos[2] - 1*PerAngle[2]/90.0;
				TIM4_OC3(ServoPos[2]);
				ServoPos[5] = ServoPos[5] - 1*PerAngle[5]/90.0;	
				TIM5_OC4(ServoPos[5]);
				delay_ms(JBHWSD);
		}

		
}
void step2(void)						
{
		unsigned char i;

		for(i = XS;i>0;i--)						
		{	
				ServoPos[2] = ServoPos[2] - 1*PerAngle[2]/90.0;
				TIM4_OC3(ServoPos[2]);	
				ServoPos[5] = ServoPos[5] - 2*PerAngle[5]/90.0;				
				TIM5_OC4(ServoPos[5]);
				delay_ms(JBHWSD);

		}
		for(i = XS;i>0;i--)						
		{	
				ServoPos[5] = ServoPos[5] + 1*PerAngle[5]/90.0;	
				TIM5_OC4(ServoPos[5]);			
				delay_ms(JBHWSD);
		}
		for(i = MBFDE;i>0;i--)						
		{
				ServoPos[0] = ServoPos[0] + 1*PerAngle[0]/90.0;
				TIM4_OC4(ServoPos[0]);
				ServoPos[1] = ServoPos[1] + 1*PerAngle[1]/90.0;
				TIM5_OC2(ServoPos[1]);
				ServoPos[3] = ServoPos[3] + 1*PerAngle[3]/90.0;
				TIM5_OC1(ServoPos[3]);
				ServoPos[4] = ServoPos[4] + 1*PerAngle[4]/90.0;
				TIM5_OC3(ServoPos[4]);
				delay_ms(MBSD);
		}
		for(i = XS;i>0;i--)						
		{
				ServoPos[5] = ServoPos[5] + 1*PerAngle[5]/90.0;
				TIM5_OC4(ServoPos[5]);			
				ServoPos[2] = ServoPos[2] + 1*PerAngle[2]/90.0;	
				TIM4_OC3(ServoPos[2]);				
				delay_ms(JBHWSD);
		}
}



void step3(void)						
{
		unsigned char i;
		for(i =XS;i>0;i--)						
		{	
				ServoPos[2] = ServoPos[2] + 2*PerAngle[2]/90.0;
				TIM4_OC3(ServoPos[2]);	
				ServoPos[5] = ServoPos[5] + 1*PerAngle[5]/90.0;
				TIM5_OC4(ServoPos[5]);			
				delay_ms(JBHWSD);
		}
		for(i =XS;i>0;i--)						
		{	
				ServoPos[2] = ServoPos[2] - 1*PerAngle[2]/90.0;
				TIM4_OC3(ServoPos[2]);				
				delay_ms(JBHWSD);
		}
		for(i = MBFDE;i>0;i--)						
		{
				ServoPos[0] = ServoPos[0] - 1*PerAngle[0]/90.0;
				TIM4_OC4(ServoPos[0]);
				ServoPos[1] = ServoPos[1] - 1*PerAngle[1]/90.0;
				TIM5_OC2(ServoPos[1]);
				ServoPos[3] = ServoPos[3] - 1*PerAngle[3]/90.0;
				TIM5_OC1(ServoPos[3]);
				ServoPos[4] = ServoPos[4] - 1*PerAngle[4]/90.0;
				TIM5_OC3(ServoPos[4]);
				delay_ms(MBSD);
		}
		for(i = XS;i>0;i--)						
		{	
				ServoPos[2] = ServoPos[2] - 1*PerAngle[2]/90.0;
				TIM4_OC3(ServoPos[2]);	
				ServoPos[5] = ServoPos[5] - 1*PerAngle[5]/90.0;
				TIM5_OC4(ServoPos[5]);			
				delay_ms(JBHWSD);
		}
}


void step4(void)						
{	
		unsigned char i;
		for(i = XS;i>0;i--)						
		{
				ServoPos[2] = ServoPos[2] - 1*PerAngle[2]/90.0;
				TIM4_OC3(ServoPos[2]);	
				ServoPos[5] = ServoPos[5] - 2*PerAngle[5]/90.0;	
				TIM5_OC4(ServoPos[5]);		
				delay_ms(JBHWSD);
		}
		for(i=XS;i>0;i--)						
		{
				ServoPos[5] = ServoPos[5] + 1*PerAngle[5]/90.0;
				TIM5_OC4(ServoPos[5]);				
				delay_ms(JBHWSD);
		}
		for(i=MBFDY;i>0;i--)						
		{		
				ServoPos[0] = ServoPos[0] + 1*PerAngle[0]/90.0;
				TIM4_OC4(ServoPos[0]);
				ServoPos[1] = ServoPos[1] + 1*PerAngle[1]/90.0;
				TIM5_OC2(ServoPos[1]);
				ServoPos[3] = ServoPos[3] + 1*PerAngle[3]/90.0;
				TIM5_OC1(ServoPos[3]);
				ServoPos[4] = ServoPos[4] + 1*PerAngle[4]/90.0;
				TIM5_OC3(ServoPos[4]);
				delay_ms(MBSD);
		}
		for(i = XS;i>0;i--)						
		{	
				ServoPos[5] = ServoPos[5] + 1*PerAngle[5]/90.0;
				TIM5_OC4(ServoPos[5]);
				ServoPos[2] = ServoPos[2] + 1*PerAngle[2]/90.0;
				TIM4_OC3(ServoPos[2]);			
				delay_ms(JBHWSD);
		}
}


void step5(void)	//翻滚
{	 
		unsigned char i;
		for(i=FGFD;i>0;i--)						
		{		
				ServoPos[3] = ServoPos[3] + 1*PerAngle[3]/90.0;	
				TIM5_OC1(ServoPos[3]);
				ServoPos[0] = ServoPos[0] - 1*PerAngle[0]/90.0;
				TIM4_OC4(ServoPos[0]);		
				delay_ms(FGSD);
		}
		for(i=FGFD;i>0;i--)						
		{		
				ServoPos[1] = ServoPos[1] + 1*PerAngle[1]/90.0;	
				TIM5_OC2(ServoPos[1]);
				ServoPos[4] = ServoPos[4] - 1*PerAngle[4]/90.0;	
				TIM5_OC3(ServoPos[4]);		
				delay_ms(FGSD);
		}
}


void step6(void)						
{
		unsigned char i;
		for(i=FGFD;i>0;i--)					
		{		
				ServoPos[0] = ServoPos[0] + 1*PerAngle[0]/90.0;
				TIM4_OC4(ServoPos[0]);
				delay_ms(FGSD);
		}
		delay_ms(50);
		for(i=FGFD;i>0;i--)
		{		
				ServoPos[1] = ServoPos[1] - 2*PerAngle[1]/90.0;	
				TIM5_OC2(ServoPos[1]);
				delay_ms(FGSD);	
		}
		for(i=FGFD;i>0;i--)				
		{		
				ServoPos[0] = ServoPos[0] + 1*PerAngle[0]/90.0;
				TIM4_OC4(ServoPos[0]);		
				delay_ms(FGSD);
		}
		delay_ms(50);
		for(i=FGFD;i>0;i--)					
		{		
				ServoPos[3] = ServoPos[3] - 1*PerAngle[3]/90.0;	
				TIM5_OC1(ServoPos[3]);		
				delay_ms(FGSD);
		}
		delay_ms(50);
		for(i=FGFD;i>0;i--)					
		{		
				ServoPos[4] = ServoPos[4] + 2*PerAngle[4]/90.0;	
				TIM5_OC3(ServoPos[4]);
				delay_ms(FGSD);
		}
		for(i=FGFD;i>0;i--)						
		{		
				ServoPos[3] = ServoPos[3] - 1*PerAngle[3]/90.0;
				TIM5_OC1(ServoPos[3]);		
				delay_ms(FGSD);
		}
}


void step7(void)						
{
		unsigned char i;
		for(i=FGFD;i>0;i--)							
		{		
				ServoPos[1] = ServoPos[1] + 1*PerAngle[1]/90.0;	
				TIM5_OC2(ServoPos[1]);		
				ServoPos[4] = ServoPos[4] - 1*PerAngle[4]/90.0;	
				TIM5_OC3(ServoPos[4]);		
				delay_ms(FGSD);
		}
		delay_ms(50);
		for(i=FGFD;i>0;i--)							
		{		
				ServoPos[0] = ServoPos[0] - 1*PerAngle[0]/90.0;	
				TIM4_OC4(ServoPos[0]);		
				ServoPos[3] = ServoPos[3] + 1*PerAngle[3]/90.0;
				TIM5_OC1(ServoPos[3]);		
				delay_ms(FGSD);
		}
}


void step8(void)						
{    
		unsigned char i;
		for(i=FGFD;i>0;i--)						
		{		
				ServoPos[3] = ServoPos[3] - 1*PerAngle[3]/90.0;	
				TIM5_OC1(ServoPos[3]);
				ServoPos[0] = ServoPos[0] + 1*PerAngle[0]/90.0;	
				TIM4_OC4(ServoPos[0]);		
				delay_ms(FGSD);
		}
		for(i=FGFD;i>0;i--)						
		{		
				ServoPos[1] = ServoPos[1] - 1*PerAngle[1]/90.0;	
				TIM5_OC2(ServoPos[1]);
				ServoPos[4] = ServoPos[4] + 1*PerAngle[4]/90.0;
				TIM5_OC3(ServoPos[4]);		
				delay_ms(FGSD);
		}
}


void step9(void)						
{
		unsigned char i;
		for(i=FGFD;i>0;i--)					
		{		
				ServoPos[3] = ServoPos[3] + 1*PerAngle[3]/90.0;
				TIM5_OC1(ServoPos[3]);		
				delay_ms(FGSD);
		}
		delay_ms(50);
		for(i=FGFD;i>0;i--)					
		{		
				ServoPos[4] = ServoPos[4] - 2*PerAngle[4]/90.0;	
				TIM5_OC3(ServoPos[4]);
				delay_ms(FGSD);
		}
		for(i=FGFD;i>0;i--)				
		{		
				ServoPos[3] = ServoPos[3] + 1*PerAngle[4]/90.0;
				TIM5_OC1(ServoPos[3]);	
				delay_ms(FGSD);
		}
		delay_ms(50);
		for(i=FGFD;i>0;i--)					
		{		
				ServoPos[0] = ServoPos[0] - 1*PerAngle[0]/90.0;	
				TIM4_OC4(ServoPos[0]);		
				delay_ms(FGSD);
		}
		delay_ms(50);
		for(i=FGFD;i>0;i--)					
		{		
				ServoPos[1] = ServoPos[1] + 2*PerAngle[1]/90.0;	
				TIM5_OC2(ServoPos[1]);
				delay_ms(FGSD);
		}
		for(i=FGFD;i>0;i--)						
		{		
				ServoPos[0] = ServoPos[0] - 1*PerAngle[0]/90.0;
				TIM4_OC4(ServoPos[0]);			
				delay_ms(FGSD);
		}
}


void step10(void)						
{	
		unsigned char i;
		for(i=FGFD;i>0;i--)							
		{		
				ServoPos[1] = ServoPos[1] - 1*PerAngle[1]/90.0;	
				TIM5_OC2(ServoPos[1]);		
				ServoPos[4] = ServoPos[4] + 1*PerAngle[4]/90.0;	
				TIM5_OC3(ServoPos[4]);		
				delay_ms(FGSD);
		}
		delay_ms(50);
		for(i=FGFD;i>0;i--)							
		{		
				ServoPos[0] = ServoPos[0] + 1*PerAngle[0]/90.0;
				TIM4_OC4(ServoPos[0]);		
				ServoPos[3] = ServoPos[3] - 1*PerAngle[3]/90.0;	
				TIM5_OC1(ServoPos[3]);			
				delay_ms(FGSD);
		}
}


void step11(void)						
{
		unsigned char i;
		for(i=XS;i>0;i--)						
		{	
				ServoPos[2] = ServoPos[2] - 1*PerAngle[2]/90.0;
				TIM4_OC3(ServoPos[2]);	
				ServoPos[5] = ServoPos[5] - 2*PerAngle[5]/90.0;				
				delay_ms(JBHWSD);
		}
		for(i =XS;i>0;i--)						
		{
				ServoPos[5] = ServoPos[5] + 1*PerAngle[5]/90.0;
				TIM5_OC4(ServoPos[5]);
				delay_ms(JBHWSD);
		} 
		for(i = MBFDE;i>0;i--)						
		{
				ServoPos[0] = ServoPos[0] + 1*PerAngle[0]/90.0;
				TIM4_OC4(ServoPos[0]);
				ServoPos[1] = ServoPos[1] + 1*PerAngle[1]/90.0;
				TIM5_OC2(ServoPos[1]);
				ServoPos[3] = ServoPos[3] + 1*PerAngle[3]/90.0;
				TIM5_OC1(ServoPos[3]);	
				ServoPos[4] = ServoPos[4] + 1*PerAngle[4]/90.0;	
				TIM5_OC3(ServoPos[4]);		
				delay_ms(MBSD);
		}
		for(i = XS;i>0;i--)						
		{	
				ServoPos[2] = ServoPos[2] + 1*PerAngle[2]/90.0;
				TIM4_OC3(ServoPos[2]);	
				ServoPos[5] = ServoPos[5] + 1*PerAngle[5]/90.0;
				TIM5_OC4(ServoPos[5]);
				delay_ms(JBHWSD);
		}
}


void homeP(void)
{
				ServoPos[0] = HomePos[0];
				TIM4_OC4(ServoPos[0]);		
								  	delay_ms(FGDD);
				ServoPos[1] = HomePos[1];
				TIM5_OC2(ServoPos[1]);
										delay_ms(FGDD);
				ServoPos[2] = HomePos[2];
				TIM4_OC3(ServoPos[2]);
									  delay_ms(FGDD);	
				ServoPos[3] = HomePos[3];
				TIM5_OC1(ServoPos[3]);	
										delay_ms(FGDD);
				ServoPos[4] = HomePos[4];
				TIM5_OC3(ServoPos[4]);
										delay_ms(FGDD);
				ServoPos[5] = HomePos[5];	
				TIM5_OC4(ServoPos[5]);
										delay_ms(FGDD);
}


int main(void)
{	
	unsigned int i;
	
	delay_init();	    	 //延时函数初始化	  
	Port_Init();	
	TIM4_PWM_Init(20000,71);//不分频。  72M/(71+1)=1Mhz  1us
	TIM5_PWM_Init(20000,71);
	
//					delay_ms(20000);
					homeP();	
					delay_ms(2000);
	
					step1();			
					delay_ms(CBDD);
					step2();			
					delay_ms(CBDD);
					step3();			
					delay_ms(CBDD);
					step4();			
					delay_ms(CBDD);
				
					homeP();
			
			for(i=0;i<3;i++)
			{   
					step5();			
					delay_ms(FGDD);
					step6();			
					delay_ms(FGDD);
					step7();			
					delay_ms(FGDD);
			}	
			
					homeP();		
			
			for(i=0;i<2;i++)
			{   
					step8();			
					delay_ms(FGDD);
					step9();			
					delay_ms(FGDD);
					step10();			
					delay_ms(FGDD);
			}	
			
					homeP();	
					
					step1();			
					delay_ms(CBDD);
					step2();			
					delay_ms(CBDD);
					step3();			
					delay_ms(CBDD);
			
			for(i=0;i<10;i++)
			{  			
					step2();			   
					delay_ms(CBDD); 
					step3();			
					delay_ms(CBDD);				
			}	
					step4();			
					delay_ms(CBDD);
			
			while(1)
			{			

			} 
}

