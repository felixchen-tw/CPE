#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();

    vector<int> cnt(256, 0);
    string s;
    
    for(int i = 0; i < n; i++) {
        getline(cin, s);
        for(char c : s) {
            cnt[toupper(c)]++;
        }
    }

    vector<pair<char, int>> freq;
    for(char i = 'A'; i <= 'Z'; i++) {
        if(cnt[i] > 0) {
            freq.push_back({i, cnt[i]});
        }
    }

    sort(freq.begin(), freq.end(), [](const auto& a, const auto& b) {
        return a.second != b.second ? a.second > b.second : a.first < b.first;
    });

    for(const auto& p : freq) {
        cout << p.first << " " << p.second << "\n";
    }
}