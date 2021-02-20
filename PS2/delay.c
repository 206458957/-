// delay.c
#include "delay.h"


static uint8_t fac_us = 0;	//us延时倍乘数
static uint16_t fac_ms = 0; //ms延时倍乘数,在os下,代表每个节拍的ms数

//初始化延迟函数
//SYSTICK的时钟固定为AHB时钟的1/8
//SYSCLK:系统时钟频率
void delay_init(uint8_t SYSCLK)
{
	fac_us = SYSCLK / 8;	//不论是否使用OS,fac_us都需要使用
	fac_ms = fac_us * 1000; //非OS下,代表每个ms需要的systick时钟数
}

//仿原子延时，不进入systic中断
void delay_us(uint32_t nus)
{
	uint32_t temp;
	SysTick->LOAD = (uint32_t)(fac_us * nus);
	SysTick->VAL = 0X00;  //清空计数器
	SysTick->CTRL = 0X01; //使能，减到零是无动作，采用外部时钟源
	do

	{
		temp = SysTick->CTRL; //读取当前倒计数值		 
	}
	while ((temp & 0x01) && (!(temp & (1 << 16))))
		;					   //等待时间到达
	SysTick->CTRL = 0x00; //关闭计数器
	SysTick->VAL = 0X00;   //清空计数器
}

void delay_ms(uint16_t nms)
{
	uint32_t temp;
	SysTick->LOAD = (uint32_t)(fac_ms * nms);
	SysTick->VAL = 0X00;  //清空计数器
	SysTick->CTRL = 0X01; //使能，减到零是无动作，采用外部时钟源
	do
	{
		temp = SysTick->CTRL; //读取当前倒计数值
		
	}
	while ((temp & 0x01) && (!(temp & (1 << 16))))
		;					  //等待时间到达
	SysTick->CTRL = 0x00; //关闭计数器
  SysTick->VAL = 0X00;  //清空计数器
}
