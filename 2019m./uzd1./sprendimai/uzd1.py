def countContainers(l1, l3, l5, oil):
    while(oil >= 5 and l5 > 0):
        oil -= 5
        l5 -= 1
    while(oil >= 3 and l3 > 0):
        oil -= 3
        l3 -= 1
    while(oil >= 1 and l1 > 0):
        oil -= 1
        l1 -= 1
    return [l1, l3, l5], oil

def countExtraContainers(oil):
    l5, l3, l1 = 0, 0, 0
    while(oil >= 5):
        l5 += 1
        oil -= 5
    while(oil >= 3):
        l3 += 1
        oil -= 3
    while(oil >= 1):
        l1 += 1
        oil -= 1
    return [l1, l3, l5]

def main():
    data = open("U1.txt", "r")
    output = open("U1rez.txt", "w")

    oilData = data.readline().split(" ")
    oilData = [int(i) for i in oilData]
    containersLeft, oilLeft = countContainers(oilData[0], oilData[1], oilData[2], oilData[3])

    output.write(str(oilData[0] - containersLeft[0]) + " " + str(oilData[1] - containersLeft[1])
                 + " " + str(oilData[2] - containersLeft[2]) + " " + str(oilLeft) + "\n")
    output.write(str(containersLeft[0]) + " " + str(containersLeft[1]) + " " + str(containersLeft[2]) + "\n")

    extraContainers = countExtraContainers(oilLeft)

    output.write(str(extraContainers[0]) + " " + str(extraContainers[1]) + " " + str(extraContainers[2]) + "\n")

    oilPrice = data.readline().split(" ")
    oilPrice = [int(i) for i in oilPrice]

    profit = (-oilPrice[0] + (oilData[0] - containersLeft[0] + extraContainers[0]) * oilPrice[1] + 
                             (oilData[1] - containersLeft[1] + extraContainers[1]) * oilPrice[2] + 
                             (oilData[2] - containersLeft[2] + extraContainers[2]) * oilPrice[3] )
    
    output.write(str(profit))

    data.close()
    output.close()

if __name__ == "__main__":
    main()