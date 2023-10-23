#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

struct Path {
    vector<int> path;
    int length;
    string result;
};

int main() {
    ifstream data("U2.txt");
    ofstream output("U2rez.txt");

    int startPosX, startPosY, endPosX, endPosY;
    data >> startPosX >> startPosY;
    data >> endPosX >> endPosY;

    int pathCount;
    data >> pathCount;
    vector<Path> paths(pathCount);

    data.ignore();

    for (int i = 0; i < pathCount; ++i) {
        int posX = startPosX;
        int posY = startPosY;

        string line;

        getline(data, line);
        istringstream datasream(line);

        int pathDataSize;
        datasream >> pathDataSize;
        vector<int> pathData(pathDataSize);

        paths[i].result = "sekos pabaiga       ";

        for (int j = 0; j < pathDataSize; ++j) {
            datasream >> pathData[j];
            if (pathData[j] == 1) {
                posY += 1;
            } else if (pathData[j] == 2) {
                posX += 1;
            } else if (pathData[j] == 3) {
                posY -= 1;
            } else {
                posX -= 1;
            }

            paths[i].path.push_back(pathData[j]);
            paths[i].length++;

            if (posX == endPosX && posY == endPosY) {
                paths[i].result = "pasiektas tikslas   ";
                break;
            }
        }
    }

    for (const Path& path : paths) {
        output << path.result << " ";
        for (int point : path.path) {
            output << point << " ";
        }
        output << path.length << "\n";
    }

    data.close();
    output.close();
}

