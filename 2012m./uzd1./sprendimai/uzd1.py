def getMaxElementIndex(arr):
    maxIndex = 0
    for i in range(1, len(arr)):
        if(arr[maxIndex] < arr[i]):
            maxIndex = i
    return maxIndex

def readData():
    data = open("U1.txt", "r")

    startingPlayers = [None]*5
    startingPlayerIndex = 0
    timeSpentOnBench = [0]*100
    timeSpentPlaying = [0]*100

    for i in range(int(next(data))):
        playerData = next(data).split(" ")
        playerData = [int(o) for o in playerData]
        if(playerData[2] > 0):
            startingPlayers[startingPlayerIndex] = str(playerData[0])
            startingPlayerIndex += 1
        for j in range(2, 2 + playerData[1]):
            if(playerData[j] > 0):
                timeSpentPlaying[playerData[0]] += playerData[j]
            else:
                timeSpentOnBench[playerData[0]] += abs(playerData[j])
    
    data.close()
    
    return startingPlayers, timeSpentOnBench, timeSpentPlaying

def main():
    output = open("U1rez.txt", "w")

    startingPlayers, timeSpentOnBench, timeSpentPlaying = readData()

    mostActivePlayer = getMaxElementIndex(timeSpentPlaying)
    leastActivePlayer = getMaxElementIndex(timeSpentOnBench)

    output.write(f"{' '.join(startingPlayers)}\n")
    output.write(f"{mostActivePlayer} {timeSpentPlaying[mostActivePlayer]}\n")
    output.write(f"{leastActivePlayer} {timeSpentOnBench[leastActivePlayer]}\n")

    output.close()

if __name__ == "__main__":
    main()