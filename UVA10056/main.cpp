#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int num;
        double p, q;
        cin >> num >> p >> q;

        if(p == 0) {
            cout << "0.0000\n";
        }
        else {
            cout << fixed << setprecision(4) << p * pow(1 - p, q - 1) / (1 - pow(1 - p, num)) << "\n";
        }
    }
}