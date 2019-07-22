#include "mbed.h"
#include "getGPS.h"

//PCとシリアル通信
Serial pc(USBTX, USBRX);

int main(){

    pc.baud(9600);
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
        } else{
            pc.printf("値取れなかった！ごめんて〜\r\n");
        }
        wait_ms(50);
    }

}