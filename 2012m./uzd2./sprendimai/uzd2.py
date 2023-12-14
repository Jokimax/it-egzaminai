class God:
    def __init__(self, name, score):
        self.name = name
        self.score = score

def readData():
    data = open("U2.txt", "r")

    basicData = next(data).split(" ")

    numOfGods = int(basicData[0])
    numOfDice = int(basicData[1])

    gods = []
    for i in range(numOfGods):
        godData = next(data)
        name = godData[:10]
        score = 0
        godData = godData[10:].split(" ")
        for j in range(numOfDice):
            score += int(godData[j])
        gods.append(God(name, score))

    data.close()

    return gods

def findLord(gods):
    lordIndex = 0
    for i in range(1, len(gods)):
        if(gods[i].score > gods[lordIndex].score):
            lordIndex = i
    return gods[lordIndex]

def main():
    output = open("U2rez.txt", "w")

    gods = readData()
    lord = findLord(gods)

    output.write(f"{lord.name} {lord.score}")

    output.close()

if __name__ == "__main__":
    main()