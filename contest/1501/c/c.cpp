/**
 * author: masab hasnain
 * Time: 2021-03-13 15:48:57
**/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int mm = 6e6;
    pair<int, int> pre[mm];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    vector<int> in(n + 5);
    for(int i = 1; i <= n; i++) cin >> in[i];
    
    for(int i = 0; i < mm; i++) pre[i].first = pre[i].second = -1;
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            int left = in[i] + in[j];
            if(pre[left].first == -1) pre[left] = {i, j};
            else{
                if(pre[left].first != i and pre[left].first != j and pre[left].second != i and pre[left].second != j){
                    cout << "YES" << endl;
                    cout << pre[left].first << " " << pre[left].second << " " << i << " " << j << endl;
                    return 0;
                }
            }
        }
    }
    cout << "NO" << endl;
       
}




