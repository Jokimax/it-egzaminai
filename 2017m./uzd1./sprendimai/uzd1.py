hexadecimalValues = ["0", "1", "2", "3", "4",
                     "5", "6", "7", "8", "9",
                     "A", "B", "C", "D", "E", "F"]

def convertToHexadecimal(num):
    hexadecimalValue = num%16
    hexadecimal = hexadecimalValues[hexadecimalValue]
    num -= hexadecimalValue
    hexadecimalValue = int(num/16)
    hexadecimal = hexadecimalValues[hexadecimalValue] + hexadecimal
    return hexadecimal

def main():
    data = open("U1.txt", "r")
    output = open("U1rez.txt", "w")

    size = next(data).split(" ")
    size = [int(i) for i in size]

    xPos = 0

    for i in range(size[0] * size[1]):
        xPos += 1
        rgb = next(data)
        rgb = rgb.split(" ")
        rgb = [int(i) for i in rgb]
        for i in range(3):
            hexadecimal = convertToHexadecimal(rgb[i])
            output.write(hexadecimal)
        if(xPos == size[1]):
            output.write("\n")
            xPos = 0
        else:
            output.write(";")

    data.close()
    output.close()

if __name__ == "__main__":
    main()