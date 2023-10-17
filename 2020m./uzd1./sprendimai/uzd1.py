monthDays = {"6": 0, "7": 30, "8": 61}

class Flower:
    def __init__(self, bloom, end):
        self.bloom = bloom
        self.end = end
 
def getMaxBloomingFlowerDayIndex(flowers, maxBloomingFlower):
    for i in range(len(flowers)):
        if(flowers[i] == maxBloomingFlower):
            return i

def getMaxBloomingFlowerEndDay(flowers, maxBloomingFlowerDay):
    for i in range(maxBloomingFlowerDay, len(flowers)):
        if(flowers[i] != flowers[i - 1]):
            return i + 1
    return 92

def getDate(day):
    if(day > 61):
        return "8 " + str(day - 61)
    elif(day > 30): 
        return "7 " + str(day - 30)
    return "6 " + str(day)

def main():
    data = open("U1.txt", "r")
    output = open("U1rez.txt", "w")

    count = int(next(data))
    flowers = [None]*count

    for i in range(count):
        flowerData = next(data).split(" ")
        bloom = monthDays[flowerData[1]] + int(flowerData[2]) - 1
        end = monthDays[flowerData[3]] + int(flowerData[4]) - 1
        flowers[i] = Flower(bloom, end)

    flowerCount = [None]*92
    bloomingFlowers = 0

    for i in range(0, 92):
        for flower in flowers:
            if(flower.bloom == i):
                bloomingFlowers += 1
            elif(flower.end == i):
                bloomingFlowers -= 1
                flowers.remove(flower)
        flowerCount[i] = bloomingFlowers
    
    maxBloomingFlowers = max(flowerCount)
    maxBloomingFlowersDayIndex = getMaxBloomingFlowerDayIndex(flowerCount, maxBloomingFlowers)
    maxBloomingFlowersDay = maxBloomingFlowersDayIndex + 1
    maxBloomingFlowersEndDay = getMaxBloomingFlowerEndDay(flowerCount, maxBloomingFlowersDay)

    output.write(str(maxBloomingFlowers) + "\n")
    output.write(getDate(maxBloomingFlowersDay) + "\n")
    output.write(getDate(maxBloomingFlowersEndDay))

    data.close()
    output.close()

if __name__ == "__main__":
    main()