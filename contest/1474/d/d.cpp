/**
 * author: masab hasnain
 * Time: 2021-03-09 16:24:58
**/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

bool check(vector<ll> a){
    for(ll i = 0; i < (ll)a.size() - 1; i++){
        if(a[i] > a[i + 1]) return 0;
        a[i + 1] -= a[i];
        a[i] = 0;
    }
    if(a.back() == 0) return 1;
    return 0;
}

bool solve(vector<ll> a){
    ll n = (ll)a.size();
    vector<ll> b = a, cc = a;
    swap(b[0], b[1]);
    swap(cc[n - 1], cc[n - 2]);
    if(check(a) or check(b) or check(cc)) return 1;
    vector<ll> p(n), s(n);
    p[0] = a[0];
    s[n - 1] = a[n - 1];
    b = a;
    for(ll i = 1; i < n; i++){
        if(p[i - 1] == -1 or b[i] < b[i - 1]){
            p[i] = -1;
        }else{
            b[i] -= b[i - 1];
            b[i - 1] = 0;
            p[i] = b[i];
        }
    }
    b = a;
    for(ll i = n - 2; i >= 0; i--){
        if(s[i + 1] == -1 or b[i] < b[i + 1]){
           s[i] = -1;
        }else{
            b[i] -= b[i + 1];
            b[i + 1] = 0;
            s[i] = b[i];
        }
    }
    for(ll i = 1; i < n - 2; i++){
        if(p[i - 1] == -1 or s[i + 2] == -1) continue; 
        vector<ll> c = {p[i - 1], a[i], a[i + 1], s[i + 2]};
        swap(c[1], c[2]);
        if(check(c)) return 1;
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> in(n);
        for(ll &i: in) cin >> i;
        auto rev = in;
        reverse(rev.begin(), rev.end());
        if(solve(in) or solve(rev)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}




