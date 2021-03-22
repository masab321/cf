/**
 * author: masab hasnain
 * Time: 2021-02-16 22:11:30
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
        int ans = n;
        map<int, int> temp;
        for(int i = 0; i < n; i++){
            int k; cin >> k;
            temp[k]++;
        }
        vector<int> in;
        for(auto i: temp) in.push_back(i.second);
        sort(in.begin(), in.end());
        n = in.size();
        map<int, pair<int, int>> lr;
        for(int i = 0; i < n; i++){
            int r = i + 1;
            while(r < n and in[r] == in[i]) r++;
            lr[in[i]] = {i, r - 1};
            i = r - 1;
        }
        vector<int> cm(n + 5, 0);
        cm[1] = in[0];
        for(int i = 2; i <= n; i++){
            cm[i] = cm[i - 1] + in[i - 1];
        }
        for(int i = 0; i < n; i++){
            int cur = 0;
            int x = in[i];
            cur += cm[n] - cm[lr[x].second];
            cur -= (n - lr[x].second) * x;
            
            cur += cm[lr[x].first];
            ans = min(ans, cur);
        }
        cout << ans << endl;


        
    }

}




