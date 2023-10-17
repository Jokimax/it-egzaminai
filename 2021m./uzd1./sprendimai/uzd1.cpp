#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int getTimeRan(int mHourStart, int mMinStart, int mHourEnd, int mMinEnd, 
               int eHourStart, int eMinStart, int eHourEnd, int eMinEnd) {
    int minutesRan = (mHourEnd * 60 + mMinEnd - mHourStart * 60 - mMinStart +
                      eHourEnd * 60 + eMinEnd - eHourStart * 60 - eMinStart);
    return minutesRan;
}

int main() {
    ifstream data("U1.txt");
    ofstream output("U1rez.txt");

    int minTime = 10000000;
    vector<int> minDays;

    int numDays;
    data >> numDays;

    for (int i = 0; i < numDays; ++i) {
        int dayData[9];
        for (int j = 0; j < 9; ++j) {
            data >> dayData[j];
        }
        if (dayData[1] == 0 && dayData[2] == 0 && dayData[3] == 0 && dayData[4] == 0)
            continue;
        if (dayData[5] == 0 && dayData[6] == 0 && dayData[7] == 0 && dayData[8] == 0)
            continue;
        int minutesRan = getTimeRan(dayData[1], dayData[2], dayData[3], dayData[4],
                                    dayData[5], dayData[6], dayData[7], dayData[8]);
        if (minutesRan == minTime) {
            minDays.push_back(dayData[0]);
        } else if (minutesRan < minTime) {
            minTime = minutesRan;
            minDays = {dayData[0]};
        }
    }

    output << "Minimalus laikas\n";
    output << minTime << "\n";
    output << "Dienos\n";
    for (const int& day : minDays) {
        output << day << " ";
    }

    data.close();
    output.close();

    return 0;
}

