#include <iostream>
using namespace std;

int main() {
    int n, test = 1;
    while(cin >> n) {
        int arr[n], checkSum[20005] = {0};
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        bool flag = true;
        if(arr[0] < 1)  flag = false;

        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(arr[i] > arr[j] || checkSum[arr[i] + arr[j]]) {
                    flag = false;
                    break;
                }
                checkSum[arr[i] + arr[j]] = 1;
            }
            if(!flag)   break;
        }

        cout << "Case #" << test++ << ": ";
        if(flag) cout << "It is a B2-Sequence.\n\n";
        else cout << "It is not a B2-Sequence.\n\n";
    }
    return 0;
}