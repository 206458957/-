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
	 //��ʼ��������������
  pid ->integrator = 0.0f;
  pid ->prevError = 0.0f;
	 
  pid ->differentiator = 0.0f;
  pid ->prevMeaurement = 0.0f;

  pid ->out = 0.0f;
  
 }
 
 float PID_Update(PID_t *pid , float setpont , float meaurement)
 {
	/*����ź�
	*/	 
	 float error = setpont - meaurement;	 
	 /*����
	 */
	 float proportional = pid ->Kp * error ;	 
	 /*����
	 */
	 float integrator = pid ->integrator + 0.5f * pid ->Ki * pid ->T * (error + pid ->prevError);
	
	 
	 float limMinInt , limMaxInt;
	 
	 /*�Ƚϻ�������
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
	 
	 /*�����޷�
	 */
	 if(pid ->integrator > limMaxInt)
	 {
		 pid ->integrator = limMaxInt ;
	 }
	 else if(pid ->integrator < limMinInt)
	 {
		 pid ->integrator = limMinInt ;
	 }
	 /*΢��(�����Ʒ���)
	 */
	 pid ->differentiator = (2.0f * pid ->Kd * (meaurement - pid ->prevMeaurement)
						  + (2.0f * pid ->tau - pid ->T) * pid ->differentiator)
						  / (2.0f * pid ->tau - pid ->T);
	 /*������� Ӧ������
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
	 /*����
	 */
	 pid ->prevError = error ;
	 pid ->prevMeaurement = meaurement ;
	 /*����PID���
	 */
	 return pid ->out ;
	 
 }




 