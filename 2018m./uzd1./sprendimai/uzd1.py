def countFlags(g, z, r):
    return min(g//2, z//2, r//2)

def main():
    data = open("U1.txt", "r")
    output = open("U1rez.txt", "w")

    g, z, r = 0, 0, 0

    for i in range(int(next(data))):
        color, count = next(data).split(" ")
        count = int(count)
        if(color == "G"):
            g += count
        elif(color[0] == "Z"):
            z += count
        else:
            r += count
    
    flags = countFlags(g, z, r)

    g -= flags * 2
    z -= flags * 2
    r -= flags * 2

    output.write(str(flags) + "\n")
    output.write("G = " + str(g) + "\n")
    output.write("Z = " + str(z) + "\n")
    output.write("R = " + str(r) + "\n")

    data.close()
    output.close()

if __name__ == "__main__":
    main()