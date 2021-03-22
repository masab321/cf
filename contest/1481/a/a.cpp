/**
 * author: masab hasnain
 * Time: 2021-02-11 14:24:30
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
        int x, y; cin >> x >> y;
        string s; cin >> s;
        int u = 0, d = 0, l = 0, r = 0;
        for(char c: s){
            if(c == 'U') r++;
            else if(c == 'D') l++;
            else if(c == 'L') d++;
            else if(c == 'R') u++;
        }
        bool no = 0;
        if(x < 0){
            if(d < abs(x)) no = 1;
            if(y < 0){
                if(l < abs(y)) no = 1;
            }else{
                if(r < abs(y)) no = 1;
            }
        }else{
            if(u < abs(x)) no = 1;
            if(y < 0){
                if(l < abs(y)) no = 1;
            }else{
                if(r < abs(y)) no = 1;
            }
        }
        if(no) cout << "NO" << endl;
        else cout << "YES" << endl;
    }

}




