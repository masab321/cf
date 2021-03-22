/**
 * author: masab hasnain
 * Time: 2021-02-17 23:19:48
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
        int ans = 0;
        int i = 3;
        while(i * i / 2 + 1 <= n){
            if(i % 2) ans++;
            i++;
        }
        cout << ans << endl;
    }
}




