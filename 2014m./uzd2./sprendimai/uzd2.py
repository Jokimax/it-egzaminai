class Path:
    path = []
    length = 0
    result = ""

def main():
    data = open("U2.txt", "r")
    output = open("U2rez.txt", "w")

    temp = next(data).split(" ")
    temp = [int(o) for o in temp]
    startPosX = temp[0]
    startPosY = temp[1]

    temp = next(data).split(" ")
    temp = [int(o) for o in temp]
    endPosX = temp[0]
    endPosY = temp[1]

    pathCount = int(next(data))
    paths = [None]*pathCount

    for i in range(pathCount):
        posX = startPosX
        posY = startPosY

        pathData = next(data).split(" ")
        pathData = [int(o) for o in pathData]
        pathTaken = []
        pathLength = 0
        pathResult = "sekos pabaiga       "

        for j in range(1, pathData[0] + 1):
            if(pathData[j] == 1):
                posY += 1
            elif(pathData[j] == 2):
                posX += 1
            elif(pathData[j] == 3):
                posY -= 1
            else:
                posX -= 1
            pathLength += 1
            pathTaken.append(str(pathData[j]))
            if(posX == endPosX and posY == endPosY):
                pathResult = "pasiektas tikslas   "
                break
        
        path = Path()
        path.path = pathTaken
        path.length = pathLength
        path.result = pathResult
        
        paths[i] = path

    for path in paths:
        output.write(f"{path.result} {' '.join(path.path)} {str(path.length)}\n")

    data.close()
    output.close()

if __name__ == "__main__":
    main()