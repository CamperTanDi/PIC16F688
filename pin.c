//using encoding UTF-8.

/******************************************
 *pin文件，用于定义引脚及引脚输出操作
*****************************************/

#define choose          RA2
#define choosen         TRISA2

#define IO_BS1          RA0
#define IO_BS_EN        TRISA0
#define IO_BS2          RA1
#define IO_BS2_EN       TRISA1

#define SHT10_SDA       RC2
#define SHT10_SDAEN     TRISC2
#define SHT10_SCL       RC3
#define SHT10_SCLEN     TRISC3

void pinInit(){
     if(time == 0){
         feedback.pin = 1
     }
}
//希望能够将引脚操作写成函数
/*******************************************
 *pinHandle()函数
 *用于操作引脚。
 *argument：pin引脚号，引脚操作数组。
*******************************************/
void pinHandle(unsigned char pin, ){

}