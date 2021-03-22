/**
 * author: masab hasnain
 * Time: 2021-03-18 13:26:19
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
        vector<int> in(n);
        for(int &i: in) cin >> i;
        vector<int> out, pref(n + 5, 0);
        for(int i = 0; i < n; i++){
            if(i){
                if(in[i] >= in[pref[i - 1]]) pref[i] = i;
                else pref[i] = pref[i - 1];
            }
        }
        /* for(int i = 0; i < n; i++) cout << pref[i] << " "; cout << endl; */
        for(int i = n - 1; i >= 0; i--){
            int r = i, l = pref[i];
            for(int j = l; j <= r; j++) out.push_back(in[j]);
            i = l;
        }
        for(int i: out ) cout << i << " "; cout << endl;
    }
}




