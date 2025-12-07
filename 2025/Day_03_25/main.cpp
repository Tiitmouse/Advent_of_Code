#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void read_joltage(vector<string> &joltages){
    ifstream file("/Users/lorena/desktop/aoc/joltage.txt");
    if (!file) {
        cout << "ho ho hhooo oof";
        return;
    }
    cout << "reading joltages..." << endl;
    string line;
    while (getline(file, line)){
        joltages.push_back(line);
    }
    cout << "joltages read..." << endl;
}

int sumMaxJoltages(vector<string> &joltages) {
    cout << "summing joltages..." << endl;
    int totalSum = 0;

    for (const auto &joltage : joltages) {
        int maxJoltageForBank = 0;

        for (size_t i = 0; i < joltage.size(); ++i) {
            int tens = joltage[i] - '0';

            for (size_t j = i + 1; j < joltage.size(); ++j) {
                int ones = joltage[j] - '0';

                int currentJoltage = (tens * 10) + ones;

                if (currentJoltage > maxJoltageForBank) {
                    maxJoltageForBank = currentJoltage;
                }
            }
        }

        cout << "processing joltage: " << joltage << endl;
        cout << "max joltage for this bank: " << maxJoltageForBank << endl;

        totalSum += maxJoltageForBank;
    }

    cout << "joltages summed..." << endl;
    return totalSum;
}

int main() {
    vector<string> joltages;
    read_joltage(joltages);
    int totalOutputJoltge = sumMaxJoltages(joltages);

    cout << "total output joltage: " << totalOutputJoltge << endl;

    return 0;
}


