/**
 * author: masab hasnain
 * Time: 2021-03-06 10:51:48
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
        string s; cin >> s;
        string ss = s;
        s = "a" + s;
        vector<int> dpl(n + 5 , 0), dpr(n + 5, 0);
        
        for(int i = 1; i <= n; i++){
            if(s[i] == 'L'){
                dpl[i] = 1;
                if(i > 1 and s[i - 1] == 'R') dpl[i] = dpl[i - 2] + 2;
            }
        }
        for(int i = n - 1; i >= 0; i--){
            if(ss[i] == 'R'){
                dpr[i] = 1;
                if(i < n - 1){
                    if(ss[i + 1] == 'L') dpr[i] = dpr[i + 2] + 2;
                }
            }
        }

        for(int i = 0; i <= n; i++) cout << dpl[i] + dpr[i] + 1 << " "; cout << endl;
    }
}




