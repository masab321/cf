/**
 * author: masab hasnain
 * Time: 2021-03-20 21:31:28
**/

#include<bits/stdc++.h>
using namespace std;
using ull = long long;
using uull = unsigned long long;

bool cmp(const pair<ull, ull> &a, const pair<ull, ull> &b){
    return a.first < b.first;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ull t; cin >> t;
    while(t--){
        ull a, b, n;
        cin >> a >> b >> n;
        vector<pair<ull, ull>> in(n);
        for(auto &i: in) cin >> i.first;
        ull tot = 0;
        for(auto &i: in){
            cin >> i.second;
            ull s = i.second / a;
            if(i.second % a) s++;
            tot += i.first * s;
        }
        ull yes = 0;
        for(auto i: in){
            ull cur = tot - i.first;
            if(cur < b){
                yes = 1;
                break;
            }
        }
        
        if(!yes) cout << "NO" << endl;
        else cout << "YES" << endl;
    }

}




