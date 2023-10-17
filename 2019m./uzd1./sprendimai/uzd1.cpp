#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> countContainers(int l1, int l3, int l5, int &oil) {
    while (oil >= 5 && l5 > 0) {
        oil -= 5;
        l5 -= 1;
    }
    while (oil >= 3 && l3 > 0) {
        oil -= 3;
        l3 -= 1;
    }
    while (oil >= 1 && l1 > 0) {
        oil -= 1;
        l1 -= 1;
    }
    return { l1, l3, l5 };
}

vector<int> countExtraContainers(int oil) {
    int l5 = 0, l3 = 0, l1 = 0;
    while (oil >= 5) {
        l5 += 1;
        oil -= 5;
    }
    while (oil >= 3) {
        l3 += 1;
        oil -= 3;
    }
    while (oil >= 1) {
        l1 += 1;
        oil -= 1;
    }
    return { l1, l3, l5 };
}

int main() {
    ifstream data("U1.txt");
    ofstream output("U1rez.txt");

    vector<int> containers;
    for (int i = 0; i < 3; i++) {
        int value;
        data >> value;
        containers.push_back(value);
    }
    
    int oil;
    data >> oil;

    vector<int> containersLeft = countContainers(containers[0], containers[1], containers[2], oil);

    output << containers[0] - containersLeft[0] << " " << containers[1] - containersLeft[1]
           << " " << containers[2] - containersLeft[2] << " " << oil << "\n";
    output << containersLeft[0] << " " << containersLeft[1] << " " << containersLeft[2] << "\n";

    vector<int> extraContainers = countExtraContainers(oil);

    output << extraContainers[0] << " " << extraContainers[1] << " " << extraContainers[2] << "\n";

    vector<int> oilPrice;
    for (int i = 0; i < 4; i++) {
        int value;
        data >> value;
        oilPrice.push_back(value);
    }

    int profit = (-oilPrice[0] + (containers[0] - containersLeft[0] + extraContainers[0]) * oilPrice[1] +
                                 (containers[1] - containersLeft[1] + extraContainers[1]) * oilPrice[2] +
                                 (containers[2] - containersLeft[2] + extraContainers[2]) * oilPrice[3]);

    output << profit;

    data.close();
    output.close();

    return 0;
}
