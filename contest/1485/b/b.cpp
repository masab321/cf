/**
 * author: masab hasnain
 * Time: 2021-03-19 22:38:40
**/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q, k;
    cin >> n >> q >> k;
    vector<ll> in(n + 1, 0);
    for(int i = 1; i <= n; i++) cin >> in[i];
    in.push_back(k);
    auto val = in;
    for(int i = 1; i <= n; i++){
        val[i] = in[i + 1] - in[i];
    }
    vector<ll> pref(n + 2, 0);
    for(int i = 1; i <= n; i++){
        pref[i] += pref[i - 1] + val[i];
    }
    /* cout << "VAl" << endl; */
    /* for(int i = 1; i <= n; i++) cout << val[i] << " "; cout << endl; */
    /* cout << "pref" << endl; */
    /* for(int i = 1; i <= n; i++) cout << pref[i] << " "; cout << endl; */
    while(q--){
        int l, r; cin >> l >> r;
        ll cur = (in[r] - in[l] + 1) - (r - l + 1);

        cur *= 2;
        cur += in[l] - 1;
        cur += k - in[r];
        cout << cur << endl;
    }

}




