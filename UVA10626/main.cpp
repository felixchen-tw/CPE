#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int cas;
    cin >> cas;
    while(cas--) {
        int n, coins[3];
        cin >> n >> coins[0] >> coins[1] >> coins[2];

        int used[3] = {0};
        int cnt = 0;

        int temp = min(n, coins[2]);
        used[2] += temp;
        cnt += temp;
        coins[0] += temp * 2;
        n -= temp;
        if(n == 0) {
            cout << cnt << "\n";
            continue;
        }

        temp = min(n, coins[1] / 2);
        cnt += temp * 2;
        used[1] += temp * 2;
        coins[0] += temp * 2;
        n -= temp;
        if(n == 0) {
            cout << cnt << "\n";
            continue;
        }

        int cover[3] = {0};
        if(n > 0 && coins[1] - used[1] > 0) {
            n--;
            cnt += 4;
            used[1]++;
            used[0] += 3;
            cover[1]++;
        }

        used[0] += 8 * n;
        cnt += 8 * n;
        n = 0;

        for(int i = 0; i < 150; i++) {
            if(used[1] - cover[1] > 1 && used[0] - cover[0] >= 8){
                cover[1] += 2;
                cover[0] += 6;
                coins[0] -= 2;
                used[0] -= 2;
                cnt -= 2;
                continue;
            }
            if(used[2] - cover[2] > 0 && used[0] - cover[0] >= 8){
                cover[2]++;
                cover[1]++;
                cover[0] += 6;
                coins[0] -= 2;
                used[0] -= 2;
                cnt--;
                continue;
            }
        }
        cout << cnt << "\n";
    }
}