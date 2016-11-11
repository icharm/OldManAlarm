#include <iom128v.h>
#include "basic.h"
#include "USART.h"


//�����ַ����� 
uchar TxCharBuf[128];
uchar TxCharNum, TxStrLen;
//�����ַ�����
uchar RxCharBuf[16];
uchar RxCharNum, RxBufWr, RxBufRd;

//�����ַ�����
uchar TxCharBuf_wifi[128];
uchar TxCharNum_wifi, TxStrLen_wifi;
//�����ַ�����
uchar RxCharBuf_wifi[16];
uchar RxCharNum_wifi, RxBufWr_wifi, RxBufRd_wifi;

//***********************************************************************
// ����0��ʼ���ӿں���
// ��ʼ��uart,��ѯ��ʽ��д
//***********************************************************************
void UART0_Init(void)
{
    UCSR0B = 0x00;    //disable while setting baud rate
    UCSR0C = 0x06;
	UCSR0A = 0x00;
    UBRR0H = baud_h;  //д�����ʵ�ֵ
    UBRR0L = baud_l;
    UCSR0B = (1 << RXEN0) | (1 << TXEN0) | (1 << RXCIE0); //���ͽ���ʹ�ܡ����ս����ж�ʹ��

	RxBufWr = 0;
	RxBufRd = 0;	
}
	
//***********************************************************************
// USART0�����ַ�������
//***********************************************************************
void puts0(void)
{
    for(TxCharNum = 0; TxCharNum < TxStrLen; TxCharNum++){
        UDR0 = TxCharBuf[TxCharNum];
        while(!(UCSR0A & (1 << TXC0))) ;
        UCSR0A |= (1 << TXC0);
    }
    //UDR0 = 0x0d;
    //while(!(UCSR0A & (1 << TXC0))) ;
    //UCSR0A |= (1 << TXC0);
}

//***********************************************************************
// USART0�жϽ����ַ���
//***********************************************************************
#pragma interrupt_handler uart0_rx_isr:iv_USART0_RXC
void uart0_rx_isr(void)
{
    RxCharBuf[RxBufWr] = UDR0;  //�����ݻ������н�������
	RxBufWr++;
 	RxBufWr &= 0x0f;            //16->0
}


//************************************************************UART1 WIFI_ESP8266*********************************************************************
//***************************************************************************************************************************************************
// ����1��ʼ���ӿں���
// ��ʼ��uart,��ѯ��ʽ��д
//***********************************************************************
void UART1_Init(void)
{
    UCSR1B = 0x00;    //disable while setting baud rate
    UCSR1C = 0x06;
	UCSR1A = 0x00;
    UBRR1H = baud_h;  //д�����ʵ�ֵ
    UBRR1L = baud_l;
    UCSR1B = (1 << RXEN1) | (1 << TXEN1) | (1 << RXCIE1); //���ͽ���ʹ�ܡ����ս����ж�ʹ��

	RxBufWr_wifi = 0;
	RxBufRd_wifi = 0;	
}
	
//***********************************************************************
// USART1�����ַ�������
//***********************************************************************
void puts1(void)
{
    for(TxCharNum_wifi = 0; TxCharNum_wifi < TxStrLen_wifi; TxCharNum_wifi++){
        UDR1 = TxCharBuf_wifi[TxCharNum_wifi];
        while(!(UCSR1A & (1 << TXC1))) ;   //�ȴ��������
        UCSR1A |= (1 << TXC1);             //������ɱ�־��λ
    }
    UDR1 = 0x0d;
    while(!(UCSR1A & (1 << TXC1))) ;
    UCSR1A |= (1 << TXC1);
}

//***********************************************************************
// USART1�жϽ����ַ���
//***********************************************************************
#pragma interrupt_handler uart1_rx_isr:iv_USART1_RXC
void uart1_rx_isr(void)
{
    RxCharBuf_wifi[RxBufWr_wifi] = UDR1;  //�����ݻ������н�������
	RxBufWr_wifi++;
 	RxBufWr_wifi &= 0x0f;            //16->0
}