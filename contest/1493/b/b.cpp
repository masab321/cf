/**
 * author: masab hasnain
 * Time: 2021-03-08 00:13:40
**/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;


bool check(string &s){
    string mir = "01258";
    for(char c: s){
        if(mir.find(c) == string::npos) return 0;
    }
    return 1;
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int h, m; cin >> h >> m;
        string cur; cin >> cur;
        string temp = "";
        temp += cur[0]; temp += cur[1];
        int hh = stoi(temp);
        temp = "";
        temp += cur[3]; temp += cur[4];
        int mm = stoi(temp);

        for(int i = 0; i < 10009; i++){
            if(mm == m){
                hh++;
                mm = 0;
                if(hh == h){
                    hh = 0;
                }
            }
            string now = "";
            now += to_string(hh); now += to_string(mm);
            if(!check(now)){
                mm++;
                continue;
            }
            //cout << now << endl;
            string tmp = to_string(hh);
            if(tmp.size() == 1) tmp = "0" + tmp;
            for(char &c: tmp){
                if(c == '2') c = '5';
                else if(c == '5') c = '2';
            }
            reverse(tmp.begin(), tmp.end());
            int rh = stoi(tmp);
            tmp = to_string(mm);
            if(tmp.size() == 1) tmp = "0" + tmp;
            for(char &c: tmp){
                if(c == '2') c = '5';
                else if(c == '5') c = '2';
            }
            reverse(tmp.begin(), tmp.end());
            int rm = stoi(tmp);
            //cout << rh << ":" << rm << endl;
            swap(rh, rm);
            if(check(now) and rm < m and rh < h){
                if(hh < 10) cout << 0;
                cout << hh << ":";
                if(mm < 10) cout << 0;
                cout << mm << endl;
                break;
            }
            mm++;
        }
    }

}




