#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
#define PI acos(0.0)*2.0

int main() {
    double r, s, a;
    string unit;

    double chord, arc;
    r = 6440.0;
    while(cin >> s >> a >> unit) {
        if(unit == "min") a /= 60.0;
        if(a > 180) a = 360.0 - a;
        chord = (r + s) * cos((90.0 - a / 2.0) / 180.0 * PI) * 2.0;
        arc = 2.0 * PI * (r + s) * a / 360.0;
        cout << fixed << setprecision(6) << arc << " " << chord << "\n";
    }
}