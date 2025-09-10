#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string ans;
    string s1, s2;
    while(getline(cin, s1)) {
        int a[26] = {0}, b[26] = {0};
        for(const char c : s1) {
            a[c - 'a']++;
        }
        getline(cin, s2);
        for(const char c : s2) {
            b[c - 'a']++;
        }
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < min(a[i], b[i]); j++) {
                cout << (char)(i + 'a');
            }
        }
        cout << "\n";
    }
}