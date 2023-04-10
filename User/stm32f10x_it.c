/**
  ******************************************************************************
  * @file    Project/STM32F10x_StdPeriph_Template/stm32f10x_it.c 
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    08-April-2011
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTI
  
  AL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_it.h"
#include "bsp_TiMbase.h"
#include "bsp_led.h"


extern volatile uint32_t time;


/** @addtogroup STM32F10x_StdPeriph_Template
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M3 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
}

/******************************************************************************/
/*                 STM32F10x Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f10x_xx.s).                                            */
/******************************************************************************/

/**
  * @brief  This function handles TIM2 interrupt request.
  * @param  None
  * @retval None
  */
extern uint32_t time_ms;
extern Led_t Led1;
uint32_t lastTime_ms;
void  BASIC_TIM_IRQHandler(void)
{
	if ( TIM_GetITStatus( BASIC_TIM, TIM_IT_Update) != RESET ) 
	{	
		time_ms++;
		TIM_ClearITPendingBit(BASIC_TIM , TIM_FLAG_Update);  
		if(Led1.blink.ledState == eLedStateOn)
		{
			if((time_ms - lastTime_ms) >= Led1.blink.blinkTime)
			{
				lastTime_ms = time_ms;
				if(Led1.blink.ledColor == eLedColorRed)
				{
					if(Led1.blink.toggle == 0)
					{
						LED_RED;
						Led1.blink.toggle = 1;
					}else if(Led1.blink.toggle == 1)
					{
						LED_RGBOFF;
						Led1.blink.toggle = 0;
					}
				}
				else if(Led1.blink.ledColor == eLedColorGreen)
				{
					if(Led1.blink.toggle == 0)
					{
						LED_GREEN;
						Led1.blink.toggle = 1;
					}else if(Led1.blink.toggle == 1)
					{
						LED_RGBOFF;
						Led1.blink.toggle = 0;
					}
				}
				else if(Led1.blink.ledColor == eLedColorBlue)
				{
					if(Led1.blink.toggle == 0)
					{
						LED_BLUE;
						Led1.blink.toggle = 1;
					}else if(Led1.blink.toggle == 1)
					{
						LED_RGBOFF;
						Led1.blink.toggle = 0;
					}
				}
				else if(Led1.blink.ledColor == eLedColorBlue)
				{
					if(Led1.blink.toggle == 0)
					{
						LED_BLUE;
						Led1.blink.toggle = 1;
					}else if(Led1.blink.toggle == 1)
					{
						LED_RGBOFF;
						Led1.blink.toggle = 0;
					}
				}
				else if(Led1.blink.ledColor == eLedColorYellow)
				{
					if(Led1.blink.toggle == 0)
					{
						LED_YELLOW;
						Led1.blink.toggle = 1;
					}else if(Led1.blink.toggle == 1)
					{
						LED_RGBOFF;
						Led1.blink.toggle = 0;
					}
				}
				else if(Led1.blink.ledColor == eLedColorPurple)
				{
					if(Led1.blink.toggle == 0)
					{
						LED_PURPLE;
						Led1.blink.toggle = 1;
					}else if(Led1.blink.toggle == 1)
					{
						LED_RGBOFF;
						Led1.blink.toggle = 0;
					}
				}
				else if(Led1.blink.ledColor == eLedColorWhite)
				{
					if(Led1.blink.toggle == 0)
					{
						LED_WHITE;
						Led1.blink.toggle = 1;
					}else if(Led1.blink.toggle == 1)
					{
						LED_RGBOFF;
						Led1.blink.toggle = 0;
					}
				}
			}
		}		 
	}		 	
}

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

/**
  * @}
  */ 


/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
