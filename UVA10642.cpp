#include <iostream>
using namespace std;

int main() {
    int test;
    cin >> test;

    long long x, y, n, step1, step2;
    for(int Case = 1; Case <= test; Case++) {
        cin >> x >> y;
        if (x == 0 && y == 0) step1 = 0;
        else {
            n = x + y - 1;
            step1 = (n * n + 3 * n) / 2 + (x + 1);
        }
        
        cin >> x >> y;
        if (x == 0 && y == 0) step2 = 0;
        else {
            n = x + y - 1;
            step2 = (n * n + 3 * n) / 2 + (x + 1);
        }

        cout << "Case " << Case << ": " << step2 - step1 << '\n';
    }
}