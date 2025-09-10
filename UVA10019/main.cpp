#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string decToBinary(int n) {
    string res;
    while(n > 0) {
        res = to_string(n & 1) + res;
        n >>= 1;
    }
    return res;
}

string hexToBinary(string hex) {
    string res;
    for (char c : hex) {
        int val;
        if (c >= '0' && c <= '9') val = c - '0';
        else if (c >= 'A' && c <= 'F') val = c - 'A' + 10;
        else if (c >= 'a' && c <= 'f') val = c - 'a' + 10;
        else continue;

        res += decToBinary(val);
    }
    return res;
}

int main() {
    int test;
    cin >> test;
    for(int i = 0; i < test; i++) {
        string val;
        cin >> val;

        string bin = decToBinary(stoi(val));
        string hex = hexToBinary(val);
        cout << count(bin.begin(), bin.end(), '1') << ' ' << count(hex.begin(), hex.end(), '1') << '\n';
    }
}