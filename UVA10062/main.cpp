#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string s;
    while(getline(cin, s)) {
        pair<int, int> p[256];
        for(int i = 0; i < 256; i++) {
            p[i] = {i, 0};
        }

        for(char c : s) {
            p[(int)c].second++;
        }

        sort(p, p + 256, [](const pair<int, int>& a, const pair<int, int>& b) {
            if(a.second != b.second) return a.second < b.second;
            return a.first > b.first;
        });

        for(int i = 0; i < 256; i++) {
            if(p[i].second > 0) {
                cout << p[i].first << ' ' << p[i].second << '\n';
            }
        }
        cout << '\n';
    }
}