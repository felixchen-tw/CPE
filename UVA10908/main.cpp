#include <iostream>
using namespace std;

int main() {
    int t, m, n, q;
    cin >> t;

    while(t--) {
        cin >> m >> n >> q;
        cout << m << ' ' << n << ' ' << q << '\n';
        
        char arr[m][n];
        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++) {
                cin >> arr[r][c];
            }
        }

        while(q--) {
            int row, col;
            cin >> row >> col;

            bool flag = true;
            int len = 1;
            while(flag) {
                if(row - len < 0 || row + len >= m || col - len < 0 || col + len >= n) {
                    flag = false;
                    break;
                }

                for(int r = row - len; r <= row + len; r++) {
                    for(int c = col - len; c <= col + len; c++) {
                        if(arr[r][c] != arr[row][col]) {
                            flag = false;
                            break;
                        }
                    }
                    if(!flag)   break;
                }
                if(!flag)   break;
                len++;
            }
            cout << 2 * (len - 1) + 1 << '\n';
        }
    }
}