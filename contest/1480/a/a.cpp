/**
 * author: masab hasnain
 * Time: 2021-03-20 21:15:27
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
        for(int i = 0; i < s.size(); i++){
            if(i % 2){
                if(s[i] == 'z') s[i] = 'y';
                else s[i] = 'z';
            }else{
                if(s[i] == 'a') s[i] = 'b';
                else s[i] = 'a';
            }
        }cout << s << endl;
    }
}




