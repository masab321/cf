/**
 * author: masab hasnain
 * Time: 2021-03-18 13:10:33
**/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

ll cal(ll a, ll b){
    ll left = b / a;
    ll right = left + 1;
    left *= a;
    right *= a;
    if(left == b) return 0;
    return abs(right - b);
    return min(abs(left - b), abs(right - b));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--){
        ll p, a, b, c;
        cin >> p >> a >> b >> c;
        cout << min(cal(a, p), min(cal(b, p), cal(c, p))) << endl;
    }

}




