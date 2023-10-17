def getTimeRan(mHourStart, mMinStart, mHourEnd, mMinEnd, 
               eHourStart, eMinStart, eHourEnd, eMinEnd):
    minutesRan = (mHourEnd * 60 + mMinEnd - mHourStart * 60 - mMinStart +
                  eHourEnd * 60 + eMinEnd - eHourStart * 60 - eMinStart )
    return minutesRan

def main():
    data = open("U1.txt", "r")
    output = open("U1rez.txt", "w")

    minTime = 10000000
    minDays = []

    for i in range(int(next(data))):
        dayData = next(data).split(" ")
        dayData = [int(o) for o in dayData]
        if(dayData[1:5] == [0,0,0,0] or dayData[5:9] == [0,0,0,0]):
            continue
        minutesRan = getTimeRan(dayData[1], dayData[2], dayData[3], dayData[4],
                                dayData[5], dayData[6], dayData[7], dayData[8])
        if(minutesRan == minTime):
            minDays.append(str(dayData[0]))
        elif(minutesRan < minTime):
            minTime = minutesRan
            minDays = [str(dayData[0])]

    

    output.write("Minimalus laikas\n")
    output.write(f"{minTime}\n")
    output.write("Dienos\n")
    output.write(" ".join(minDays))

    data.close()
    output.close()

if __name__ == "__main__":
    main()