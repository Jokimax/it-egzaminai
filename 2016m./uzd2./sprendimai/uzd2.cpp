#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Exercise {
public:
    string name;
    int timesDone;

    Exercise(string n, int t) : name(n), timesDone(t) {}
};

int findExerciseIndex(vector<Exercise>& exercises, string name) {
    for (size_t i = 0; i < exercises.size(); ++i) {
        if (exercises[i].name == name) {
            return i;
        }
    }
    return -1;
}

vector<Exercise> sortExercises(vector<Exercise>& exercises) {
    for (size_t i = 0; i < exercises.size(); ++i) {
        for (size_t j = i + 1; j < exercises.size(); ++j) {
            if (exercises[i].timesDone < exercises[j].timesDone ||
                (exercises[i].timesDone == exercises[j].timesDone && exercises[i].name > exercises[j].name)) {
                swap(exercises[i], exercises[j]);
            }
        }
    }
    return exercises;
}

int main() {
    ifstream data("U2.txt");
    ofstream output("U2rez.txt");

    vector<Exercise> exercises;

    int n;
    data >> n;

    data.ignore();  // Consume the newline

    for (int i = 0; i < n; ++i) {
        string exerciseData;
        getline(data, exerciseData);
        string name = exerciseData.substr(0, 20);
        int timesDone = stoi(exerciseData.substr(20));
        int exerciseIndex = findExerciseIndex(exercises, name);
        if (exerciseIndex == -1) {
            exercises.push_back(Exercise(name, timesDone));
        } else {
            exercises[exerciseIndex].timesDone += timesDone;
        }
    }

    exercises = sortExercises(exercises);

    for (const Exercise& exercise : exercises) {
        output << exercise.name << " " << exercise.timesDone << endl;
    }

    data.close();
    output.close();

    return 0;
}

