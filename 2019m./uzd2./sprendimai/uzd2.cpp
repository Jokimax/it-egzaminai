#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Contestant {
public:
    string name;
    int id;
    int time;

    Contestant(const string& name, int id, int time) : name(name), id(id), time(time) {}
};

int getIndexById(int id, const vector<Contestant>& arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i].id == id) {
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

void writeOutput(ofstream& output, const vector<Contestant>& finishers, const string& gender) {
    output << gender << "\n";
    for (const Contestant& contestant : finishers) {
        int seconds = contestant.time % 60;
        int minutes = (contestant.time / 60) % 60;
        int hours = contestant.time / 3600;
        output << contestant.id << " " << contestant.name << string(20 - contestant.name.length(), ' ')
               << hours << " " << minutes << " " << seconds << "\n";
    }
}

int main() {
    ifstream data("U2.txt");
    ofstream output("U2rez.txt");

    vector<Contestant> contestants;

    int numContestants;
    data >> numContestants;
    data.ignore();

    for (int i = 0; i < numContestants; ++i) {
        string contestantData;
        getline(data, contestantData);
        string name = contestantData.substr(0, 20);
        contestantData = contestantData.substr(20);
        stringstream dataStream(contestantData);
        int id, hours, minutes, seconds;
        dataStream >> id >> hours >> minutes >> seconds;
        int startTime = hours * 3600 + minutes * 60 + seconds;
        contestants.push_back(Contestant(name, id, startTime));
    }

    vector<Contestant> femaleFinishers;
    vector<Contestant> maleFinishers;

    int numFinishers;
    data >> numFinishers;
    data.ignore();

    for (int i = 0; i < numFinishers; ++i) {
        string contestantData;
        getline(data, contestantData);
        stringstream dataStream(contestantData);
        int id, hours, minutes, seconds;
        dataStream >> id >> hours >> minutes >> seconds;
        vector<int> shots;
        int value;
        while (dataStream >> value) {
            shots.push_back(value);
        }
        int contestantIndex = getIndexById(id, contestants);
        int startTime = contestants[contestantIndex].time;
        int endTime = hours * 3600 + minutes * 60 + seconds;

        if (id >= 200) {
            int penaltyTime = (20 - shots[0] - shots[1] - shots[2] - shots[3]) * 60;
            int finishTime = endTime - startTime + penaltyTime;
            maleFinishers.push_back(Contestant(contestants[contestantIndex].name, id, finishTime));
        } else {
            int penaltyTime = (10 - shots[0] - shots[1]) * 60;
            int finishTime = endTime - startTime + penaltyTime;
            femaleFinishers.push_back(Contestant(contestants[contestantIndex].name, id, finishTime));
        }
    }

    femaleFinishers = sortContestants(femaleFinishers);
    maleFinishers = sortContestants(maleFinishers);

    writeOutput(output, femaleFinishers, "Merginos");
    writeOutput(output, maleFinishers, "Vaikinai");

    data.close();
    output.close();

    return 0;
}
