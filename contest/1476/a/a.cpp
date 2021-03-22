/**
 * author: masab hasnain
 * Time: 2021-02-01 13:13:56
**/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const ll INF = 1ll << 62;
const int inf = 1 << 30;
const ll eps = -INF;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        if(n >= k){
            if(n % k == 0) cout << 1 << endl;
            else cout << 2 << endl;
        }else{
            int res = k / n;
            if(k % n) res++;
            cout << res << endl;
        }
    }

}
