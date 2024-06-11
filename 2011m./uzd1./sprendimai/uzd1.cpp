#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

pair<int, int> countPairs(vector<int> &femaleGlovesLeft, vector<int> &femaleGlovesRight, vector<int> &maleGlovesLeft, vector<int> &maleGlovesRight)
{
    int pairsFemale = 0;
    int pairsMale = 0;

    for (auto i = femaleGlovesLeft.begin(); i != femaleGlovesLeft.end();)
    {
        bool foundPair = false;
        for (auto j = femaleGlovesRight.begin(); j != femaleGlovesRight.end(); ++j)
        {
            if (*i == *j)
            {
                pairsFemale++;
                i = femaleGlovesLeft.erase(i);
                femaleGlovesRight.erase(j);
                i--;
                break;
            }
        }
        i++;
    }

    for (auto i = maleGlovesLeft.begin(); i != maleGlovesLeft.end();)
    {
        bool foundPair = false;
        for (auto j = maleGlovesRight.begin(); j != maleGlovesRight.end(); ++j)
        {
            if (*i == *j)
            {
                pairsMale++;
                i = maleGlovesLeft.erase(i);
                maleGlovesRight.erase(j);
                i--;
                break;
            }
        }
        i++;
    }

    return make_pair(pairsFemale, pairsMale);
}

pair<int, int> countLeftovers(const vector<int> &femaleGlovesLeft, const vector<int> &femaleGlovesRight, const vector<int> &maleGlovesLeft, const vector<int> &maleGlovesRight)
{
    int leftFemale = femaleGlovesLeft.size() + femaleGlovesRight.size();
    int leftMale = maleGlovesLeft.size() + maleGlovesRight.size();
    return make_pair(leftFemale, leftMale);
}

void readData(vector<int> &femaleGlovesLeft, vector<int> &femaleGlovesRight, vector<int> &maleGlovesLeft, vector<int> &maleGlovesRight)
{
    ifstream data("U1.txt");

    int n;
    data >> n;

    for (int i = 0; i < n; i++)
    {
        int type, side, size;
        data >> type >> side >> size;

        if (type == 3)
        {
            if (side == 1)
            {
                maleGlovesLeft.push_back(size);
            }
            else
            {
                maleGlovesRight.push_back(size);
            }
        }
        else
        {
            if (side == 1)
            {
                femaleGlovesLeft.push_back(size);
            }
            else
            {
                femaleGlovesRight.push_back(size);
            }
        }
    }

    data.close();
}

int main()
{
    ofstream output("U1rez.txt");

    vector<int> femaleGlovesLeft, femaleGlovesRight, maleGlovesLeft, maleGlovesRight;

    readData(femaleGlovesLeft, femaleGlovesRight, maleGlovesLeft, maleGlovesRight);

    auto [pairsFemale, pairsMale] = countPairs(femaleGlovesLeft, femaleGlovesRight, maleGlovesLeft, maleGlovesRight);
    auto [leftFemale, leftMale] = countLeftovers(femaleGlovesLeft, femaleGlovesRight, maleGlovesLeft, maleGlovesRight);

    output << pairsFemale << endl;
    output << pairsMale << endl;
    output << leftFemale << endl;
    output << leftMale << endl;

    output.close();

    return 0;
}
