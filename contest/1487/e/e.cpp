/**
 * author: masab hasnain
 * Time: 2021-02-15 22:10:38
**/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int n1, n2, n3, n4; cin >> n1 >> n2 >> n3 >> n4;
    vector<pair<int, int>> a, b, c, d;
    vector<int> pa(n1 + 5), pb(n2 + 4), pc(n3 + 5), pd(n4 + 5);
    for(int i = 1; i <= n1; i++){
        int now; cin >> now;
        pa[i] = now;
        a.push_back({now, i});
    }
    for(int i = 1; i <= n2; i++){
        int now; cin >> now;
        pb[i] = now;
        b.push_back({now, i});
    }
    for(int i = 1; i <= n3; i++){
        int now; cin >> now;
        pc[i] = now;
        c.push_back({now, i});
    }
    for(int i = 1; i <= n4; i++){
        int now; cin >> now;
        pd[i] = now;
        d.push_back({now, i});
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    sort(d.begin(), d.end());

    int m; cin >> m;
    const int mm = 150009;
    set<int> am[mm], bm[mm], cm[mm];

    while(m--){
        int u, v; cin >> u >> v;
        am[u].insert(v);
    }
    cin >> m;
    while(m--){
        int u, v; cin >> u >> v;
        bm[u].insert(v);
    }
    cin >> m;
    while(m--){
        int u, v; cin >> u >> v;
        cm[u].insert(v);
    }
    vector<int> ra(mm, -1), rb(mm, -1), rc(mm, -1);

    for(int i = 1; i <= n3; i++){

    
}




