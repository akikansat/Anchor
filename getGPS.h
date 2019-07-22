#ifndef _getGPS_h
#define _getGPS_h

#include "GPS/TinyGPSplus.h"

Serial GPSSerial(p9, p10);
TinyGPSPlus gps;

#define MAX_TRY_GPS 100000

bool getGPS(double* GPSData);

#endif