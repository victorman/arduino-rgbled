#ifndef RGBLED_h
#define RGBLED_h

/*
	library defines LED object
	which can store up to MAX_COLORS and fades between each color
	once every second. The pattern repeats endlessly.
	a call to led.updateLED() recolors the led appropriately.

*/

#include "Arduino.h"

const int MAX_COLORS = 10;
float const FADERATE = 1000.0; // change colors over 1000 ms or 1 s

class LED
{
  public:
    LED();
    void updateLED();
	void changeToRGB(int r, int g, int b);
	void subtractRGB(int r, int g, int b);
	void setR(int r);
	void setG(int g);
	void setB(int b);
	void addRGB(int r, int g, int b);
  private:
    int _rpin;
	int _gpin;
	int _bpin;
	int cred;
	int cgrn;
	int cblu;
	int ored;
	int ogrn;
	int oblu;
	int nred;
	int ngrn;
	int nblu;
	int _i;
	long _elapsed;
	unsigned long _last;
	
	int _k;
	int _colors[MAX_COLORS][3];
};

#endif