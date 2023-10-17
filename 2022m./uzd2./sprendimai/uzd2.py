class Exercise:
    daysDone = 0
    morningsDone = 0
    middaysDone = 0
    eveningsDone = 0
    timeSpent = 0
    def __init__(self, name):
        self.name = name

def findAllExercises():
    data = open("U2.txt", "r")

    exercises = [None]*5
    exercisesFound = 0

    for i in range(int(next(data))):
        dayData = next(data)
        while("  " in dayData):
            dayData = dayData.replace("  ", " ")
        dayData = dayData.split(" ")
        for j in range(int(dayData[0])):
            if dayData[1 + j * 3] not in exercises:
                exercises[exercisesFound] = dayData[1 + j * 3]
                exercisesFound += 1
                if(exercisesFound == 5):
                    break
        if(exercisesFound == 5):
            break

    data.close()

    return exercises

def main():
    data = open("U2.txt", "r")
    output = open("U2rez.txt", "w")

    exerciseNames = findAllExercises()
    exercises = [Exercise(exerciseNames[0]), Exercise(exerciseNames[1]), Exercise(exerciseNames[2]), Exercise(exerciseNames[3]), Exercise(exerciseNames[4])]

    for i in range(int(next(data))):
        dayData = next(data)
        while("  " in dayData):
            dayData = dayData.replace("  ", " ")
        dayData = dayData.split(" ")
        for exercise in exercises:
            if(exercise.name in dayData):
                exercise.daysDone += 1
        for j in range(int(dayData[0])):
            exerciseIndex = exerciseNames.index(dayData[1 + j * 3])
            if(dayData[2 + j * 3] == "Rytas"):
                exercises[exerciseIndex].morningsDone += 1
            elif(dayData[2 + j * 3] == "Diena"):
                exercises[exerciseIndex].middaysDone += 1
            else:
                exercises[exerciseIndex].eveningsDone += 1
            exercises[exerciseIndex].timeSpent += int(dayData[3 + j * 3])

    exercises.sort(key=lambda x: x.name)

    for exercise in exercises:
        filler = " "*(14-len(exercise.name))
        output.write(f"{exercise.name}{filler} {exercise.daysDone} {exercise.timeSpent}\n")
        if(exercise.morningsDone > 0): output.write(f"Rytas   {exercise.morningsDone}\n")
        if(exercise.middaysDone > 0):  output.write(f"Diena   {exercise.middaysDone}\n")
        if(exercise.eveningsDone > 0): output.write(f"Vakaras {exercise.eveningsDone}\n")

    data.close()
    output.close()

if __name__ == "__main__":
    main()