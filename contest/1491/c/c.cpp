/**
 * author: masab hasnain
 * Time: 2021-03-16 00:09:27
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
        vector<int> in(n + 1);
        for(int i = 1; i <= n; i++) cin >> in[i];
        ll ans = 0;
        for(int i = 1; i <= n; i++) if(in[i] > 1){
            /* cout << i << " ---- " ; */
            /* for(int r = 1; r <= n; r++) cout << in[r] << " "; cout << endl; */
            /* cout << ans << endl; */
            if(i == n){
                ans += in[i] - 1;
                continue;
            }
            if(in[i] > n - i){
                ans += in[i] - (n - i);
                in[i] = n - i ;
            }
            vector<int> suf(n + 5, 0);
            suf[n + 1] = n + 1;
            for(int j = n; j >= i; j--){
                if(in[j] > 1) suf[j] = j;
                else suf[j] = suf[j + 1];
            }
            for(int j = in[i]; j > 1; j--){
                ans++;
                int cur = i, next; 
                while(cur <= n){
                    next = cur + in[cur];
                    if(in[cur] == 1) next = max(next, suf[cur]);
                    in[cur]--;
                    in[cur] = max(1, in[cur]);
                    cur = next;
                }
            }
        }
        cout << ans << endl;
    }
 
}
