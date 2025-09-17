#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int cas = 1;
    int row, col, numCmds, numArgs, r1, c1, r2, c2, cnt, r, c, tmp;
    bool flag = false;
    string cmd;
    cin >> row >> col;
    while(row || col) {
        vector<vector<int>> data;
        vector<int> a;
        cnt = 0;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                a.push_back(cnt);
                cnt++;
            }
            data.push_back(a);
            a.clear();
        }

        cin >> numCmds;
        for(int k = 0; k < numCmds; k++) {
            a.clear();
            cin >> cmd;

            if(cmd == "EX") {
                cin >> r1 >> c1 >> r2 >> c2;
            }
            else {
                cin >> numArgs;
                for(int i = 0; i < numArgs; i++) {
                    cin >> tmp;
                    a.push_back(tmp - 1);
                }
                sort(a.begin(), a.end());
            }

            if(cmd == "EX") {
                swap(data[r1 - 1][c1 - 1], data[r2 - 1][c2 - 1]);
            }
            else if(cmd == "DR") {
                for(int i = 0; i < numArgs; i++) {
                    data.erase(data.begin() + a[i] - i);
                }
            }
            else if(cmd == "DC") {
                for(int i = 0; i < numArgs; i++) {
                    for(int j = 0; j < data.size(); j++) {
                        data[j].erase(data[j].begin() + a[i] - i);
                    }
                }
            }
            else if(cmd == "IR") {
                for(int i = 0; i < numArgs; i++) {
                    data.insert(data.begin() + a[i] + i, vector<int>(data[0].size(), -1));
                }
            }
            else if(cmd == "IC") {
                for(int i = 0; i < numArgs; i++) {
                    for(int j = 0; j < data.size(); j++) {
                        data[j].insert(data[j].begin() + a[i] + i, -1);
                    }
                }
            }
        }

        printf("Spreadsheet #%d\n", cas++);
        cin >> numCmds;
        for(int k = 0; k < numCmds; k++) {
            flag = false;
            cin >> r >> c;
            printf("Cell data in (%d,%d) ", r, c);
            for(int i = 0; i < data.size(); i++) {
                for(int j = 0; j < data[0].size(); j++) {
                    if(data[i][j] == (r - 1) * col + (c - 1)) {
                        printf("moved to (%d,%d)\n", i + 1, j + 1);
                        flag = true;
                        break;
                    }
                }
                if(flag)    break;
            }
            if(!flag) {
                printf("GONE\n");
            }
        }
        cin >> row >> col;
        if(row || col) {
            printf("\n");
        }
    }
    return 0;
}