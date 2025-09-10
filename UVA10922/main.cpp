#include <iostream>
using namespace std;

int sumOfDigits(string n) {
    int sum = 0;
    for(char c : n) {
        sum += c - '0';
    }
    return sum;
}

int calcDegree(string s, int cnt) {
    cnt++;
    int sum = sumOfDigits(s);
    if(sum == 9)    return cnt;
    else if(sum < 9)    return 0;
    else            return calcDegree(to_string(sum), cnt);
}

int main() {
    string n;
    while(cin >> n) {
        if(n == "0")    break;

        int degree = calcDegree(n, 0);
        if(degree == 0)    cout << n << " is not a multiple of 9.\n";
        else            cout << n << " is a multiple of 9 and has 9-degree " << degree << ".\n";
    }
}