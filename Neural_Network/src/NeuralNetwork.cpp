#include "NeuralNetwork.h"
#include <iostream>

void NeuralNetwork::setInputLayer(int size) {
    if (size <= 0) {
        std::cout << "Error: Input layer size must be greater than 0!" << std::endl;
        return;
    }
    inputLayer.resize(size);
    std::cout << "Enter values for the input layer: ";
    for (int i = 0; i < size; ++i) {
        std::cin >> inputLayer[i];
    }
}

void NeuralNetwork::setHiddenLayers(int numLayers, const std::vector<int>& layerSizes) {
    if (numLayers <= 0) {
        std::cout << "Error: Number of hidden layers must be greater than 0!" << std::endl;
        return;
    }
    hiddenLayers.resize(numLayers);
    for (int i = 0; i < numLayers; ++i) {
        if (layerSizes[i] <= 0) {
            std::cout << "Error: Hidden layer size must be greater than 0!" << std::endl;
            return;
        }
        hiddenLayers[i].resize(layerSizes[i]);
    }
}

void NeuralNetwork::setOutputLayer(int size) {
    if (size <= 0) {
        std::cout << "Error: Output layer size must be greater than 0!" << std::endl;
        return;
    }
    outputLayer.resize(size);
}

void NeuralNetwork::setActivationFunctions(const std::vector<int>& choices) {
    activationFunctionChoices = choices;
}

void NeuralNetwork::forwardPropagation() {
    std::vector<double> previousLayerOutput = inputLayer;

    for (size_t layerIndex = 0; layerIndex < hiddenLayers.size(); ++layerIndex) {
        for (size_t neuronIndex = 0; neuronIndex < hiddenLayers[layerIndex].size(); ++neuronIndex) {
            double value = previousLayerOutput[neuronIndex];

            switch (activationFunctionChoices[layerIndex]) {
                case 1:
                    hiddenLayers[layerIndex][neuronIndex] = ActivationFunctions::identity(value);
                    break;
                case 2:
                    hiddenLayers[layerIndex][neuronIndex] = ActivationFunctions::binaryStep(value);
                    break;
                case 3:
                    hiddenLayers[layerIndex][neuronIndex] = ActivationFunctions::bipolarStep(value);
                    break;
                case 4:
                    hiddenLayers[layerIndex][neuronIndex] = ActivationFunctions::binarySigmoid(value);
                    break;
                case 5:
                    hiddenLayers[layerIndex][neuronIndex] = ActivationFunctions::ramp(value);
                    break;
                default:
                    hiddenLayers[layerIndex][neuronIndex] = value;
                    break;
            }
        }
        previousLayerOutput = hiddenLayers[layerIndex];
    }

    // Set the final output layer values
    for (size_t neuronIndex = 0; neuronIndex < outputLayer.size(); ++neuronIndex) {
        outputLayer[neuronIndex] = previousLayerOutput[neuronIndex];
    }
}

void NeuralNetwork::displayOutput() {
    std::cout << "\n=== Final Output Layer Values ===" << std::endl;
    for (const auto& value : outputLayer) {
        std::cout <<" " << value << " ";
    }
    std::cout << "\n================================" << std::endl;
}

void NeuralNetwork::displayNetworkStructure() {
    std::cout << "\n=== Neural Network Structure ===" << std::endl;
    std::cout << "Input Layer (" << inputLayer.size() << " Neurons)" << std::endl;

    for (size_t i = 0; i < hiddenLayers.size(); ++i) {
        std::cout << "Hidden Layer " << i + 1 << " (" << hiddenLayers[i].size() << " Neurons)" << std::endl;
    }

    std::cout << "Output Layer (" << outputLayer.size() << " Neurons)" << std::endl;
    std::cout << "==================================" << std::endl;
}
