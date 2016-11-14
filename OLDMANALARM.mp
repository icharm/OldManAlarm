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
                           idata   0207   022F =    559. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0207  __idata_start
       0436  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   0436   1A1E =   6686. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       021B  __text_start
       021B  __start
       023D  _exit
       023E  _welcomeDisplay
       0252  _syn7318InitDisplay
       0266  _init_devices
       0278  _main
       037C  _ds1302_write_byte
       039E  _ds1302_read_byte
       03C3  _ds1302_write_time
       03E8  _ds1302_read_time
       0410  _ds1302_init
       0415  _dayToChina
       044A  _displayDateTime
       0532  _Timetostr
       059C  _DS18B20_Reset
       05B6  _DS18B20_Read_byte
       05D0  _ds1820_write_byte
       05E8  _ds1820_start
       05ED  _DS18B20_Read_temp
       062F  _data_do
       0655  _LCD_write_temperature
       069F  _Temperaturetostr
       06D0  _delay_1us
       06D7  _delay_3us
       06ED  _delay_10us
       06F0  _delay_50us
       06F4  _delay_100us
       06F6  _delay_n100us
       0701  _delay_1ms
       070B  _delay_nms
       071A  _system_init
       0733  _LCD_write_com
       0750  _LCD_write_data
       076D  _LCD_write_char
       0783  _LCD_clear
       0789  _DisplayCgrom
       07A3  _LCD_init
       07C0  _UART0_Init
       07D1  _puts0
       07ED  _uart0_rx_isr
       080D  _UART1_Init
       0822  _puts1
       0851  _uart1_rx_isr
       0872  _SYN7318_init
       0884  _buildHead
       0896  _checkSendReturn
       090F  _voicePlayer
       0955  _SYN7318_welcome
       095E  _SYN7318_Error
       0967  _setVoiceLevel
       0986  _setVoiceOption
       09B1  _updateWords
       0A1B  _waitFree
       0A3A  _startRecognition
       0A57  _wifi_Restart
       0A65  _wifi_ConnectSTA
       0A73  _wifi_CIPMUX
       0A81  _wifi_TCPConnect
       0A8F  _wifi_CIPMODE
       0A9D  _wifi_CIPSEND
       0AAB  _wifi_SendMsg
       0AB9  _wifi_SENDMSG
       0AC9  _strcat
       0AD6  _strcpy
       0ADF  _strlen
       0AEB  push_arg4
       0AED  push_arg2
       0AF0  mod16u
       0AF2  div16u
       0AF3  xdiv16u
       0B0C  elpm32
       0B20  pop_xgsetF0FC
       0B2B  push_xgsetF0FC
       0B2D  push_xgset30FC
       0B2F  push_xgset00FC
       0B31  push_xgset003C
       0B36  push_xgset300C
       0B3B  pop_xgset300C
       0B40  push_xgsetF000
       0B45  pop_xgsetF000
       0B4A  push_xgsetF00C
       0B51  pop_xgsetF00C
       0B58  push_xgset303C
       0B5F  pop_xgset303C
       0B66  push_xgsetF03C
       0B6F  pop_xgsetF03C
       0B78  xicallx
       0B81  neg32
       0B8A  asgnblk
       0BA2  fpint
       0BD4  uint2fp
       0BD6  int2fp
       0BDF  ulong2fp
       0BE1  long2fp
       0BF8  unpacks
       0C00  tstR16_R19
       0C08  unpacku
       0C21  normalize_and_pack
       0C56  pack
       0C66  saveFPRegs
       0C75  restoreFPRegs
       0C84  fpmule
       0CD7  fpmule2
       0CE2  _itoa
       0D4D  _utoa
       0D8D  _islower
       0D97  _toupper
       0DAA  __print
       0EF7  __sdepi
       0F01  _sprintf
       0F2A  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0100   022F =    559. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0100  __data_start
       0173  _time_buf
       01BD  _words
       020B  _wordID
       032F  __data_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             bss   032F   024C =    588. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       032F  __bss_start
       032F  _A3
       0331  _A2
       0333  _A1
       0335  _temp_value
       0337  _RxBufRd_wifi
       0338  _RxBufWr_wifi
       0339  _RxCharNum_wifi
       033A  _RxCharBuf_wifi
       034A  _TxStrLen_wifi
       034B  _TxCharNum_wifi
       034C  _TxCharBuf_wifi
       03CC  _RxBufRd
       03CD  _RxBufWr
       03CE  _RxCharNum
       03CF  _RxCharBuf
       03DF  _TxStrLen
       03E0  _TxCharNum
       03E1  _TxCharBuf
       0461  _tmp_text
       057B  __bss_end

Area                               Start  End    Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                          vector   0000   007C =    124. bytes (abs,ovr,rom)

Files Linked      [ module(s) ]

F:\ICCAVR\lib\crtatmega.o	[ crtatmega.s ]
main.o	[ main.c ]
12864time.o	[ _12864time.c ]
DS18B20.o	[ DS18B20.C ]
basic.o	[ basic.c ]
LCD.o	[ LCD.c ]
USART.o	[ USART.c ]
SYN7318.o	[ SYN7318.c ]
ESP8266.o	[ ESP8266.c ]
<library>	[ strcat.s, strcpy.s, strlen.s, asave.s, div16u.s, elpm32.s, gpop5.s, gpush.s, gpushx.s, gpushy.s, gpushz.s ]
[ gpusha.s, gpushb.s, icallx.s, lneg.s, struct.s, fpint.s, int2fp.s, fputil.s, fpmule.s, fpmule2.s, itoa.s ]
[ utoa.s, islower.s, ctype.s, toupper.s, _printf.s, sprintf.s ]

User Global Definitions

ram_end = 0x10ff
hwstk_size = 0x1e

User Base Address Definitions

func_lit = 0x8c
data = 0x100
eeprom:0.4096

