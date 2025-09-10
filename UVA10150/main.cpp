#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
using namespace std;

vector<vector<int>> g;
vector<int> parent;

void BFS(int beg, int end) {
    parent.assign(g.size(), -1);
    queue<int> q;
    q.push(beg);
    parent[beg] = beg;

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        for(int i = 0; i < g[curr].size(); i++) {
            if(parent[g[curr][i]] == -1) {
                parent[g[curr][i]] = curr;

                if(g[curr][i] == end)   return;
                q.push(g[curr][i]);
            }
        }
    }
}

int main() {
    string s;
    vector<string> dict;
    while(getline(cin, s) && s != "") {
        dict.push_back(s);
    }
    sort(dict.begin(), dict.end());

    g.assign(dict.size(), vector<int>());
    for(int i = 0; i < dict.size(); i++) {
        string alpha = "abcdefghijklmnopqrstuvwxyz";

        for(int j = 0;j < min((int)dict[i].size(), 16); j++) {
            for(char c : alpha) {
                string temp = dict[i];
                if(temp[j] == c)    continue;
                
                temp[j] = c;
                auto it = lower_bound(dict.begin(), dict.end(), temp);
                if(it != dict.end() && *it == temp) {
                    g[i].push_back(it - dict.begin());
                    g[it - dict.begin()].push_back(i);
                }
            }
        }
    }

    for(auto &v : g) {
        sort(v.begin(), v.end());
    }

    int cas = 0;
    string beg, end;
    while(cin >> beg >> end) {
        if(cas++)   cout << "\n";

        int b = find(dict.begin(), dict.end(), beg) - dict.begin();
        int e = find(dict.begin(), dict.end(), end) - dict.begin();
        BFS(b, e);
        vector<int> path;
        path.push_back(e);
        for(int curr = e; curr >= 0 && curr != parent[curr]; curr = parent[curr]) {
            if(curr >= 0) {
                path.push_back(parent[curr]);
            }
        }
        reverse(path.begin(), path.end());

        if(path.size() && path[0] == b) {
            for(int &idx : path) {
                cout << dict[idx] << "\n";
            }
        }
        else {
            cout << "No solution.\n";
        }
    }
}