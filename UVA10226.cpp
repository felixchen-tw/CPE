#include <iostream>
#include <map>
using namespace std;

int main() {
    int test;
    cin >> test;

    string s;
    getline(cin, s);
    getline(cin, s);
    while(test--) {
        map<string, int> mp;
        int total = 0;
        while(getline(cin, s) && !s.empty()) {
            mp[s]++;
            total++;
        }

        for(auto [name, cnt] : mp) {
            double percentage = (double)cnt / total * 100;
            cout << name << " " << fixed;
            cout.precision(4);
            cout << percentage << endl;
        }

        if(test >= 1) {
            cout << '\n';
        }
    }
}