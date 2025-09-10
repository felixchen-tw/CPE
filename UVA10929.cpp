#include <iostream>
using namespace std;

int main() {
    string s;
    while(cin >> s) {
        if(s == "0")  break;

        int arr[2] = {0, 0};
        for(int i = 0; i < s.size(); i++) {
            arr[i % 2] += s[i] - '0';
        }
        if((abs(arr[0] - arr[1]) % 11) == 0) {
            cout << s << " is a multiple of 11." << endl;
        }
        else {
            cout << s << " is not a multiple of 11." << endl;
        }
    }
}