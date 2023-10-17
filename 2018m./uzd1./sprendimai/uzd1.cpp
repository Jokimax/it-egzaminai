#include <iostream>
#include <fstream>

using namespace std;

int countFlags(int g, int z, int r) {
    return min(min(g / 2, z / 2), r / 2);
}

int main() {
    ifstream data("U1.txt");
    ofstream output("U1rez.txt");

    int g = 0, z = 0, r = 0;

    int n;
    data >> n;

    for (int i = 0; i < n; ++i) {
        char color;
        int count;
        data >> color >> count;
        if (color == 'G') {
            g += count;
        }
        else if (color == 'Z') {
            z += count;
        }
        else {
            r += count;
        }
    }

    int flags = countFlags(g, z, r);

    g -= flags * 2;
    z -= flags * 2;
    r -= flags * 2;

    output << flags << "\n";
    output << "G = " << g << "\n";
    output << "Z = " << z << "\n";
    output << "R = " << r << "\n";

    data.close();
    output.close();

    return 0;
}
