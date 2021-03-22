/**
 * author: masab hasnain
 * Time: 2021-03-11 22:48:42
**/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;


int cal(vector<int> a, vector<int> b){
    int n = a.size(), m = b.size();

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans = 0;
    set<int> last(b.begin(), b.end());
    vector<int> all;
    for(int i: a){
        if(last.find(i) != last.end()) all.push_back(i);
    }
    sort(all.begin(), all.end());

    for(int i = m - 1; i >= 0; i--){
        int cur = 0;
        int r = b[i];
        int temp = upper_bound(a.begin(), a.end(), r) - a.begin();
        int l = r - temp + 1;
        cur = upper_bound(b.begin(), b.end(), r) - lower_bound(b.begin(), b.end(), l);
        cur += all.end() - upper_bound(all.begin(), all.end(), r);
        ans = max(ans, cur);
    }
    return ans;;
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<int> ls, l, rs, r;
        for(int i = 0; i < n; i++){
            int k; cin >> k;
            if(k < 0) l.push_back(abs(k));
            else r.push_back(k);
        }
        for(int i = 0; i < m; i++){
            int k; cin >> k;
            if(k < 0) ls.push_back(abs(k));
            else rs.push_back(abs(k));
        }

        cout << (cal(l, ls) +  cal(r, rs)) << endl;
    }
}




