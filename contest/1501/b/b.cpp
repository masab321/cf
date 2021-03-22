/**
 * author: masab hasnain
 * Time: 2021-03-13 15:31:52
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
        int n; cin >> n;
        vector<int> in(n + 5, 0);
        for(int i = 1; i <= n; i++){
            int k; cin >> k;
            if(k != 0){
                in[i] += -1;
                if(i - k >= 0) in[i - k] += 1;
                else in[0] += 1;
            }
        }
        /* for(int i = 0; i <= n; i++) cout << in[i] << " "; cout << endl; */
        for(int i = 0; i < n; i++){
            if(i) in[i] += in[i - 1];
            if(in[i]) cout << 1 << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }
}




