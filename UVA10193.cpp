#include <iostream>
using namespace std;

int binToDec(string b) {
    int res = 0;
    for(const char c : b) {
        res <<= 1;
        res += (c - '0');
    }
    return res;
}

int GCD(int a, int b) {
    int t = 0;
    while(b != 0) {
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    int test;
    cin >> test;
    for(int c = 1; c <= test; c++) {
        string a, b;
        bool flag = true;
        cin >> a >> b;

        int decA = binToDec(a);
        int decB = binToDec(b);

        cout << "Pair #" << c << ": ";
        if(GCD(decA, decB) == 1)    cout << "Love is not all you need!\n";
        else        cout << "All you need is love!\n";
    }
}