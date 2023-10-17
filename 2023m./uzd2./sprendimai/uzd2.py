class Password:
    similarPasswords = []
    passwordStrength = ""

    def __init__(self, password, wordCount, capitalCount, lowerCount, numberCount, specialCount):
        self.password = password
        self.wordCount = wordCount
        self.capitalCount = capitalCount
        self.lowerCount = lowerCount
        self.numberCount = numberCount
        self.specialCount = specialCount

def getSimilarity(password1, password2):
    passwordDif = (abs(password1.wordCount - password2.wordCount) +
                   abs(password1.capitalCount - password2.capitalCount) +
                   abs(password1.lowerCount - password2.lowerCount) +
                   abs(password1.numberCount - password2.numberCount) +
                   abs(password1.specialCount - password2.specialCount))
    return passwordDif


def main():
    data = open("U2.txt", "r")
    output = open("U2rez.txt", "w")

    size = next(data).split(" ")
    size = [int(o) for o in size]

    userPasswords = [None]*size[0]
    systemPasswords = [None]*size[1]

    for i in range(size[0]):
        passwordData = next(data)
        password = passwordData[:15]
        passwordData = passwordData[16:].split(" ")
        passwordData = [int(o) for o in passwordData]
        userPasswords[i] = Password(password, passwordData[0], passwordData[1], 
                                    passwordData[2], passwordData[3], passwordData[4])
        
    for i in range(size[1]):
        passwordData = next(data)
        password = passwordData[:15]
        passwordData = passwordData[16:].split(" ")
        passwordData = [int(o) for o in passwordData[:5]] + [passwordData[5]]
        systemPasswords[i] = Password(password, passwordData[0], passwordData[1], 
                                      passwordData[2], passwordData[3], passwordData[4])
        systemPasswords[i].passwordStrength = passwordData[5][:-1]
    
    for i in range(size[0]):
        minDif = 100000000
        strength = ""
        similarPasswords = []
        for j in range(size[1]):
            passwordDif = getSimilarity(userPasswords[i], systemPasswords[j])
            if(passwordDif == minDif):
                similarPasswords.append(systemPasswords[j])
            elif(passwordDif < minDif):
                similarPasswords = [systemPasswords[j]]
                minDif = passwordDif
                strength = systemPasswords[j].passwordStrength
        similarPasswords.sort(key = lambda x: x.wordCount, reverse=True)
        if(strength == "Vidutinis"):
            output.write(f"{userPasswords[i].password} {strength} {minDif}\n")
        else:
            output.write(f"{userPasswords[i].password} {strength}   {minDif}\n")
        for password in similarPasswords:
            output.write(f"{password.password}\n")


    data.close()
    output.close()

if __name__ == "__main__":
    main()