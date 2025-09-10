#include <iostream>
using namespace std;

bool isPrime(int n) {
    if(n <= 1) return false;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

int reverseInt(int n) {
    int res = 0;
    while(n) {
        res = res * 10 + n % 10;
        n /= 10;
    }
    return res;
}

int main() {
    int n;
    while(cin >> n) {
        if(isPrime(n)) {
            if(n != reverseInt(n) && isPrime(reverseInt(n))) {
                cout << n << " is emirp.\n";
            }
            else {
                cout << n << " is prime.\n";
            }
        }
        else cout << n << " is not prime.\n";
    }
    return 0;
}