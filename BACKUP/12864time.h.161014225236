//***********************************************************************
//	定义变量区
//***********************************************************************
#define LOW		0
#define HIGH    1


/*复位脚*/
#define RST_CLR	PORTE &= ~(1 << PE7)              //电平置低
#define RST_SET	PORTE |= (1 << PE7)               //电平置高
#define RST_IN	DDRE &= ~(1 << PE7)               //方向输入
#define RST_OUT	DDRE |= (1 << PE7)                //方向输出

/*双向数据*/
#define IO_CLR	PORTE &= ~(1 << PE6)              //电平置低
#define IO_SET	PORTE |= (1 << PE6)               //电平置高
#define IO_R	PINE & (1 << PE6)                 //电平读取
#define IO_IN	DDRE &= ~(1 << PE6)               //方向输入
#define IO_OUT	DDRE |= (1 << PE6)                //方向输出
/*时钟信号*/
#define SCK_CLR	PORTE &= ~(1 << PE5)              //时钟信号
#define SCK_SET	PORTE |= (1 << PE5)               //电平置高
#define SCK_IN	DDRE &= ~(1 << PE5)               //方向输入
#define SCK_OUT	DDRE |= (1 << PE5)                //方向输出

/*ds1302命令与相关地址*/
#define ds1302_sec_add			0x80		//秒数据地址
#define ds1302_min_add			0x82		//分数据地址
#define ds1302_hr_add			0x84		//时数据地址
#define ds1302_date_add			0x86		//日数据地址
#define ds1302_month_add		0x88		//月数据地址
#define ds1302_day_add			0x8a		//星期数据地址
#define ds1302_year_add			0x8c		//年数据地址
#define ds1302_control_add		0x8e		//控制数据地址
#define ds1302_charger_add		0x90 					 
#define ds1302_clkburst_add		0xbe

void ds1302_write_byte(unsigned char addr, unsigned char d);
unsigned char ds1302_read_byte(unsigned char addr);
void ds1302_write_time(void);
void ds1302_read_time(void);
void ds1302_init(void);
void dayToChina(unsigned char day);
void displayDateTime(void);
