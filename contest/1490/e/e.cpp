/**
 * author: masab hasnain
 * Time: 2021-02-16 22:02:18
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
        vector<pair<int, int>> p;
        for(int i = 0; i < n; i++){
            cin >> in[i];
            p.push_back({in[i], i});
        }
        sort(p.begin(), p.end());
        vector<ll> cm(n, 0);
        cm[0] = p[0].first;
        for(int i = 1; i < n; i++){
            cm[i] = cm[i - 1] + p[i].first;
        }
        vector<int> res(n, 0);
        res[n - 1] = 1;
        for(int i = n - 2; i >= 0; i--){
            if(p[i].first == p[i + 1].first and res[i + 1]){
                res[i] = 1;
                continue;
            }
            if(cm[i] >= p[i + 1].first){
                res[i] = 1;
            }else break;
        }
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++){
            if(res[i]){
                ans[p[i].second] = 1;
            }
        }
        cout << count(ans.begin(), ans.end(), 1) << endl;
        for(int i = 0; i < n; i++) if(ans[i]) cout << i + 1 << " ";
        cout << endl;
    }
}




