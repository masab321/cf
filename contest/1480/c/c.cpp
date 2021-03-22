/**
 * author: masab hasnain
 * Time: 2021-03-22 13:48:31
**/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    int l = 1, r = n;
    int ans = n;
    while(l < r){
        int mid = l + r; mid /= 2;
        int a, b;
        cout << "? " << mid << endl;
        cin >> a;
        cout << "? " << mid + 1 << endl;
        cin >> b;

        if(a < b){
            r = mid;
            ans = r;
        }else{
            l = mid + 1;
            ans = l;
        }
    }

    cout << "! " << r << endl;

}




