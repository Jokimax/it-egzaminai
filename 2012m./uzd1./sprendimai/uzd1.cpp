#include <iostream>
#include <fstream>
#include <tuple>
#include <algorithm>

using namespace std;

int getMaxElementIndex(const int arr[], int size) {
    int maxIndex = 0;
    for (int i = 1; i < size; i++) {
        if (arr[maxIndex] < arr[i]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

void readData(string startingPlayers[5], int timeSpentOnBench[100], int timeSpentPlaying[100]) {
    ifstream data("U1.txt");

    int startingPlayerIndex = 0;

    int numPlayers;
    data >> numPlayers;

    for (int i = 0; i < numPlayers; i++) {
        int playerId, numEntries, firstTimeEntry;
        data >> playerId >> numEntries >> firstTimeEntry;

        if (firstTimeEntry > 0) {
            timeSpentPlaying[playerId] += firstTimeEntry;
            startingPlayers[startingPlayerIndex] = to_string(playerId);
            startingPlayerIndex++;
        }
        else {
            timeSpentOnBench[playerId] += abs(firstTimeEntry);
        }

        for (int j = 0; j < numEntries - 1; j++) {
            int timeEntry;
            data >> timeEntry;

            if (timeEntry > 0) {
                timeSpentPlaying[playerId] += timeEntry;
            } else {
                timeSpentOnBench[playerId] += abs(timeEntry);
            }
        }
    }

    data.close();
}

int main() {
    ofstream output("U1rez.txt");

    string startingPlayers[5];
    int timeSpentOnBench[100] = {0};
    int timeSpentPlaying[100] = {0};

    readData(startingPlayers, timeSpentOnBench, timeSpentPlaying);

    int mostActivePlayer = getMaxElementIndex(timeSpentPlaying, 100);
    int leastActivePlayer = getMaxElementIndex(timeSpentOnBench, 100);

    for (const auto& player : startingPlayers) {
        if (!player.empty()) {
            output << player << " ";
        }
    }
    output << "\n";

    output << mostActivePlayer << " " << timeSpentPlaying[mostActivePlayer] << "\n";
    output << leastActivePlayer << " " << timeSpentOnBench[leastActivePlayer] << "\n";

    output.close();

    return 0;
}

