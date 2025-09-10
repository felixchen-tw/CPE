#include <iostream>
#include <vector>
using namespace std;

int GCD(int a, int b) {
    while(b) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main() {
    int cas;
    cin >> cas;
    while(cas--) {
        int n, days = 1;
        cin >> n;
        vector<vector<int>> cows;
        for(int i = 0; i < n; i++) {
            int sz, m;
            cin >> sz;
            vector<int> temp(sz);
            days = days / GCD(days, sz) * sz;
            for(auto &x : temp) {
                cin >> x;
            }
            cows.push_back(temp);
        }

        vector<int> eaten(n, false);
        int last = -1;
        for(int i = 0; i < last + days + 1; i++) {
            int mCow = -1;
            bool alive = false;

            for(int j = 0; j < n; j++) {
                if(eaten[j])    continue;

                if(mCow == -1) {
                    mCow = j;
                    continue;
                }

                int currCow = cows[j][i % cows[j].size()];
                int minCow = cows[mCow][i % cows[mCow].size()];
                if(currCow == minCow) {
                    alive = true;
                    continue;
                }

                if(currCow < minCow) {
                    mCow = j;
                    alive = false;
                }
            }

            if(!alive && mCow != -1) {
                eaten[mCow] = true;
                last = i;
                days = 1;
                for(int j = 0; j < n; j++) {
                    if(eaten[j])    continue;
                    days = days / GCD(days, cows[j].size()) * cows[j].size();
                }
            }
        }

        int aliveNum = 0;
        for(int i = 0; i < n; i++) {
            aliveNum += !eaten[i];
        }

        cout << aliveNum << " " << last + 1 << "\n";
    }
}