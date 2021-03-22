/**
 * author: masab hasnain
 * Time: 2021-03-11 11:36:04
**/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

bool can(string s){
    stack<char> st;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ')'){
            if(st.empty()) return 0;
            else st.pop();
        }else{
            st.push('(');
        }
    }
    if(st.empty()) return 1;
    return 0;
}

string conv(string now, string abc){
    string ret = "";
    for(int i = 0; i < now.size(); i++){
        if(now[i] == 'A') ret += abc[0];
        else if(now[i] == 'B') ret += abc[1];
        else ret += abc[2];
    }
    return ret;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--){
        string now; cin >> now;
        bool yes = 0;
        if(can(conv(now, "((("))) yes = 1;
        if(can(conv(now, "(()"))) yes = 1;
        if(can(conv(now, "()("))) yes = 1;
        if(can(conv(now, "())"))) yes = 1;
        if(can(conv(now, ")(("))) yes = 1;
        if(can(conv(now, ")()"))) yes = 1;
        if(can(conv(now, "))("))) yes = 1;
        if(can(conv(now, ")))"))) yes = 1;

        if(yes) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}




