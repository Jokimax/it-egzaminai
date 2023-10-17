#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> monthDays = {{"6", 0}, {"7", 30}, {"8", 61}};

class Flower {
public:
    int bloom;
    int end;

    Flower(int bloom, int end) : bloom(bloom), end(end) {}
};

int getMaxBloomingFlowerDayIndex(const vector<int>& flowers, int maxBloomingFlower) {
    for (int i = 0; i < flowers.size(); ++i) {
        if (flowers[i] == maxBloomingFlower) {
            return i;
        }
    }
    return -1;
}

int getMaxBloomingFlowerEndDay(const vector<int>& flowers, int maxBloomingFlowerDay) {
    for (int i = maxBloomingFlowerDay; i < flowers.size(); ++i) {
        if (flowers[i] != flowers[i - 1]) {
            return i + 1;
        }
    }
    return 92;
}

string getDate(int day) {
    if (day > 61) {
        return "8 " + to_string(day - 61);
    } else if (day > 30) {
        return "7 " + to_string(day - 30);
    }
    return "6 " + to_string(day);
}

int main() {
    ifstream data("U1.txt");
    ofstream output("U1rez.txt");

    int count;
    data >> count;
    vector<Flower> flowers;

    for (int i = 0; i < count; ++i) {
        string month1, month2;
        int id, day1, day2;
        data >> id >> month1 >> day1 >> month2 >> day2;
        int bloom = monthDays[month1] + day1 - 1;
        int end = monthDays[month2] + day2 - 1;
        cout << bloom << " " << end << "\n";
        flowers.push_back(Flower(bloom, end));
    }

    vector<int> flowerCount(92, 0);
    int bloomingFlowers = 0;

    for (int i = 0; i < 92; ++i) {
        for (Flower& flower : flowers) {
            if (flower.bloom == i) {
                bloomingFlowers++;
            } else if (flower.end == i) {
                bloomingFlowers--;
                flower.bloom =- 1;
            }
        }
        flowerCount[i] = bloomingFlowers;
    }

    int maxBloomingFlowers = *max_element(flowerCount.begin(), flowerCount.end());
    int maxBloomingFlowersDayIndex = getMaxBloomingFlowerDayIndex(flowerCount, maxBloomingFlowers);
    int maxBloomingFlowersDay = maxBloomingFlowersDayIndex + 1;
    int maxBloomingFlowersEndDay = getMaxBloomingFlowerEndDay(flowerCount, maxBloomingFlowersDay);

    output << maxBloomingFlowers << "\n";
    output << getDate(maxBloomingFlowersDay) << "\n";
    output << getDate(maxBloomingFlowersEndDay);

    data.close();
    output.close();

    return 0;
}

