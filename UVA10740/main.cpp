#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
#define ll long long

int main() {
    int n, m;
    while(cin >> n >> m, n, m) {
        int x, y, k;
        cin >> x >> y >> k;

        vector<vector<pair<int, int>>> adj(n + 1);
        for(int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].emplace_back(v, w);
        }

        vector<int> cnt(n + 1, 0);
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        pq.emplace(0LL, x);

        ll ans = -1;
        while(!pq.empty()) {
            pair<ll, int> temp = pq.top();
            pq.pop();

            ll d = temp.first;
            int u = temp.second;

            cnt[u]++;
            if(u == y && cnt[u] == k) {
                ans = d;
                break;
            }
            if(cnt[u] > k) continue;

            for(auto &e : adj[u]) {
                int v = e.first;
                int w = e.second;
                pq.emplace(d + w, v);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}