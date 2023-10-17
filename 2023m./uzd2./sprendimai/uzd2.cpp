#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Password {
public:
    vector<Password> similarPasswords;
    string passwordStrength;
    string password;
    int wordCount;
    int capitalCount;
    int lowerCount;
    int numberCount;
    int specialCount;

    Password(const string& password, int wordCount, int capitalCount, int lowerCount, int numberCount, int specialCount)
        : password(password), wordCount(wordCount), capitalCount(capitalCount), lowerCount(lowerCount),
          numberCount(numberCount), specialCount(specialCount) {}
};

int getSimilarity(const Password& password1, const Password& password2) {
    int passwordDif = abs(password1.wordCount - password2.wordCount) +
                      abs(password1.capitalCount - password2.capitalCount) +
                      abs(password1.lowerCount - password2.lowerCount) +
                      abs(password1.numberCount - password2.numberCount) +
                      abs(password1.specialCount - password2.specialCount);
    return passwordDif;
}

int main() {
    ifstream data("U2.txt");
    ofstream output("U2rez.txt");

    int size[2];
    data >> size[0] >> size[1];

    vector<Password> userPasswords;
    vector<Password> systemPasswords;

    for (int i = 0; i < size[0]; ++i) {
        string password;
        data >> password;
        vector<int> passwordCounts(5);
        for (int j = 0; j < 5; ++j) {
            data >> passwordCounts[j];
        }
        userPasswords.push_back(Password(password, passwordCounts[0], passwordCounts[1],
                                    passwordCounts[2], passwordCounts[3], passwordCounts[4]));
    }

    for (int i = 0; i < size[1]; ++i) {
        string password;
        data >> password;
        vector<int> passwordCounts(5);
        for (int j = 0; j < 5; ++j) {
            data >> passwordCounts[j];
        }
        string strength;
        data >> strength;
        systemPasswords.push_back(Password(password, passwordCounts[0], passwordCounts[1],
                                      passwordCounts[2], passwordCounts[3], passwordCounts[4]));
        systemPasswords.back().passwordStrength = strength;
    }

    for (int i = 0; i < size[0]; ++i) {
        int minDif = 100000000;
        string strength = "";

        for (int j = 0; j < size[1]; ++j) {
            int passwordDif = getSimilarity(userPasswords[i], systemPasswords[j]);
            if (passwordDif == minDif) {
                userPasswords[i].similarPasswords.push_back(systemPasswords[j]);
            } else if (passwordDif < minDif) {
                userPasswords[i].similarPasswords = {systemPasswords[j]};
                minDif = passwordDif;
                strength = systemPasswords[j].passwordStrength;
            }
        }

        sort(userPasswords[i].similarPasswords.begin(), userPasswords[i].similarPasswords.end(),
             [](const Password& p1, const Password& p2) {
                 return p1.wordCount > p2.wordCount;
             });

        string filler = "                ";
        filler.erase(15 - userPasswords[i].password.length());
        if (strength == "Vidutinis") {
            output << userPasswords[i].password << filler << " " << strength << " " << minDif << "\n";
        } else {
            output << userPasswords[i].password << filler << " " << strength << "   " << minDif << "\n";
        }

        for (const Password& password : userPasswords[i].similarPasswords) {
            output << password.password << "\n";
        }
    }

    data.close();
    output.close();

    return 0;
}