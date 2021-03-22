/**
 * author: masab hasnain
 * Time: 2021-02-11 14:39:27
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
        vector<int> in(n);
        for(int &i: in) cin >> i;
        bool no = 0;
        int ans = 0;
        for(int i = 0; i < k; i++){
            for(int j = 0; j < n; j++){
                if(j == n - 1){
                    no = 1;
                    break;
                }
                if(in[j] < in[j + 1]){
                    in[j]++;
                    ans = j + 1;
                    break;
                }
            }
            if(no) break;
        }
        if(no) cout << -1 << endl;
        else cout << ans << endl;
    }
}




