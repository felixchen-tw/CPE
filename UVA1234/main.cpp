#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

#define INF 0x3F3F3F3F

vector<int> UF;

int FIND(int x) {
    if(UF[x] == x)  return x;
    return UF[x] = FIND(UF[x]);
}

void UNION(int x, int y) {
    if(FIND(x) != FIND(y)) {
        UF[FIND(x)] = FIND(y);
    }
}

int main() {
    int c;
    cin >> c;
    while(c--) {
        int n, m, sum = 0;
        cin >> n >> m;
        UF.resize(n);

        for(int i = 0; i < n; i++)  UF[i] = i;
        vector<pair<int, int>> edges;
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            sum += w;
            edges.push_back({u - 1, v - 1});
            pq.push({w, i});
        }
        while(pq.size()) {
            int w, idx;
            tie(w, idx) = pq.top();
            pq.pop();

            if(FIND(edges[idx].first) != FIND(edges[idx].second)) {
                sum -= w;
                UNION(edges[idx].first, edges[idx].second);
            }
        }
        cout << sum << '\n';
    }
    
    return 0;
}