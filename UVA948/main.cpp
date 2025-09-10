#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> v, int tar) {
    int left = 0;
    int right = v.size() - 1;
    int mid = 0;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (v[mid] == tar) return mid;
        if (v[mid] < tar) left = mid + 1;
        else right = mid - 1;
    }
    return mid;
}

int main() {
    vector<int> fib = {1, 2};
    int len = fib.size();
    while (fib[len - 1] <= 100000000) {
        fib.push_back(fib[len - 1] + fib[len - 2]);
        len++;
    }

    int n, num, temp;
    string res;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> num;

        res = "";
        temp = num;
        for(int i = binarySearch(fib, temp); i >= 0; i--) {
            if(temp >= fib[i]) {
                res += "1";
                temp -= fib[i];
            }
            else {
                res += "0";
            }
        }
        if(res[0] == '0')   res.erase(0, 1);
        cout << num << " = "<< res << " (fib)\n";
    }
}