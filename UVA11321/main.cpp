#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    while(cin >> n >> m) {
        int arr[n];
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        sort(arr, arr + n, [m](int a, int b) {
            if(a % m != b % m)  return a % m < b % m;
            if(a % 2 && b % 2)  return a > b;
            if(a % 2 == 0 && b % 2 == 0) return a < b;
            if(a % 2 == 0 && b % 2) return false;
            return true;
        });

        cout << n << ' ' << m << '\n';
        for(int i = 0; i < n; i++) {
            cout << arr[i] << '\n';
        }

        if(n == 0 && m == 0) break;
    }
}