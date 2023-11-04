#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

class City {
public:
    string name;
    string region;
    int population;

    City(const string name = "", const string region = "", long population = 1000000)
        : name(name), region(region), population(population) {}
};

class Region {
public:
    string name;
    int minPopulation;
    int population;

    Region(const string name = "", int minPopulation = 10000000, long population = 1000000)
        : name(name), minPopulation(minPopulation), population(population) {}
};

int findRegionIndex(const string name, Region regions[]) {
    for (int i = 0; i < 103; i++) {
        if (regions[i].name == "") {
            return -1;
        } else if (regions[i].name == name) {
            return i;
        }
    }
    return -1;
}

int main() {
    ifstream data("U2.txt");
    ofstream output("U2rez.txt");

    City cities[103];
    int cityCount;
    data >> cityCount;
    data.ignore();

    for (int i = 0; i < cityCount; ++i) {
        string cityData;
        getline(data, cityData);
        string name = cityData.substr(0, 20);
        string region = cityData.substr(21, 13);
        int population = stoi(cityData.substr(34));
        cities[i] = City(name, region, population);
    }

    Region regions[103];
    int regionCount = 0;

    for (int i = 0; i < cityCount; ++i) {
        int regionIndex = findRegionIndex(cities[i].region, regions);
        if (regionIndex == -1) {
            regions[regionCount] = Region(cities[i].region, cities[i].population, cities[i].population);
            regionCount++;
        } else {
            regions[regionIndex].population += cities[i].population;
            if (regions[regionIndex].minPopulation > cities[i].population) {
                regions[regionIndex].minPopulation = cities[i].population;
            }
        }
    }

    sort(regions, regions + 103, [](const Region& a, const Region& b) {
        return a.population == b.population ? a.name < b.name : a.population < b.population;
    });

    for (int i = 0; i < 103; i++) {
        if (regions[i].name == "") {
            break;
        }
        output << regions[i].name << " " << regions[i].minPopulation << " " << regions[i].population << "\n";
    }

    data.close();
    output.close();

    return 0;
}

