//Tomas de camino Beck

#include "Perceptron.h"
#include <Wire.h>
#include "Adafruit_TCS34725.h"

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

uint16_t clear, red, green, blue ;

//we will use one perceptron with 3 inputs (Red, green, blue)
perceptron colorPerceptron(4);//fourth is for bias

void setup() {

  tcs.begin();

  randomSeed(A0);
  colorPerceptron.randomize();//weight initialization

  pinMode(12, OUTPUT);//TCS LED
  digitalWrite(12, HIGH);
  //Leds red and green
  //They are not necesary if you are using serial
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);


  pinMode(10, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  /*** read from the sensor**/
  tcs.setInterrupt(false);
  delay(60);
  tcs.getRawData(&red, &green, &blue, &clear);
  tcs.setInterrupt(true);
  
  //convert then in values from 0 to 255
  uint32_t sum = clear;
  float r, g, b;
  r = red; r /= sum;
  g = green; g /= sum;
  b = blue; b /= sum;
  r *= 256; g *= 256; b *= 256;

  /*** store in perceptron inputs ***/
  colorPerceptron.inputs[0] = r;
  colorPerceptron.inputs[1] = g;
  colorPerceptron.inputs[2] = b;

  float guess = colorPerceptron.feedForward();

  if (digitalRead(10) == 0) {
    digitalWrite(12, LOW);
    colorPerceptron.train(1, guess);
    delay(1000);
    digitalWrite(12, HIGH);
  }

  if (digitalRead(9) == 0) {
    digitalWrite(12, LOW);
    colorPerceptron.train(-1, guess);
    delay(1000);
    digitalWrite(12, HIGH);
  }

  //  Serial.print(colorPerceptron.inputs[0]); Serial.print(",");
  //  Serial.print(colorPerceptron.inputs[1]); Serial.print(",");
  //  Serial.print(colorPerceptron.inputs[2]); Serial.print(",");
  //  Serial.println(guess);

  if (guess == 1) {
    Serial.println("Match");
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
  }
  else {
    Serial.println("No Match");
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
  }
}
