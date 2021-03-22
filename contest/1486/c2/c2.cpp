/**
 * author: masab hasnain
 * Time: 2021-03-13 12:39:11
**/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int query(int l, int r){
    if(l >= r) return -1;
    cout << "? " << l << " " << r << endl;
    int ret; cin >> ret;
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    int sm = query(1, n);
    int l, r;
    int d;
    bool f = 0;
    if(n == 2){
        if(sm == 1) cout << "! " << 2 << endl;
        else cout << "! 1" << endl;
    }
    if(sm != 1){
        d = query(1, sm);
        if(d == sm){
            l = 1; r = sm - 1; 
        }else{
            l = sm + 1; r = n; f = 1;
        }
    }else{
        l = 2;
        r = n; f = 1;
    }

    int ans = 0;
    if(f) while(l <= r){
        int mid = l + r; mid >>= 1;
        d = query(sm, mid);
        if(d == sm){
            r = mid - 1;
            ans = mid;
        }else{
            l = mid + 1;
        }
    }else while(l <= r){
        int mid = l + r; mid >>= 1;
        d = query(mid, sm);
        /* cout << l << " " << r << " " << mid << " " << d << endl; */
        if(d == sm){
            l = mid + 1;
            ans = mid;
        }else{
            r = mid - 1;
        }
    }
    cout << "! " << ans << endl;

}




