/**
 * author: masab hasnain
 * Time: 2021-03-10 18:11:36
**/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

bool palindrome(string s){
    int i = 0, j = s.size() - 1;
    while(i < j){
        if(s[i] != s[j]) return 0;
        i++; j--;
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        string s; cin >> s;
        bool can = 1;
        for(int i = 0; i < k; i++){
            if(s[i] != s[n - i - 1]) can = 0;
        }
        if(can == 0 or (n % 2 == 0 and k == n / 2)) cout << "NO" << endl;
        else cout << "YES" << endl;

    }

}




