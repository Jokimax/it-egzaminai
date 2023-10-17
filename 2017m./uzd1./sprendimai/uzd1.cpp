#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<string> hexadecimalValues = {
    "0", "1", "2", "3", "4",
    "5", "6", "7", "8", "9",
    "A", "B", "C", "D", "E", "F"
};

string convertToHexadecimal(int num) {
    int hexadecimalValue = num % 16;
    string hexadecimal = hexadecimalValues[hexadecimalValue];
    num -= hexadecimalValue;
    hexadecimalValue = num / 16;
    hexadecimal = hexadecimalValues[hexadecimalValue] + hexadecimal;
    return hexadecimal;
}

int main() {
    ifstream data("U1.txt");
    ofstream output("U1rez.txt");

    int height, width;
    data >> height >> width;

    int xPos = 0;

    for (int i = 0; i < height * width; i++) {
        xPos += 1;
        vector<int> rgb(3);
        data >> rgb[0] >> rgb[1] >> rgb[2];

        for (int j = 0; j < 3; ++j) {
            string hexadecimal = convertToHexadecimal(rgb[j]);
            output << hexadecimal;
        }

        if (xPos == width) {
            output << "\n";
            xPos = 0;
        }
        else {
            output << ";";
        }
    }

    data.close();
    output.close();

    return 0;
}
