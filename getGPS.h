#ifndef _getGPS_h
#define _getGPS_h

#include "GPS/TinyGPSplus.h"

#define MAX_TRY_GPS 100000

bool getGPS(double* GPSData);

#endif