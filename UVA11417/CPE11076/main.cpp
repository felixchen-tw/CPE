#include <iostream>
using namespace std;

int GCD(int a, int b) {
    int t = 0;
    while(b) {
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    int n;
    while(cin >> n, n) {
        int sum = 0;
        for(int i = 1; i < n; i++) {
            for(int j = i + 1; j <= n; j++) {
                sum += GCD(i, j);
            }
        }
        cout << sum << "\n";
    }
}