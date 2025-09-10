#include <iostream>
using namespace std;

int main() {
    long long s, d, team;
    while(cin >> s >> d) {
        team = s;
        while(s < d) {
            team++;
            s += team;
        }
        cout << team << "\n";
    }
}