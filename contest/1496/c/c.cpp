/**
 * author: masab hasnain
 * Time: 2021-03-10 18:50:40
**/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

bool comp(double a, double b){
    return a <= b;
}

int main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n ;
        vector<ll> miners, diamonds;

        for(ll i = 0; i < n + n; i++){
            ll x, y; cin >> x >> y;
            if(x == 0){
                miners.push_back(abs(y));
            }else{
                diamonds.push_back(abs(x));
            }
        }
        sort(miners.begin(), miners.end());
        sort(diamonds.begin(), diamonds.end());
        double  ans = 0;
        for(ll i = 0, j = n - 1; i < n; i++, j--){
            double cur = sqrt((miners[i] * miners[i]) + (diamonds[i] * diamonds[i]));
            ans += cur;
        }
        printf("%.15lf\n", ans);
    }




}




