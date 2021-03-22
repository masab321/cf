/**
 * author: masab hasnain
 * Time: 2021-03-19 00:03:37
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
        string s; cin >> s;
        int one = 1;
        int n = s.size();
        if(count(s.begin(), s.end(), s[0]) == n){
            cout << "YES" << endl;
            continue;
        }
        int pre =  -2;
        for(int i = 0; i < n; i++){
            if(one){
                if(s[i] == '1'){
                    if(i - pre >= 2){
                        pre = i;
                    }else{
                        one = 0;
                    }
                }
            }else{
                if(s[i] == '0'){
                    if(i - pre >= 2){
                        pre = i;
                    }else{
                        one = 3;
                        break;
                    }
                }
            }
        }
        if(one == 3){
            cout << "NO" << endl;
        }else cout << "YES" << endl;
    }

}




