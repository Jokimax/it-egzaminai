#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <numeric>
#include <sstream>

using namespace std;

struct Performance {
    string name;
    vector<int> technique;
    vector<int> artistry;
    int score;

    Performance(string n, vector<int> t, vector<int> a) : name(n), technique(t), artistry(a), score(0) {}
};

vector<Performance> sortPerformances(vector<Performance>& performances) {
    sort(performances.begin(), performances.end(), [](const Performance& a, const Performance& b) {
        return a.score > b.score;
    });
    return performances;
}

int countScore(vector<int>& scores) {
    auto minMax = minmax_element(scores.begin(), scores.end());
    scores.erase(minMax.first);
    scores.erase(find(scores.begin(), scores.end(), *minMax.second));
    return accumulate(scores.begin(), scores.end(), 0);
}

int main() {
    ifstream input("U2.txt");
    ofstream output("U2rez.txt");

    int contestantCount;
    string judgeCount;
    input >> contestantCount >> judgeCount;
    
    vector<string> contestants;
    vector<Performance> performances;
    
    input.ignore();

    while (contestants.size() < contestantCount) {
        string teamName;
        getline(input, teamName);

        istringstream issNames(teamName);
        string name1, name2;
        issNames >> name1 >> name2;

        if (!name1.empty() && find(contestants.begin(), contestants.end(), name1) == contestants.end()) {
            contestants.push_back(name1);
        }
        if (!name2.empty() && find(contestants.begin(), contestants.end(), name2) == contestants.end()) {
            contestants.push_back(name2);
        }

        string line;
        vector<int> technique, artistry;

        getline(input, line);
        istringstream issTechnique(line);
        int score;
        while (issTechnique >> score) {
            technique.push_back(score);
        }

        getline(input, line);
        istringstream issArtistry(line);
        while (issArtistry >> score) {
            artistry.push_back(score);
        }

        performances.emplace_back(teamName, technique, artistry);
    }

    for (auto& performance : performances) {
        int score = countScore(performance.technique);
        score += countScore(performance.artistry);
        performance.score = score;
    }

    performances = sortPerformances(performances);

    for (const auto& performance : performances) {
        output << performance.name;
        output << string(20 - performance.name.size(), ' ');
        output << performance.score << endl;
    }

    input.close();
    output.close();

    return 0;
}
