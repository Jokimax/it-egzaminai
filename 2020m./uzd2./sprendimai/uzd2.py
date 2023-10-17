class Fisher:
    score = 0
    def __init__(self, name, fishes):
        self.name = name 
        self.fishes = fishes

class Fish:
    def __init__(self, name, weight):
        self.name = name
        self.weight = weight

def sortList(list, values):
    size = len(list)
    for i in range(size):
        for j in range(i + 1, size):
            if(values[i] < values[j] or 
                (values[i] == values[j]
                and list[i].name > list[j].name)):
                list[i], list[j] = list[j], list[i]
                values[j], values[i] = values[i], values[j]
    return list

def main():
    data = open("U2.txt", "r")
    output = open("U2rez.txt", "w")

    fishers = []

    for i in range(int(next(data))):
        fisherData = next(data)
        name = fisherData[:19]
        fishCaught = int(fisherData[20:])
        fishes = []
        for j in range(fishCaught):
            fishData = next(data)
            fishName = fishData[:19]
            weight = int(fishData[20:])
            fishes.append(Fish(fishName, weight))
        fishers.append(Fisher(name, fishes))

    fishes = []
    
    for i in range(int(next(data))):
        weight = 0
        fishData = next(data)
        name = fishData[:19]
        pointWorth = int(fishData[20:])
        for fisher in fishers:
            for fish in fisher.fishes:
                if(fish.name == name):
                    weight += fish.weight
                    fisher.score += pointWorth
                    if(fish.weight >= 200):
                        fisher.score += 30
                    else:
                        fisher.score += 10
        fishes.append(Fish(name, weight))

    fishers = sortList(fishers, [fisher.score for fisher in fishers])
    fishes = sortList(fishes, [fish.weight for fish in fishes])

    output.write("Dalyviai\n")

    for fisher in fishers:
        output.write(fisher.name + " " + str(fisher.score) + "\n")

    output.write("Laimikis\n")

    for fish in fishes:
        output.write(fish.name + " " + str(fish.weight) + "\n")
    
    data.close()
    output.close()

if __name__ == "__main__":
    main()