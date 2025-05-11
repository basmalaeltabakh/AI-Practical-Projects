#include <bits/stdc++.h>
using namespace std;

// Define the Item class representing each item in the knapsack
class Item {
public:
    int value;    // Item's value
    int weight;   // Item's weight

    // Constructor to initialize the item with its value and weight
    Item(int v, int w) {
        value = v;
        weight = w;
    }
};

// Define the FractionalKnapsack class to handle the logic
class FractionalKnapsack {
public:

    // Comparison function to sort items based on value/weight ratio
    static bool compare(Item a, Item b) {
        // Calculate the ratio for each item
        double ratio1 = a.value * 1.0 / a.weight;
        double ratio2 = b.value * 1.0 / b.weight;
        // Sort in descending order of ratio
        return ratio1 > ratio2;
    }

    // Function to get the maximum value achievable with the given capacity
    static double getMaxValue(vector<Item>& items, int capacity) {
        // Sort items based on value/weight ratio
        sort(items.begin(), items.end(), compare);

        double totalValue = 0.0; // Variable to store the final total value

        // Loop through each item and try to add it to the knapsack
        for (auto& item : items) {
            // If the full item can fit in the knapsack, add it
            if (capacity >= item.weight) {
                capacity -= item.weight;      // Reduce available capacity
                totalValue += item.value;     // Add the item's full value
            }
            // If the item can't fit completely, add the fractional part
            else {
                double fraction = capacity * 1.0 / item.weight;
                totalValue += item.value * fraction;
                capacity = 0; // Knapsack is now full
                break;
            }
        }

        // Return the maximum value obtained
        return totalValue;
    }
};

// Define the ZeroOneKnapsack class to handle the 0/1 Knapsack logic using Greedy
class ZeroOneKnapsack {
public:

    // Comparison function to sort items based on value/weight ratio
    static bool compare(Item a, Item b) {
        double ratio1 = a.value * 1.0 / a.weight;
        double ratio2 = b.value * 1.0 / b.weight;
        return ratio1 > ratio2;
    }

    // Function to get the maximum value achievable with the given capacity
    static int getMaxValue(vector<Item>& items, int capacity) {
        // Sort items based on value/weight ratio
        sort(items.begin(), items.end(), compare);

        int totalValue = 0; // Variable to store the final total value

        // Loop through each item
        for (auto& item : items) {
            // If the full item can fit, add it and reduce the capacity
            if (capacity >= item.weight) {
                capacity -= item.weight;
                totalValue += item.value;
            }
            // If it can't fit, stop (Greedy stops here, no partial allowed in 0/1)
            else {
                break;
            }
        }

        return totalValue;
    }
};

int main() {
    // Define the items available with their values and weights
    vector<Item> items = { Item(60, 10), Item(100, 20), Item(120, 30) };
    int capacity = 50;

    // Calculate and display the maximum value for Fractional Knapsack
    cout << "Maximum value in Fractional Knapsack = "
         << FractionalKnapsack::getMaxValue(items, capacity) << endl;

    // Calculate and display the maximum value for 0/1 Knapsack using Greedy
    cout << "Maximum value in 0/1 Knapsack (Greedy) = "
         << ZeroOneKnapsack::getMaxValue(items, capacity) << endl;

    return 0;
}

