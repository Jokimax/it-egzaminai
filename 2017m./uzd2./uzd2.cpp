#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Pixel {
public:
    int r;
    int g;
    int b;

    Pixel(int r = 255, int g = 255, int b = 255) : r(r), g(g), b(b) {}
};

vector<vector<Pixel>> placeSquare(int x, int y, int offsetX, int offsetY, vector<vector<Pixel>>& image, const Pixel& newPixel) {
    int endPosX = x + offsetX;
    int endPosY = y + offsetY;

    if (endPosX - 1 >= image[0].size()) {
        int pixelsToAdd = endPosX - image[0].size();
        for (auto& row : image) {
            row.insert(row.end(), pixelsToAdd, Pixel());
        }
    }

    if (endPosY - 1 >= image.size()) {
        image.resize(endPosY, vector<Pixel>(image[0].size(), Pixel()));
    }

    for (int i = y; i < endPosY; ++i) {
        for (int j = x; j < endPosX; ++j) {
            image[i][j] = newPixel;
        }
    }

    return image;
}

int main() {
    vector<vector<Pixel>> image(1, vector<Pixel>(1, Pixel()));

    ifstream data("U2.txt");
    ofstream output("U2rez.txt");

    int squareCount;
    data >> squareCount;

    for (int i = 0; i < squareCount; ++i) {
        int x, y, offsetX, offsetY, r, g, b;
        data >> x >> y >> offsetX >> offsetY >> r >> g >> b;
        Pixel newPixel(r, g, b);
        image = placeSquare(x, y, offsetX, offsetY, image, newPixel);
    }

    output << image.size() << " " << image[0].size() << "\n";

    for (const auto& row : image) {
        for (const Pixel& pixel : row) {
            output << pixel.r << " " << pixel.g << " " << pixel.b << " " << "\n";
        }
    }

    data.close();
    output.close();

    return 0;
}
