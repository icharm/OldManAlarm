#include <string.h>
#include <stdio.h>
#include <iom128v.h>
#include "USART.h"
#include "basic.h"
#include "SYN7318.h"
#include "LCD.h"


//������ʶ�����
const uchar words[] = "���� 1|������ 1|���� 2|���ڶ��ٶ� 100|�����¶ȶ��� 100|���ڼ��� 101|ʱ�� 101|";
uchar tmp_text[255];

uint wordID = 0x0000;

//����֡��0֡ͷ��1���������ȸ��ֽڣ�2���������ȵ��ֽڣ�3�����֣�4�����ʽ
extern uchar TxCharBuf[128];
extern uchar TxStrLen;
extern uchar RxCharBuf[16];
extern uchar RxBufWr, RxBufRd;

/*******************************************************************************
* SYN����ʶ��ģ��_��ʼ��
********************************************************************************/
void SYN7318_init(void)
{
    //PC6,7 �������� 10ms�͵�ƽ ��ʱ100ms
    SRT_SYN_OUT;
    RST_SYN_OUT;
    SRT_SYN_SET;
    RST_SYN_SET;
    delay_nms(100);
    RST_SYN_CLR;
    delay_nms(10);
    RST_SYN_SET;
    delay_nms(100);
}

/*******************************************************************************
* ����֡ͷ
********************************************************************************/
void buildHead(uint len, uchar command)
{
    TxCharBuf[0] = 0xFD;        //����֡ͷ
    TxCharBuf[1] = len >> 8;    //�������������ȵĸ��ֽ�
    TxCharBuf[2] = len & 0xff;  //�������������ȵĵ��ֽ�
    TxCharBuf[3] = command;     //����������
    TxCharBuf[4] = 0x00;
}

/*******************************************************************************
* ���ش� ͨ��
********************************************************************************/
uint checkSendReturn(void)
{   
    uchar RxSt, command, length, number = 0;
    wordID = 0x0000;
    do {
        while(RxBufRd == RxBufWr) delay_nms(1);
        RxSt = RxCharBuf[RxBufRd];
        RxBufRd ++;
        RxBufRd &= 0x0f;
        switch(number){
            case 0 :
                if (RxSt == 0xFC){
                    number = 1;
                }
                break;
            case 1 : 
                if(RxSt != 0)
                    return 0;
                number = 2;
                break;
           case 2 :
                if(RxSt > 6)
                    return 0;
                length = RxSt;
                number = 3;
                break;
           case 3 : 
                if(RxSt == ACC_ERR)
                    return 0;
                length--;
                if(length == 0)
                    return RxSt;
                command = RxSt;
                number = 4;
                break;
            case 4 :
                wordID <<= 8;
                wordID |= RxSt;
                //wordID |= command;
                length--;
                if(length == 0)
                    return wordID;
                break;
        }
    }while(1);
    return 0;
}


/*******************************************************************************
* ��������
********************************************************************************/
void voicePlayer(uchar *content)
{   
    int i;
    uchar temp;
    uint length = strlen(content); //�������ı�����
    buildHead(length+2, PLAY_TEXT); //���������ȡ��ϳɲ�������
    TxCharBuf[4] = GB2312;   //�����������,�����ʽΪGB2312
    for(i = 0; i < length; i++){    //����������ı�
        TxCharBuf[5+i] = content[i]; 
    }
    TxCharBuf[5+i] = 0x00;

    TxStrLen = length+5;   //����֡�ĳ���
    do {	
        RxBufRd = RxBufWr = 0;
        puts0();                    //����0��������
        if(checkSendReturn() != ACC_OK)
            delay_nms(20);          //��ʱ20ms��֡��֮֡�����������15ms
        else
            break;
    }while(1);
    if(checkSendReturn() == STA_FREE)
        return;
    else
        waitFree();                 //�ȴ�ģ�����                        
}

/*******************************************************************************
* ����������ӭ��Ϣ
********************************************************************************/
void SYN7318_welcome(void)
{
    sprintf(tmp_text,"[m3][s5][v3][f1][b0]��ӭʹ�ö�������Ӧ������ϵͳ[m3][d]");
    voicePlayer(tmp_text);
}

