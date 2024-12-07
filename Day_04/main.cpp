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

bool search_word(const vector<string> &grid, const string &word, int row, int col, int row_dir, int col_dir) {
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

int count_word_occurrences(const vector<string> &grid, const string &word) {
    int count = 0;
    int rows = grid.size();
    int cols = grid[0].size();
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {1, 1}, {1, -1}, {0, -1}, {-1, 0}, {-1, -1}, {-1, 1}};

    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            for (const auto &dir : directions) {
                if (search_word(grid, word, row, col, dir.first, dir.second)) {
                    ++count;
                }
            }
        }
    }
    return count;
}

int main() {
    vector<string> words;
    read_words(words);

    string word_to_find = "XMAS";
    int occurrences = count_word_occurrences(words, word_to_find);

    cout << "XMAS was found " << occurrences << " times " << endl;

    return 0;
}