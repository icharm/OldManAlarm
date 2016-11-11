#include <iom128v.h>
#include "LCD.h"
#include "basic.h"

//*************************************************************************
//			初始化子程序
//*************************************************************************
void system_init(void){

	Data_IO = 0xFF;				        //电平设置
	Data_DDR = 0xFF;				        //方向输出

	PORTF = 0xFF;                       //电平设置
	DDRF = 0xFF;                        //方向输出
    PORTD=0xFF;
	DDRD=0xFF;
	PORTE=0xFF;                        //PSB对应于PE2
	DDRE=0xfe;
	D_LE1;                             //关掉数码管，以免显示乱码                   
    W_LE1;                     
    Data_IO=0xFF;                      //关数码管            
    W_LE0; 
	
	PORTB=0xFF;				  		   //关闭发光二极管
	DDRB=0xFF;

	PSB_SET;						   //液晶并口方式
}


//***********************************************************************
//	显示屏命令写入函数
//***********************************************************************


void LCD_write_com(unsigned char com) 
{	
	RS_CLR;
	RW_CLR;
	EN_SET;
	Data_IO = com;
	delay_nms(5);
	EN_CLR;
}

//***********************************************************************
//	显示屏数据写入函数
//***********************************************************************

void LCD_write_data(unsigned char data) 
{
    RS_SET;
	RW_CLR;
	EN_SET;
	Data_IO = data;
	delay_nms(5);
	EN_CLR;
}

//***********************************************************************
//	显示屏单字符写入函数
//***********************************************************************

void LCD_write_char(unsigned char x,unsigned char y,unsigned char data) 
{
	
    if (y == 0) 
    {
    	LCD_write_com(0x80 + x);
    }
    else 
    {
    	LCD_write_com(0x90 + x);
    }
    delay_nms(2);
    LCD_write_data( data);  
}

//***********************************************************************
//	显示屏清空显示
//***********************************************************************

void LCD_clear(void) 
{
	LCD_write_com(0x01);
	delay_nms(10);
}

//***********************************************************************
//函数名称：DisplayCgrom(uchar hz)显示CGROM里的汉字
//***********************************************************************
void DisplayCgrom(uchar addr,uchar *hz)
{
	LCD_write_com(addr);
    delay_nms(5);
	while(*hz != '\0')
	{
		LCD_write_data(*hz);
		hz++;
        delay_nms(5);
	}

}

//***********************************************************************
//	显示屏初始化函数
//***********************************************************************

void LCD_init(void) 
{
	DDRA = 0xFF;				        //I/O口方向设置
	DDRA |= (1 << PA5) | (1 << PA6) | (1 << PA7);
	LCD_write_com(FUN_MODE);			//显示模式设置
	delay_nms(5);
	LCD_write_com(FUN_MODE);			//显示模式设置
	delay_nms(5);
    LCD_write_com(DISPLAY_ON);			//显示开
	delay_nms(5);
    LCD_write_com(CLEAR_SCREEN);			//清屏
	delay_nms(5);
}