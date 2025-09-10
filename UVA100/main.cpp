#include <iostream>
using namespace std;

int main() {
    int a = 0, b = 0;
    while(cin >> a >> b) {
        int maxCycle = 0;
        for(int i = min(a, b); i <= max(a, b); i++) {
            int n = i;
            int cycle = 1;
            while(n != 1) {
                if(n % 2) {
                    n = 3 * n + 1;
                }
                else {
                    n /= 2;
                }
                cycle++;
            }
            maxCycle = max(maxCycle, cycle);
        }
        cout << a << " " << b << " " << maxCycle << endl;
    }
}