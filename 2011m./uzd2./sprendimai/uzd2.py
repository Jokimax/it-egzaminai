class Performance:
    score = 0
    def __init__(self, name, technique, artistry) -> None:
        self.name = name
        self.technique = technique
        self.artistry = artistry

def sortPerformances(performances):
    for i in range(len(performances)):
        for j in range(i + 1, len(performances)):
            if(performances[i].score < performances[j].score):
                performances[i], performances[j] = performances[j], performances[i]
    return performances

def countScore(scores):
    scores.remove(min(scores))
    scores.remove(max(scores))
    return sum(scores)

def main():
    input = open("U2.txt", "r")

    data = next(input).split(" ")

    contestantCount = int(data[0])
    judgeCount = data[1]
    contestants = []
    performances = []
    
    while(len(contestants) < contestantCount):
        teamName = next(input)
        teamName = teamName[:-2]
        names = teamName.split(" ")

        if(names[0] not in contestants):
            contestants.append(data[0])
        if(names[1] not in contestants):
            contestants.append(data[1])
        
        technique = next(input).split(" ")
        technique = [int(o) for o in technique]
        artistry = next(input).split(" ")
        artistry = [int(o) for o in artistry]

        performances.append(Performance(teamName, technique, artistry))
    
    for performance in performances:
        score = countScore(performance.technique)
        score += countScore(performance.artistry)
        performance.score = score
    
    performances = sortPerformances(performances)

    output = open("U2rez.txt", "w")

    for performance in performances:
        output.write(f'{performance.name}{" "*(20-len(performance.name))}{performance.score}\n')

    input.close()
    output.close()

if __name__ == "__main__":
    main()