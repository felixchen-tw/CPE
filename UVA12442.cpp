#include <iostream>
#include <vector>

using namespace std;

vector<int> sent;
vector<bool> check, sum;
int times;

void DFS(int num) {
    times++;
    sum[num] = true;
    check[num] = true;
    if(!check[sent[num]])    DFS(sent[num]);
}

int main() {
    int test;
    cin >> test;
    for(int cas = 0; cas < test; cas++) {
        int n;
        cin >> n;
        sent.assign(n + 1, -1);
        sum.assign(n + 1, false);

        for(int i = 0, u, v; i < n; i++) {
            cin >> u >> v;
            sent[u] = v;
        }

        int maxTimes = 1;
        int ans = sent[0];
        for(int i = 1; i <= n; i++) {
            if(!sum[i]) {
                check.assign(n + 1, false);
                check[i] = true;
                times = 1;

                DFS(sent[i]);
                if(times > maxTimes || (times == maxTimes && i < ans)) {
                    ans = i;
                    maxTimes = times;
                }
            }
        }

        cout << "Case " << cas + 1 << ": " << ans << "\n";
    }
}