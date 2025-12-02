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

long long invaliIdSum_sq2(vector<pair<long long, long long>> &ranges) {
    long long iidsum = 0;

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
    return iidsum;
}

long long invaliIdSum_sq2m(vector<pair<long long, long long>> &ranges) {
    long long iidsum = 0;

    for (const auto &range : ranges) {
        long long start = range.first;
        long long end = range.second;

        for (long long id = start; id <= end; ++id) {
            string id_str = to_string(id);

            regex pattern(R"((\d+)\1+)");
            if (regex_match(id_str, pattern)) {
                iidsum += id;
            }
        }
    }
    return iidsum;
}

int main() {
    vector<pair<long long, long long>> ranges;
    read_ranges(ranges);
    cout << "finding invalid ids..." << endl;
    long long sumsq2 = invaliIdSum_sq2(ranges);
    cout << "sum of double sequence invalid ids: " << sumsq2 << endl;
    long long sumsqm = invaliIdSum_sq2m(ranges);
    cout << "sum of at least double sequence invalid ids: " << sumsqm << endl;
    return 0;
}