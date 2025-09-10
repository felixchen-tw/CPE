#include <iostream>
using namespace std;

int main() {
    string pattern = "1234567890-=qwertyuiop[]asdfghjkl;'zxcvbnm,./";
    string s;
    getline(cin, s);

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == ' ') continue;
        s[i] = pattern[(pattern.find(tolower(s[i])) - 2 + pattern.size()) % pattern.size()];
    }
    cout << s << "\n";
}