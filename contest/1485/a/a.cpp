/**
 * author: masab hasnain
 * Time: 2021-03-19 22:15:47
**/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
ll cal(ll a, ll b){
    ll ans = 0;
    while(a){
        a /= b;
        ans++;
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        ll a, b; cin >> a >> b;
        ll ans = 100000;
        for(int i = (b == 1 ? 1 : 0); i < 200; i++){
            ans = min(ans, cal(a, b + i) + i);
        }
        cout << ans << endl;
    }
}




