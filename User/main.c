
// 基本定时器TIMx,x[6,7]定时应用
#include "bsp.h"



Led_t Led1;
Blink_t Blink1;

void bsp_init(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0); //配置优先级分组
	LED_GPIO_Config();	//led端口配置
	BASIC_TIM_Init();	//定时器6初始化为1ms中断
	Serial_Init();		//初始化串口1为9600波特率
//	OLED_Init();
}

/**
  * @brief  主函数
  * @param  无  
  * @retval 无
  */
int main(void)
{
//	char *str = "{blink:{blinkTime:100,ledColor:eLedColorGreen,ledState:eLedStateOn}}";

	char* pstr;
	bsp_init(); 
//	OLED_ShowString(1, 1, "TxPacket");
//	OLED_ShowNum(3, 1, strlen("TxPacket"),10);
	
	Blink1.blinkTime = 500;
	Blink1.ledColor = eLedColorRed;
	Blink1.ledState = eLedStateOn;
	 
	Led1.ledMode = eLedBlink;
	Led1.blink = Blink1;



	while(1)
	{
		if (Serial_RxFlag == 1)
		{
			pstr = Serial_RxPacket;
			while(*pstr++)
			{
				//	char *str = "{blink:{blinkTime:100,ledColor:eLedColorGreen,ledState:eLedStateOn}}";
				if(strlen(pstr) < strlen("eLedStateOn") + 2)
				{
					break;
				}
				if(strncmp(pstr,"blinkTime:",strlen("blinkTime:")) == 0)
				{
					pstr += strlen("blinkTime:");
					__set_BASEPRI(1);
					Blink1.blinkTime = 50; //最低50ms,猜测是定时器中断函数的问题
					__set_BASEPRI(0);
				}
				if(strncmp(pstr,"ledColor:",strlen("ledColor:")) == 0)
				{
					pstr += strlen("ledColor:");
					if(strncmp(pstr,"eLedColorRed",strlen("eLedColorRed")) == 0)
					{
						__set_BASEPRI(1);
						Blink1.ledColor = eLedColorRed;
						__set_BASEPRI(0);
					}
					else if(strncmp(pstr,"eLedColorGreen",strlen("eLedColorGreen")) == 0)
					{
						__set_BASEPRI(1);
						Blink1.ledColor = eLedColorGreen;
						__set_BASEPRI(0);
					}
					else if(strncmp(pstr,"eLedColorBlue",strlen("eLedColorBlue")) == 0)
					{
						__set_BASEPRI(1);
						Blink1.ledColor = eLedColorBlue;
						__set_BASEPRI(0);
					}
					else if(strncmp(pstr,"eLedColorYellow",strlen("eLedColorYellow")) == 0)
					{
						__set_BASEPRI(1);
						Blink1.ledColor = eLedColorYellow;
						__set_BASEPRI(0);
					}
					else if(strncmp(pstr,"eLedColorPurple",strlen("eLedColorPurple")) == 0)
					{
						__set_BASEPRI(1);
						Blink1.ledColor = eLedColorPurple;
						__set_BASEPRI(0);
					}
					else if(strncmp(pstr,"eLedColorWhite",strlen("eLedColorWhite")) == 0)
					{
						__set_BASEPRI(1);
						Blink1.ledColor = eLedColorWhite;
						__set_BASEPRI(0);
					}
				}
				if(strncmp(pstr,"ledState:",strlen("ledState:")) == 0)
				{
					pstr += strlen("ledState:");
					if(strncmp(pstr,"eLedStateOn",strlen("eLedStateOn")) == 0)
					{
						__set_BASEPRI(1);
						Blink1.ledState = eLedStateOn;
						__set_BASEPRI(0);
					}
					else if(strncmp(pstr,"eLedStateOff",strlen("eLedStateOff")) == 0)
					{
						__set_BASEPRI(1);
						Blink1.ledState = eLedStateOff;
						__set_BASEPRI(0);
					}
				}
				Led1.blink = Blink1;
			}
			Serial_RxFlag = 0;
		}
	}
}
/*********************************************END OF FILE**********************/

