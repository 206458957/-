/**
  ******************************************************************************
  * @file    Motor.c 
  * @author  ChenY
  * @version V1.0.0
  * @date    2021/1/18
  * @brief  
  ******************************************************************************
  * @attention 
  *
  ******************************************************************************
  */
#include "Motor.h"

void Motor_Speed_Control(Motor_t*motor , float V , float tar_speed)
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
	PID_Update(&motor->PID_Speed , V  , tar_speed);
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
