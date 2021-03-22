/**
 * author: masab hasnain
 * Time: 2021-02-01 13:20:13
**/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const ll INF = 1ll << 62;
const int inf = 1 << 30;
const ll eps = -INF;

bool can(vector<double> &in, ll k){
    double inflation = double(k) / double(100);
    double tot = in[0];
    for(int i = 1; i < in.size(); i++){
        if(in[i] / tot > inflation) return false;
        tot += in[i];
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--){
        ll n, k; cin >> n >> k;
        vector<double> in(n);
        for(auto &i: in) cin >> i;
        ll l = in[0]; ll r = double(1ll << 60);
        ll f = in[0];
        ll ans = in[0];
        while(l <= r){
            ll mid = l + r; mid >>= 1;
            in[0] = mid;
            if(can(in, k)){
                ans = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        cout << abs(f - ans) << endl;
    }
}
