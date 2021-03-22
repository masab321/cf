/**
 * author: masab hasnain
 * Time: 2021-03-12 11:55:48
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
        vector<ll> in(n);
        for(ll &i: in) cin >> i;
        for(int i = 0; i < n - 1; i++){
            if(in[i] < i) break;
            else{
                in[i + 1] += in[i] - i;
                in[i] = i;
            }
        }
        bool no = 0;
        /* for(auto i: in) cout << i << " "; cout << endl; */
        for(int i = 1; i < n; i++) if(in[i] <= in[i - 1]){
            no = 1;
            break;
        }
        if(no) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}




