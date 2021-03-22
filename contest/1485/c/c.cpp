/**
 * author: masab hasnain
 * Time: 2021-03-19 23:12:37
**/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

bool can(ll mid, ll a, ll x){
    if(mid *a  + a<= x) return 1;
    return false;
}


ll bin_search(ll a, ll x){
    ll l = a, r =  a + a - 1;
    ll ret = 1;
    while(l <= r){
        ll mid = r + l; mid >>= 1;
        cout << l << " " << r <<  " " << mid << endl;
        if(can(mid, a, x)){
            l = mid + 1;
            ret = mid;
        }else{
            r = mid - 1;
        }
        cout << l << "--- " << r <<  "--- " << mid << endl;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t; cin >> t;
    while(t--){
        ll x, y;
        cin >> x >> y;
        ll ans = 0;
        for(ll i = 1; i * (i + 1) <= x; i++){
            ll cur = min(y, x / i - 1);
            ans += max(cur - i, 0ll);
        }
        cout << ans << endl;
    }
}




