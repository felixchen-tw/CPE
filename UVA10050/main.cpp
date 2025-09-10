#include <iostream>
using namespace std;

int main() {
    int test;
    cin >> test;
    for(int c = 0; c < test; c++) {
        int n, p, h;
        cin >> n >> p;
        bool flag[3650] = {false};
        for(int i = 0; i < p; i++) {
            cin >> h;
            for(int d = h - 1; d < n; d += h) {
                if(d % 7 == 5 || d % 7 == 6)  flag[d] = 0;
                else flag[d] = 1;
            }
        }

        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(flag[i]) cnt++;
        }
        cout << cnt << "\n";
    }
}