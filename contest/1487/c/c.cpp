/**
 * author: masab hasnain
 * Time: 2021-02-15 21:34:46
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
        if(n % 2){
            int half = n / 2;
            for(int i = 1; i < n; i++){
                for(int j = i + 1, a = 0; j <= n; j++){
                    if(a < half){
                        cout << 1 << " ";
                        a++;
                    }else{
                        cout << -1 << " ";
                    }
                }
            }
        }else{
            int half = n / 2;
            half--;
            for(int i = 1; i < n; i++){
                for(int j = i + 1 , a = 0; j <= n; j++){
                    if(j - i < n / 2) cout << 1 << " ";
                    else if(j - i == n / 2) cout << 0 << " ";
                    else cout << -1 << " ";
                }
            }
        }
        cout << endl;
    }


}




