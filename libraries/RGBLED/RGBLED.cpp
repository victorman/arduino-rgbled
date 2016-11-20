#include "Arduino.h"
#include "RGBLED.h"

int redPin = 5;
int greenPin = 3;
int bluePin = 6;


LED::LED()
{
	_rpin = redPin;
	_gpin = greenPin;
	_bpin = bluePin;
	pinMode(_rpin,OUTPUT);
	pinMode(_gpin,OUTPUT);
	pinMode(_bpin,OUTPUT);
	_k = 0;
	_i = 0;
	cred = cgrn = cblu = ored = ogrn = oblu = nred = ngrn = nblu = 0;
	_last = millis();
	
}

void LED::updateLED()
{
  	long elapsed = millis() - _last;
  
	int t = constrain(elapsed,0,FADERATE);
    cred = map(t,0,FADERATE,ored,nred);
    cgrn = map(t,0,FADERATE,ogrn,ngrn);
    cblu = map(t,0,FADERATE,oblu,nblu);
	
	analogWrite(_rpin,cred);
	analogWrite(_gpin,cgrn);
	analogWrite(_bpin,cblu);
	
  //hoping to take a second to fade and hold on that color for 1 second
    if(elapsed >= FADERATE) {
		ored = nred;
		ogrn = ngrn;
		oblu = nblu;
		int i = _i%_k;
		nred = _colors[i][0];
		ngrn = _colors[i][1];
		nblu = _colors[i][2];
    	_i++;
    	_last = millis();
	}
}

void LED::changeToRGB(int r, int g, int b)
{
	cred = constrain(r,0,255);
	cgrn = constrain(g,0,255);
	cblu = constrain(b,0,255);
}

void LED::subtractRGB(int r, int g, int b)
{
	cred = constrain(cred - r,0,255);
	cgrn = constrain(cgrn - g,0,255);
	cblu = constrain(cblu - b,0,255);
}

void LED::setR(int r)
{
	ored = cred;
	cred = r;
}

void LED::setG(int g)
{
	ogrn = cgrn;
	cgrn = g;
}

void LED::setB(int b)
{
	oblu = cblu;
	cblu = b;
}

void LED::addRGB(int r, int g, int b)
{
	if(_k < 10) {
		_colors[_k][0] = r;
		_colors[_k][1] = g;
		_colors[_k][2] = b;
		_k++;
	}
}
