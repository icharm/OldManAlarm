#include <string.h>
#include <stdio.h>
#include <iom128v.h>
#include "USART.h"
#include "basic.h"
#include "SYN7318.h"
#include "LCD.h"


//带命令识别词条
const uchar words[] = "救命 1|救命啊 1|哎呦 2|现在多少度 100|现在温度多少 100|现在几点 101|";
uchar tmp_text[255];

uint wordID = 0x0000;

//发送帧，0帧头，1数据区长度高字节，2数据区长度低字节，3命令字，4编码格式
extern uchar TxCharBuf[128];
extern uchar TxStrLen;
extern uchar RxCharBuf[16];
extern uchar RxBufWr, RxBufRd;

/*******************************************************************************
* SYN语音识别模块_初始化
********************************************************************************/
void SYN7318_init(void)
{
    //PC6,7 定义输入 10ms低电平 延时100ms
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
* 构造帧头
********************************************************************************/
void buildHead(uint len, uchar command)
{
    TxCharBuf[0] = 0xFD;        //构造帧头
    TxCharBuf[1] = len >> 8;    //构造数据区长度的高字节
    TxCharBuf[2] = len & 0xff;  //构造数据区长度的低字节
    TxCharBuf[3] = command;     //构造命令字
    TxCharBuf[4] = 0x00;
}

/*******************************************************************************
* 检查回传 通用
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
* 语音播报
********************************************************************************/
void voicePlayer(uchar *content)
{   
    int i;
    uchar temp;
    uint length = strlen(content); //待发送文本长度
    buildHead(length+2, PLAY_TEXT); //数据区长度、合成播放命令
    TxCharBuf[4] = GB2312;   //构造命令参数,编码格式为GB2312
    for(i = 0; i < length; i++){    //构造待发送文本
        TxCharBuf[5+i] = content[i]; 
    }
    TxCharBuf[5+i] = 0x00;

    TxStrLen = length+5;   //整个帧的长度
    do {	
        RxBufRd = RxBufWr = 0;
        puts0();                    //串口0发送数据
        if(checkSendReturn() != ACC_OK)
            delay_nms(20);          //延时20ms，帧与帧之间必须间隔超过15ms
        else
            break;
    }while(1);
    if(checkSendReturn() == STA_FREE)
        return;
    else
        waitFree();                 //等待模块空闲                        
}

/*******************************************************************************
* 语音播报欢迎信息
********************************************************************************/
void SYN7318_welcome(void)
{
    sprintf(tmp_text,"[m3][s5][v3][f1][b0]欢迎使用独居老人应急呼救系统[m3][d]");
    voicePlayer(tmp_text);
}

/*******************************************************************************
* 语音播报 识别错误提示
********************************************************************************/
void SYN7318_Error(void)
{
    sprintf(tmp_text,"[m3][s5][v3][f1][b0]不好意思，系统未理解您的意思，请重新说一遍[m3][d]");
    voicePlayer(tmp_text);
}

/*******************************************************************************
* 设置播放音量
********************************************************************************/
void setVoiceLevel(uchar level)
{
    buildHead(0x02, SET_VOLUME); //数据区长度、播放音量设置命令
    TxCharBuf[4] = level;   //构造命令参数,播放音量设置为level级（0-9级，默认为5级）
    TxStrLen = strlen(TxCharBuf);   //整个帧的长度
	do{
        RxBufRd = RxBufWr = 0;
        puts0();                        //串口0发送数据
    }while(checkSendReturn() == 0);
    //while(checkReturnByParam(0x4F) == 0);
    delay_nms(20);                  //延时20ms，帧与帧之间必须间隔超过15ms 
    
}

/*******************************************************************************
* 设置语音识别参数命令
********************************************************************************/
void setVoiceOption(void)
{
    buildHead(0x07, SET_PARAM);
    TxCharBuf[4] = DIS_NEAR; //设置识别距离为 中
    TxCharBuf[5] = QUI_H; //用户静音上限高字节
    TxCharBuf[6] = QUI_L; //用户静音上限低字节 3000ms
    TxCharBuf[7] = RECO_TIME_H; //用户语音上限高字节
    TxCharBuf[8] = RECO_TIME_L; //用户语音上限低字节 5000ms
    TxCharBuf[9] = REFUSE_LEVEL; //拒识级别 较低
    
    TxStrLen = 10;   //整个帧的长度
    do{
        RxBufRd = RxBufWr = 0;
	    puts0();                        //串口0发送数据
        if(checkSendReturn() == ACC_OK){
           break;
        }
    }while(1); 
    delay_nms(20);                  //延时20ms，帧与帧之间必须间隔超过15ms  
}

/*******************************************************************************
* 词条更新
********************************************************************************/
void updateWords(void)
{
    int i;
    uchar length = strlen(words);
    buildHead(length+3, UPADTE_WORD);
    TxCharBuf[4] = GB2312;          //编码格式GB2312
    TxCharBuf[5] = 0x20;            //词典参数，启用内置智能解析，关闭内置垃圾词条，词典编号为0x00
    for(i = 0; i < length; i++){    //词条
        TxCharBuf[6+i] = words[i];
    }
    
    TxStrLen = length + 6;       //整个帧的长度
	do{
        RxBufRd = RxBufWr = 0;
        puts0();                        //串口0发送数据
        DisplayCgrom(0x88,"正在更新词条。。");
        delay_nms(2);
        if(checkSendReturn() == ACC_OK){
            break;
        }
        else{
            delay_nms(20);
        }
    }while(1);
    if(checkSendReturn() == UPD_OK){    //检查回传 ，词条更新时不能被打断
        LCD_clear();
        DisplayCgrom(0x88,"词条更新成功");
        delay_nms(1000);
        LCD_clear();
    }else{
        LCD_clear();
        DisplayCgrom(0x88,"词条更新失败");
        delay_nms(1000);
        LCD_clear();
    }
    //延时20ms，帧与帧之间必须间隔超过15ms
    
}

/*******************************************************************************
* 等待模块空闲状态
********************************************************************************/
void waitFree(void)
{
    buildHead(0x01, CHECK_STATUS);
    TxStrLen = 4;//strlen(TxCharBuf);   //整个帧的长度
    do{
        RxBufRd = RxBufWr = 0;
        puts0();                        //串口0发送数据
        if(checkSendReturn() == ACC_OK){
            if(checkSendReturn() == STA_FREE)
                break;
        }
        delay_nms(20);      //延时20ms，帧与帧之间必须间隔超过15ms
    }while(1);              
}

/*******************************************************************************
* 开始语音识别
********************************************************************************/
void startRecognition(void)
{
    buildHead(0x02, START_RECOGN);
    TxCharBuf[4] = 0x00;     //词典编号
    TxStrLen = 5 ;
    do{
        RxBufRd = RxBufWr = 0;
        puts0();            //串口0发送数据
        if(checkSendReturn() == ACC_OK){
           break;
        }
        delay_nms(20);      //延时20ms，帧与帧之间必须间隔超过15ms
    }while(1);
}