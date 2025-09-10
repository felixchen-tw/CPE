#include <iostream>
using namespace std;

int main() {
    int n;
    while(cin >> n) {
        if(n == 0)    break;

        int matrix[n][n];
        int row = -1, col = -1;
        bool flag = true;
        int sumRow[n];
        for(int i = 0; i < n; i++) {
            sumRow[i] = 0;
            for(int j = 0; j < n; j++) {
                cin >> matrix[i][j];
                sumRow[i] += matrix[i][j];
            }
            if(sumRow[i] % 2) {
                if(row == -1)   row = i;
                else            flag = false;
            }
        }

        int sumCol[n];
        for(int j = 0; j < n; j++) {
            sumCol[j] = 0;
            for(int i = 0; i < n; i++) {
                sumCol[j] += matrix[i][j];
            }
            if(sumCol[j] % 2) {
                if(col == -1)   col = j;
                else            flag = false;
            }
        }

        if(row == -1 && col == -1)  cout << "OK\n";
        else if(!flag) cout << "Corrupt\n";
        else cout << "Change bit (" << row + 1 << "," << col + 1 << ")\n";
    }
}