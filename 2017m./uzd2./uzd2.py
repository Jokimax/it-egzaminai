class Pixel:
    def __init__(self, r = 255, g = 255, b = 255):
        self.r = r
        self.g = g
        self.b = b

def placeSquare(x, y, offsetX, offsetY, image, newPixel):
    endPosX = x + offsetX
    endPosY = y + offsetY
    
    if(endPosX - 1 >= len(image[0])):
        pixelsToAdd = endPosX - len(image[0])
        for i in range(len(image)):
            image[i] = image[i] + [Pixel() for i in range(pixelsToAdd)]
    
    if(endPosY - 1 >= len(image)):
        image.append([Pixel() for j in range(len(image[0]))])

    for i in range(y, endPosY):
        for j in range(x, endPosX):
            image[i][j] = newPixel
    
    return image

def main():
    image = [[Pixel()]]

    data = open("U2.txt", "r")
    output = open("U2rez.txt", "w")

    squareCount = int(next(data))

    for i in range(squareCount):
        newSquare = next(data).split(" ")
        newSquare = [int(i) for i in newSquare]
        newPixel = Pixel(newSquare[4], newSquare[5], newSquare[6])
        image = placeSquare(newSquare[0], newSquare[1], newSquare[2], newSquare[3], image, newPixel)

    output.write(str(len(image)) + " " + str(len(image[0])) + "\n")

    for i in range(len(image)):
        for j in range(len(image[0])):
            output.write(str(image[i][j].r) + " " + str(image[i][j].g) + " " + str(image[i][j].b) + " " "\n")
    
    data.close()
    output.close()

if __name__ == "__main__":
    main()