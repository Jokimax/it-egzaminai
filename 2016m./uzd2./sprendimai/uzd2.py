class Exercise:
    def __init__(self, name, timesDone):
        self.name = name
        self.timesDone = timesDone

def findExerciseIndex(exercises, name):
    for i in range(len(exercises)):
        if(exercises[i].name == name):
            return i
    return -1

def sortExercises(exercises):
    size = len(exercises)
    for i in range(size):
        for j in range(i + 1, size):
            if(exercises[i].timesDone < exercises[j].timesDone or(
               exercises[i].timesDone == exercises[j].timesDone and
               exercises[i].name > exercises[j].name
               )):
                exercises[j], exercises[i] = exercises[i], exercises[j]
    return exercises

def main():
    data = open("U2.txt", "r")
    output = open("U2rez.txt", "w")

    exercises = []

    for i in range(int(next(data))):
        exerciseData = next(data)
        name = exerciseData[:20]
        timesDone = int(exerciseData[20:])
        exerciseIndex = findExerciseIndex(exercises, name)
        if(exerciseIndex == -1):
            exercises.append(Exercise(name, timesDone))
        else:
            exercises[exerciseIndex].timesDone += timesDone

    exercises = sortExercises(exercises)
    
    for exercise in exercises:
        output.write(f"{exercise.name} {exercise.timesDone}\n")
    
    data.close()
    output.close()

if __name__ == "__main__":
    main()