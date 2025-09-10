#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int sumOfFactors(int n) {
    if(n == 1)  return 0;

    int sum = 0;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            sum += i;
            sum += n / i;
        }
    }
    return sum + 1;
}

int main() {
    int n;
    vector<int> vec;
    while(cin >> n && n) {
        vec.push_back(n);
    }

    cout << "PERFECTION OUTPUT\n";
    for(const int num : vec) {
        cout << setw(5) << setfill(' ') << num << "  ";
        int sum = sumOfFactors(num);
        if(sum == num)      cout << "PERFECT\n";
        else if(sum < num)  cout << "DEFICIENT\n";
        else                cout << "ABUNDANT\n";
    }
    cout << "END OF OUTPUT\n";
}