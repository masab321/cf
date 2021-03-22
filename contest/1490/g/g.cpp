/**
 * author: masab hasnain
 * Time: 2021-02-16 22:32:17
**/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t; cin >> t;
    while(t--){
        ll n, m; cin >> n >> m;
        vector<ll> in(n);
        for(ll &i: in) cin >> i;
        map<ll, ll> mp;
        vector<ll> cm(n, 0);
        cm[0] = in[0];
        if(cm[0] > 0) mp[cm[0]] = 0;
        for(ll i = 1; i < n; i++) {
            cm[i] = cm[i - 1] + in[i];

            if(cm[i] > 0){
                if(mp.empty()) mp[cm[i]] = i;
                else{
                    if(mp.rbegin()->first < cm[i]){
                        mp[cm[i]] = i;
                    }
                }
            }
        }
        while(m--){
            ll k; cin >> k;
            if(mp.empty() or (k > mp.rbegin()->first and cm[n - 1] <= 0)) cout << -1 << " ";
            else{
                auto cur = mp.lower_bound(k);
                if(cur != mp.end()){
                    cout << cur->second << " ";
                }else{
                    ll ans = (k - mp.rbegin()->first) / cm[n - 1];
                    ll temp = (k - mp.rbegin()->first) % cm[n - 1];
                    if(temp) ans++;
                    temp = ans;
                    ans *= n;
                    ans += mp.lower_bound(k - (temp * cm[n - 1]))->second;
                    cout << ans << " ";
                }
            }
        }
        cout << endl;
    }
}




