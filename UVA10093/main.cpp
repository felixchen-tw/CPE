#include <iostream>
using namespace std;

int main() {
    string s;
    int sum, maximum, temp;
    while(getline(cin, s)) {
        sum = 0;
        maximum = 1;
        int i;
        for(i = 0; i < s.size(); i++) {
            if(isdigit(s[i])) {
                temp = s[i] - '0';
            }
            else if(s[i] >= 'A' && s[i] <= 'Z') {
                temp = s[i] - 'A' + 10;
            }
            else if(s[i] >= 'a' && s[i] <= 'z') {
                temp = s[i] - 'a' + 36;
            }
            else    continue;

            if(maximum < temp)   maximum = temp;
            sum += temp;
        }

        for(i = maximum; i < 62; i++) {
            if(sum % i == 0) {
                cout << i + 1 << "\n";
                break;
            }
        }
        if(i == 62) {
            cout << "such number is impossible!\n";
        }
    }
}