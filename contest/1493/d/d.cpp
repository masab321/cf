/**
 * author: masab hasnain
 * Time: 2021-03-08 02:07:42
**/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll mm = 2e5 + 10;
const ll mod = 1e9 + 7;
vector<ll> pr(mm + 100, 0ll), in(mm);
map<ll, ll> prime_factors[mm];
multiset<ll> divisor[mm];
ll ans = 1, n, q;

void add(ll p, ll x){
    while(x != 1){
        ll prime = pr[x];
        ll cur = 0;
        while(pr[x] == prime){
            cur++;
            x /= pr[x];
        }
        ll last = prime_factors[p][prime];
        prime_factors[p][prime] += cur;

        ll last_min = 0;
        if((int)divisor[prime].size() == n){
            last_min = (*divisor[prime].begin());
        }

        if(last != 0){
            divisor[prime].erase(divisor[prime].find(last));
        }
        divisor[prime].insert(last + cur);
        if((int)divisor[prime].size() == n) 
            for(last_min = last_min + 1; last_min <= (*divisor[prime].begin()); last_min++){
                ans = ans * prime % mod;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    

    pr[1] = 1;
    for(ll i = 2; i < mm; i++){
        if(pr[i] == 0){
            pr[i] = i;
            for(ll j = i * i; j < mm; j += i){
                if(pr[j] == 0) pr[j] = i;
            }
        }
        //cout << i << " " << pr[i] << " " << mm  << endl;
    }
    
    cin >> n >> q;
    //cout << "ok" << endl;
    for(int i = 1; i <= n; i++){
        ll x; cin >> x;
        add(i, x);
    }

    while(q--){
        ll p, x; cin >> p >> x;
        add(p, x);
        cout << ans << endl;
    }

}




