#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void read_rotations(vector<string> &rotations){
    ifstream file("/Users/lorena/desktop/aoc/rotations.txt");
    if (!file) {
        cout << "ho ho hhooo oof";
        return;
    }
    cout << "reading rotations..." << endl;
    string line;
    while (getline(file, line)){
        rotations.push_back(line);
    }
    cout << "rotations read..." << endl;
}

int dialZeroPoints(vector<string> &rotations) {
    cout << "rotation dials..." << endl;
    int min = 0, max = 99, point = 50, zeros = 0;

    for (const string &rotation : rotations) {
        char direction = rotation[0];
        int steps = stoi(rotation.substr(1));

        if (direction == 'L') {
            point -= steps;
            while (point < min) {
                point += (max + 1);
            }
        } else if (direction == 'R') {
            point += steps;
            while (point > max) {
                point -= (max + 1);
            }
        }
        if (point == 0) {
            zeros++;
        }

    }
    cout << "all dials rotated..." << endl;
    return zeros;
}

int dialZeroHits(vector<string> &rotations) {
    cout << "rotation dials..." << endl;
    int min = 0, max = 99, point = 50, zeros = 0;

    for (const string &rotation : rotations) {
        char direction = rotation[0];
        int steps = stoi(rotation.substr(1));

        if (direction == 'L') {
            point -= steps;
            while (point < min) {
                point += (max + 1);
                cout << "zeros hit" << endl;
                zeros++;
            }
        } else if (direction == 'R') {
            point += steps;
            while (point > max) {
                point -= (max + 1);
                cout << "zeros hit" << endl;
                zeros++;
            }
        }

    }
    cout << "all dials rotated..." << endl;
    return zeros;
}

int main() {
    vector<string> rotations;
    read_rotations(rotations);
    int Ppassword = dialZeroPoints(rotations);
    int Hpassword = dialZeroHits(rotations);
    cout << "0 amount password is : " << Ppassword << endl;
    cout << "0x434C49434B password is : " << Hpassword << endl;

    return 0;
}


