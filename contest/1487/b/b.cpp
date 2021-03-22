/**
 * author: masab hasnain
 * Time: 2021-02-15 21:06:56
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
        ll n, k; cin >> n >> k;
        if(n % 2 == 0){
            if(k <= n) cout << k << endl;
            else{
                if(k % n == 0) cout << n << endl;
                else cout << k % n << endl;
            }
        }else{
            k--;
            k = k + k / (n / 2);
            cout << (k % n) + 1 << endl;
        }
    }


}




