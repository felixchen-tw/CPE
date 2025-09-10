#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

const ll MAXN =  1e12;
const ll MAXN_SQRT = sqrt(MAXN);
vector<ll> almostPrimes;
vector<bool> isPrime(MAXN_SQRT + 1, true);

void init() {
    isPrime[0] = false;
    isPrime[1] = false;

    for(ll i = 2; i * i <= MAXN_SQRT; i++) {
        if(isPrime[i]) {
            for(ll j = i * i; j <= MAXN_SQRT; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for(ll i = 2; i <= MAXN_SQRT; i++) {
        if(isPrime[i]) {
            ll x = i * i;
            while(x <= MAXN) {
                almostPrimes.push_back(x);
                x *= i;
            }
        }
    }
    sort(almostPrimes.begin(), almostPrimes.end());
}

int main() {
    init();
    int test;
    cin >> test;
    while(test--) {
        ll lo, hi;
        cin >> lo >> hi;
        cout << upper_bound(almostPrimes.begin(), almostPrimes.end(), hi) -
                lower_bound(almostPrimes.begin(), almostPrimes.end(), lo) << "\n";
    }
    return 0;
}