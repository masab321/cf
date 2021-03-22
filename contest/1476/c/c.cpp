/**
 * author: masab hasnain
 * Time: 2021-02-02 12:05:27
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
        int n; cin >> n;
        vector<int> c(n), a(n), b(n);
        for(int &i: c) cin >> i;
        for(int &i: a) cin >> i;
        for(int &i: b) cin >> i;

        ll res = 0;
        ll prev = 0;
        for(int i = 1; i < n; i++){
            ll cur = c[i] + abs(a[i] - b[i]) + 1;
            if(a[i] != b[i]){
                cur = max(cur, prev + c[i] - abs(a[i] - b[i]) + 1);
            }
            res = max(res, cur);
            prev = cur;
        }
        cout << res << endl;
    }


}




