#include <iostream>
#include <vector>
using namespace std;
#define MOD 1000000007

int main() {
    vector<long long> factorial(1000001, 1);
    for(int i = 1; i <= 1000000; i++) {
        factorial[i] = (factorial[i - 1] * i) % MOD;
    }
    
    int n;
    while(cin >> n) {
        long long ans = (factorial[n / 2] * factorial[n / 2]) % MOD;
        if(n % 2) {
            ans = (ans * n) % MOD;
        }
        cout << ans << "\n";
    }

    return 0;
}