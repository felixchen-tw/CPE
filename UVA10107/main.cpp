#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(vector<int> arr, int tar) {
    int l = 0, r = arr.size() - 1;
    int mid;
    while(l <= r) {
        mid = (l + r) / 2;
        
        if(arr[mid] == tar) return mid;
        if(arr[mid] < tar)  l = mid + 1;
        else                r = mid - 1;
    }
    return l;
}

int main() {
    int n, sz = 0;
    vector<int> arr;
    while(cin >> n) {
        sz++;
        int idx = binarySearch(arr, n);
        arr.insert(arr.begin() + idx, n);

        if(sz % 2 == 0) {
            cout << (arr[sz / 2] + arr[sz / 2 - 1]) / 2 << "\n";
        }
        else {
            cout << arr[sz / 2] << "\n";
        }
    }
}