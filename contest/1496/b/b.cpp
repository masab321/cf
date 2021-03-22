/**
 * author: masab hasnain
 * Time: 2021-03-10 18:28:21
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
        int n, k; cin >> n >> k;
        set<ll>in;
        for(int i = 0; i < n; i++){
            ll r; cin >> r;
            in.insert(r);
        }
        ll pre = 0;
        bool f = 0;
        ll ans = 0;
        for(int i = 0; i < k; i++){
            ll mex = pre;
            while(in.find(mex) != in.end()) mex++;
            pre = mex;
            ll mx = *in.rbegin();
            ll cur = mex + mx + 1;
            cur /= 2;
            if(mex == mx + 1){
                f = 1;
                ans = in.size();
                ans += k - i;
                break;
            }
            if(in.find(cur) != in.end()){
                break;
            }else{
                in.insert(cur);
            }
        }
        if(f){
            cout << ans << endl;
        }else
            cout << in.size() << endl;
    }
}




