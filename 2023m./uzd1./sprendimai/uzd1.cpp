#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

class Cls {
public:
    int studentCount = 1;
    int category;
    double kmWalked;

    Cls(int category, double kmWalked) : category(category), kmWalked(kmWalked) {}
};

int main() {
    ifstream data("U1.txt");
    ofstream output("U1rez.txt");

    vector<Cls> classes;

    int numStudents;
    data >> numStudents;

    for (int i = 0; i < numStudents; ++i) {
        int category, stepDistance;
        data >> category;
        data >> stepDistance;
        int cmWalked = 0;
        bool hasUnregisteredDay = false;

        for (int j = 0; j < 7; ++j) {
            int daySteps;
            data >> daySteps;
            if (daySteps == 0) {
                cmWalked = 0;
                hasUnregisteredDay = true;
            }
            cmWalked += daySteps * stepDistance;
        }
        double kmWalked = 0;

        if(!hasUnregisteredDay) kmWalked = round(cmWalked * 0.001) * 0.01;

        if (kmWalked > 0) {
            bool foundClass = false;
            for (Cls& cls : classes) {
                if (cls.category == category) {
                    cls.kmWalked += kmWalked;
                    cls.studentCount++;
                    foundClass = true;
                    break;
                }
            }
            if (!foundClass) {
                classes.push_back(Cls(category, kmWalked));
            }
        }
    }

    for (const Cls& cls : classes) {
        output << cls.category << " " << cls.studentCount << " " << cls.kmWalked << endl;
    }

    data.close();
    output.close();

    return 0;
}