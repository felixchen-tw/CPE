#include <iostream>
using namespace std;

int main() {
    char c;
    int count = 0;
    while(cin.get(c)) {
        if(c == '"') {
            count++;
            cout << (count % 2 == 1 ? "``" : "''");
        } else {
            cout << c;
        }
    }
}