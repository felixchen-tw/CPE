#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a, b, q, r;
    while(cin >> a >> b) {
        vector<int> v;
        while(b > 1) {
            q = a / b;
            r = a % b;
            v.push_back(q);

            a = b;
            b = r;
        }
        v.push_back(a);
        if(b == 0)  v.pop_back();

        cout << "[" << v[0] << ";";
        for(int i = 1; i < v.size() - 1; i++) {
            cout << v[i] << ",";
        }
        cout << v[v.size() - 1] << "]\n";
    }
    return 0;
}