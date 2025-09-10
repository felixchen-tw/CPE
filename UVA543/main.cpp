#include <iostream>
using namespace std;

bool isPrime(int n) {
    if(n < 2) return false;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    while(cin >> n && n) {
        int a, b;
        for(a = 3; a <= n / 2; a += 2) {
            b = n - a;
            if(b % 2 && isPrime(a) && isPrime(b)) {
                break;
            }
        }
        cout << n << " = " << a << " + " << b << '\n';
    }
}