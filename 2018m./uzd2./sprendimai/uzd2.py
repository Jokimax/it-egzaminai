class Contestant:
    def __init__(self, name, time):
        self.name = name
        self.time = time

def getIndexByName(name, arr):
    for i in range(len(arr)):
        if(arr[i].name == name):
            return i

def sortContestants(contestants):
    size = len(contestants)
    for i in range(size):
        for j in range(i + 1, size):
            if(contestants[i].time > contestants[j].time or 
                (contestants[i].time == contestants[j].time
                and contestants[i].name > contestants[j].name)):
                contestants[i], contestants[j] = contestants[j], contestants[i]
    return contestants

def writeOutput(contestants):
    output = open("U2rez.txt", "w")

    for i in range(len(contestants)):
        time = contestants[i].time
        seconds = time%60
        minutes = int((time-seconds)/60)
        output.write(contestants[i].name + " " * (20-len(contestants[i].name)) + str(minutes)+ " " + str(seconds) + "\n")

    output.close()

def main():
    data = open("U2.txt", "r")

    contestants = []
    finishedContestants = []

    for i in range(int(next(data))):
        contestantData = next(data)
        name = contestantData[:19]
        contestantData = contestantData[20:]
        contestantData = contestantData.split(" ")
        contestantData = [int(i) for i in contestantData]
        startTime = contestantData[0] * 3600 + contestantData[1] * 60 + contestantData[2]
        contestants.append(Contestant(name, startTime))

    for i in range(int(next(data))):
        contestantData = next(data)
        name = contestantData[:19]
        contestantData = contestantData[20:]
        contestantData = contestantData.split(" ")
        contestantData = [int(i) for i in contestantData]
        startTime = contestants[getIndexByName(name, contestants)].time
        endTime = contestantData[0] * 3600 + contestantData[1] * 60 + contestantData[2]
        finishedContestants.append(Contestant(name, endTime - startTime))
    
    finishedContestants = sortContestants(finishedContestants)

    writeOutput(finishedContestants)

    data.close()

if __name__ == "__main__":
    main()