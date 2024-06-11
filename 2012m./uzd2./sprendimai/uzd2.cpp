#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

struct God {
    string name;
    int score;

    God(const string name, int score) : name(name), score(score) {}
};

vector<God> readData() {
    ifstream data("U2.txt");

    vector<God> gods;

    int numOfGods, numOfDice;
    data >> numOfGods >> numOfDice;
    data.ignore();

    for (int i = 0; i < numOfGods; i++) {
        string godData;
        getline(data, godData);
        string name = godData.substr(0, 10);

        stringstream datastream(godData.substr(10)); 

        int score = 0;
        for (int j = 0; j < numOfDice; j++) {
            int diceValue;
            datastream >> diceValue;
            score += diceValue;
        }

        gods.push_back(God(name, score));
    }

    data.close();

    return gods;
}

God findLord(const vector<God> gods) {
    int lordIndex = 0;
    for (size_t i = 1; i < gods.size(); i++) {
        if (gods[i].score > gods[lordIndex].score) {
            lordIndex = static_cast<int>(i);
        }
    }
    return gods[lordIndex];
}

int main() {
    ofstream output("U2rez.txt");

    vector<God> gods = readData();
    God lord = findLord(gods);

    output << lord.name << " " << lord.score;

    output.close();

    return 0;
}