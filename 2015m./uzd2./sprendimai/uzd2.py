class Sheep:
    geneticSimilarity = 0
    def __init__(self, name, dnr):
        self.name = name
        self.dnr = dnr

def readData():
    data = open("U2.txt", "r")
    sheepCount, geneCount = next(data).split(" ")
    sheepCount = int(sheepCount)
    geneCount = int(geneCount)
    studiedSheepIndex = int(next(data)) - 1
    studiedSheep = None

    sheep = []

    for i in range(sheepCount):
        sheepData = next(data)
        name = sheepData[:10]
        dnr = sheepData[11:]
        if(i == studiedSheepIndex):
            studiedSheep = Sheep(name, dnr)
            continue
        sheep.append(Sheep(name, dnr))

    data.close()

    return studiedSheep, geneCount, sheep

def outputData(studiedSheep, sheep):
    output = open("U2rez.txt", "w")

    output.write(f"{studiedSheep.name}\n")
    for i in range(len(sheep)):
        output.write(f"{sheep[i].name} {sheep[i].geneticSimilarity}\n")

    output.close()

def sortSheep(sheep):
    size = len(sheep)
    for i in range(size):
        for j in range(i + 1, size):
            if(sheep[i].geneticSimilarity < sheep[j].geneticSimilarity or 
              (sheep[i].geneticSimilarity == sheep[j].geneticSimilarity and
               sheep[i].name > sheep[j].name)):
                sheep[j], sheep[i] = sheep[i], sheep[j]

    return sheep

def getGeneticSimilarity(dnr1, dnr2, geneCount):
    geneticSimilarity = 0
    for i in range(geneCount):
        if(dnr1[i] == dnr2[i]):
            geneticSimilarity += 1
    return geneticSimilarity
    
def main():
    studiedSheep, geneCount, sheep = readData()
    
    for i in range(len(sheep)):
        geneticSimilarity = getGeneticSimilarity(sheep[i].dnr, studiedSheep.dnr, geneCount)
        sheep[i].geneticSimilarity = geneticSimilarity
    
    sheep = sortSheep(sheep)

    outputData(studiedSheep, sheep)

if __name__ == "__main__":
    main()