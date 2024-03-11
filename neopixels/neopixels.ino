#include <Adafruit_NeoPixel.h>

const int NI = 4;
const int numberOfPixels = 3;
Adafruit_NeoPixel ledstrip = Adafruit_NeoPixel(numberOfPixels, NI);


void setup() {
  ledstrip.begin();

}

void loop() {
  customLight();

}

void customLight() {
  setLightsToColor(250, 0, 0);
}

void setLightsToColor(int red, int green, int blue) {
  for (uint8_t i = 0; i < numberOfPixels; i++) {
    ledstrip.setPixelColor(i, ledstrip.Color(red, green, blue));
  }
  ledstrip.show();
}
