//using encoding UTF-8

/******************************************
 *SHT通信程序
******************************************/

#define DATA           RC2
#define DATAEN         TRISC2
#define SCK           RC3
#define SCKEN         TRISC3

#define DATA_OUT     DATAEN = 0
#define DATA_IN      DATAEN = 1
#define SCK_OUT     SCKEN = 0
#define SCK_IN      SCKEN = 1


void shtInit(){
    if(time == 0){
        feedback.SHTsensor = 1
    }
}

/*
＿︱￣︱＿︱￣︱＿︱￣︱＿︱￣︱＿︱￣︱＿
*/

#define halfCycle       asm("nop"); asm("nop"); asm("nop"); asm("nop"); asm("nop");
//SCK的半个波长(halfWavelength) = 5 * nop


void transmissionStart(){
/*************************************
 *启动传输
 *SCK 	    ＿︱￣￣︱＿︱￣￣︱＿
 *DATA		￣￣︱＿＿＿＿＿︱￣￣
**************************************/
    SCK = 0; halfCycle;
    DATA = 1; halfCycle;
    SCK = 1; halfCycle;
    DATA = 0; halfCycle;
    SCK = 0; halfCycle;
    SCK = 1; halfCycle;
    DATA = 1; halfCycle;
    SCK = 0; halfCycle;
}

void resetTransmission(){
/*************************************
 *通信复位  SCK至少9个周期中DATA保持1，然后进入transmissionStart()
 *SCK 	    ＿︱￣︱＿︱￣︱＿︱￣︱＿︱￣︱＿︱￣￣︱＿︱￣￣︱＿
 *DATA		￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣︱＿＿＿＿＿︱￣￣
**************************************/
    for(unsigned char i = 0; i <= 9; i++){
        DATA = 1;
        SCK = 1; halfCycle;
        SCK = 0; halfCycle;
    }
    transmissionStart();
}

void sendOrder(char Order){
/**************************************
 *传输命令函数
 *函数输入参数为命令名，函数自带命令对应二进制码
 *
**************************************/
    if(Order[] = "T"){
//‘00000011’表示温度T

    }
    if(Order[] = "H"){
//‘00000101’表示相对湿度RH
    }
    
}

void sendDataBin(char sendDataBin[8]){
    char dataBin[] = sendDataBin[];//[0,0,0,0,0,1,0,1]
    unsigned char sensorStatus;
    DATA_OUT;
    for(char i = 0; i < 8; i++){
        DATA = dataBin[i]; 
        SCK = 1; halfCycle; 
        SCK = 0; halfCycle;
    }
    //等待SHT10返回确认位
    DATA_IN;
    SCK = 1; halfCycle;
    if(DATA){
        SCK = 0; halfCycle;
        return error;
    }
    else{
        sensorStatus = 1;
        SCK = 0; halfCycle;
    }
    SCK = 0; halfCycle;
}

void dataPreparation(){
/*SHT10测量结束后的“数据备妥”信号判断
 *如果接收到数据备妥信号则返回1；
 *                  否则返回0。
 */
    DATA_IN;
    if(sensorStatus){
        if(DATA){
            return 0;
        }
        else{
            return 1;
        }
    }
    else{
        return error;
    }
}

void reciveDataBin(char *reciveDataBin){
/*接收函数
 *参数为写入接受值的地址
 *注意只允许8bit数据
 */
    char dataBin = 0;
    char clock;
    DATA_IN;
    DATA = 1;
    for(unsigned char i = 0; i < 8; i++){
        SCK = 1; halfCycle;
        dataBin <<= 1;
        if(DATA){
            dataBin |= 1;
        }
        SCK = 0; halfCycle;
    }
//接收完毕输出ACK标志位
    DATA_OUT;
    DATA = 0;
    SCK = 1; halfCycle;
    SCK = 0; halfCycle;
    DATA = 1;//恢复DATA线高电平
    *reciveDataBin = dataBin;
    return dataBin;
}
