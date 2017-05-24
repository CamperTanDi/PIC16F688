//using encoding UTF-8.




/*
 *主函数main()，time1函数，上电主动执行的第一个函数，完成以下行为：
 *1、检查所有函数模块；
 *2、确认time0情况；
 *3、保持运行；
 *4、向其他函数提供“正在运行”参数；
 */
bank2 volatile int time;
 }
bank2 volatile struct {
    char eepromRW;
    char pin;
    
}_feedback;
extern volatile _feedback feedback;



void main(){
    //review time0's status.
    time = 0;
    //init functions and read data in eeprom.
    eepromRWInit();
    //check every function aleady waiting for launch.
    time = 1;
    feedback();
    }
}



/********************************************************************
 *feedback函数
 *用于确认其他函数块在time0时的初始化情况。
********************************************************************/
void feedback(){
    if(feedback.eepromRW){
        
    }
    else{
        return error;
    }
}