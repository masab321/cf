/**
 * author: masab hasnain
 * Time: 2021-03-17 20:39:12
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
        vector<int> in(1000, 0);
        for(int i = 0; i < n; i++){
            int k; cin >> k;
            in[k]++;
        }
        for(int i = 0; i <= 110; i++){
            if(in[i]){
                cout << i << " ";
                in[i]--;
            }
        }
        for(int i = 0; i <= 110; i++){
            for(int j = 0; j < in[i]; j++){
                cout << i << " ";
            }
        }
        cout << endl;
    }
}




