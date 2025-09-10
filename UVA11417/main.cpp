#include <iostream>
using namespace std;

int main() {
    int test;
    cin >> test;

    int cost[36];
    for(int c = 1; c <= test; c++) {
        if(c > 1) cout << "\n";
        for(int i = 0; i < 36; i++) {
            cin >> cost[i];
        }

        cout << "Case " << c << ":\n";
        int n, val;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> val;
            cout << "Cheapest base(s) for number " << val << ":";
                        
            int minCost = 0x7FFFFFFF;
            int sums[37];
            for(int b = 2; b <= 36; b++) {
                int temp = val, sum = 0;
                while(temp) {
                    sum += cost[temp % b];
                    temp /= b;
                }
                minCost = min(minCost, sum);
                sums[b] = sum;
            }
            
            for(int j = 2; j <= 36; j++) {
                if(sums[j] == minCost) {
                    cout << ' ' << j;
                }
            }
            cout << "\n";
        }
    }
}