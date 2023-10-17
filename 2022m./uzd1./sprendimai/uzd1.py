class Contestant:
    def __init__(self, name, timeTaken, taskCompleted):
        self.name = name
        self.timeTaken = timeTaken
        self.tasksCompleted = taskCompleted

def getContestantStatictics(contestantData, taskCount, points, timeLimit):
    name = contestantData[:10]
    contestantData = contestantData[11:]
    contestantData = contestantData.split(" ")
    contestantData = [int(o) for o in contestantData]

    pointsEarned = 0
    timeTaken = 0
    tasksCompleted = 0
        
    for j in range(taskCount):
        if(contestantData[j] == 0):
                continue
        elif(contestantData[j] > timeLimit[j]):
            pointsEarned += points[j] // 2
        else:
            pointsEarned += points[j]
        timeTaken += contestantData[j]
        tasksCompleted += 1
    return name, pointsEarned, timeTaken, tasksCompleted

def main():
    data = open("U1.txt", "r")
    output = open("U1rez.txt", "w")

    taskCount = int(next(data))

    timeLimit = next(data).split(" ")
    timeLimit = [int(i) for i in timeLimit]
    points = next(data).split(" ")
    points = [int(i) for i in points]

    contestants = []

    maxPoints = 0

    for i in range(5):
        contestantData = next(data)

        name, pointsEarned, timeTaken, tasksCompleted = getContestantStatictics(
            contestantData, taskCount, points, timeLimit)

        if(pointsEarned > maxPoints):
            maxPoints = pointsEarned
            contestants = [Contestant(name, timeTaken, tasksCompleted)]
        elif(pointsEarned == maxPoints):
            contestants.append(Contestant(name, timeTaken, tasksCompleted))

    contestants.sort(key=lambda x: x.tasksCompleted)

    output.write(f"{maxPoints}\n")
    for i in range(len(contestants)):
        output.write(f"{contestants[i].name} {contestants[i].tasksCompleted} {contestants[i].timeTaken}\n")



    data.close()
    output.close()

if __name__ == "__main__":
    main()