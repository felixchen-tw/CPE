#include <iostream>
using namespace std;

int main() {
    int n, a, b;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        int ans = 0;
        for(int i = a; i <= b; i++) {
            if(i % 2) {
                ans += i;
            }
        }
        cout << "Case " << i + 1 << ": " << ans << "\n";
    }
}