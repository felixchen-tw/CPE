#include <iostream>
using namespace std;

int arr[15];
int ans[15];

void DFS(int start, int size, int len) {
    if(len == 6) {
        cout << ans[0];
        for(int i = 1; i < 6; i++) {
            cout << ' ' << ans[i];
        }
        cout << '\n';
        return;
    }

    for(int i = start; i < size; i++) {
        ans[len] = arr[i];
        DFS(i + 1, size, len + 1);
    }
}

int main() {
    int k, t = 0;
    while(cin >> k) {
        if(k == 0)  break;
        if(t++) cout << '\n';
        for(int i = 0; i < k; i++) {
            cin >> arr[i];
        }
        DFS(0, k, 0);
    }
    return 0;
}