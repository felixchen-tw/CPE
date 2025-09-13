#include <iostream>
#include <vector>
using namespace std;

int main() {
    int test, terLen, numBars;
    vector<int> bars(20);
    vector<vector<bool>> flags(20, vector<bool>(20010));
    cin >> test;
    while(test--) {
        string ans = "NO";
        cin >> terLen >> numBars;
        for(int i = 0; i < numBars; i++) {
            cin >> bars[i];
        }
        
        for(int i = 0; i < numBars; i++) {
            for(int j = 0; j <= terLen; j++) {
                flags[i][j] = false;
            }
        }

        flags[0][0] = true;
        flags[0][bars[0]] = true;
        if(bars[0] == terLen) {
            ans = "YES";
        }

        for(int i = 1; i < numBars; i++) {
            for(int j = 0; j <= terLen; j++) {
                if(flags[i - 1][j]) {
                    flags[i][j] = true;
                    flags[i][j + bars[i]] = true;
                }
            }
            if(flags[i][terLen]) {
                ans = "YES";
                break;
            }
        }

        cout << ans << "\n";
    }
    
    return 0;
}