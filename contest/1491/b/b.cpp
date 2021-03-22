/**
 * author: masab hasnain
 * Time: 2021-03-15 23:51:46
**/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        ll n, u, v; cin >> n >> u >> v;
        vector<int> in(n);
        for(int &i: in) cin >> i;
        if(count(in.begin(), in.end(), in[0]) == n){
            cout << v + min(u, v) << endl;
            continue;
        }
        bool yes = 0;
        for(int i = 0; i < n - 1; i++){
            if(abs(in[i] - in[i + 1]) > 1) yes = 1;
        }
        if(yes) cout << 0 << endl;
        else cout << min(u, v) << endl;
    }
}




