class Cls:
    studentCount = 1
    def __init__(self, category, kmWalked):
        self.category = category
        self.kmWalked = kmWalked

def main():
    data = open("U1.txt", "r")
    output = open("U1rez.txt", "w")


    classes = []

    for i in range(int(next(data))):
        studentData = next(data).split(" ")
        studentData = [int(o) for o in studentData]
        cmWalked = 0
        for j in range(2, 9):
            if(studentData[j] == 0):
                cmWalked = 0
                break
            cmWalked += studentData[j] * studentData[1]
        if(cmWalked == 0):
            continue
        kmWalked = round(cmWalked * 0.00001, 2)
        foundClass = False
        for j in range(len(classes)):
            if(classes[j].category == studentData[0]):
                classes[j].studentCount += 1
                classes[j].kmWalked += kmWalked
                foundClass = True
                break
        if(not foundClass):
            classes.append(Cls(studentData[0], kmWalked))

    for cls in classes:
        output.write(f"{cls.category} {cls.studentCount} {cls.kmWalked}\n")

    data.close()
    output.close()

if __name__ == "__main__":
    main()