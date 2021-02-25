/**
  ******************************************************************************
  * @file    controler.c
  * @author  ChenY
  * @version V1.0.0
  * @date    2021/2/21
  * @brief   
  ******************************************************************************
  * @attention 
  * https://www.bilibili.com/video/BV1R541137KP?from=search&seid=1784864303952024281
  ******************************************************************************
  */
 #include "controler.h"

 void PID_Init(PID_t *pid , float Kp , float Ki , float Kd , float limMax , float limMin , float T , float tau )
 {
	 //初始化控制器各参数
  pid ->integrator = 0.0f;
  pid ->prevError = 0.0f;
	 
  pid ->differentiator = 0.0f;
  pid ->prevMeaurement = 0.0f;

  pid ->out = 0.0f;
  
 }
 
 float PID_Update(PID_t *pid , float setpont , float meaurement)
 {
	/*误差信号
	*/	 
	 float error = setpont - meaurement;	 
	 /*比例
	 */
	 float proportional = pid ->Kp * error ;	 
	 /*积分
	 */
	 float integrator = pid ->integrator + 0.5f * pid ->Ki * pid ->T * (error + pid ->prevError);
	
	 
	 float limMinInt , limMaxInt;
	 
	 /*比较积分限制
	 */
	 if(pid ->limMax > proportional)
	 {
		 limMaxInt = pid ->limMax - proportional ;
	 }
	 else
	 {
		limMaxInt = 0.0f ;
	 }
	 
	 if(pid ->limMin < proportional)
	 {
		limMinInt = pid ->limMin - proportional ;
		 
	 }
	 else
	 {
		limMinInt = 0.0f ;
	 }
	 
	 /*积分限幅
	 */
	 if(pid ->integrator > limMaxInt)
	 {
		 pid ->integrator = limMaxInt ;
	 }
	 else if(pid ->integrator < limMinInt)
	 {
		 pid ->integrator = limMinInt ;
	 }
	 /*微分(反缠绕方法)
	 */
	 pid ->differentiator = (2.0f * pid ->Kd * (meaurement - pid ->prevMeaurement)
						  + (2.0f * pid ->tau - pid ->T) * pid ->differentiator)
						  / (2.0f * pid ->tau - pid ->T);
	 /*计算输出 应用限制
	 */
	 pid ->out = proportional + pid ->integrator + pid ->differentiator ;
	 if(pid ->out > pid ->limMax)
	 {
		pid ->out = pid ->limMax ;
	 }
	 else if(pid ->out < pid ->limMin)
	 {
		 pid ->out = pid ->limMin;
	 }
	 /*迭代
	 */
	 pid ->prevError = error ;
	 pid ->prevMeaurement = meaurement ;
	 /*返回PID输出
	 */
	 return pid ->out ;
	 
 }




 