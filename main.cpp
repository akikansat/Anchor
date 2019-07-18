#include "mbed.h"
#include "GPS/tinyGPSplus.h"

//GPSとシリアル通信（TX=9，RX=10）
Serial GPSSerial(p9, p10);
TinyGPSPlus gps;

//PCとシリアル通信
Serial pc(USBTX, USBRX);

//グローバル変数定義
//GPS試行回数
#define MAX_TRY_GPS 100000


bool getGPS(double* GPSData)
{
    //MAX_TRY_GPS回だけ試行
    for (int i = 0; i < MAX_TRY_GPS; i++){
        //GPSとシリアル通信できているとき
        if (GPSSerial.readable()) {
            pc.printf("シリアル通信はきてる！\r\n");
            //シリアル通信読み取り
            char c = GPSSerial.getc();
            //うまくエンコードできているか
            bool GPSAvailable = gps.encode(c);
            if (GPSAvailable) {

                //
                GPSData[0] = 1;

                //うまく値取れればtrueを返す
                return true;
            } 
        }
    }
    //うまく値取れなければfalseを返す
    return false;
}


int main(){

    pc.baud(9600);
    pc.printf("GPSの値取ってみるよ〜〜〜\r\n");

    while(1){

        //GPS値初期化
        double GPSData[4] = {0, 0, 0, 0};

        //GPS値取得
        bool GPSStatus = false;
        GPSStatus = getGPS(GPSData);

        //エラー判定
        if (GPSStatus){
            pc.printf("値取れたで！取れたてや！\r\n");
            pc.printf("%f\n", GPSData[0]);
        } else{
            pc.printf("値取れなかった！ごめんて〜\r\n");
        }
        wait_ms(100);
    }

}

// #include "mbed.h"

// Serial gps(p9, p10);       // TX, RX
// Serial pc(USBTX, USBRX);    // TX, RX
// DigitalOut led1(LED1);

// int main() {
//     pc.baud(9600);
//     pc.printf("PA6C DEMO\n");
//     char gpsout[1024];
//     while (1) {
//         gpsout[0] = '\0';
//         while (1) {
//             char c = gps.getc();
//             char s[2];
//             s[0] = c;
//             s[1] = '\0';
//             strcat(gpsout, s);
//             if (c == '\n') {
//                 break;
//             }
//         }
//         pc.printf(gpsout);
//         led1 = !led1;
//     }
// }