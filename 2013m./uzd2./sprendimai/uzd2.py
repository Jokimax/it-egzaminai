class City:
    def __init__(self, name = "", region = "", population = 100000000000):
        self.name = name
        self.region = region
        self.population = population

class Region:
    def __init__(self, name = "", minPopulation = 100000000000, population = 100000000000):
        self.name = name
        self.minPopulation = minPopulation
        self.population = population

def findRegionIndex(name, regions):
    for i in range(103):
        if(regions[i].name == ""):
            return -1
        elif(regions[i].name == name):
            return i
    return -1

def main():
    data = open("U2.txt", "r")
    output = open("U2rez.txt", "w")

    cities = [City()]*103
    cityCount = int(next(data))
    for i in range(cityCount):
        cityData = next(data)
        name = cityData[:20]
        region = cityData[21:34]
        population = int(cityData[35:])
        cities[i] = City(name, region, population)
    
    regions = [Region()]*103
    regionCount = 0

    for i in range(cityCount):
        regionIndex = findRegionIndex(cities[i].region, regions)
        if(regionIndex == -1):
            regions[regionCount] = Region(cities[i].region, cities[i].population, cities[i].population)
            regionCount += 1
        else:
            regions[regionIndex].population += cities[i].population
            if(regions[regionIndex].minPopulation > cities[i].population):
                regions[regionIndex].minPopulation = cities[i].population
    
    regions.sort(key = lambda x: (x.population, x.name))
    
    for i in range(103):
        if(regions[i].name == ""):
            break
        output.write(f"{regions[i].name} {regions[i].minPopulation} {regions[i].population}\n")

    data.close()
    output.close()

if __name__ == "__main__":
    main()