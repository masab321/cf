/**
 * author: masab hasnain
 * Time: 2021-02-15 20:36:45
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
        for(int &i: in) cin >> i;
        sort(in.begin(), in.end());
        int p = 0;
        if(count(in.begin(), in.end(), in.back()) == n) cout << 0 << endl;
        else{
            cout << n - count(in.begin(), in.end(), in[0]) << endl;
        }
    }
}




