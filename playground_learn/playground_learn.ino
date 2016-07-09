//Tomas de camino Beck
//www.funcostarica.org


#include "Perceptron.h"
#include <Wire.h>
#include <Adafruit_CircuitPlayground.h>


//we will use one perceptron with 3 inputs (Red, green, blue)
perceptron colorPerceptron(4);//fourth is for bias

void setup() {

  randomSeed(CircuitPlayground.readCap(3));
  colorPerceptron.randomize();//weight initialization
  CircuitPlayground.begin();


  CircuitPlayground.clearPixels();

  Serial.begin(9600);
}

void loop() {
  float accX, accY, accZ;
  /*** read from the sensor**/
  accX = CircuitPlayground.motionZ();
  accY = CircuitPlayground.motionZ();
  accZ = CircuitPlayground.motionZ();

  /*** store in perceptron inputs ***/
  colorPerceptron.inputs[0] = accX;
  colorPerceptron.inputs[1] = accY;
  colorPerceptron.inputs[2] = accZ;

  //make a guess
  float guess = colorPerceptron.feedForward();

  //press button if guess incorrect
  if (CircuitPlayground.leftButton()) {
    digitalWrite(12, LOW);
    colorPerceptron.train(-guess, guess);
    delay(1000);
    digitalWrite(12, HIGH);
  }

  //  Serial.print(colorPerceptron.inputs[0]); Serial.print(",");
  //  Serial.print(colorPerceptron.inputs[1]); Serial.print(",");
  //  Serial.print(colorPerceptron.inputs[2]); Serial.print(",");
  //  Serial.println(guess);
  
  //change color
  uint32_t c;
  if (guess == 1) {
    c = CircuitPlayground.strip.Color(0, 255, 0);
    Serial.println("Match");
  }
  else {
    c = CircuitPlayground.strip.Color(255, 0, 0);
    Serial.println("No Match");

  }

  //update pixels
  for (int i = 0; i <= 9; i++) {
    CircuitPlayground.setPixelColor(i, c);
  }



  // CircuitPlayground.clearPixels();
}
