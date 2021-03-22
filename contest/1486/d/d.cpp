/**
 * author: masab hasnain
 * Time: 2021-03-12 13:01:15
**/

#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using  ull = unsigned long long;
ll n, k; 
bool can(ll cur, vector<ll> a){
    vector<int> temp(n + 5, 0);
    for(int i = 0; i < n; i++){
        if(a[i] >= cur) temp[i + 1] = 1;
        else temp[i + 1] = -1;
    }
    for(int i = 1; i <= n; i++) temp[i] += temp[i - 1];
    /* cout << cur << endl; */
    /* for(int i = 1; i <= n; i++) cout << temp[i] << " "; cout << endl; */
    int mn = 0;
    for(int i = k; i <= n; i++){
        mn = min(mn, temp[i - k]);
        if(temp[i] - mn > 0) return 1;
    }
    return 0;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    vector<ll> in(n);
    for(auto &i: in) cin >> i;

    ll l = 1, r = n + 5;
    ll ans = 0;
    while(l <= r){
        ll mid = l + r; mid /= 2;
        if(can(mid, in)){
            l = mid + 1;
            ans = mid;
        }else{
            r = mid - 1;
        }
    }
    cout << ans << endl;

}




