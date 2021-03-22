/**
 * author: masab hasnain
 * Time: 2021-02-16 21:08:54
**/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

bool is_cube(ll b){
    ll r = 1;
    while(r * r * r <= b){
        if(r * r * r == b) return 1;
        r++;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        ll x; cin >> x;
        ll a = 1;
        bool f = 0;
        set<ll> cb;
        ll mm = ll(1e12) + 10;
        ll temp = 1;
        while(temp * temp * temp <= mm){
            cb.insert(temp * temp * temp);
            temp++;
        }
        while(a * a * a <= x){
            ll b = x - (a * a * a);
            if(cb.find(b) != cb.end()){
                f = 1;
                break;
            }
            a++;
        }
        if(f) cout << "YES" << endl;
        else cout << "NO" << endl;
    }


}




