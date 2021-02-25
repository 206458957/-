/**
  ******************************************************************************
  * @file    Motor.h
  * @author  ChenY
  * @version V1.0.0
  * @date    2021/1/18
  * @brief   
  ******************************************************************************
  * @attention 
  *
  ******************************************************************************
  */
#ifndef MOTOR_H
#define MOTOR_H

#include "tim.h"
#include <stdint.h>
#include "controler.h"

typedef struct
{
	TIM_HandleTypeDef*MotorTIM; // 电机PWM定时器
	
	uint8_t OUT1_3 ;
	uint8_t OUT2_4 ;
	
	float VelocityGain;
	
	uint32_t MinPWMValue;
	int16_t V_rpm;
	
	PID_t PID_Speed;

}Motor_t;

void Motor_Speed_Control(Motor_t*motor , float V , float tar_speed);
void TIM_Set_PWM(TIM_HandleTypeDef*htim , uint8_t Channel , uint16_t value );
#endif
