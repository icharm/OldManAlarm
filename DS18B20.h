#include "basic.h"

/*温度传感器*/
#define DQ_IN	        DDRE &= ~(1 << PE4)		//设置输入，DS18B20接单片机PE4口
#define DQ_OUT	        DDRE |= (1 << PE4)		//设置输出
#define DQ_CLR	        PORTE &= ~(1 << PE4)	//置低电平
#define DQ_SET	        PORTE |= (1 << PE4)		//置高电平
#define DQ_R	        PINE & (1 << PE4)		//读电平



unsigned char DS18B20_Reset(void);                 //初始化和复位
unsigned char DS18B20_Read_byte(void);
void ds1820_write_byte(unsigned char value);
void ds1820_start(void);
unsigned int DS18B20_Read_temp(void);
void data_do(uint temp_d);
void LCD_write_temperature(void);
unsigned char* Temperaturetostr(void);