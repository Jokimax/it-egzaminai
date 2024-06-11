def countPairs(femaleGlovesLeft, femaleGlovesRight, maleGlovesLeft, maleGlovesRight):
    pairsFemale = 0
    pairsMale = 0

    i = 0
    while(i < len(femaleGlovesLeft)):
        for j in range(len(femaleGlovesRight)):
            if(femaleGlovesLeft[i] == femaleGlovesRight[j]):
                pairsFemale += 1
                femaleGlovesLeft.pop(i)
                femaleGlovesRight.pop(j)
                i -= 1
                break
        i += 1
    
    i = 0
    while(i < len(maleGlovesLeft)):
        for j in range(len(maleGlovesRight)):
            if(maleGlovesLeft[i] == maleGlovesRight[j]):
                pairsMale += 1
                maleGlovesLeft.pop(i)
                maleGlovesRight.pop(j)
                i -= 1
                break
        i += 1
    
    return pairsFemale, pairsMale

def countLeftovers(femaleGlovesLeft, femaleGlovesRight, maleGlovesLeft, maleGlovesRight):
    leftFemale = len(femaleGlovesLeft) + len(femaleGlovesRight)
    leftMale = len(maleGlovesLeft) + len(maleGlovesRight)
    return leftFemale, leftMale

def readData():
    data = open("U1.txt", "r")

    femaleGlovesLeft = []
    femaleGlovesRight = []
    maleGlovesLeft = []
    maleGlovesRight = []

    for i in range(int(next(data))):
        gloveData = next(data).split(" ")
        gloveData = [int(o) for o in gloveData]
        if(gloveData[0] == 3):
            if(gloveData[1] == 1):
                maleGlovesLeft.append(gloveData[2])
            else:
                maleGlovesRight.append(gloveData[2])
        else:
            if(gloveData[1] == 1):
                femaleGlovesLeft.append(gloveData[2])
            else:
                femaleGlovesRight.append(gloveData[2])

    data.close()
    
    return femaleGlovesLeft, femaleGlovesRight, maleGlovesLeft, maleGlovesRight

def main():
    output = open("U1rez.txt", "w")

    femaleGlovesLeft, femaleGlovesRight, maleGlovesLeft, maleGlovesRight = readData()

    pairsFemale, pairsMale = countPairs(femaleGlovesLeft, femaleGlovesRight, maleGlovesLeft, maleGlovesRight)
    leftFemale, leftMale = countLeftovers(femaleGlovesLeft, femaleGlovesRight, maleGlovesLeft, maleGlovesRight)

    output.write(f"{pairsFemale}\n")
    output.write(f"{pairsMale}\n")
    output.write(f"{leftFemale}\n")
    output.write(f"{leftMale}")

    output.close()

if __name__ == "__main__":
    main()