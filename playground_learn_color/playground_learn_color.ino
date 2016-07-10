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
  //Read color

  if (CircuitPlayground.lightSensor() <10) {
    CircuitPlayground.clearPixels();
    uint8_t red, green, blue;
    CircuitPlayground.senseColor(red, green, blue);

    /*** store in perceptron inputs ***/
    colorPerceptron.inputs[0] = red;
    colorPerceptron.inputs[1] = green;
    colorPerceptron.inputs[2] = blue;
  }
  //make a guess
  float guess = colorPerceptron.feedForward();

  //press button if guess incorrect
  if (CircuitPlayground.rightButton()) {
    CircuitPlayground.clearPixels();
    colorPerceptron.train(-guess, guess);
    delay(1000);
  }


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
  for (int i = 3; i <= 9; i++) {
    CircuitPlayground.setPixelColor(i, c);
  }



  // CircuitPlayground.clearPixels();
}
