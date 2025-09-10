#include <iostream>
#include <cmath>
using namespace std;

int main() {
    unsigned int n;
    while(cin >> n && n) {
        unsigned int num = sqrt(n);

        if(num * num == n) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }
    }
}