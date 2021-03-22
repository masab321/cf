/**
 * author: masab hasnain
 * Time: 2021-02-16 20:37:36
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
        vector<int> in(n);
        for(int &i: in) cin >> i;
        int mn = *min_element(in.begin(), in.end());
        int ans = 0;
        for(int i = 0; i < n - 1;){
            if(max(in[i] , in[i + 1]) > min(in[i], in[i + 1]) * 2){
                ans++;
                if(in[i] > in[i + 1]){
                    in[i] = (in[i] + 1) / 2;
                }else{
                    in[i] *= 2; 
                }
            }
            else i++;
        }
        cout << ans << endl;
    }

}




