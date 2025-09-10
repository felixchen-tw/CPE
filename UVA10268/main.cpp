#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
  ll x, val;
  string s;
  while(cin >> x) {
    getline(cin, s);
    getline(cin, s);
    istringstream sin(s);
    vector<ll> poly;
    while(sin >> val){
        poly.push_back(val);
    }
    reverse(poly.begin(), poly.end());

    for(int k = 0; k < poly.size(); k++){
      poly[k] *= k;
    }
    poly.erase(poly.begin());
    
    ll u = 1, ans = 0;
    for(auto &v : poly){
        ans += u * v;
        u *= x;
    }
    cout << ans << "\n";
  }
  return 0;
}