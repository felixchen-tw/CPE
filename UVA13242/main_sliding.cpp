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
        double curr_cap = 0, curr_sugar = 0;
        int left = 0;
        for(int right = 0; right < n; right++) {
            curr_cap += jars[right].first;
            curr_sugar += jars[right].first * jars[right].second;

            // 收縮左指針直到容量 <= cap
            while(curr_cap > cap && left <= right) {
                curr_cap -= jars[left].first;
                curr_sugar -= jars[left].first * jars[left].second;
                left++;
            }

            // 檢查容量是否符合條件
            if(curr_cap >= cap / 2 && curr_cap <= cap) {
                double avg_sugar = curr_sugar / curr_cap;
                double curr_diff = fabs(avg_sugar - tar);
                if(curr_diff <= 5 && curr_diff < diff) {
                    diff = curr_diff;
                    start = left;
                    end = right;
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