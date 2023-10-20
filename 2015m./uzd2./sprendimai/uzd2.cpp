#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Sheep {
public:
    int geneticSimilarity;
    string name;
    string dnr;

    Sheep(string name, string dnr) : name(name), dnr(dnr), geneticSimilarity(0) {}
};

vector<Sheep> readData(int& geneCount, Sheep& studiedSheep) {
    ifstream data("U2.txt");
    int sheepCount;
    data >> sheepCount >> geneCount;
    int studiedSheepIndex;
    data >> studiedSheepIndex;
    studiedSheepIndex--;

    vector<Sheep> sheep;

    for (int i = 0; i < sheepCount; ++i) {
        string name, dnr;
        data >> name >> dnr;
        if (i == studiedSheepIndex) {
            studiedSheep = Sheep(name, dnr);
        } else {
            sheep.push_back(Sheep(name, dnr));
        }
    }

    data.close();

    return sheep;
}

void outputData(const Sheep& studiedSheep, const vector<Sheep>& sheep) {
    ofstream output("U2rez.txt");
    output << studiedSheep.name << endl;
    for (const Sheep& s : sheep) {
        output << s.name << " " << s.geneticSimilarity << endl;
    }
    output.close();
}

vector<Sheep> sortSheep(vector<Sheep> sheep) {
    int size = sheep.size();
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (sheep[i].geneticSimilarity < sheep[j].geneticSimilarity ||
                (sheep[i].geneticSimilarity == sheep[j].geneticSimilarity && sheep[i].name > sheep[j].name)) {
                swap(sheep[i], sheep[j]);
            }
        }
    }
    return sheep;
}

int getGeneticSimilarity(const string& dnr1, const string& dnr2, int geneCount) {
    int geneticSimilarity = 0;
    for (int i = 0; i < geneCount; ++i) {
        if (dnr1[i] == dnr2[i]) {
            geneticSimilarity++;
        }
    }
    return geneticSimilarity;
}

int main() {
    int geneCount;
    Sheep studiedSheep("", "");
    vector<Sheep> sheep = readData(geneCount, studiedSheep);

    for (int i = 0; i < sheep.size(); ++i) {
        sheep[i].geneticSimilarity = getGeneticSimilarity(sheep[i].dnr, studiedSheep.dnr, geneCount);
    }

    sheep = sortSheep(sheep);

    outputData(studiedSheep, sheep);

    return 0;
}
