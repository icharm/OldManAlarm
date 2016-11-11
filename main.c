//DMAVR-128������12864��Һ����ʾʵʱʱ����������
//���뻷�� ���뻷�� ICCAVR 7.16A
//ϵͳʱ��7.3728MHZ��������˿λΪ�ⲿ��ƵʯӢ�����񵴣�����ʱ��4.1ms
//���ߣ����� www.avrgcc.com
//���ڣ�2010.12.112

//***********************************************************************
//			�����ļ�
//***********************************************************************

#include <string.h>
#include <stdio.h>
#include <macros.h>
#include <AVRdef.h>
#include <iom128v.h>
#include "DS18B20.h"    //�¶ȴ�����
#include "basic.h"      //��������
#include "12864time.h"  //DS1302ʱ��
#include "LCD.h"        //12864LCD��ʾ��
#include "USART.h"
#include "SYN7318.h"
#include "ESP8266.h"    

extern uchar RxCharBuf[16];
extern uchar RxCharNum, RxBufWr, RxBufRd;
extern uchar TxCharBuf[128];
extern uchar TxCharNum,TxStrLen;

extern uchar RxCharBuf_wifi[16];
extern uchar RxCharNum_wifi, RxBufWr_wifi, RxBufRd_wifi;
extern uchar TxCharBuf_wifi[128];
extern uchar TxCharNum_wifi,TxStrLen_wifi;

 
//****************************************************************
//  ��ʾ��ӭ��Ϣ
//****************************************************************
void welcomeDisplay(void)
{
 	DisplayCgrom(0x90,"��ӭʹ�ö�������");
	delay_nms(100);
	DisplayCgrom(0x8a,"Ԥ��ϵͳ");
	delay_nms(3000);
	LCD_clear();                                  //����
}

//****************************************************************
//  ��ʾ����ģ���ʼ����Ϣ
//****************************************************************
void syn7318InitDisplay(void)
{
 	DisplayCgrom(0x90,"����ģ��");
	delay_nms(100);
	DisplayCgrom(0x8a,"��ʼ����");
	delay_nms(3000);
	LCD_clear();                                  //����
}


//call this routine to initialize all peripherals
void init_devices(void)
{
    //stop errant interrupts until set up
    CLI(); //disable all interrupts
    XDIV  = 0x00; //xtal divider
    XMCRA = 0x00; //external memory
    UART0_Init();
    //UART1_Init();
    MCUCR = 0x00;
    EICRA = 0x00; //extended ext ints
    EICRB = 0x00; //extended ext ints
    EIMSK = 0x00;
    TIMSK = 0x00; //timer interrupt sources
    ETIMSK = 0x00; //extended timer interrupt sources
    SEI(); //re-enable interrupts
    //all peripherals are now initialized
}

//***********************************************************************
//			������
//***********************************************************************
void main(void)
{
    // volatile unsigned char temp;
	uchar u8temp;
    uchar command;
    uchar temp;   

    system_init();                                //ϵͳ��ʼ��������IO������
	delay_nms(100);                                //��ʱ100ms
	LCD_init();                                   //Һ��������ʼ������
	LCD_clear();                                  //����
    
	ds1302_init();                                //DS1302��ʼ��
	DS18B20_Reset();			        		  //��λD18B20
	delay_nms(10);
	//ds1302_write_time();                        //��DS1302д��ʼ���ݣ������º�ʱ���
	welcomeDisplay();
	init_devices(); 
	
    SYN7318_init();                               //SYN7318����ʶ��ģ�� ��ʼ��
    syn7318InitDisplay();
       

    //updateWords();                                //SYN7318����ʶ��ģ�� �ʵ����                                                 
    //SYN7318_welcome();

    updateWords();

    while(1) { 

		displayDateTime();
		LCD_write_temperature();
        
         //wifi
        while(RxBufWr_wifi != RxBufRd_wifi) {
            LCD_write_com(0x98);
            delay_nms(2);
            u8temp = RxCharBuf_wifi[RxBufRd_wifi];
            RxBufRd_wifi++;
            RxBufRd_wifi &= 0x0f;
            if(u8temp == 0x0d) break;
            LCD_write_data(u8temp);
            delay_nms(2);
            //DisplayCgrom(0x98, &u8temp);
        }


        startRecognition();
        command = checkSendReturn();
        
        switch(command){
            case OVER_TIME :
                break;
            case 0x04 :
                //SYN7318_Error();
                DisplayCgrom(0x88,"������ʱ");
                delay_nms(2);
                break;
            case 0x05 :
                //SYN7318_Error();
                DisplayCgrom(0x88,"ʶ���ʶ");
                delay_nms(2);
                break;
            case 0x07 :
                //SYN7318_Error();
                DisplayCgrom(0x88,"ʶ���ʶһ");
                delay_nms(2);
                break;
            case 0x06 :
                //SYN7318_Error();
                DisplayCgrom(0x88,"ʶ���ڲ�����");
                delay_nms(2);
                break;
            case 1 :
                DisplayCgrom(0x8C,"����");
                delay_nms(2);
                //wifi_SENDMSG();
                wifi_Restart();
                break;
            case 2 :
                DisplayCgrom(0x8C,"����");
                delay_nms(2);
                break;
            case 100 :
                DisplayCgrom(0x8C,"�¶�");
                delay_nms(2);
                break;
            default :
                DisplayCgrom(0x8C,"ʶ��ɹ�");
                delay_nms(2);
                LCD_write_com(0x8C);
	            delay_nms(2);
                temp = (command >> 4) + '0';          //��LCD��дҪ��ʾ������	
                LCD_write_data(temp);
                delay_nms(2);
                break;
        }

        //if(command == )
	}
}
