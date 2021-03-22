/**
 * author: masab hasnain
 * Time: 2021-03-07 12:37:37
**/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

bool is_palindrome(string s){
    int i = 0, j = s.size() - 1;
    while(i < j){
        if(s[i] != s[j]) return 0;
        ++i; --j;
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<string>in(n);
        for(auto &i: in) cin >> i;
        // check for two pair;
        bool f = 0;
        for(int i = 0; i < n and !f; i++){
            for(int j = 0; j < n and !f; j++){
                if(i == j) continue;
                if(in[i][j] == in[j][i]){
                    cout << "YES" << endl;
                    vector<int> temp = {i + 1, j + 1};
                    for(int k = 0; k <= m; k++) cout << temp[k % 2] << " ";
                    cout << endl;
                    f = 1;
                    break;
                }
            }
        }
        if(f) continue;

        if(m % 2 == 1){
            for(int i = 0; i < n and !f; i++){
                for(int j = i + 1; j < n and !f; j++){
                    if( 1 or in[i][j] != in[j][i]){
                        cout << "YES" << endl;
                        f = 1;
                        vector<int> temp = {i + 1, j + 1};
                        for(int k = 0; k <= m; k++) cout << temp[k % 2] << " "; cout << endl;
                        break;
                    }
                }
            }
        }

        if(f) continue;

        vector<int> res;
        if(n == 2){
            cout << "NO" << endl;
            continue;
        }
        vector<vector<int>> has(n, vector<int>(2, -1));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                has[i][in[i][j] - 'a'] = j;
            }
        }

        for(int i = 0; i < n and !f; i++){
            for(int j = 0; j < n and !f; j++){
                if(i == j) continue;
                if(has[j][in[i][j] - 'a'] == -1) continue;
                vector<int> temp = {i + 1, j + 1, has[j][in[i][j] - 'a'] + 1, j + 1};
                if((m / 2) % 2 == 1 ) res = temp;
                else{
                    vector<int> r = {j + 1, has[j][in[i][j] - 'a'] + 1, j + 1, i + 1};
                    res = r;
                }
                f = 1;
                break;
            }
        }


        cout << "YES" << endl;
        if( 0 and (m / 2) % 2 == 0){
            for(int i = 1; i <= m + 1; i++)
                cout << res[i % 4] << " "; cout << endl;
            
        }else{
            for(int i = 0; i <= m; i++)
                cout << res[i % 4] << " "; cout << endl;
        }

    }
}




