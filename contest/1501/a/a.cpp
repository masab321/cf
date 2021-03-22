/**
 * author: masab hasnain
 * Time: 2021-03-13 15:11:43
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
        vector<pair<int, int>> in(n);
        for(auto &i: in) cin >> i.first >> i.second;

        vector<int> tm(n);
        for(int &i: tm) cin >> i;
        int cur = 0;
        for(int i = 0; i < n; i++){
            /* cout << cur << endl; */
            if(i) cur += in[i].first - in[i - 1].second + tm[i];
            else cur += in[i].first + tm[i];
            int dif = in[i].second - in[i].first;
            dif++; 
            dif /= 2;
            if(i == n - 1) break;
            if(cur + dif < in[i].second) cur = in[i].second;
            else if(cur + dif >= in[i].second) cur += dif;
        }
        cout << cur << endl;
    }

}




