/*��λ�� PC7
#define RST_ESP_CLR	PORTB &= ~(1 << PB6)              //��ƽ�õ�
#define RST_ESP_SET	PORTB |= (1 << PB6)               //��ƽ�ø�
#define RST_ESP_IN	DDRB &= ~(1 << PB6)               //��������
#define RST_ESP_OUT	DDRB |= (1 << PB6)                //�������*/
/*���ؽ� PC6
#define SRT_ESP_CLR	PORTB &= ~(1 << PB5)              //��ƽ�õ�
#define SRT_ESP_SET	PORTB |= (1 << PB5)               //��ƽ�ø�
#define SRT_ESP_IN	DDRB &= ~(1 << PB5)               //��������
#define SRT_ESP_OUT	DDRB |= (1 << PB5)                //�������*/

/*ATָ��
#define AT_RST "AT+RST"            //�����̼�
#define AT_CWMODE "AT+CWMODE=1"    //����ģ��Wi-FiӦ��ģʽΪStationģʽ
#define AT_CWJAP "AT+CWJAP=ICHARM,meiyanliang"*/

void wifi_Restart(void);
void wifi_ConnectSTA(void);
void wifi_CIPMUX(void);
void wifi_TCPConnect(void);
void wifi_CIPMODE(void);
void wifi_CIPSEND(void);
void wifi_SendMsg(void);
void wifi_SENDMSG(void);