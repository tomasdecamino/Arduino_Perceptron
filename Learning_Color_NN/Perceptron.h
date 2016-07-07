/*Tomas de Camino Beck
Class Perceptron for machine learning

Ussage:
1.Create object class perceptron, e.g. perceptron p1(number of inputs)
2. Randomize weights,  p1.randomize();
3. In loop update inputs e.g. p1.inputs[0] = analogRead...; p1.inputs[2] = analogRead...
4. Make a guess store in variable e.g. float guess = p1.feedForward();
5. Train compared obtained with some desired e.g. p1.train(desired, obtained);

Made for teaching poruposes www.funcostarica.org
*/
//**************Class perceptron*************
class perceptron
{

    const float c = 0.008;//constante de aprendizaje

  public:
    //arrays that hold inputs and weights
    float* inputs;
    float* weights;
    int n; //numero de entradas

    perceptron(int ninputs) {
      n = ninputs;
      inputs = new float[n];
      weights = new float[n];
      inputs[n - 1] = 1;//bias
      for (int i = 0; i < n; i++) {
        // The weights are picked randomly to start.
        //a trick to get values from -1 to 1
        weights[i] = (float)random(-1000, 1000) / 1000;
      }
    }

    //reset weights to random values
    void randomize() {
      for (int i = 0; i < n; i++) {
        // The weights are picked randomly to start.
        weights[i] = (float)random(-1000, 1000) / 1000;
      }
    }

    //training function
    void train(int desired, float guess) {
      float error = desired - guess;
      for (int i = 0; i < n; i++) {
        weights[i] += c * error * inputs[i];
      }
    }

    //forward function
    float feedForward() {
      float sum = 0;
      for (int i = 0; i < n; i++) {
        sum += inputs[i] * weights[i];
      }

      return activate(sum);
    }


   float weightedSum() {
      float sum = 0;
      for (int i = 0; i < n; i++) {
        sum += inputs[i] * weights[i];
      }

      return sum;
    }


  private:
    //activation function
    int activate(float sum) {
      //regresa 1 si es positivo, -1 si negativo.
      if (sum > 0) {
        return 1;
      }
      else {
        return -1;
      }
    }



};
