/*复位脚 PC7
#define RST_ESP_CLR	PORTB &= ~(1 << PB6)              //电平置低
#define RST_ESP_SET	PORTB |= (1 << PB6)               //电平置高
#define RST_ESP_IN	DDRB &= ~(1 << PB6)               //方向输入
#define RST_ESP_OUT	DDRB |= (1 << PB6)                //方向输出*/
/*开关脚 PC6
#define SRT_ESP_CLR	PORTB &= ~(1 << PB5)              //电平置低
#define SRT_ESP_SET	PORTB |= (1 << PB5)               //电平置高
#define SRT_ESP_IN	DDRB &= ~(1 << PB5)               //方向输入
#define SRT_ESP_OUT	DDRB |= (1 << PB5)                //方向输出*/

/*AT指令
#define AT_RST "AT+RST"            //重启固件
#define AT_CWMODE "AT+CWMODE=1"    //设置模块Wi-Fi应用模式为Station模式
#define AT_CWJAP "AT+CWJAP=ICHARM,meiyanliang"*/

void wifi_Restart(void);
void wifi_ConnectSTA(void);
void wifi_CIPMUX(void);
void wifi_TCPConnect(void);
void wifi_CIPMODE(void);
void wifi_CIPSEND(void);
void wifi_SendMsg(void);
void wifi_SENDMSG(void);