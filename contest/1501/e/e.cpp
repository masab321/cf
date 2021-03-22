/**
 * author: masab hasnain
 * Time: 2021-03-13 17:13:21
**/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

bool comp(vector<int> &a, vector<int> &b, int pos){
    if(a[pos] <= b[pos]) return 1;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<vector<int>> a(n + 5, vector<int>(m + 5));
    auto b = a;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) cin >> a[i][j];
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) cin >> b[i][j];
    vector<int> res;
    
    for(int i = 1; i <= m; i++){
        vector<int> temp;
        for(int j = 1; j <= n; j++) temp.push_back(b[j][i]);
        if(is_sorted(temp.begin(), temp.end())) res.push_back(i);
        else{


}




