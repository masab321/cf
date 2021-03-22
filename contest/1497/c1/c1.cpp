/**
 * author: masab hasnain
 * Time: 2021-03-17 21:19:08
**/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >>t;
    while(t--){
        int n, k; cin >> n >> k;
        if(n % 2){
            cout << 1 << " " << n / 2 << " " << n/2 << endl;
        }else{
            if((n / 2) % 2){
                cout << 2 << " " << (n - 2) / 2  << " " << (n - 2) / 2 << endl;
            }else {
                cout << n / 2 << " " << (n / 2) / 2 << " " << (n / 2) / 2 << endl;
            }
        }
    }
}




