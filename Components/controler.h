/**
  ******************************************************************************
  * @file    controler.h
  * @author  ChenY
  * @version V1.0.0
  * @date    2021/2/21
  * @brief   
  ******************************************************************************
  * @attention 
  *
  ******************************************************************************
  */
 /**
  ******************************************************************************
  * @file    controler.h
  * @author  ChenY
  * @version V1.0.0
  * @date    2021/2/21
  * @brief   
  ******************************************************************************
  * @attention 
  *
  ******************************************************************************
  */
  #ifndef _PID_H
  #define _PID_H
  
typedef struct
{
	float Kp;
	float Ki;
	float Kd;
	
	float tau ;
	
	float limMax;
	float limMin;
	
	float T;
	
	float integrator;
	float prevError;
	float differentiator;
	float prevMeaurement;
	
	float out ;
	
}PID_t;
void PID_Init(PID_t *pid , float Kp , float Ki , float Kd , float limMax , float limMin , float T , float tau );
float PID_Update(PID_t *pid , float setpont , float meaurement);

  #endif
