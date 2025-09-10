#include <iostream>
#include <string.h>
using namespace std;

int main() {
    char sentences[100][100];
    string s;
    int row = 0, max = 0;
    while(gets(sentences[row]) != NULL) {
        if(row == 0) {
            max = strlen(sentences[row]);
        }
        else if(max < strlen(sentences[row])) {
            max = strlen(sentences[row]);
        }
        row++;
    }

    for(int j = 0; j < max; j++) {
        for(int i = row - 1; i >= 0; i--) {
            if(j < strlen(sentences[i])) {
                cout << sentences[i][j];
            }
            else if(j != 0) {
                cout << " ";
            }
        }
        cout << "\n";
    }
}