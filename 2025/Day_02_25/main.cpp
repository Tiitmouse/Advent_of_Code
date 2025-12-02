#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

void read_ranges(vector<pair<long long, long long>> &ranges) {
    ifstream file("/Users/lorena/desktop/ranges.txt");
    if (!file) {
        cout << "ho ho hhooo oof";
        return;
    }
    cout << "reading ranges..." << endl;
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string range;
        while (getline(ss, range, ',')) {
            size_t dash = range.find('-');
            if (dash != string::npos) {
                string start_str = range.substr(0, dash);
                string end_str = range.substr(dash + 1);

                long long start = stoll(start_str);
                long long end = stoll(end_str);
                ranges.emplace_back(start, end);
            }
        }
    }
    cout << "ranges read..." << endl;
}

long long invaliIdSum(vector<pair<long long, long long>> &ranges) {
    long long iidsum = 0;
    cout << "finding invalid ids..." << endl;

    for (const auto &range : ranges) {
        long long start = range.first;
        long long end = range.second;

        for (long long id = start; id <= end; ++id) {
            string id_str = to_string(id);

            regex pattern(R"((\d+)\1)");
            if (regex_match(id_str, pattern)) {
                iidsum += id;
            }
        }
    }

    cout << "invalid ids found..." << endl;
    return iidsum;
}

int main() {
    vector<pair<long long, long long>> ranges;
    read_ranges(ranges);
    long long sum = invaliIdSum(ranges);
    cout << "sum of invalid ids: " << sum << endl;
    return 0;
}