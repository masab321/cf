/**
 * author: masab hasnain
 * Time: 2021-03-18 22:56:19
**/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;


vector<ll> cal(vector<ll> in, ll n){
    ll path = n;
    ll a = in[0] * path;
    ll ans = a;
    ll pre = in[0];
    ll last = 1;
    ll mn = in[0];
    vector<ll> ret(in.size(), 0);
    ret[0] = ans;
    for(int i = 1; i < in.size(); i++){
        pre += in[i];
        mn = min(mn, in[i]);
        ll cur = mn * (path - last - 1);
        cur += pre;
        ret[i] = cur;
        last += 1;
    }
    return ret;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        ll path = n + n;
        vector<ll> in(n);
        vector<ll> a, b;
        for(int i = 0; i < n; i++){
            ll k; cin >> k;
            if(i % 2 == 0) a.push_back(k);
            else b.push_back(k);
        }
        ll ans = (1ll << 62);
        a = cal(a, n);
        b = cal(b, n);
        
        for(int i = 0; i < a.size(); i++){
            if(i < b.size()) ans = min(ans, a[i] + b[i]);
            if(i - 1 >= 0) ans = min(ans, a[i] + b[i - 1]);
        }

        cout << ans << endl;
    }

}




