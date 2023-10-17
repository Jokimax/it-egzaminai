#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Contestant {
public:
    string name;
    int time;

    Contestant(const string& name, int time) : name(name), time(time) {}
};

int getIndexByName(const string& name, const vector<Contestant>& arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i].name == name) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

vector<Contestant> sortContestants(vector<Contestant> contestants) {
    size_t size = contestants.size();
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = i + 1; j < size; ++j) {
            if (contestants[i].time > contestants[j].time ||
                (contestants[i].time == contestants[j].time &&
                 contestants[i].name > contestants[j].name)) {
                swap(contestants[i], contestants[j]);
            }
        }
    }
    return contestants;
}

void writeOutput(const vector<Contestant>& contestants) {
    ofstream output("U2rez.txt");

    for (const Contestant& contestant : contestants) {
        int time = contestant.time;
        int seconds = time % 60;
        int minutes = (time - seconds) / 60;
        output << contestant.name << string(20 - contestant.name.length(), ' ') << minutes << " " << seconds << "\n";
    }

    output.close();
}

int main() {
    ifstream data("U2.txt");

    vector<Contestant> contestants;
    vector<Contestant> finishedContestants;

    int n;
    data >> n;
    data.ignore();

    for (int i = 0; i < n; ++i) {
        string contestantData;
        getline(data, contestantData);
        string name = contestantData.substr(0, 20);
        contestantData = contestantData.substr(20);
        stringstream dataStream(contestantData);
        int hours, minutes, seconds;
        dataStream >> hours >> minutes >> seconds;
        int startTime = hours * 3600 + minutes * 60 + seconds;
        contestants.push_back(Contestant(name, startTime));
    }

    int m;
    data >> m;
    data.ignore();

    for (int i = 0; i < m; ++i) {
        string contestantData;
        getline(data, contestantData);
        string name = contestantData.substr(0, 20);
        contestantData = contestantData.substr(20);
        stringstream dataStream(contestantData);
        int hours, minutes, seconds;
        dataStream >> hours >> minutes >> seconds;
        int startTime = contestants[getIndexByName(name, contestants)].time;
        int endTime = hours * 3600 + minutes * 60 + seconds;
        finishedContestants.push_back(Contestant(name, endTime - startTime));
    }

    finishedContestants = sortContestants(finishedContestants);
    writeOutput(finishedContestants);

    data.close();

    return 0;
}

