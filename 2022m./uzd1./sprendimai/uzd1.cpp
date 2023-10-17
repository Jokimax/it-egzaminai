#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

class Contestant {
public:
    string name;
    int timeTaken;
    int tasksCompleted;

    Contestant(const string& name, int timeTaken, int tasksCompleted)
        : name(name), timeTaken(timeTaken), tasksCompleted(tasksCompleted) {}
};

void getContestantStatistics(string& contestantData, int taskCount, const vector<int>& points, const vector<int>& timeLimit,
                             string& name, int& pointsEarned, int& timeTaken, int& tasksCompleted) {
    pointsEarned = 0;
    timeTaken = 0;
    tasksCompleted = 0;
    name = contestantData.substr(0, 11);
    contestantData = contestantData.substr(11);
    vector<int> contestantDataSplit;
    stringstream dataStream(contestantData);
    int num;
    while (dataStream >> num) {
        contestantDataSplit.push_back(num);
    }

    for (int j = 0; j < taskCount; j++) {
        if (contestantDataSplit[j] == 0) {
            continue;
        } else if (contestantDataSplit[j] > timeLimit[j]) {
            pointsEarned += int(floor(points[j] / 2));
        } else {
            pointsEarned += points[j];
        }
        timeTaken += contestantDataSplit[j];
        tasksCompleted++;
    }
}

vector<Contestant> sortContestants(vector<Contestant>& contestants) {
    sort(contestants.begin(), contestants.end(), [](const Contestant& a, const Contestant& b) {
        return a.tasksCompleted > b.tasksCompleted;
    });
    return contestants;
}

int main() {
    ifstream data("U1.txt");
    ofstream output("U1rez.txt");

    int taskCount;
    data >> taskCount;

    vector<int> timeLimit(taskCount);
    for (int i = 0; i < taskCount; i++) {
        data >> timeLimit[i];
    }

    vector<int> points(taskCount);
    for (int i = 0; i < taskCount; i++) {
        data >> points[i];
    }

    vector<Contestant> contestants;
    int maxPoints = 0;

    data.ignore();

    for (int i = 0; i < 5; ++i) {
        string contestantData;
        string name;
        int pointsEarned, timeTaken, tasksCompleted;
        getline(data, contestantData);
        getContestantStatistics(contestantData, taskCount, points, timeLimit, name, pointsEarned, timeTaken, tasksCompleted);

        if (pointsEarned > maxPoints) {
            maxPoints = pointsEarned;
            contestants = {Contestant(name, timeTaken, tasksCompleted)};
        } else if (pointsEarned == maxPoints) {
            contestants.push_back(Contestant(name, timeTaken, tasksCompleted));
        }
    }

    contestants = sortContestants(contestants);

    output << maxPoints << "\n";
    for (const Contestant& contestant : contestants) {
        output << contestant.name << " " << contestant.tasksCompleted << " " << contestant.timeTaken << "\n";
    }

    data.close();
    output.close();

    return 0;
}

