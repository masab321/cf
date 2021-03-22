/**
 * author: masab hasnain
 * Time: 2021-03-10 19:33:27
**/
 
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int n; cin >> n;
    vector<int> in(n + 5), left(n + 5, 0), right(n + 5, 0), lb(n + 5, 0), rb(n + 5, 0);
    
    for(int i = 1; i <= n; i++){
        cin >> in[i];
    }
 
    for(int i = 2; i <= n; i++){
        if(in[i] > in[i - 1]) left[i] = left[i - 1] + 1;
    }
    for(int i = 2; i <= n; i++){
        lb[i] = max(left[i], lb[i - 1]);
    }
    
    for(int i = n - 1; i >= 0; i--){
        if(in[i] > in[i + 1]) right[i] = right[i + 1] + 1;
    }
    for(int i = n - 1; i >= 0; i--){
        rb[i] = max(rb[i + 1], right[i]);
    }
 
    int ans = 0;
    int mx = max(lb[n], rb[1]);
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        cnt += (left[i] == mx);
        cnt += (right[i] == mx);
    }
    if(cnt >= 3){
        cout << 0 << endl;
        return 0;
    }
    for(int i = 2; i < n; i++){
        int cn = min(left[i], right[i]);
        int cm = max(left[i], right[i]);
        if(left[i] == right[i] and left[i] == mx and mx % 2 == 0 ){
                ans++;
        }
    }
    cout << ans << endl;
}
