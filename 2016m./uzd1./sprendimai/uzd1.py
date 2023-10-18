def getMaxBackpackWeight():
    data = open("U1.txt", "r")

    maxWeight = 0

    for i in range(int(next(data))):
        weight = int(next(data))
        if(maxWeight < weight):
            maxWeight = weight

    data.close()

    return maxWeight

def countBackpacksWithHalfWeight(weight):
    data = open("U1.txt", "r")

    weight *= 0.5

    backpackCount = 0

    for i in range(int(next(data))):
        if(weight >= int(next(data))):
            backpackCount += 1

    data.close()

    return backpackCount


def main():
    output = open("U1rez.txt", "w")

    maxWeight = getMaxBackpackWeight()
    backpackCount = countBackpacksWithHalfWeight(maxWeight)

    output.write(f"{maxWeight} {backpackCount}")

    output.close()


if __name__ == "__main__":
    main()