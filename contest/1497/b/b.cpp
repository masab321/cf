/**
 * author: masab hasnain
 * Time: 2021-03-17 20:50:26
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
        int n, m; cin >> n >> m;
        map<int, int> in;
        for(int i = 0; i < n; i++){
            int k; cin >> k;
            k %= m;
            in[k]++;
        }
        int ans = 0;
        while(!in.empty()){
            auto a = in.begin();
            
            auto b = in.find((m - a->first));
            if(a->first == 0){
                ans++;
                in.erase(a);
            }
            else if(a == b){
                in.erase(a);
                ans++;
            }else if(b == in.end()){
                ans += a->second;
                in.erase(a);
            }else{
                /* cout << "b " << b->first << endl; */
                int dif = abs(a->second - b->second);
                if(dif <= 1) ans++;
                else ans += 1 + (dif - 1);
                in.erase(a);
                in.erase(b);
            }
            /* cout << a->first << " " << ans << endl; */
        }
        cout << ans << endl;
    }
}




