#include <iostream>
using namespace std;

int main() {
    int m, n;
    int field = 1;
    while(cin >> m >> n, m, n) {
        char board[m][n];
        int arr[m][n];
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                cin >> board[i][j];
                if(board[i][j] == '*') {
                    arr[i][j] = -1;
                }
                else {
                    arr[i][j] = 0;
                }
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(arr[i][j] == -1) {
                    continue;
                }
                for(int k = -1; k <= 1; k++) {
                    for(int l = -1; l <= 1; l++) {
                        if(i + k < 0 || i + k >= m || j + l < 0 || j + l >= n) {
                            continue;
                        }
                        if(arr[i + k][j + l] == -1) {
                            arr[i][j]++;
                        }
                    }
                }
            }
        }

        cout << "Field #" << field << ":\n";
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(arr[i][j] == -1) {
                    cout << '*';
                } else {
                    cout << arr[i][j];
                }
            }
            cout << '\n';
        }
        cout << '\n';
        field++;
    }
}