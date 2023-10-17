#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class FishFisher {
public:
    string name;
    vector<FishFisher> fishes;
    int num;

    FishFisher(const string& name, const int num) : name(name), fishes({}), num(num) {}
};
void sortList(std::vector<FishFisher>& list) {
    int size = list.size();
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (list[i].num < list[j].num ||
                (list[i].num == list[j].num && list[i].name > list[j].name)) {
                std::swap(list[i], list[j]);
            }
        }
    }
}

int main() {
    ifstream data("U2.txt");
    ofstream output("U2rez.txt");

    vector<FishFisher> fishers;

    int numFishers;
    data >> numFishers;
    data.ignore();

    for (int i = 0; i < numFishers; ++i) {
        string fisherData;
        getline(data, fisherData);
        string name = fisherData.substr(0, 19);
        int fishCaught = stoi(fisherData.substr(20));
        vector<FishFisher> fishes;
        for (int j = 0; j < fishCaught; ++j) {
            string fishData;
            getline(data, fishData);
            string fishName = fishData.substr(0, 19);
            int weight = stoi(fishData.substr(20));
            fishes.push_back(FishFisher(fishName, weight));
        }
        fishers.push_back(FishFisher(name, 0));
        fishers[i].fishes = fishes;
    }

    vector<FishFisher> fishes;

    int numFish;
    data >> numFish;
    data.ignore();

    for (int i = 0; i < numFish; ++i) {
        int weight = 0;
        string fishData;
        getline(data, fishData);
        string name = fishData.substr(0, 19);
        int pointWorth = stoi(fishData.substr(20));
        for (FishFisher& fisher : fishers) {
            for (FishFisher& fish : fisher.fishes) {
                if (fish.name == name) {
                    weight += fish.num;
                    fisher.num += pointWorth;
                    if (fish.num >= 200) {
                        fisher.num += 30;
                    } else {
                        fisher.num += 10;
                    }
                }
            }
        }
        fishes.push_back(FishFisher(name, weight));
    }

    sortList(fishers);
    sortList(fishes);

    output << "Dalyviai\n";

    for (const FishFisher& fisher : fishers) {
        output << fisher.name << " " << fisher.num << "\n";
    }

    output << "Laimikis\n";

    for (const FishFisher& fish : fishes) {
        output << fish.name << " " << fish.num << "\n";
    }

    data.close();
    output.close();

    return 0;
}