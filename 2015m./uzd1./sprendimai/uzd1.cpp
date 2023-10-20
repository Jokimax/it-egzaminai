#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

vector<int> getTotalGrapesEaten(const vector<int>& grapesEaten) {
    vector<int> grapesEatenCopy = grapesEaten;
    vector<int> updatedGrapesEaten = grapesEaten;
    updatedGrapesEaten.resize(20, 0);

    for (int i = 0; i < 10; ++i) {
        for (int j = i + 1; j < i + 10 - grapesEatenCopy[i] + 1; ++j) {
            updatedGrapesEaten[j]++;
        }
    }
    return updatedGrapesEaten;
}

int main() {
    ifstream data("U1.txt");
    ofstream output("U1rez.txt");

    vector<int> grapesEaten;
    string line;

    int grape;
    while (data >> grape) {
        grapesEaten.push_back(grape);
    }

    vector<int> updatedGrapesEaten = getTotalGrapesEaten(grapesEaten);

    for (int i = 0; i < updatedGrapesEaten.size(); ++i) {
        output << updatedGrapesEaten[i];
        if (i < updatedGrapesEaten.size() - 1) {
            output << " ";
        }
    }

    data.close();
    output.close();

    return 0;
}

