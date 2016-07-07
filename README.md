# Arduino_Perceptron
Un perceptrón programado para aprendiaje mecánico en Arduino

Ussage:

1. Create object class perceptron, e.g. perceptron p1(number of inputs);
2. Randomize weights,  p1.randomize();
3. In loop update inputs e.g. p1.inputs[0] = analogRead...; p1.inputs[2] = analogRead...
4. Make a guess store in a variable e.g. float guess = p1.feedForward();
5. Train: compared obtained (guess) with some desired e.g. p1.train(desired, obtained);

MIT License

Copyright (c) 2016 Tomas de-Camino-Beck

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
