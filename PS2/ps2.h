
#ifndef __PS2_H__
#define __PS2_H__
#include "delay.h"
extern volatile int PS2_LX,PS2_LY,PS2_RX,PS2_RY,PS2_KEY;

#define DI HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_6)
#define DO_H HAL_GPIO_WritePin(GPIOC,GPIO_PIN_7,GPIO_PIN_SET)
#define DO_L HAL_GPIO_WritePin(GPIOC,GPIO_PIN_7,GPIO_PIN_RESET)

#define CS_H HAL_GPIO_WritePin(GPIOC,GPIO_PIN_8,GPIO_PIN_SET)
#define CS_L HAL_GPIO_WritePin(GPIOC,GPIO_PIN_8,GPIO_PIN_RESET)

#define CLK_H HAL_GPIO_WritePin(GPIOC,GPIO_PIN_9,GPIO_PIN_SET)
#define CLK_L HAL_GPIO_WritePin(GPIOC,GPIO_PIN_9,GPIO_PIN_RESET)

//These are our button constants
#define PSB_SELECT      1
#define PSB_L3          2
#define PSB_R3          3
#define PSB_START       4
#define PSB_PAD_UP      5
#define PSB_PAD_RIGHT   6
#define PSB_PAD_DOWN    7
#define PSB_PAD_LEFT    8
#define PSB_L2         9
#define PSB_R2          10
#define PSB_L1          11
#define PSB_R1          12
#define PSB_GREEN       13
#define PSB_RED         14
#define PSB_BLUE        15
#define PSB_PINK        16
#define PSB_TRIANGLE    13
#define PSB_CIRCLE      14
#define PSB_CROSS       15
#define PSB_SQUARE      26

//These are stick values
#define PSS_RX 5                //右摇杆X轴数据
#define PSS_RY 6
#define PSS_LX 7
#define PSS_LY 8

extern uint8_t Data[9];
extern uint16_t MASK[16];
extern uint16_t Handkey;

void PS2_Init(void);
uint8_t PS2_RedLight(void);//判断是否为红灯模式
void PS2_ReadData(void);
void PS2_Cmd(uint8_t CMD);		  //
uint8_t PS2_DataKey(void);		  //键值读取
uint8_t PS2_AnologData(uint8_t button); //得到一个摇杆的模拟量
void PS2_ClearData(void);	  //清除数据缓冲区
void delay_init(uint8_t SYSCLK);
void delay_us(uint32_t nus);

void PS2_ShortPoll(void);//short poll
void PS2_EnterConfing(void);//进入设置
void PS2_TurnOnAnalogMode(void);//保存并完成设置
void PS2_VibrationMode(void);
void PS2_ExitConfing(void);//保存并完成设置
void PS2_SetInit(void);//手柄设置初始化
void PS2_Vibration(uint8_t motor1 ,uint8_t motor2);
void PS2_Receive(void);



//位带操作,实现51类似的GPIO控制功能
//具体实现思想,参考<<CM3权威指南>>第五章(87页~92页).M4同M3类似,只是寄存器地址变了.
//IO口操作宏定义
#define BITBAND(addr, bitnum) ((addr & 0xF0000000)+0x2000000+((addr &0xFFFFF)<<5)+(bitnum<<2)) 
#define MEM_ADDR(addr)  *((volatile unsigned long  *)(addr)) 
#define BIT_ADDR(addr, bitnum)   MEM_ADDR(BITBAND(addr, bitnum)) 

#endif


