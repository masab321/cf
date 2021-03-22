/**
 * author: masab hasnain
 * Time: 2021-03-13 17:08:14
**/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n), b(n);
    for(ll &i: a) cin >> i;
    for(ll &i: b) cin >> i;
    if(n < m){
        swap(a, b);
        swap(n, m);
    }
    for(int i = 0; i < n; i++) a.push_back(a[i]);
}




