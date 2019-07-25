#include "mbed.h"
#include "getGPS.h"
#include "GPS/TinyGPSplus.h"

bool getGPS(double* GPSData)
{
    Serial GPSSerial(p9, p10);
    GPSSerial.enable_input(true);
    GPSSerial.enable_output(true);
    GPSSerial.baud(9600);

    TinyGPSPlus gps;

    //MAX_TRY_GPS回だけ試行
    for (int i = 0; i < MAX_TRY_GPS; i++){

        //GPSとシリアル通信できているとき
        if (GPSSerial.readable()) {

            //シリアル通信読み取り
            char c = GPSSerial.getc();

            //うまくエンコードできているか
            bool GPSAvailable = gps.encode(c);
            if (GPSAvailable) {

                //場所，時間が更新されているか
                if (gps.location.isUpdated() && gps.time.isUpdated()){

                    //緯度経度，時間（UTC）を取得
                    GPSData[0] = gps.location.lat();
                    GPSData[1] = gps.location.lng();
                    GPSData[2] = (double)gps.time.value();

                    //うまく値取れればtrueを返す
                    GPSSerial.enable_input(false);
                    GPSSerial.enable_output(false);
                    
                    return true;

                }
            } 
        }
    }
    //うまく値取れなければfalseを返す
    GPSSerial.enable_input(false);
    GPSSerial.enable_output(false);
    return false;
}