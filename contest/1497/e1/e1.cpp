/**
 * author: masab hasnain
 * Time: 2021-03-17 22:29:53
**/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
vector<ll> primes_global;
vector<ll> sieve(ll _upper_bound = 10000000){//be careful when calling with a value.
    bitset<10000007> bs;
    bs.set();
    if(_upper_bound > 10000000)
        _upper_bound = 10000000;
    vector<ll> primes;
    ll _sieve_size = _upper_bound ;
    bs[0] = bs[1] = 0;
    for (ll i = 2; i <= _sieve_size; i++){
        if(bs[i]){
            for (ll j = i * i; j <= _sieve_size; j += i)
                bs[j] = 0;
            primes.push_back(i);
        }
    }
    primes_global = primes;
    return primes;
}
bool is_prime(ll _number){
    if(primes_global.empty())
        sieve();
    for (int i = 0; primes_global[i] * primes_global[i] <= _number and i < primes_global.size(); i++){
        if(_number % primes_global[i] == 0)
            return false;
    }
    return true;
}
vector<ll> prime_factors(ll _number){ //be careful about the upperbound of sieve.
    if(primes_global.empty()){ //calls sieve() if sieve() was not called before.
        sieve();
    }
    vector<ll> factors;
    ll pf_idx = 0, pf = primes_global[pf_idx];
    if(is_prime(_number)){
        factors.push_back(_number);
        return factors;
    }
    while (pf * pf <= _number )
    {
        if(_number % pf == 0){
            factors.push_back(pf);
            while(_number % pf == 0)
                _number /= pf;
        }
        
        pf = primes_global[++pf_idx];
    }
    if(_number != 1)
        factors.push_back(_number);

    return factors;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    auto pr = sieve();
    while(pr.back() > 4500) pr.pop_back();
    for(ll &i: pr) i *= i; 

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int k; cin >> k;
        vector<ll>in(n);
        for(ll &i: in) cin >> i;
        set<ll> pre;
        int ans = 0;
        for(int i = 0; i < n; i++){
            int k = in[i];
            for(ll p: pr){
                while(k % p == 0) k /= p;
            }
            if(pre.find(k) != pre.end()){
                pre.clear();
                pre.insert(k);
                ans++;
            }else{
                pre.insert(k);
            }
        }
        cout << ans + 1 << endl;
    }
}




