/**
  ******************************************************************************
  * @file    Chassis.h
  * @author  ChenY
  * @version V1.0.0
  * @date    2021/1/18
  * @brief   copy(Hongxi Wong) 
  ******************************************************************************
  * @attention 
  *
  ******************************************************************************
  */
#ifndef _CHASSIS_H
#define _CHASSIS_H

#define K 0.7071067811865475
#define r 0.185

#include "Motor.h"
typedef struct
{
	float Vx;
	float Vy;
	float Vw;
	
	float VxTransfer;
	float VyTransfer;
	
	Motor_t ChassisMotor[4];
	float V1,V2,V3,V4;

}Chassis_t;


extern Chassis_t Chassis;

void Chassis_Init(void);
void Chassis_Control(void);
#endif
