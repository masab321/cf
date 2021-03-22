/**
 * author: masab hasnain
 * Time: 2021-03-11 12:09:08
**/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

vector<vector<int>> ar(110, vector<int>(110, 0));

bool cal(int u, int r, int d, int l, int mask, int n){
    if(mask & 1){
        u--;
        r--;
    }
    if(mask & 2){
        u--;
        l--;
    }
    if(mask & 4){
        d--;
        r--;
    }
    if(mask & 8){
        d--;
        l--;
    }
    /* cout << "mask = " << mask << " ------ " << u << " " << r << " " << d << " " << l << endl; */
    return (min(min(u, d), min(r, l)) >= 0 and max(max(u, d), max(r, l)) <= n - 2); 
    if(max({u, l, d, r}) > n - 2) return 0;
    return 1;

}





int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n, u, r, d, l;
        cin >> n >> u >> r >> d >> l;
        bool yes = 0;
        for(int i = 0; i < (1 << 4); i++){
            if(cal(u, r, d, l, i, n)){
                yes = 1;
                break;
            }
        }
        if(yes) cout << "YES" << endl;
        else cout << "NO" << endl;

    }
}




