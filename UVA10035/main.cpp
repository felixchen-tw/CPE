#include <iostream>
using namespace std;

int main() {
    unsigned int a, b;
    while(cin >> a >> b) {
        if(a == 0 && b == 0)    break;

        int carry = 0;
        int count = 0;
        while(a != 0 || b != 0 || carry != 0) {
            carry = ((a % 10) + (b % 10) + carry) >= 10;
            if(carry)  count++;
            a /= 10;
            b /= 10;
        }
        if(count == 0) {
            cout << "No carry operation." << endl;
        } else if(count == 1) {
            cout << count << " carry operation." << endl;
        } else {
            cout << count << " carry operations." << endl;
        }
    }
}