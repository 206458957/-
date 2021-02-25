/**
  ******************************************************************************
  * @file    Chassis.c
  * @author  ChenY
  * @version V1.0.0
  * @date    2021/1/18
  * @brief   
  ******************************************************************************
  * @attention 
  *
  ******************************************************************************
  */
#include "Chassis.h"
#include "Motor.h"
#include "ps2.h"
#include "controler.h"

Chassis_t Chassis;

void Chassis_Init(void)
{
	Chassis.ChassisMotor[0].MotorTIM = &htim3;
    Chassis.ChassisMotor[0].OUT1_3  = TIM_CHANNEL_1;
    Chassis.ChassisMotor[0].OUT2_4  = TIM_CHANNEL_2;
    Chassis.ChassisMotor[0].VelocityGain = 8;
    Chassis.ChassisMotor[0].MinPWMValue = 200;
	
	Chassis.ChassisMotor[1].MotorTIM = &htim3;
    Chassis.ChassisMotor[1].OUT1_3  = TIM_CHANNEL_3;
    Chassis.ChassisMotor[1].OUT2_4  = TIM_CHANNEL_4;
    Chassis.ChassisMotor[1].VelocityGain = 8;	
    Chassis.ChassisMotor[2].MinPWMValue = 200;
	
	Chassis.ChassisMotor[2].MotorTIM = &htim2;
    Chassis.ChassisMotor[2].OUT1_3  = TIM_CHANNEL_3;
    Chassis.ChassisMotor[2].OUT2_4  = TIM_CHANNEL_4;
    Chassis.ChassisMotor[2].VelocityGain = 8;	
    Chassis.ChassisMotor[3].MinPWMValue = 200;
	
	Chassis.ChassisMotor[3].MotorTIM = &htim1;
    Chassis.ChassisMotor[3].OUT1_3  = TIM_CHANNEL_3;
    Chassis.ChassisMotor[3].OUT2_4  = TIM_CHANNEL_4;
    Chassis.ChassisMotor[3].VelocityGain = 8;
    Chassis.ChassisMotor[3].MinPWMValue = 200;
}
void Chassis_Control(void)
{
	//获取遥控数值
	Chassis.Vy = PS2_LX;
	Chassis.Vx = PS2_LY;
	Chassis.Vw = PS2_RX;
	//驱动地盘旋转以及PID控制
	Chassis.V1 = Chassis.Vx + Chassis.Vy + Chassis.Vw ;
	Chassis.V2 = -Chassis.Vx + Chassis.Vy + Chassis.Vw ;
	Chassis.V3 = Chassis.Vx - Chassis.Vy + Chassis.Vw ;
	Chassis.V4 = -Chassis.Vx - Chassis.Vy + Chassis.Vw ;
	
	Motor_Speed_Control(&Chassis.ChassisMotor[0] , Chassis.ChassisMotor[0].V_rpm , Chassis .V1);
	Motor_Speed_Control(&Chassis.ChassisMotor[1] , Chassis.ChassisMotor[1].V_rpm , Chassis .V2);
	Motor_Speed_Control(&Chassis.ChassisMotor[2] , Chassis.ChassisMotor[2].V_rpm , Chassis .V3);
	Motor_Speed_Control(&Chassis.ChassisMotor[3] , Chassis.ChassisMotor[3].V_rpm , Chassis .V4);
}
