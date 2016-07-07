# Arduino_Perceptron
Un perceptrón programado para aprendiaje mecánico en Arduino

Ussage:

1. Create object class perceptron, e.g. perceptron p1(number of inputs)
2. Randomize weights,  p1.randomize();
3. In loop update inputs e.g. p1.inputs[0] = analogRead...; p1.inputs[2] = analogRead...
4. Make a guess store in variable e.g. float guess = p1.feedForward();
5. Train compared obtained with some desired e.g. p1.train(desired, obtained);
