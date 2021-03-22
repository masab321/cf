/**
 * author: masab hasnain
 * Time: 2021-03-08 01:19:01
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
        int k; cin >> k;
        string s; cin >> s;
        if(n % k){
            cout << -1 << endl;
            continue;
        }
        vector<int> freq(26, 0);
        for(char c: s) freq[c - 'a']++;
        bool f = 0;
        for(int i: freq){
            if(i % k) f = 1;
        }
        if(!f){
            cout << s << endl;
            continue;
        }
        
        for(int &i: freq) i = 0;
        int pos = -1;
        char ch = s[0];
        for(int i = 0; i < n; i++){
            char cur;
            bool can = 0;
            for(char c = s[i] + 1; c <= 'z'; c++){
                int rem = 0;
                freq[c - 'a']++;
                for(int j: freq){
                    if(j % k){
                        rem += k - (j % k);
                    }
                }
                if(n - i - 1 >= rem and ((n - i - 1) - rem) % k == 0){
                    ch = c;
                    pos = i;
                    freq[c - 'a']--;
                    break;
                }
                freq[c - 'a']--;
            }
            freq[s[i] - 'a']++;
        }
        //cout << pos << " " << ch << endl;
        if(pos == -1) cout << -1 << endl;
        else{
            freq.assign(26, 0);
            for(int i = 0; i < pos; i++){
                cout << s[i];
                freq[s[i] - 'a']++;
            }
            cout << ch;
            freq[ch - 'a']++;
            int rem = 0;
            for(int i = 0; i < 26; i++){
                if(freq[i] % k){
                    rem += k - (freq[i] % k);
                    int rest =  k - (freq[i] % k);
                    freq[i] = rest;
                }
                else freq[i] = 0;
              //  cout << char('a' + i) << " = " << freq[i] << endl;
            }
            //cout << " --- " << rem << endl;
            int r = n - (pos + 1) - rem;
            //cout << "---r " << r << endl;
            while(r > 0 and r--) cout << 'a';
            for(int i = 0; i < 26; i++){
                while(freq[i] > 0){
                    char tr = 'a' + i;
                    cout << tr;
                    freq[i]--;
                }
            }
            cout << endl;
        }
    }

}




