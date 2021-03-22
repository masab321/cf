/**
 * author: masab hasnain
 * Time: 2021-03-15 23:05:30
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
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ordered_set os;
    int n, q; cin >> n >>q;
    vector<int> in(n + 1);
    int a = 0, b = 0;
    for(int i = 1; i <= n; i++){
        cin >> in[i];
        if(in[i]) a++;
    }
    while(q--){
        int t, k;
        cin >> t >> k;
        if(t == 1){
            if(in[k]) a--;
            else a++;
            in[k] = 1 - in[k];
        }else{
            if(a >= k) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }

}




