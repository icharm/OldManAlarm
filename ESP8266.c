#include <string.h>
#include <stdio.h>
#include <iom128v.h>
#include "USART.h"
#include "basic.h"
#include "ESP8266.h"

//发送字符数组
extern uchar TxCharBuf_wifi[128];
extern uchar TxStrLen_wifi;
//接收字符数组
extern uchar RxCharBuf_wifi[16];
extern uchar RxCharNum_wifi, RxBufWr_wifi, RxBufRd_wifi;

//***********************************************************************
//	wifi模块重启
//***********************************************************************
void wifi_Restart(void)
{
    sprintf(TxCharBuf_wifi, "AT+RST");
    TxStrLen_wifi = strlen(TxCharBuf_wifi);
	puts1();
}

//***********************************************************************
//	wifi模块连接wifi热点
//***********************************************************************
void wifi_ConnectSTA(void)
{
    sprintf(TxCharBuf_wifi, "AT+CWJAP=ICHARM,meiyanliang");
    TxStrLen_wifi = strlen(TxCharBuf_wifi);
	puts1();
}

//***********************************************************************
//	设置为单路连接模式
//***********************************************************************
void wifi_CIPMUX(void)
{
    sprintf(TxCharBuf_wifi, "AT+CIPMUX=0");
    TxStrLen_wifi = strlen(TxCharBuf_wifi);
	puts1();
}

//***********************************************************************
//	建立TCP连接
//***********************************************************************
void wifi_TCPConnect(void)
{
    sprintf(TxCharBuf_wifi, "TCP,alarm.icharm.me,80");
    TxStrLen_wifi = strlen(TxCharBuf_wifi);
	puts1();
}

//***********************************************************************
//	设置模块为透传模式
//***********************************************************************
void wifi_CIPMODE(void)
{
    sprintf(TxCharBuf_wifi, "AT+CIPMODE=1");
    TxStrLen_wifi = strlen(TxCharBuf_wifi);
	puts1();
}

//***********************************************************************
//	使用透传模式向服务器发送数据
//***********************************************************************
void wifi_CIPSEND(void)
{
    sprintf(TxCharBuf_wifi, "AT+CIPSEND");
    TxStrLen_wifi = strlen(TxCharBuf_wifi);
	puts1();
}


//***********************************************************************
//	发送短信
//***********************************************************************
void wifi_SendMsg(void)
{
    sprintf(TxCharBuf_wifi, "GET http://alarm.icharm.me");
    TxStrLen_wifi = strlen(TxCharBuf_wifi);
	puts1();
}

//***********************************************************************
//	发送短信
//***********************************************************************
void wifi_SENDMSG(void)
{
    wifi_TCPConnect();
    delay_nms(200);
    wifi_CIPMODE();
    delay_nms(200);
    wifi_CIPSEND();
    delay_nms(50);
    wifi_SendMsg();
}
