#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a, b, c, d, l;
    while(cin >> a >> b >> c >> d >> l) {
        if(!a && !b && !c && !d && !l)  break;

        int f = 0, cnt = 0;
        for(int x = 0; x <= l; x++) {
            f = a * pow(x, 2) + b * x + c;
            if(!(f % d))  cnt++;
        }
        cout << cnt << "\n";
    }
    
    return 0;
}