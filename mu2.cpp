/**
*@author TakedaShinji
*@dateで2019/07/01
**/

/**
*引数の文字列を一回だけ送信する関数
*@param (送りたい文字列, グループID，チャンネル, 目的局ID )グループID,チャンネル，目的局IDは2桁の文字列
*@return なし
*@todo 送信出力をいじるかどうか
**/

#include "mbed.h"
#include "mu2.h"

void transmitMU2(char* transmitdata, char* group_id, char* channel, char* dest_id){

    uint8_t last_data[] = {0x0d, 0x0a};

    Serial MU2Serial(p13, p14);    
    MU2Serial.enable_input(true);
    MU2Serial.enable_output(true);
    MU2Serial.baud(19200);

    //GI設定
    MU2Serial.printf("@GI%s", group_id);
    for (int i = 0; i < 2; i++){  
        MU2Serial.putc(last_data[i]);
    }
    
    //CH設定
    MU2Serial.printf("@CH%s", channel);
    for (int i = 0; i < 2; i++){  
        MU2Serial.putc(last_data[i]);
    }

    //DI(目的局ID)設定
    MU2Serial.printf("@DI%s", dest_id);
    for (int i = 0; i < 2; i++){  
        MU2Serial.putc(last_data[i]);
    }

    //送りたい文字のバイト数を数える
    int mojisuu = strlen(transmitdata);
    MU2Serial.printf("@DT%02x", mojisuu);      
    MU2Serial.printf("%s", transmitdata);
    for (int i = 0; i < 2; i++){  
        MU2Serial.putc(last_data[i]);
    }
    MU2Serial.enable_input(false);
    MU2Serial.enable_output(false);

}
