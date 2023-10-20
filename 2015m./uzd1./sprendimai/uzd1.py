def getTotalGrapesEaten(grapesEaten):
    grapesEatenCopy = grapesEaten
    grapesEaten = grapesEaten + [0]*10

    for i in range(10):
        for j in range(i + 1, i + 10 - grapesEatenCopy[i] + 1):
            grapesEaten[j] += 1
    return grapesEaten

def main():
    data = open("U1.txt", "r")
    output = open("U1rez.txt", "w")

    grapesEaten = next(data).split(" ")
    grapesEaten = [int(o) for o in grapesEaten]

    grapesEaten = getTotalGrapesEaten(grapesEaten)

    grapesEaten = [str(o) for o in grapesEaten]

    output.write(" ".join(grapesEaten))

    data.close()
    output.close()


if __name__ == "__main__":
    main()