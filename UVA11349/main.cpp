#include <iostream>
using namespace std;

int main() {
    int num;
    cin >> num;

    for(int i = 1; i <= num; i++) {
        char temp;
        int n;
        cin >> temp >> temp >> n;

        long long int arr[n][n];
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                cin >> arr[j][k];
            }
        }

        bool isSymmetric = true;
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                if(arr[j][k] < 0) {
                    isSymmetric = false;
                    break;
                }
                else if(arr[j][k] != arr[n - j - 1][n - k - 1]) {
                    isSymmetric = false;
                    break;
                }
            }
        }

        cout << "Test #" << i << ": ";
        if(isSymmetric) {
            cout << "Symmetric." << "\n";
        } else {
            cout << "Non-symmetric." << "\n";
        }
    }
}