#include <iostream>
#include <vector>
#include <bitset>
#include <climits>
using namespace std;

#define maxn 10101

int main() {
    int n, m;
    while(cin >> n >> m) {
        vector<int> arr(n + m);
        int sum = 0;
        for(int i = 0; i < n + m; i++) {
            cin >> arr[i];
            sum += arr[i];
        }
        vector<bitset<maxn>> table(min(n, m) + 1);
        table[0][0] = true;
        for(int i = 0; i < arr.size(); i++) {
            for(int j = table.size() - 2; j >= 0; j--) {
                table[j + 1] |= table[j] << (arr[i] + 50);
            }
        }

        int minVal = INT_MAX, maxVal = INT_MIN;
        auto k = table.back();
        for(int i = 0; i < maxn; i++) {
            if(k[i]) {
                int temp = i - 50 * (table.size() - 1);
                int re = sum - temp;
                minVal = min(minVal, temp * re);
                maxVal = max(maxVal, temp * re);
            }
        }
        cout << maxVal << " " << minVal << "\n";
    }
    
    return 0;
}