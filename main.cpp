#include "mbed.h"
#include <string.h>
#include <stdio.h>

#include "getGPS.h"
#include "mu2.h"

//PCとシリアル通信
Serial pc(USBTX, USBRX);

int main(){

    pc.printf("GPSの値取ってみるよ〜〜〜\r\n");

    while(1){

        //GPS値初期化
        double GPSData[3] = {0, 0, 0};

        //GPS値取得
        bool GPSStatus = false;
        GPSStatus = getGPS(GPSData);

        //エラー判定
        if (GPSStatus){
            pc.printf("値取れたで！取れたてや！\r\n");
            pc.printf("緯度: %f\r\n", GPSData[0]);
            pc.printf("経度: %f\r\n", GPSData[1]);
            pc.printf("時間: %f\r\n", GPSData[2]);

            char lat[24];
            snprintf(lat, 24, "%f", GPSData[0]);

            pc.printf("mu2で送信するで〜！\r\n");
            char message[] = "latitude: ";
            strcat(message, lat);
            char groupID[] = "01";
            char channel[] = "09";
            char ID[] = "02";
            transmitMU2(message, groupID, channel, ID);
            pc.printf("送ったで！確認してみてや〜！\r\n");

        } else {
            pc.printf("値取れなかった！ごめんて〜\r\n");
        }
        wait_ms(100);
    }

}