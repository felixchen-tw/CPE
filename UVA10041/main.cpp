#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int test;
    cin >> test;

    int n = 0;
    int arr[1001];
    while(cin >> n) {
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        sort(arr, arr + n);
        int mid = arr[n / 2];
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += abs(mid - arr[i]);
        }
        cout << sum << endl;
    }
}