#include <iostream>
using namespace std;

int main() {
    long long int hash = 0, op = 0;
    while(cin >> hash >> op) {
        cout << abs(hash - op) << endl;
    }
}