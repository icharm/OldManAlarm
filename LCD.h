#include "basic.h"

//***********************************************************************
//	定义变量区
//***********************************************************************
#define RS_CLR	PORTF &= ~(1 << PF1)                 //RS置低
#define RS_SET	PORTF |= (1 << PF1)                  //RS置高

#define RW_CLR	PORTF &= ~(1 << PF2)                 //RW置低
#define RW_SET	PORTF |= (1 << PF2)                  //RW置高

#define EN_CLR	PORTF &= ~(1 << PF3)                 //E置低
#define EN_SET	PORTF |= (1 << PF3)                  //E置高

#define PSB_CLR	PORTF &= ~(1 << PE2)                 //PSB置低，串口方式
#define PSB_SET	PORTF |= (1 << PE2)                  //PSB置高，并口方式

#define LOW		0
#define HIGH    1

//初始化指令
#define CLEAR_SCREEN	0x01		//清屏指令：清屏且AC值为00H
#define AC_INIT		    0x02		//将AC设置为00H。且游标移到原点位置
#define CURSE_ADD		0x06		//设定游标移到方向及图像整体移动方向（默认游标右移，图像整体不动）
#define FUN_MODE		0x30		//工作模式：8位基本指令集
#define DISPLAY_ON		0x0c		//显示开,显示游标，且游标位置反白
#define DISPLAY_OFF		0x08		//显示关
#define CURSE_DIR		0x14		//游标向右移动:AC=AC+1
#define SET_CG_AC		0x40		//设置AC，范围为：00H~3FH
#define SET_DD_AC		0x80

#define Data_IO	        PORTA                //液晶数据口
#define Data_DDR        DDRA                 //数据口方向寄存器
#define D_LE0	        PORTD &= ~(1 << PD4) //数码管段控制位为0，锁存端口数据
#define D_LE1           PORTD |= (1 << PD4)  //数码管段控制位为1，锁存器输出与端口一致
#define W_LE0	        PORTD &= ~(1 << PD5) //数码管位控制位为0
#define W_LE1           PORTD |= (1 << PD5)  //数码管位控制位为1

void system_init(void);
void LCD_write_com(unsigned char com);
void LCD_write_data(unsigned char data);
void LCD_write_char(unsigned char x,unsigned char y,unsigned char data) ;
void LCD_clear(void);
void DisplayCgrom(uchar addr,uchar *hz);
void LCD_init(void);