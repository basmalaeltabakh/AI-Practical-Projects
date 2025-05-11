#include <iostream>
#include <vector>
#include <limits>
#include "NeuralNetwork.h"

int getPositiveInput(const std::string& prompt) {
    int input;
    while (true) {
        std::cout << prompt;
        std::cin >> input;


        if (std::cin.fail() || input <= 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Please enter a positive number.\n";
        } else {
            return input;
        }
    }
}

int main() {
    NeuralNetwork nn;

    int inputSize, numHiddenLayers, outputSize;

    std::cout << "\n==============================\n";
    std::cout << "     Neural Network Setup    \n";
    std::cout << "==============================\n\n";

    inputSize = getPositiveInput("Enter the size of the Input Layer: ");
    nn.setInputLayer(inputSize);


    numHiddenLayers = getPositiveInput("Enter the number of Hidden Layers: ");

    std::vector<int> layerSizes(numHiddenLayers);
    std::vector<int> activationChoices(numHiddenLayers);

    for (int i = 0; i < numHiddenLayers; ++i) {
        layerSizes[i] = getPositiveInput("Enter the size of Hidden Layer " + std::to_string(i + 1) + ": ");


        while (true) {
            std::cout << "Select Activation Function for Hidden Layer " << i + 1 << ":\n";
            std::cout << "1: Identity\n2: Binary Step\n3: Bipolar Step\n4: Binary Sigmoid\n5: Ramp\n";
            std::cout << "Your choice: ";
            std::cin >> activationChoices[i];

            if (activationChoices[i] >= 1 && activationChoices[i] <= 5) {
                break;
            } else {
                std::cout << "Invalid choice! Please choose between 1 and 5.\n";
            }
        }
    }

    nn.setHiddenLayers(numHiddenLayers, layerSizes);
    nn.setActivationFunctions(activationChoices);

    outputSize = getPositiveInput("Enter the size of the Output Layer: ");
    nn.setOutputLayer(outputSize);

    nn.displayNetworkStructure();

    nn.forwardPropagation();


    nn.displayOutput();

    return 0;
}
