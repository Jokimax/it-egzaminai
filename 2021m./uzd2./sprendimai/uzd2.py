class Class:
    studentCount = 1
    def __init__(self, subject, student):
        self.subject = subject
        self.students = [student]

def findSubject(classes, subject):
    for i in range(len(classes)):
        if(classes[i].subject == subject):
            return i
    return -1

def sortClasses(classes):
    size = len(classes)
    for i in range(size):
        for j in range(i + 1, size):
            if(classes[i].studentCount < classes[j].studentCount or
              (classes[i].studentCount == classes[j].studentCount and
               classes[i].subject > classes[j].subject)):
                classes[j], classes[i] = classes[i], classes[j]
    return classes

def main():
    data = open("U2.txt", "r")
    output = open("U2rez.txt", "w")

    classes = []

    for i in range(int(next(data))):
        studentData = next(data).split(" ")
        studentData = studentData[:2] + [int(o) for o in studentData[2:]]
        gradeAverage = sum(studentData[3:])/studentData[2]
        if(gradeAverage < 9):
            continue

        subjectIndex = findSubject(classes, studentData[1])
        if(subjectIndex == -1):
            classes.append(Class(studentData[1], studentData[0]))
        else:
            classes[subjectIndex].students.append(studentData[0])
            classes[subjectIndex].studentCount += 1

    classes = sortClasses(classes)

    size = len(classes)

    if(size == 0):
        output.write("Neatitinka vidurkis")

    for i in range(size):
        output.write(f"{classes[i].subject} {classes[i].studentCount}\n")
        for j in range(classes[i].studentCount):
            output.write(f"{classes[i].students[j]}\n")

    data.close()
    output.close()

if __name__ == "__main__":
    main()