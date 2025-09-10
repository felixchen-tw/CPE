#include <iostream>
#include <sstream>
#include <map>
using namespace std;

int main() {
    int line = 0;
    cin >> line;
    map<string, int> mp;
    cin.ignore();  // Ignore the newline character after the integer input
    for(int i = 0; i < line; i++) {
        string str;
        getline(cin, str);
        stringstream ss(str);
        string country, name;
        ss >> country >> name;
        mp[country]++;
    }

    for(const auto& [country, count] : mp) {
        cout << country << " " << count << endl;
    }
}