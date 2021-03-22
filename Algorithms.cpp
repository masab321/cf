/**
    author: masab hasnain
    time: 1:50:29 pm
    date: 22:5:2020

    things I can not memorize starts from here.
    
    Formulae:
    total number of subsegments = (n*(n+1))/2
    contribution to sum of all subsegments = i * (n-i + 1) * a[i];
    permutation (nPr) = n! / (n-r)!
    combination (nCr) = nPr / r! == n!/(r! * (n-r)!) 

    Turn on bit 0
    code = code | 1;

    Turn off bit 0 
    code = code & ~1;

    Turn on bit 1   
    code = code | 2;

    Turn off bit 1 
    code = code & ~2;

    linux commands:
    ls *.cpp | nl.
**/

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using  ull = unsigned long long;

// policy based data structrue. it can be used to find the k th element in a set. starts from 0.
// supports two additional operation:
// 1. order_of_key(val) returns number of items strictly less than key;
// 2. find_by_order(index) return a pointer pointing to the index; same as returning arr[index] but a pointer.
// I only know the use of set.
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

ll gcd(ll a, ll b){
    return b == 0LL ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b){
    return (a * b) / gcd(a, b);
}

const ll mm = 2e6; //set the value of highest range.
ll mod = 1e7 + 9;  //set the value of mod.
ll mod_pow(ll base, ll power){
    base %= mod;
    ll ret = 1LL;
    while(power){
        if(power&1)
            ret = (ret * base) % mod;
        base = (base * base) % mod;
        power >>= 1;
    }
    return ret;
}

ll mod_add(ll x, ll y){
    x += y;
    x %= mod;
    if(x<0){
        x = mod + x;
    }
    return x;
}

ll mod_sub(ll x, ll y){
    x -= y;
    x %= mod;
    return x<0 ? mod + x : x;
}

ll mod_inv(ll x){
    return mod_pow(x, mod - 2LL);
}

ll mod_div(ll x, ll y){
    return (x % mod) * mod_inv(y) % mod;
}
ll mod_mul(ll x, ll y){
    return (x%mod) * (y%mod) % mod;
}
ll fact[mm];
ll nCr(ll n , ll r){
    if(fact[1] != 1 and fact[2] != 2){
        fact[0] = 1;
        for(ll i =1; i <= mm; i++){
            fact[i] = (fact[i-1] % mod) * i % mod;
            fact[i] %= mod;
        }
    }
    return (fact[n] * mod_inv(fact[r] * fact[n-r] % mod)) % mod; 
}

ll nPr(ll n, ll r){
    //This function was not tested.
    ll ret = 1;
    for(ll i = 1; i<= r; i++){
        ret = (ret % mod) * (n % mod);
        ret %= mod;
        n--;
    }
    return ret;
}


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
vector<int> prefix_match(string a){ //0 based index.
    //It can be used to find the largest palindrome starting from the begining in a string. string format a + "#" + reverse(a); palindrome is a[0] --- a[k-1];
    int n = a.size();
    vector<int> ret(n, 0);
    int k = 0;
    for(int i = 1; i<n; i++){
        while(k>0 and a[i] != a[k])
            k = ret[k-1];

        if(a[i] == a[k])
            k++;
        ret[i] = k;
    }
    return ret;
}

vector<int>kmp(string t, string p){ //0 based index.
    vector<int>shifts;
    int k = 0;
    auto pi = prefix_match(p);
    int n = t.size(), m = p.size();
    for(int i = 0; i<n ; i++){
        while(k>0 and t[i] != p[k])
            k = pi[k-1];
        if(t[i]==p[k]){
            k++;
        }
        if(k == m){
            shifts.push_back(i - m + 1);
            k = pi[k-1];
        }
    }
    return shifts;
}

struct LCA {
    vector<int> height, euler, first, segtree;
    vector<bool> visited;
    int n;

    LCA(vector<vector<int>> &adj, int root = 0) { // construct with vector of vectors not arrays.0 - based indexing. uses segment tree.
        n = adj.size();
        height.resize(n);
        first.resize(n);
        euler.reserve(n * 2);
        visited.assign(n, false);
        dfs(adj, root);
        int m = euler.size();
        segtree.resize(m * 4);
        build(1, 0, m - 1);
    }

    void dfs(vector<vector<int>> &adj, int node, int h = 0) {
        visited[node] = true;
        height[node] = h;
        first[node] = euler.size();
        euler.push_back(node);
        for (auto to : adj[node]) {
            if (!visited[to]) {
                dfs(adj, to, h + 1);
                euler.push_back(node);
            }
        }
    }

    void build(int node, int b, int e) {
        if (b == e) {
            segtree[node] = euler[b];
        } else {
            int mid = (b + e) / 2;
            build(node << 1, b, mid);
            build(node << 1 | 1, mid + 1, e);
            int l = segtree[node << 1], r = segtree[node << 1 | 1];
            segtree[node] = (height[l] < height[r]) ? l : r;
        }
    }

