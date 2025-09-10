#include <iostream>
#include <set>
#include <sstream>
using namespace std;

int main() {
    string s;
    set<string> words;
    while(cin >> s) {
        for(int i = 0; i < s.size(); i++) {
            if(isalpha(s[i])) {
                s[i] = tolower(s[i]);
            } else {
                s[i] = ' ';
            }
        }
        stringstream ss(s);
        string word;
        while(ss >> word) {
            words.insert(word);
        }
    }

    for(const string word : words) {
        cout << word << "\n";
    }

    return 0;
}