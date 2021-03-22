/**
 * author: masab hasnain
 * Time: 2021-03-12 12:18:08
**/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int query(int l, int r){
    cout << "? " << l << " " << r << endl;
    int c; cin >> c;
    return c;
}


int main(){
    /* ios_base::sync_with_stdio(0); */
    /* cin.tie(0); */

    int n; cin >> n;
    int l = 1, r = n;
    while(r - l > 1 and r > l){
        
        int c = query(l, r);
        
        if(c - l > 1){
            int d = query(l , c);
            if(c == d){
                r = c - 1;
            }else{
                l = c + 1;
            }
        }else{
            int d = query(c, r);
            if(c == d){
                l = c + 1;
            }else{
                r = c - 1;
            }
        }
    }
    if(l == r) cout << "! " << l << endl;
    else{
        int c = query(l , r);
        cout << "! ";
        cout.flush();
        if(c == l) cout << r << endl;
        else cout << l << endl;
    }
    return 0;
}