    int query(int node, int b, int e, int L, int R) {
        if (b > R || e < L)
            return -1;
        if (b >= L && e <= R)
            return segtree[node];
        int mid = (b + e) >> 1;

        int left = query(node << 1, b, mid, L, R);
        int right = query(node << 1 | 1, mid + 1, e, L, R);
        if (left == -1) return right;
        if (right == -1) return left;
        return height[left] < height[right] ? left : right;
    }

    int lca(int u, int v) {
        int left = first[u], right = first[v];
        if (left > right)
            swap(left, right);
        return query(1, 0, euler.size() - 1, left, right);
    }

    int dist(int u, int v){
        return height[u] + height[v] - (2 * height[lca(u, v)]);
    }
};


// Segment tree example with lazy propagation to find the min element on right side equAL to zero;
const ll mm = 2e5 + 10;
ll seg[mm << 2], lazy[mm << 2];
ll in[mm];

void build(ll node, ll l, ll r){
    if(l == r){seg[node] = in[l]; return;}
    ll mid = l + r; mid >>= 1;
    build(node << 1, l, mid);
    build((node << 1) + 1, mid + 1, r);
    seg[node] = min(seg[node << 1], seg[(node << 1) + 1]);
}

void update(ll node, ll l, ll r, ll L, ll R, ll val){
    if(r < L or l > R) return;
    if(lazy[node] != 0){
        seg[node] += lazy[node];
        if(l != r){
            lazy[node << 1] += lazy[node];
            lazy[(node <<  1) + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(l >= L and r <= R){
        seg[node] += val;
        if(l != r){
            lazy[node << 1] += val;
            lazy[(node << 1) + 1] += val;
        }
        return;
    }

    ll mid = l + r; mid >>= 1;
    update(node << 1, l, mid, L, R, val);
    update((node << 1) + 1, mid + 1, r, L, R, val);
    seg[node] = min(seg[node << 1] + lazy[node << 1], seg[(node << 1) + 1] + lazy[(node << 1) + 1]);
}

ll get_last(ll node, ll l, ll r, ll L, ll R){
    if(l > R or r < L) return -1;
    // cout << l << " " << r << " " << seg[node] << " " << lazy[node] << endl;
    if(lazy[node] != 0){
        seg[node] += lazy[node];
        if(l != r){
            lazy[node << 1] += lazy[node];
            lazy[(node << 1) + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(l == r) return l;
    ll mid = l + r; mid >>= 1;
    int ret = -1;
    if(seg[(node << 1) + 1] + lazy[(node << 1) + 1] == 0) ret = get_last((node << 1) + 1, mid + 1, r, L, R);
    else ret = get_last(node << 1, l, mid, L, R);
    seg[node] = min(seg[node << 1] + lazy[node << 1], seg[(node << 1) + 1] + lazy[(node << 1) + 1]);
    return ret;
}


// Fenwick Tree or Binary Indexed Tree(BIT) from cp3.

class fenwick_tree{ // first index is 1;
private:
    vector<int> ft;
public:
    fenwick_tree(int n){
        ft.assign(n + 1, 0);
    }
    int ls_one(int a){  //returns the least significant bit of a;
        return (a & (-a));
    }
    int rsq(int a){ // range sum query from 1 to a; 
        int sum = 0;
        for(; a; a -= ls_one(a)) sum += ft[a];
        return sum;
    }
    int rsq(int a, int b){ // range sum query from a to b;
        return (rsq(b) - (a <= 1 ? 0 : rsq(a - 1)));
    }
    void update(int pos, int val){ // to update sum of range update(pos, pos); to update the index by 1 update(pos, 1);
        for(; pos < ft.size(); pos += ls_one(pos)) ft[pos] += val;
    } 
};

class seg_tree{ //1 based indexed. first item should be at position 1;
private:
    int n;
    vector<int> tree;
    vector<int> in;
public:
    seg_tree(vector<int> _in, int sz){
        tree.assign((sz + 5) * 4, 0);
        n = sz;
        in = _in;
        build(1, 1, sz);
    }
    void build(int v, int l, int r){
        if(l == r){
            tree[v] = in[l];
        }else{
            int mid = l + r; mid >>= 1;
            build(v * 2, l, mid);
            build(v * 2 + 1, mid + 1, r);
            tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
        }
    }
    int query(int v, int l, int r, int tl, int tr){
        if(tr < l or tl > r) return INT_MAX;
        if(tl >= l and tr <= r) return tree[v];
        
        int mid = tl + tr; mid >>= 1;
        int left = query(v * 2, l, r, tl, mid);
        int right = query(v * 2 + 1, l, r, mid + 1, tr);

        return min(left, right);
    }
    void update(int val, int v, int pos, int l, int r){
        int mid = l + r; mid /= 2;
        if(mid == pos){
            tree[v] = val;
            in[pos] = val;
            return;
        }
        if(mid > pos) update(val, v * 2, pos, l, mid);
        if(mid < pos) update(val, v * 2 + 1, pos, mid + 1, r);

        tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
    }
    int query(int l, int r){
        return query(1, l, r, 1, n);
    }
    void update(int pos, int val){
        update(val, 1, pos, 1, n);
    }
};


/*___________________________________________________________*/



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
}
