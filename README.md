# AI Practical Projects

This repository contains practical implementations of **Neural Networks** and **Knapsack Algorithms** in C++. The Neural Network project allows you to define the architecture of a neural network with customizable layers and activation functions. The Knapsack project includes two solutions for the Knapsack problem:
- **Fractional Knapsack**: A greedy algorithm that allows fractional parts of items.
- **0/1 Knapsack**: A greedy algorithm where items are either fully taken or not taken at all.

Both projects demonstrate practical AI and algorithmic concepts.

---

## Projects in this Repository

### 1. **Neural Network**

This project implements a basic neural network with:
- **Input Layer**: User defines the size and provides input values.
- **Hidden Layers**: Multiple hidden layers with customizable sizes and activation functions.
- **Output Layer**: The final output after forward propagation.
- **Activation Functions**: Supports the following functions:
  - Identity
  - Binary Step
  - Bipolar Step
  - Binary Sigmoid
  - Ramp

### 2. **Knapsack Algorithm**

This project implements two solutions for the Knapsack problem:
- **Fractional Knapsack**: The greedy approach where items can be taken fractionally.
- **0/1 Knapsack**: The greedy approach where items are either taken completely or not taken at all.

---

## Requirements

- **C++ Compiler**: A C++ compiler like `g++` or any C++ IDE should be sufficient to compile and run the code.
- **Operating System**: The code is cross-platform (works on Windows, macOS, and Linux).

---


## Usage

### Neural Network
1. **Input Layer**: The program prompts you to enter the size of the input layer and its values.
2. **Hidden Layers**: Define the number of hidden layers, set the size for each layer, and select the activation function for each hidden layer.
3. **Output Layer**: The program calculates the output based on forward propagation.
4. **Display**: After forward propagation, the structure of the network and the output values will be displayed.

### Knapsack Algorithm
1. **Fractional Knapsack**: The program calculates the maximum value achievable by filling the knapsack with fractional items.
2. **0/1 Knapsack**: The program calculates the maximum value by fully including or excluding each item in the knapsack.

---

## Example Outputs

### Neural Network Example
```
==============================
     Neural Network Setup    
==============================

Enter the size of the Input Layer: 3
Enter the number of Hidden Layers: 2
Enter the size of Hidden Layer 1: 4
Select Activation Function for Hidden Layer 1:
1: Identity
2: Binary Step
3: Bipolar Step
4: Binary Sigmoid
5: Ramp
Your choice: 4
Enter the size of Hidden Layer 2: 2
Select Activation Function for Hidden Layer 2:
1: Identity
2: Binary Step
3: Bipolar Step
4: Binary Sigmoid
5: Ramp
Your choice: 2
Enter the size of the Output Layer: 1

=== Neural Network Structure ===
Input Layer (3 Neurons)
Hidden Layer 1 (4 Neurons)
Hidden Layer 2 (2 Neurons)
Output Layer (1 Neurons)

=== Final Output Layer Values ===
→ 0.123  → 0.456
================================
```

### Knapsack Example
```
Maximum value in Fractional Knapsack = 240
Maximum value in 0/1 Knapsack (Greedy) = 220
```
## Acknowledgments
- This repository showcases the implementation of essential algorithms in C++ for educational purposes.
- The knapsack problems demonstrate classical greedy algorithms commonly used in optimization.
