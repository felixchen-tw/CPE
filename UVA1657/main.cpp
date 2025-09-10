#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

int main() {
    int n, m;
    while(cin >> n >> m) {
        vector<pair<int, int>> table;
        unordered_map<int, int> sumMap, productMap;

        for(int i = 1; i <= n; i++) {
            for(int j = i + 1; j <= n; j++) {
                table.emplace_back(i, j);
                sumMap[i + j]++;
                productMap[i * j]++;
            }
        }

        vector<bool>usable(table.size(), true);
        for(int i = 0 ; i < m; i++) {
            for(auto it = table.begin(); it != table.end(); it++) {
                if(!usable[it - table.begin()]) continue;

                int sum = it->first + it->second;
                int product = it->first * it->second;

                if(i % 2 == 0) {
                    if(sumMap[sum] <= 1) {
                        sumMap.erase(sum);
                        productMap[product]--;
                        usable[it - table.begin()] = false;
                    }
                }
                else {
                    if(productMap[product] <= 1) {
                        productMap.erase(product);
                        sumMap[sum]--;
                        usable[it - table.begin()] = false;
                    }
                }
            }
        }

        vector<pair<int, int>> res;
        if(m % 2 == 0) {
            for(const auto &p : table) {
                if(!usable[&p - &(table.front())])  continue;
                if(sumMap[p.first + p.second] == 1) {
                    res.push_back(p);
                }
            }
        }
        else {
            for(const auto &p : table) {
                if(!usable[&p - &(table.front())])  continue;

                if(productMap[p.first * p.second] == 1) {
                    res.push_back(p);
                }
            }
        }

        cout << res.size() << "\n";
        for(const auto &p : res) {
            cout << p.first << " " << p.second << "\n";
        }
    }
}