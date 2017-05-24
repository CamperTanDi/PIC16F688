//using encoding UTF-8

/**********************************************
 *config.
 *用于配置位、需要保持的参数修改或参照。
 *可以通过拆解函数释放内存。
***********************************************/
/**********************************************
 *uartConfig()
 *用于配置uart通信，与RS232，RS485有关。
**********************************************/
void uartConfig(unsigned char asyn, unsigned char baud,unsigned char status){
    
    RX9 = 0;                        //允许8位接收数据
    TX9 = 0;                        //允许8位发送数据
    FERR = 0;                       //没有帧错误
    OERR = 0;                       //没有溢出错误
    TRMT = 0;

    SPBRG = (unsigned char)arg;     //arg需要处理才能应用
    SPBRGH = (unsigned char)(arg >> 8);//并且只影响RS232通信

    if(asyn == asyn){
        SYNC = 0;
        if(baud == high){
            BRGH = 1;
            BRG16 = 1;
        }
    }
    else{
        SYNC = 1;
    }
    if(status == send){
        CREN = 1;
        SPEN = 0;
        TXEN = 0;
        TRMT = 0;
    }
}