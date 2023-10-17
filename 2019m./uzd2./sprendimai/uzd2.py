class Contestant:
    def __init__(self, name, id, time):
        self.name = name
        self.id = id
        self.time = time

def getIndexById(id, arr):
    for i in range(len(arr)):
        if(arr[i].id == id):
            return i

def sortContestants(contestants):
    size = len(contestants)
    for i in range(size):
        for j in range(i + 1, size):
            if(contestants[i].time > contestants[j].time or (
                contestants[i].time == contestants[j].time
                and contestants[i].name > contestants[j].name)):
                contestants[j], contestants[i] = contestants[i], contestants[j]
    return contestants

def writeOutput(output, finishers, gender):
    output.write(gender + "\n")
    for i in range(len(finishers)):
        seconds = finishers[i].time % 60
        finishers[i].time -= seconds
        finishers[i].time /= 60
        minutes = int(finishers[i].time % 60)
        hours = int((finishers[i].time - minutes) / 60)
        output.write(str(finishers[i].id) + " " + finishers[i].name + " " * (20 - len(finishers[i].name)) + str(hours) + " " + str(minutes) + " " + str(seconds) + "\n") 

def main():
    data = open("U2.txt", "r")
    output = open("U2rez.txt", "w")

    contestants = []

    for i in range(int(next(data))):
        contestantData = next(data)
        name = contestantData[:19]
        contestantData = contestantData[20:].split(" ")
        contestantData = [int(o) for o in contestantData]
        startTime = contestantData[1] * 3600 + contestantData[2] * 60 + contestantData[3]
        contestants.append(Contestant(name, contestantData[0], startTime))

    femaleFinishers = []
    maleFinishers = []

    for i in range(int(next(data))):
        contestantData = next(data).split(" ")
        contestantData = [int(o) for o in contestantData]
        contestantIndex = getIndexById(contestantData[0], contestants)
        startTime = contestants[contestantIndex].time
        endTime = contestantData[1] * 3600 + contestantData[2] * 60 + contestantData[3]

        if(contestantData[0] >= 200):
            penaltyTime = (20 - contestantData[4] - contestantData[5] 
                              - contestantData[6] - contestantData[7]) * 60
            finishTime = endTime - startTime + penaltyTime
            maleFinishers.append(Contestant(contestants[contestantIndex].name, contestantData[0], finishTime))
        else:
            penaltyTime = (10 - contestantData[4] - contestantData[5]) * 60
            finishTime = endTime - startTime + penaltyTime
            femaleFinishers.append(Contestant(contestants[contestantIndex].name, contestantData[0], finishTime))
    
    femaleFinishers = sortContestants(femaleFinishers)
    maleFinishers = sortContestants(maleFinishers)

    writeOutput(output, femaleFinishers, "Merginos")
    writeOutput(output, maleFinishers, "Vaikinai")

    data.close()
    output.close()

if __name__ == "__main__":
    main()