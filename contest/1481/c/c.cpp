/**
 * author: masab hasnain
 * Time: 2021-02-11 15:14:07
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
        int n; cin >> n;int m; cin >> m;
        vector<int> a(n), b(n), c(m), graph[n + 5];
        for(int &i: a) cin >> i;
        for(int i = 0; i < n; i++){
            cin >> b[i];
            if(b[i] != a[i]){
                graph[b[i]].push_back(i);
            }
        }
        int last_pos = -1;
        for(int &i: c) cin >> i;
        if(graph[c.back()].empty()){
            for(int i = 0; i < n; i++){
                if(b[i] == c.back()){
                    last_pos = i;
                    break;
                }
            }
        }else{
            last_pos = graph[c.back()].back();
            graph[c.back()].pop_back();
        }
        if(last_pos == -1){
            cout << "NO" << endl;
            continue;
        }
        vector<int> ans;
        for(int i: c){
            if(graph[i].empty()){
                ans.push_back(last_pos);
                a[last_pos] = i;
            }else{
                ans.push_back(graph[i].back());
                a[graph[i].back()] = i;
                graph[i].pop_back();
            }
        }
        if(a == b){
            cout << "YES" << endl;
            for(int i: ans) cout << i + 1 << " "; cout << endl;
        }else{
            cout << "NO" << endl;
        }
    }

}




