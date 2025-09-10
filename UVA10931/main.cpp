#include <iostream>
#include <algorithm>
using namespace std;

string decToBin(int n) {
    string res = "";
    while(n > 0) {
        res = to_string(n & 1) + res;
        n >>= 1;
    }
    return res;
}

int main() {
    int n;
    while(cin >> n, n) {
        string bin = decToBin(n);
        int bitCount = count(bin.begin(), bin.end(), '1');
        cout << "The parity of " << bin << " is " << bitCount << " (mod 2).\n";
    }
}