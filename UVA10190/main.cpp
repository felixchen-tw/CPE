#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    while(cin >> n >> m) {
        bool boring = false;
        vector<int> res;
        if(n == 0 || m <= 1 || n < m)    boring = true;
        else {
            res.push_back(n);
            while(n > 1) {
                if(n % m == 0) {
                    n /= m;
                    res.push_back(n);
                }
                else {
                    boring = true;
                    break;
                }
            }
        }

        if(boring) {
            cout << "Boring!\n";
        }
        else {
            for(int i = 0; i < res.size(); i++) {
                cout << res[i];
                if(i != res.size() - 1) cout << ' ';
            }
            cout << "\n";
        }
    }
    return 0;
}