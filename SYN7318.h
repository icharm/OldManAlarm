#include "basic.h"

/*������*/
#define PLAY_TEXT 0x01         //���ŷ��͵��ı�
#define SET_VOLUME 0x05        //���ò�������
#define START_RECOGN 0x10      //��ʼ����ʶ��
#define STOP_RECOGN 0x11       //ֹͣ����ʶ��
#define SET_PARAM 0x1E         //��������ʶ�����
#define UPADTE_WORD 0x1F       //����ʶ�����
#define ON_AWAKEN 0x51         //�����������ѹ���
#define OFF_AWAKEN 0x52        //�ر���������
#define SET_AWKEN_WORD 0x53    //�����Զ��廽����
#define CHECK_STATUS 0x21      //��ѯ��ǰģ��Ĺ���״̬

/*�ش������� ͨ��*/
#define INIT_OK 0x4A           //ģ���ʼ���ɹ��ش�
#define ACC_OK  0x41           //���ճɹ�������֡��ȷ
#define ACC_ERR 0x45           //����ʧ�ܣ��յ�����ʶ�������֡

/*�ش������� ״̬��ѯ*/
#define STA_RECOGN 0x42        //ģ�鴦������ʶ�����������״̬
#define STA_PLA_MP3 0x49       //���ڲ���mp3
#define STA_UPD_WORD 0x4B      //���ڸ��´ʵ�
#define STA_PLA_TEXT 0x4E      //���ڲ��źϳɵ��ı�
#define STA_FREE 0x4F          //����״̬

/*�ش������� ��ʼ��������*/
#define AWKEN_OK 0x21          //�������ѳɹ�
#define AWKEN_ERR 0x22         //�����ڲ�����

/*�ش������� �����Զ��廽����*/
#define SET_AWK_OK 0x23        //�Զ��廽�������óɹ�
#define SET_AWK_ERR 0x24       //�Զ��廽�������óɹ�

/*�ش������� ��������*/
#define UPD_OK  0x31           //�ʵ���³ɹ�
#define UPD_ERR  0x32           //�ʵ����ʧ��

/*�ش������� ����ʶ��*/
#define RECON_OK 0x01           //ʶ��ɹ���������ID�ţ�
#define OVER_TIME 0x03          //�û�������ʱ
#define SPK_TIME 0x04           //�û�������ʱ
#define RECO_REJECT   0x07      //ʶ�𱻾�
#define INN_ERROR 0x06              //�ڲ�����

/*�������*/
#define GB2312 0x00            //GB2312����
#define DIS_NEAR 0x02          //ʶ�����Ϊ��
#define QUI_H 0x0B             //�û��������޸��ֽ�
#define QUI_L 0xB8             //�û��������޵��ֽ� 3000ms
#define RECO_TIME_H 0x13       //�û��������޸��ֽ�
#define RECO_TIME_L 0x88       //�û��������޵��ֽ� 5000ms
#define REFUSE_LEVEL 0x04      //��ʶ���� �ϵ�


/*��λ�� PC7*/
#define RST_SYN_CLR	PORTC &= ~(1 << PC7)              //��ƽ�õ�
#define RST_SYN_SET	PORTC |= (1 << PC7)               //��ƽ�ø�
#define RST_SYN_IN	DDRC &= ~(1 << PC7)               //��������
#define RST_SYN_OUT	DDRC |= (1 << PC7)                //�������
/*���ؽ� PC6*/
#define SRT_SYN_CLR	PORTC &= ~(1 << PC6)              //��ƽ�õ�
#define SRT_SYN_SET	PORTC |= (1 << PC6)               //��ƽ�ø�
#define SRT_SYN_IN	DDRC &= ~(1 << PC6)               //��������
#define SRT_SYN_OUT	DDRC |= (1 << PC6)                //�������

void SYN7318_init(void);
//void buildHead(uchar low, uchar command);
void voicePlayer(uchar *content);
void SYN7318_welcome(void);
void SYN7318_Error(void);
uint checkSendReturn(void);
void setVoiceLevel(uchar level);
void setVoiceOption(void);
void updateWords(void);
void waitFree(void);
void startRecognition(void);