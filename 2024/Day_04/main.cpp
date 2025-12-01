//
// Created by Lorena Kovačić on 04.12.2024..
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void read_words(vector<string> &words) {
    ifstream file("word_search.txt");
    if (!file) {
        cout << "word search file not found";
        return;
    }
    string line;
    while (getline(file, line)) {
        words.push_back(line);
    }
}

bool search_xmas(const vector<string> &grid, const string &word, int row, int col, int row_dir, int col_dir) {
    int word_len = word.length();
    int rows = grid.size();
    int cols = grid[0].size();

    for (int i = 0; i < word_len; ++i) {
        int new_row = row + i * row_dir;
        int new_col = col + i * col_dir;

        if (new_row < 0 || new_row >= rows || new_col < 0 || new_col >= cols || grid[new_row][new_col] != word[i]) {
            return false;
        }
    }
    return true;
}

int count_xmas_occurrences(const vector<string> &grid, const string &word) {
    int count = 0;
    int rows = grid.size();
    int cols = grid[0].size();
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {1, 1}, {1, -1}, {0, -1}, {-1, 0}, {-1, -1}, {-1, 1}};

    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            for (const auto &dir : directions) {
                if (search_xmas(grid, word, row, col, dir.first, dir.second)) {
                    ++count;
                }
            }
        }
    }
    return count;
}

bool search_x_mas(const vector<string> &grid, int row, int col) {
    int rows = grid.size();
    int cols = grid[0].size();

    if (row + 2 >= rows || col - 1 < 0 || col + 1 >= cols) {
        return false;
    }

    bool pattern1 = (grid[row][col] == 'M' && grid[row][col + 2] == 'S' &&
                     grid[row + 1][col + 1] == 'A' &&
                     grid[row + 2][col] == 'S' && grid[row + 2][col + 2] == 'M');

    bool pattern2 = (grid[row][col] == 'S' && grid[row][col + 2] == 'M' &&
                     grid[row + 1][col + 1] == 'A' &&
                     grid[row + 2][col] == 'M' && grid[row + 2][col + 2] == 'S');

    return pattern1 || pattern2;
}

int count_x_mas_occurrences(const vector<string> &grid) {
    int count = 0;
    int rows = grid.size();
    int cols = grid[0].size();

    for (int row = 0; row < rows - 2; ++row) {
        for (int col = 1; col < cols - 1; ++col) {
            if (search_x_mas(grid, row, col)) {
                ++count;
            }
        }
    }
    return count;
}

int main() {
    vector<string> words;
    read_words(words);

    int xmas_occurrences = count_xmas_occurrences(words, "XMAS");
    int x_mas_occurrences = count_x_mas_occurrences(words);

    cout << "XMAS was found " << xmas_occurrences << " times " << endl;
    cout << "MAS was found in X " << x_mas_occurrences << " times " << endl;

    return 0;
}