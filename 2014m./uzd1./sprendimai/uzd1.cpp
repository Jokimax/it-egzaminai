#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int getWinningIdea(const vector<int>& points) {
    int maxPoints = points[0];
    int winningIdea = 1;
    bool foundMultWinners = false;
    for (int i = 1; i < 3; ++i) {
        if (points[i] > maxPoints) {
            maxPoints = points[i];
            winningIdea = i + 1;
            foundMultWinners = false;
        }
        else if (points[i] == maxPoints) {
            foundMultWinners = true;
        }
    }
    if (foundMultWinners) {
        return -1;
    }   
    return winningIdea;
}

vector<int> getPoints(const vector<int>& votes) {
    if (votes[0] == votes[1] && votes[0] == votes[2]) {
        return {0, 0, 0};
    }
    int maxVotes = max(votes[0], max(votes[1], votes[2]));
    if (votes[0] == maxVotes) {
        if (votes[1] == maxVotes) {
            return {2, 2, 0};
        }
        if (votes[2] == maxVotes) {
            return {2, 0, 2};
        }
        return {4, 0, 0};
    }
    if (votes[1] == maxVotes) {
        if (votes[2] == maxVotes) {
            return {0, 2, 2};
        }
        return {0, 4, 0};
    }
    return {0, 0, 4};
}

int main() {
    ifstream data("U1.txt");
    ofstream output("U1rez.txt");
    
    vector<int> votes = {0, 0, 0};
    vector<int> points = {0, 0, 0};

    int numSectors;
    data >> numSectors;
    
    for (int i = 0; i < numSectors; ++i) {
        vector<int> sectorVotes(3);
        data >> sectorVotes[0] >> sectorVotes[1] >> sectorVotes[2];
        votes[0] += sectorVotes[0];
        votes[1] += sectorVotes[1];
        votes[2] += sectorVotes[2];
        vector<int> sectorPoints = getPoints(sectorVotes);
        points[0] += sectorPoints[0];
        points[1] += sectorPoints[1];
        points[2] += sectorPoints[2];
    }

    int winningIdea = getWinningIdea(points);
    if (winningIdea == -1) {
        vector<int> bossVotes(3);
        data >> bossVotes[0] >> bossVotes[1] >> bossVotes[2];
        points[0] += bossVotes[0];
        points[1] += bossVotes[1];
        points[2] += bossVotes[2];
        winningIdea = getWinningIdea(points);
    }

    output << votes[0] << " " << votes[1] << " " << votes[2] << "\n";
    output << points[0] << " " << points[1] << " " << points[2] << "\n";
    output << winningIdea;

    data.close();
    output.close();

    return 0;
}

