NOTE: AVR Code addresses are word addresses
All other addresses (including ones in FLASH) are byte addresses

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                        func_lit   008C   0002 =      2. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       008C  __func_lit_start
       008E  __func_lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             lit   008E   0179 =    377. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       008E  __lit_start
       0092  __ctype
       0207  __lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                           idata   0207   0205 =    517. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0207  __idata_start
       040C  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   040C   1844 =   6212. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0206  __start
       0206  __text_start
       0228  _exit
       0229  _welcomeDisplay
       023D  _syn7318InitDisplay
       0251  _init_devices
       0263  _main
       033F  _ds1302_write_byte
       0361  _ds1302_read_byte
       0386  _ds1302_write_time
       03AF  _ds1302_read_time
       03D7  _ds1302_init
       03DC  _dayToChina
       0411  _displayDateTime
       04F9  _DS18B20_Reset
       0513  _DS18B20_Read_byte
       052D  _ds1820_write_byte
       0545  _ds1820_start
       054A  _DS18B20_Read_temp
       058C  _data_do
       05B2  _LCD_write_temperature
       05FC  _delay_1us
       0603  _delay_3us
       0619  _delay_10us
       061C  _delay_50us
       0620  _delay_100us
       0622  _delay_n100us
       062D  _delay_1ms
       0637  _delay_nms
       0646  _system_init
       065F  _LCD_write_com
       067C  _LCD_write_data
       0699  _LCD_write_char
       06AF  _LCD_clear
       06B5  _DisplayCgrom
       06CF  _LCD_init
       06EC  _UART0_Init
       06FD  _puts0
       0719  _uart0_rx_isr
       0739  _UART1_Init
       074E  _puts1
       077D  _uart1_rx_isr
       079E  _SYN7318_init
       07B0  _buildHead
       07C2  _checkSendReturn
       083B  _voicePlayer
       0881  _SYN7318_welcome
       088A  _SYN7318_Error
       0893  _setVoiceLevel
       08B2  _setVoiceOption
       08DD  _updateWords
       0947  _waitFree
       0966  _startRecognition
       0983  _wifi_Restart
       0991  _wifi_ConnectSTA
       099F  _wifi_CIPMUX
       09AD  _wifi_TCPConnect
       09BB  _wifi_CIPMODE
       09C9  _wifi_CIPSEND
       09D7  _wifi_SendMsg
       09E5  _wifi_SENDMSG
       09F5  _strlen
       0A01  push_arg4
       0A03  push_arg2
       0A06  mod16u
       0A08  div16u
       0A09  xdiv16u
       0A22  elpm32
       0A36  pop_xgsetF0FC
       0A41  push_xgsetF0FC
       0A43  push_xgset30FC
       0A45  push_xgset00FC
       0A47  push_xgset003C
       0A4C  push_xgset300C
       0A51  pop_xgset300C
       0A56  push_xgsetF000
       0A5B  pop_xgsetF000
       0A60  push_xgsetF00C
       0A67  pop_xgsetF00C
       0A6E  push_xgset303C
       0A75  pop_xgset303C
       0A7C  push_xgsetF03C
       0A85  pop_xgsetF03C
       0A8E  xicallx
       0A97  neg32
       0AA0  fpint
       0AD2  uint2fp
       0AD4  int2fp
       0ADD  ulong2fp
       0ADF  long2fp
       0AF6  unpacks
       0AFE  tstR16_R19
       0B06  unpacku
       0B1F  normalize_and_pack
       0B54  pack
       0B64  saveFPRegs
       0B73  restoreFPRegs
       0B82  fpmule
       0BD5  fpmule2
       0BE0  _itoa
       0C4B  _utoa
       0C8B  _islower
       0C95  _toupper
       0CA8  __print
       0DF5  __sdepi
       0DFF  _sprintf
       0E28  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0100   0205 =    517. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0100  __data_start
       016E  _time_buf
       019C  _words
       01E1  _wordID
       0305  __data_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             bss   0305   024E =    590. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0305  __bss_start
       0305  _A3
       0307  _A2
       0309  _A1
       030B  _temp
       030D  _temp_value
       030F  _RxBufRd_wifi
       0310  _RxBufWr_wifi
       0311  _RxCharNum_wifi
       0312  _RxCharBuf_wifi
       0322  _TxStrLen_wifi
       0323  _TxCharNum_wifi
       0324  _TxCharBuf_wifi
       03A4  _RxBufRd
       03A5  _RxBufWr
       03A6  _RxCharNum
       03A7  _RxCharBuf
       03B7  _TxStrLen
       03B8  _TxCharNum
       03B9  _TxCharBuf
       0439  _tmp_text
       0553  __bss_end

Area                               Start  End    Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                          vector   0000   007C =    124. bytes (abs,ovr,rom)

Files Linked      [ module(s) ]

D:\iccv7avr\lib\crtatmega.o	[ crtatmega.s ]
main.o	[ main.c ]
12864time.o	[ _12864time.c ]
DS18B20.o	[ DS18B20.C ]
basic.o	[ basic.c ]
LCD.o	[ LCD.c ]
USART.o	[ USART.c ]
SYN7318.o	[ SYN7318.c ]
ESP8266.o	[ ESP8266.c ]
<library>	[ strlen.s, asave.s, div16u.s, elpm32.s, gpop5.s, gpush.s, gpushx.s, gpushy.s, gpushz.s, gpusha.s, gpushb.s ]
[ icallx.s, lneg.s, fpint.s, int2fp.s, fputil.s, fpmule.s, fpmule2.s, itoa.s, utoa.s, islower.s, ctype.s ]
[ toupper.s, _printf.s, sprintf.s ]

User Global Definitions

ram_end = 0x10ff
hwstk_size = 0x1e

User Base Address Definitions

func_lit = 0x8c
data = 0x100
eeprom:0.4096

