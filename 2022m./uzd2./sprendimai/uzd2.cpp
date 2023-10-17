#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Exercise {
public:
    int daysDone = 0;
    bool doneToday = false;
    int morningsDone = 0;
    int middaysDone = 0;
    int eveningsDone = 0;
    int timeSpent = 0;
    string name;

    Exercise(const string& name) : name(name) {}
};

vector<string> findAllExercises() {
    ifstream data("U2.txt");

    vector<string> exercises(5);
    int exercisesFound = 0;
    int numEntries;
    data >> numEntries;

    while (exercisesFound < 5 && numEntries--) {
        int numExercises;
        data >> numExercises;

        for (int j = 0; j < numExercises; j++) {
            if (exercisesFound == 5) {
                break;
            }

            string exercise, extra, extra2;
            data >> exercise >> extra >> extra2;

            if (find(exercises.begin(), exercises.end(), exercise) == exercises.end()) {
                exercises[exercisesFound] = exercise;
                exercisesFound++;
            }
        }
        data.ignore();
    }

    data.close();

    return exercises;
}

int main() {
    ifstream data("U2.txt");
    ofstream output("U2rez.txt");

    vector<string> exerciseNames = findAllExercises();
    vector<Exercise> exercises;

    for (const string& exerciseName : exerciseNames) {
        exercises.push_back(Exercise(exerciseName));
    }

    int days;
    data >> days;

    while (days > 0) {
        int dayExercises;
        data >> dayExercises;
        for (int i = 0; i < dayExercises; ++i) {
            string exerciseName, timeOfDay;
            int timeSpent;
            data >> exerciseName >> timeOfDay >> timeSpent;

            for (Exercise& exercise : exercises) {
                if (exercise.name == exerciseName) {
                    if (!exercise.doneToday) {
                        exercise.daysDone++;
                        exercise.doneToday = true;
                    }
                    exercise.timeSpent += timeSpent;
                    if (timeOfDay == "Rytas") {
                        exercise.morningsDone++;
                    } else if (timeOfDay  == "Diena") {
                        exercise.middaysDone++;
                    } else {
                        exercise.eveningsDone++;
                    }
                    break;
                }
            }
        }
        for (Exercise& exercise : exercises) {
            exercise.doneToday = false;
        }
        days--;
    }

    sort(exercises.begin(), exercises.end(), [](const Exercise& a, const Exercise& b) {
        return a.name < b.name;
    });

    for (const Exercise& exercise : exercises) {
        string filler = "               ";
        filler.erase(14 - exercise.name.length());
        output << exercise.name << filler << " " << exercise.daysDone << " " << exercise.timeSpent << "\n";
        if (exercise.morningsDone > 0) output << "Rytas   " << exercise.morningsDone << "\n";
        if (exercise.middaysDone > 0)  output << "Diena   " << exercise.middaysDone << "\n";
        if (exercise.eveningsDone > 0) output << "Vakaras " << exercise.eveningsDone << "\n";
    }

    data.close();
    output.close();

    return 0;
}