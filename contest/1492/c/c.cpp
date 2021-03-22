/**
 * author: masab hasnain
 * Time: 2021-03-18 13:34:18
**/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    string a, b; cin >> a >> b;

    vector<int> pref, suf;
    for(int i = 0, j = 0; i < n; i++){
        if(j < m and a[i] == b[j]){
            j++;
            pref.push_back(i);
        }
    }

    for(int i = n - 1, j = m - 1; i >= 0; i--){
        if(j >= 0 and a[i] == b[j]){
            j--;
            suf.push_back(i);
        }
    }

    reverse(suf.begin(), suf.end());
    /* for(int i: pref) cout << i << " "; cout << endl; */
    /* for(int i: suf) cout << i << " "; cout << endl; */
    int ans = 1;
    for(int i = 0; i < m - 1; i++){
        ans = max(ans, suf[i + 1] - pref[i]);
    }
    cout << ans << endl;
}




