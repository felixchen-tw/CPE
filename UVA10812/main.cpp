#include <iostream>
using namespace std;

int main() {
    int n, s, d;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s >> d;
        if(s < d || (s + d) % 2) {
            cout << "impossible\n";
        }
        else {
            cout << (s + d) / 2 << " " << (s - d) / 2 << "\n";
        }
    }
}