class Company:
    def __init__(self, name, x, y):
        self.name = name
        self.x = x
        self.y = y

def getTravelDistance(company):
    return (abs(company.x) + abs(company.y)) * 2

def readData():
    data = open("U1.txt", "r")

    dayInfo = next(data).split(" ")
    companyCount = int(dayInfo[0])
    maxKm = int(dayInfo[1])

    companies = [None]*companyCount
    for i in range(companyCount):
        companyInfo = next(data)
        companyName = companyInfo[:10]
        companyInfo = companyInfo[11:].split(" ")
        companyInfo = [int(o) for o in companyInfo]

        companies[i] = Company(companyName, companyInfo[0], companyInfo[1])
    
    data.close()
    
    return maxKm, companies

def writeOutput(companiesVisited, km, lastCompanyVisited):
    output = open("U1rez.txt", "w")
    output.write(f"{companiesVisited} {km} {lastCompanyVisited}")
    output.close()

def main():
    maxKm, companies = readData()

    i = 0
    companyCount = len(companies)
    km = 0
    while(i < companyCount and km < maxKm):
        newKm = km + getTravelDistance(companies[i])
        if(newKm > maxKm):
            break
        km = newKm
        i += 1

    writeOutput(i, km, companies[i - 1].name)

if __name__ == "__main__":
    main()