/*******************************************************************************
* �������� ʶ�������ʾ
********************************************************************************/
void SYN7318_Error(void)
{
    sprintf(tmp_text,"[m3][s5][v3][f1][b0]������˼��ϵͳδ���������˼��������˵һ��[m3][d]");
    voicePlayer(tmp_text);
}

/*******************************************************************************
* ���ò�������
********************************************************************************/
void setVoiceLevel(uchar level)
{
    buildHead(0x02, SET_VOLUME); //���������ȡ�����������������
    TxCharBuf[4] = level;   //�����������,������������Ϊlevel����0-9����Ĭ��Ϊ5����
    TxStrLen = strlen(TxCharBuf);   //����֡�ĳ���
	do{
        RxBufRd = RxBufWr = 0;
        puts0();                        //����0��������
    }while(checkSendReturn() == 0);
    //while(checkReturnByParam(0x4F) == 0);
    delay_nms(20);                  //��ʱ20ms��֡��֮֡�����������15ms 
    
}

/*******************************************************************************
* ��������ʶ���������
********************************************************************************/
void setVoiceOption(void)
{
    buildHead(0x07, SET_PARAM);
    TxCharBuf[4] = DIS_NEAR; //����ʶ�����Ϊ ��
    TxCharBuf[5] = QUI_H; //�û��������޸��ֽ�
    TxCharBuf[6] = QUI_L; //�û��������޵��ֽ� 3000ms
    TxCharBuf[7] = RECO_TIME_H; //�û��������޸��ֽ�
    TxCharBuf[8] = RECO_TIME_L; //�û��������޵��ֽ� 5000ms
    TxCharBuf[9] = REFUSE_LEVEL; //��ʶ���� �ϵ�
    
    TxStrLen = 10;   //����֡�ĳ���
    do{
        RxBufRd = RxBufWr = 0;
	    puts0();                        //����0��������
        if(checkSendReturn() == ACC_OK){
           break;
        }
    }while(1); 
    delay_nms(20);                  //��ʱ20ms��֡��֮֡�����������15ms  
}

/*******************************************************************************
* ��������
********************************************************************************/
void updateWords(void)
{
    int i;
    uchar length = strlen(words);
    buildHead(length+3, UPADTE_WORD);
    TxCharBuf[4] = GB2312;          //�����ʽGB2312
    TxCharBuf[5] = 0x20;            //�ʵ�����������������ܽ������ر����������������ʵ���Ϊ0x00
    for(i = 0; i < length; i++){    //����
        TxCharBuf[6+i] = words[i];
    }
    
    TxStrLen = length + 6;       //����֡�ĳ���
	do{
        RxBufRd = RxBufWr = 0;
        puts0();                        //����0��������
        DisplayCgrom(0x88,"���ڸ��´�������");
        delay_nms(2);
        if(checkSendReturn() == ACC_OK){
            break;
        }
        else{
            delay_nms(20);
        }
    }while(1);
    if(checkSendReturn() == UPD_OK){    //���ش� ����������ʱ���ܱ����
        LCD_clear();
        DisplayCgrom(0x88,"�������³ɹ�");
        delay_nms(1000);
        LCD_clear();
    }else{
        LCD_clear();
        DisplayCgrom(0x88,"��������ʧ��");
        delay_nms(1000);
        LCD_clear();
    }
    //��ʱ20ms��֡��֮֡�����������15ms
    
}

/*******************************************************************************
* �ȴ�ģ�����״̬
********************************************************************************/
void waitFree(void)
{
    buildHead(0x01, CHECK_STATUS);
    TxStrLen = 4;//strlen(TxCharBuf);   //����֡�ĳ���
    do{
        RxBufRd = RxBufWr = 0;
        puts0();                        //����0��������
        if(checkSendReturn() == ACC_OK){
            if(checkSendReturn() == STA_FREE)
                break;
        }
        delay_nms(20);      //��ʱ20ms��֡��֮֡�����������15ms
    }while(1);              
}

/*******************************************************************************
* ��ʼ����ʶ��
********************************************************************************/
void startRecognition(void)
{
    buildHead(0x02, START_RECOGN);
    TxCharBuf[4] = 0x00;     //�ʵ���
    TxStrLen = 5 ;
    do{
        RxBufRd = RxBufWr = 0;
        puts0();            //����0��������
        if(checkSendReturn() == ACC_OK){
           break;
        }
        delay_nms(20);      //��ʱ20ms��֡��֮֡�����������15ms
    }while(1);
}