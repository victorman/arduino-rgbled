#include <RGBLED.h>

/*
base board layout from: https://learn.adafruit.com/rgb-led-strips/usage

TODO:
- fade colors in a ∩ pattern
- fade colors in a U pattern
- have lights flash in random patterns
- flicker like as if for a horror movie
- emulate fire
*/


unsigned long last;
long startTransitionTime;

LED led;

void setup()
{
  randomSeed(157);
  
  led.addRGB(255, 255, 0);
  led.addRGB(255, 0, 0);
  led.addRGB(80,0,80);
  led.addRGB(0,255,255);
  last = millis();  
}
 
void loop()
{
  
  
  led.updateLED();
  
}
