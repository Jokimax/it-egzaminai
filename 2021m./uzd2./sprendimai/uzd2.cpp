#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Class {
public:
    int studentCount;
    string subject;
    vector<string> students;

    Class(string subject, string student) : subject(subject) {
        students.push_back(student);
        studentCount = 1;
    }
};

int findSubject(const vector<Class>& classes, const string& subject) {
    for (size_t i = 0; i < classes.size(); ++i) {
        if (classes[i].subject == subject) {
            return i;
        }
    }
    return -1;
}

vector<Class> sortClasses(const vector<Class>& classes) {
    vector<Class> sortedClasses = classes;
    sort(sortedClasses.begin(), sortedClasses.end(), [](const Class& a, const Class& b) {
        if (a.studentCount != b.studentCount) {
            return a.studentCount > b.studentCount;
        }
        return a.subject < b.subject;
    });
    return sortedClasses;
}

int sumArray(int arr[], int arrSize) {
    int sum = 0;
    for(int i = 0; i < arrSize; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    ifstream data("U2.txt");
    ofstream output("U2rez.txt");

    vector<Class> classes;

    int numStudents;
    data >> numStudents;

    for (int i = 0; i < numStudents; ++i) {
        string subject, name;
        int gradeCount;
        data >> name >> subject >> gradeCount;
        int grades[gradeCount];
        for (int j = 0; j < gradeCount; ++j) data >> grades[j];
        int gradeSum = sumArray(grades, gradeCount);
        float gradeAverage = float(gradeSum) / float(gradeCount);
        if (gradeAverage < 9) continue;

        int subjectIndex = findSubject(classes, subject);
        if (subjectIndex == -1) {
            classes.push_back(Class(subject, name));
        } else {
            classes[subjectIndex].students.push_back(name);
            classes[subjectIndex].studentCount++;
        }
    }

    classes = sortClasses(classes);

    if (classes.empty()) {
        output << "Neatitinka vidurkis" << endl;
    } else {
        for (Class cls : classes) {
            output << cls.subject << " " << cls.studentCount << endl;
            for (string student : cls.students) {
                output << student << endl;
            }
        }
    }

    data.close();
    output.close();

    return 0;
}