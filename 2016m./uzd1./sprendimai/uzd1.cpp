#include <iostream>
#include <fstream>
using namespace std;

int getMaxBackpackWeight() {
    ifstream data("U1.txt");
    int maxWeight = 0;

    int count;
    data >> count;

    for (int i = 0; i < count; ++i) {
        int weight;
        data >> weight;
        if (maxWeight < weight) {
            maxWeight = weight;
        }
    }

    data.close();
    return maxWeight;
}

int countBackpacksWithHalfWeight(int weight) {
    ifstream data("U1.txt");
    weight *= 0.5;
    int backpackCount = 0;
    int count;
    data >> count;

    for (int i = 0; i < count; ++i) {
        int currentWeight;
        data >> currentWeight;
        if (weight >= currentWeight) {
            backpackCount++;
        }
    }

    data.close();
    return backpackCount;
}

int main() {
    ofstream output("U1rez.txt");
    int maxWeight = getMaxBackpackWeight();
    int backpackCount = countBackpacksWithHalfWeight(maxWeight);

    output << maxWeight << " " << backpackCount;
    output.close();
    return 0;
}
