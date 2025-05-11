#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

#include <vector>
#include <iostream>
#include "ActivationFunctions.h"

class NeuralNetwork {
private:
    std::vector<double> inputLayer;  // تعديل إلى double
    std::vector<std::vector<double>> hiddenLayers;
    std::vector<double> outputLayer;
    std::vector<int> activationFunctionChoices;

public:
    void setInputLayer(int size);
    void setHiddenLayers(int numLayers, const std::vector<int>& layerSizes);
    void setOutputLayer(int size);
    void setActivationFunctions(const std::vector<int>& choices);
    void forwardPropagation();
    void displayOutput();
    void displayNetworkStructure();
};

#endif // NEURAL_NETWORK_H
