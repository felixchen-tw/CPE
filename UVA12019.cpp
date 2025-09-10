#include <iostream>
using namespace std;

const string days[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

int main() {
    int n;
    cin >> n;

    int month, day;
    for(int i = 0; i < n; i++) {
        cin >> month >> day;

        switch(month) {
            case 1:
                cout << days[((day - 10) % 7 + 7) % 7];
                break;
            case 2:
                cout << days[((day - 21) % 7 + 7) % 7];
                break;
            case 3:
                cout << days[((day - 7) % 7 + 7) % 7];
                break;
            case 4:
                cout << days[((day - 4) % 7 + 7) % 7];
                break;
            case 5:
                cout << days[((day - 9) % 7 + 7) % 7];
                break;
            case 6:
                cout << days[((day - 6) % 7 + 7) % 7];
                break;
            case 7:
                cout << days[((day - 11) % 7 + 7) % 7];
                break;
            case 8:
                cout << days[((day - 8) % 7 + 7) % 7];
                break;
            case 9:
                cout << days[((day - 5) % 7 + 7) % 7];
                break;
            case 10:
                cout << days[((day - 10) % 7 + 7) % 7];
                break;
            case 11:
                cout << days[((day - 7) % 7 + 7) % 7];
                break;
            case 12:
                cout << days[((day - 12) % 7 + 7) % 7];
                break;
        }
        cout << "\n";
    }
}