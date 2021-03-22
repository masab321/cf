/**
 * author: masab hasnain
 * Time: 2021-02-16 21:01:30
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
        vector<int> in(5, 0);
        for(int i = 0; i < n; i++){
            int k; cin >> k;
            in[k % 3]++;
        }
        int ans = 0;
        for(int i = 0; i < 3; i++){
            if(in[i] > n / 3){
                int rem = in[i] - n / 3;
                ans += rem;
                in[(i + 1) % 3] += rem;
                in[i] = n / 3;
            }
        }
        for(int i = 0; i < 3; i++){
            if(in[i] > n / 3){
                int rem = in[i] - n / 3;
                ans += rem;
                in[(i + 1) % 3] += rem;
                in[i] = n / 3;
            }
        }
        cout << ans << endl;
    }

}




