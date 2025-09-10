#include <iostream>
using namespace std;

int main() {
    int test;
    cin >> test;
    while(test--) {
        int l;
        cin >> l;
        int arr[l];
        for(int i = 0; i < l; i++) {
            cin >> arr[i];
        }

        int cnt = 0;
        for(int i = l - 1; i >= 0; i--) {
            for(int j = 0; j < i; j++) {
                if(arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    cnt++;
                }
            }
        }
        cout << "Optimal train swapping takes " << cnt << " swaps.\n";
    }
}