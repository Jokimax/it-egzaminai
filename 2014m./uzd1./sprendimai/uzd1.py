def getWinningIdea(points):
    maxPoints = points[0]
    winningIdea = 1
    foundMultWinners = False
    for i in range(1, 3):
        if(points[i] > maxPoints):
            maxPoints = points[i]
            winningIdea = i + 1
            foundMultWinners = False
        elif(points[i] == maxPoints):
            foundMultWinners = True
    if(foundMultWinners):
        return -1
    return winningIdea

def getPoints(votes):
    if(votes[0] == votes[1] and votes[0] == votes[2]):
        return [0, 0, 0]
    maxVotes = max(votes)
    if(votes[0] == maxVotes):
        if(votes[1] == maxVotes):
            return [2, 2, 0]
        if(votes[2] == maxVotes):
            return [2, 0, 2]
        return [4, 0, 0]
    if(votes[1] == maxVotes):
        if(votes[2] == maxVotes):
            return [0, 2, 2]
        return [0, 4, 0]
    return [0, 0, 4]

def main():
    data = open("U1.txt", "r")
    output = open("U1rez.txt", "w")

    votes = [0, 0, 0]
    points = [0, 0, 0]

    for i in range(int(next(data))):
        sectorVotes = next(data).split(" ")
        sectorVotes = [int(o) for o in sectorVotes]
        votes[0] += sectorVotes[0]
        votes[1] += sectorVotes[1]
        votes[2] += sectorVotes[2]
        sectorPoints = getPoints(sectorVotes)
        points[0] += sectorPoints[0]
        points[1] += sectorPoints[1]
        points[2] += sectorPoints[2]

    points = [int(o) for o in points]

    winningIdea = getWinningIdea(points)
    if(winningIdea == -1):
        bossVotes = next(data).split(" ")
        bossVotes = [int(o) for o in bossVotes]
        points[0] += bossVotes[0]
        points[1] += bossVotes[1]
        points[2] += bossVotes[2]
        winningIdea = getWinningIdea(points)

    votes = [str(o) for o in votes]
    points = [str(o) for o in points]

    output.write(f"{' '.join(votes)}\n")
    output.write(f"{' '.join(points)}\n")
    output.write(f"{winningIdea}")

    data.close()
    output.close()


if __name__ == "__main__":
    main()