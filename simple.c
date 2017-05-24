//using encoding UTF-8

/************************************************
 *eepromRW模块
 *对eeprom进行读写操作。
************************************************/
void eepromRWInit(){//初始化
    eepromRWFeedback();
}
void eepromRWFeedback(){//simple function
    feedback.eepromRW = 1;
}
/***********************************************
 *以下为操作函数
 *eepromRead()函数为读取函数，argument[address,*outport,readBytes];
 *eepromWrite()函数为写入函数，argument[address,*import,writeBytes]；
***********************************************/
void eepromRead(unsigned char addr, unsigned char *outport, unsigned char readBytes){
    for(unsigned char i = 0; i < readBytes; i++){
        *(outport+i) = eeprom_read(addr);
        addr++;
    }
}

void eepromWrite(unsigned char addr, unsigned char *import, unsigned char writeBytes){
    for(unsigned char i = 0; i < writeBytes; i++){
        eeprom_write(addr, *(import _ i));
        addr++;
        while(WR);
    }
}