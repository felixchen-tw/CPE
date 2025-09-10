#include <iostream>
#include <vector>
#include <cmath>
#include <cfloat>
using namespace std;

int main() {
    int test;
    cin >> test;
    while(test--) {
        double cap, tar;
        cin >> cap >> tar;

        int n;
        cin >> n;
        vector<pair<double, double>> jars(n);
        for(int i = 0; i < n; i++) {
            cin >> jars[i].first >> jars[i].second;
        }

        int start = -1, end = -1;
        double diff = DBL_MAX;
        for(int i = 0; i < n; i++) {
            double c = 0, t = 0;
            for(int j = i; j < n; j++) {
                c += jars[j].first;
                t += jars[j].first * jars[j].second;
                if(c >= cap / 2 && c <= cap && fabs(t / c - tar) <= 5) {
                    if(fabs(t / c - tar) < diff) {
                        diff = fabs(t / c - tar);
                        start = i;
                        end = j;
                    }
                }
            }
        }
        if(diff == DBL_MAX) {
            cout << "Not possible\n";
        }
        else {
            cout << start << " " << end << "\n";
        }
    }
}