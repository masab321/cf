/**
 * author: masab hasnain
 * Time: 2021-03-08 00:02:38
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
        vector<int> res;
        for(int i = n; i >= (k + 1) / 2; i--){
            if(i == k) continue;
            else res.push_back(i);
        }
        cout << res.size() << endl;
        for(int i: res) cout << i << " "; cout << endl;
    }
}




