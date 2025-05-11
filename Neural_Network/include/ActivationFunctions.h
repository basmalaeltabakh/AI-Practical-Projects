#ifndef ACTIVATION_FUNCTIONS_H
#define ACTIVATION_FUNCTIONS_H

#include <cmath>

class ActivationFunctions {
public:
    // Identity (Linear) Function
    static double identity(double x) {
        return x;
    }

    // Binary Step Function
    static double binaryStep(double x) {
        return (x >= 0) ? 1.0 : 0.0;
    }

    // Bipolar Step Function
    static double bipolarStep(double x) {
        return (x >= 0) ? 1.0 : -1.0;
    }

    // Binary Sigmoid Function
    static double binarySigmoid(double x) {
        return 1 / (1 + exp(-x));
    }

    // Ramp Function
    static double ramp(double x) {
        if (x < 0) return 0.0;
        else if (x > 1) return 1.0;
        else return x;
    }
};

#endif // ACTIVATION_FUNCTIONS_H
