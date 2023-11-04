#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Company {
public:
    string name;
    int x;
    int y;

    Company(string name, int x, int y) : name(name), x(x), y(y) {}
};

int getTravelDistance(const Company& company) {
    return (abs(company.x) + abs(company.y)) * 2;
}

int readData(vector<Company>& companies) {
    ifstream data("U1.txt");

    string dayInfo;
    int companyCount, maxKm;
    data >> companyCount >> maxKm;

    for (int i = 0; i < companyCount; ++i) {
        string companyName;
        int x, y;
        data >> companyName >> x >> y;
        companies.push_back(Company(companyName, x, y));
    }

    data.close();

    return maxKm;
}

void writeOutput(int companiesVisited, int km, string lastCompanyVisited) {
    ofstream output("U1rez.txt");
    output << companiesVisited << " " << km << " " << lastCompanyVisited;
    output.close();
}

int main() {
    vector<Company> companies;

    int maxKm = readData(companies);

    int i = 0;
    int km = 0;
    while (i < companies.size()) {
        int newKm = km + getTravelDistance(companies[i]);
        if (newKm > maxKm) {
            break;
        }
        km = newKm;
        i++;
    }

    writeOutput(i, km, companies[i - 1].name);

    return 0;
}
