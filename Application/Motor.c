/**
  ******************************************************************************
  * @file    Motor.c 
  * @author  ChenY
  * @version V1.0.0
  * @date    2021/1/18
  * @brief  copy(Hongxi Wong) 
  ******************************************************************************
  * @attention 
  *
  ******************************************************************************
  */
#include "Motor.h"

void Motor_PWM_Control(Motor_t*motor , float V)
{
	if( V > 0) //正转
	{
		TIM_Set_PWM(motor->MotorTIM, motor->OUT1_3 , 0);
        TIM_Set_PWM(motor->MotorTIM, motor->OUT2_4 , motor->MinPWMValue + V * motor->VelocityGain);
	}
	else //反转
	{
		TIM_Set_PWM(motor->MotorTIM, motor->OUT2_4 , 0);
        TIM_Set_PWM(motor->MotorTIM, motor->OUT1_3 , motor->MinPWMValue - V * motor->VelocityGain);
	}
}
void TIM_Set_PWM(TIM_HandleTypeDef*htim , uint8_t Channel , uint16_t value )
{
	switch(Channel)
	{
		case TIM_CHANNEL_1 :
			htim->Instance->CCR1 = value ;
			break;
		case TIM_CHANNEL_2 :
			htim->Instance->CCR2 = value ;
			break;			
		case TIM_CHANNEL_3 :
			htim->Instance->CCR3 = value ;
			break;	
		case TIM_CHANNEL_4 :
			htim->Instance->CCR4 = value ;
			break;	
	}
}
