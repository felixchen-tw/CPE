#include <iostream>
using namespace std;

int main() {
    int arr[3001];

    int n;
    while(cin >> n) {

        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        bool flag[3001] = {0};
        bool isJolly = true;
        for(int i = 1; i < n; i++) {
            flag[abs(arr[i] - arr[i - 1])] = true;
        }

        for(int i = 1; i < n; i++) {
            if(!flag[i]) {
                isJolly = false;
                break;
            }
        }
        if(isJolly) {
            cout << "Jolly" << "\n";
        } else {
            cout << "Not jolly" << "\n";
        }
    }
}