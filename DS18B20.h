#include "basic.h"

/*�¶ȴ�����*/
#define DQ_IN	        DDRE &= ~(1 << PE4)		//�������룬DS18B20�ӵ�Ƭ��PE4��
#define DQ_OUT	        DDRE |= (1 << PE4)		//�������
#define DQ_CLR	        PORTE &= ~(1 << PE4)	//�õ͵�ƽ
#define DQ_SET	        PORTE |= (1 << PE4)		//�øߵ�ƽ
#define DQ_R	        PINE & (1 << PE4)		//����ƽ



unsigned char DS18B20_Reset(void);                 //��ʼ���͸�λ
unsigned char DS18B20_Read_byte(void);
void ds1820_write_byte(unsigned char value);
void ds1820_start(void);
unsigned int DS18B20_Read_temp(void);
void data_do(uint temp_d);
void LCD_write_temperature(void);
unsigned char* Temperaturetostr(void);